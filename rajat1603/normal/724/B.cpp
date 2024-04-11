#include "bits/stdc++.h"
using namespace std;
const int N = 25;
int n , m;
int arr[N][N];
bool solve(int row){
    for(int i = 1 ; i <= m ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            swap(arr[row][i] , arr[row][j]);
            bool b = 1;
            for(int k = 1 ; k <= m ; ++k){
                if(arr[row][k] != k){
                    b = 0;
                    break;
                }
            }
            swap(arr[row][i] , arr[row][j]);
            if(b){
                return 1;
            }
        }
    }
    return 0;
}
void solve(){
    for(int i = 1 ; i <= n ; ++i){
        if(!solve(i)){
            return;
        }
    }
    cout << "YES\n";
    exit(0);
}
int main(){
    scanf("%d %d" , &n , &m);
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            scanf("%d" , &arr[i][j]);
        }
    }
    for(int i = 1 ; i <= m ; ++i){
        for(int j = 1 ; j <= m ; ++j){
            for(int k = 1 ; k <= n ; ++k){
                swap(arr[k][i] , arr[k][j]);
            }
            solve();
            for(int k = 1 ; k <= n ; ++k){
                swap(arr[k][i] , arr[k][j]);
            }
        }
    }
    cout << "NO\n";
}