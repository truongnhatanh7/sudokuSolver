#include <iostream>
using namespace std;
int grid[9][9];
bool possible(int y ,int x,int n){ //check if n is possible in the puzzle
   for(int i = 0;i<9;i++){
       if(grid[y][i] == n){
           return false;
       }
   }
   for(int i = 0;i<9;i++){
       if(grid[i][x]==n){
           return false;
       }
   }
   int x0,y0;
   x0 = (x/3)*3;
   y0 = (y/3)*3;
   for(int i = 0;i<3;i++){
       for(int j = 0;j<3;j++){
           if(grid[y0+i][x0+j]==n){
               return false;
           }
       }
   }
   return true;
}
void solve(){ //backtracking the solution
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(grid[i][j]==0){ //check if the current place is empty
                for(int n = 1;n<10;n++){ //try from 1->9
                    if(possible(i,j,n)){
                        grid[i][j] = n;
                        solve();
                        grid[i][j] = 0;
//                        cout << "check"<<endl;
                    }

                }
                return;
            }
        }
    }
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            if(j==8){
                cout << grid[i][j]<<"\n";
            }
            else{
                cout << grid[i][j]<<" ";
            }
        }
    }
}
int main() {
    for(int i = 0;i<9;i++){
        for(int j = 0;j<9;j++){
            cin >> grid[i][j];
        }
    }
    solve();
    return 0;
}
