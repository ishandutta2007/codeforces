#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[2][409][409][2];
main(){
    int n, mod;
    cin >> n >> mod;
    ll ans = 0;
    dp[0][2][1][0] = 1;
    dp[0][2][2][0] = 1;
    dp[0][2][2][1] = 1;

    dp[0][1][2][0] = 1;
    for(int i = 3; i <= n; i++){
        int i0 = i %2, i1 = (i+1)%2;
        for(int j = 1; j <= i; j++){
            for(int k = 1; k <= j; k++){
                dp[i0][j][k][1] = (dp[i0][j][k-1][1] +
                                  dp[i1][j-1][k-1][0] +
                                  dp[i1][j-1][k-1][1]) % mod;
                dp[i0][j][k][0] = (dp[i0][j][k-1][0] +
                                  dp[i1][j-1][j-1][0] -
                                  dp[i1][j-1][k-1][0] +
                                  dp[i1][j-1][j][0]+
                                  mod) % mod;

            }
            //
            dp[i0][j][j+1][0] = (dp[i1][j][j][0] + dp[i1][j][j][1])%mod;
        }
    }

    for(int  j =1 ; j <= n; j++)
        ans = (ans + dp[n%2][j][j][0] +
                dp[n%2][j][j][1]) % mod;
    cout<<ans<<endl;
}
/*
n-1 n
*/