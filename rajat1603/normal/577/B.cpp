#include "bits/stdc++.h"
using namespace std;
const int M = 1e3 + 3;
int n;
int m;
int arr[M];
bool dp[M][M];
int main(){
    cin >> n >> m;
    if(n >= m){
        puts("YES");
    }
    else{
        for(int i = 1 ; i <= n ; ++i){
            cin >> arr[i];
            arr[i] %= m;
        }
        for(int i = 1 ; i <= n ; ++i){
            dp[i][arr[i]] = 1;
            for(int j = 0 ; j < m ; ++j){
                dp[i][j] |= dp[i - 1][j];
                dp[i][j] |= (dp[i - 1][(j - arr[i] + m) % m]);
            }
        }
        puts(dp[n][0] ? "YES" : "NO");
    }
}