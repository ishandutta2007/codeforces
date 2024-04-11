                            /* in the name of Allah */
#include <iostream>
using namespace std;

int mat[30][30];
bool mark[1100];

int main(){
    int n;
    cin >> n;
    mat[0][0] = 0, mat[0][1] = 3, mat[0][2] = 4;
    mat[1][0] = 3, mat[1][1] = 0, mat[1][2] = 5;
    mat[2][0] = 4, mat[2][1] = 5, mat[2][2] = 0;
    mark[3] = mark[4] = mark[5] = true;
    int arr[30];
    int ptr = 6;
    for(int i = 3; i < n; i++){
         arr[0] = 0;
         int mn = 0;
         for(int j = 1; j < i; j++){
                 int t = (j == 1 ? 2 : 1);
                 arr[j] = mat[j][t] - mat[0][t];        
                 mn = min(mn, arr[j]);
         }
         ptr = 0;
         bool can = false;
         while(!can){
                     ptr++;
                     can = true;
                     for(int j = 0; j < i; j++)
                             if(mark[ptr + arr[j] - mn])
                                         can = false;
         }
         for(int j = 0; j < i; j++){
                 mat[j][i] = mat[i][j] = ptr + arr[j] - mn;
                 mark[mat[i][j]] = true;
         } 
         mat[i][i] = 0;
    }
    for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                    if(j > 0)
                         cout << ' ';
                    cout << mat[i][j];        
            }
            cout << endl;
    }
     //cin >> ptr;
    return 0;
}