#include "bits/stdc++.h"
using namespace std;
const int N = 35;
const int K = 55;
int dp[N][N][K];
int t;
int n , m , k;
int main(){
    for(int i = 1 ; i < N ; ++i){
        for(int j = 1 ; j < N ; ++j){
            for(int k = 0 ; k < K ; ++k){
                if(k > i * j){
                    dp[i][j][k] = 1e9;
                }
                else if(!k || k == i * j){
                    dp[i][j][k] = 0;
                }
                else{
                    dp[i][j][k] = 1e9;
                    for(int l = 0 ; l <= k ; ++l){
                        for(int m = 1 ; m < i ; ++m){
                            dp[i][j][k] = min(dp[i][j][k] , dp[m][j][l] + dp[i - m][j][k - l] + j * j);
                        }
                        for(int m = 1 ; m < j ; ++m){
                            dp[i][j][k] = min(dp[i][j][k] , dp[i][m][l] + dp[i][j - m][k - l] + i * i);
                        }
                    }
                }
            }
        }
    }
    cin >> t;
    while(t--){
        cin >> n >> m >> k;
        cout << dp[n][m][k] << endl;
    }
}