#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 501;
int n , m , b , mod;
int arr[N];
int dp[2][N][N];
int main(){
    cin >> n >> m >> b >> mod;
    for(int i = 1 ; i <= n ; ++i){
        cin >> arr[i];
    }
    dp[0][0][0] = 1;
    int ans = 0;
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 0 ; j <= m ; ++j){
            for(int k = 0 ; k <= b ; ++k){
                dp[i&1][j][k] = dp[1^(i&1)][j][k] + ( (j > 0 && arr[i] <= k)? dp[i&1][j-1][k - arr[i]] : 0 );
                if(dp[i&1][j][k] >= mod){
                    dp[i&1][j][k] -= mod;
                }
                if(i == n && j == m){
                    ans += dp[i&1][j][k];
                    if(ans >= mod){
                        ans -= mod;
                    }
                }
            }
        }
    }
    printf("%d\n",ans);
}