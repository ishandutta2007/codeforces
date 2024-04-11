#pragma GCC optimize ("Ofast")
#include <bits/stdc++.h>
//#define int long long
#define endl '\n'
typedef long long ll;
using namespace std;
int mod=1000000007;
int dp[1000001][21][2];
int n;
int f(int x,int y){
    int cur=(1<<x);
    if (y) cur*=3;
    return n/cur;
}
int32_t main() {
    cin>>n;
    int lg=0;
    while ((1<<(lg))<=n) lg++;
    lg--;
    dp[1][lg][0]=1;
    if ((1<<(lg-1))*3<=n) dp[1][lg-1][1]=1;
    for (int i=1;i<=n;i++){
        for (int x=0;x<=20;x++){
            for (int y=0;y<2;y++){
                dp[i+1][x][y]=(dp[i+1][x][y]*1ll+(1ll*dp[i][x][y]*1ll*(f(x,y)-i*1ll)*1ll)%mod)%mod;
                if (x) {
                    dp[i+1][x-1][y]=(dp[i+1][x-1][y]*1ll+(1ll*dp[i][x][y]*1ll*(f(x-1,y)-f(x,y))*1ll)%mod)%mod;
                }
                if (y) {
                    dp[i+1][x][y-1]=(dp[i+1][x][y-1]*1ll+(1ll*dp[i][x][y]*1ll*(f(x,y-1)-f(x,y))*1ll)%mod)%mod;
                }
            }
        }
    }
    cout<<dp[n][0][0];
    return 0;
}