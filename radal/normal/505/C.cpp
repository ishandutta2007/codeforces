#include <bits/stdc++.h>
#define ll long long int
#define rep(i,l,r) for(ll i=l; i<r; i++)
#define X first
#define Y second
using namespace std;
const ll N=3e4+20;
ll dp[N][620];
ll a[N];
int main(){
    ios ::sync_with_stdio(false); 
    cin.tie(0);
    ll n,d,ans=0,t=0;
    cin >> n >> d;
    rep(i,0,n){
        ll x;
        cin >> x;
        t = max(t,x);
        a[x]++;
    }
    if (d == 1){
        cout << n;
        return 0;
    }
    rep (i,0,N-10){
        rep (j,0,620){
            dp[i][j] = -1;
        }
    } 
    dp[d][0] = a[d];
    ans =max(ans,dp[d][0]);
    rep (i,2*d-1,t+1){
        rep (j,-300,310){
            ll l=d-j;
           // cout <<i <<  ans << endl;
            if (l <= 0) continue;
           /* if (i-l < d){
                dp[i][l] = -1;
                continue;
            }*/
            if (i-l == d && (l == d+1 || l == d-1 || l == d)){
                dp[i][j+200] = dp[i-l][0] + a[i];
                ans = max(ans,dp[i][j+200]);
                continue;
            }
            if (i-l >= 0){
                if (j!=-200) dp[i][j+200] = max(max(dp[i-l][j+199],dp[i-l][j+201]),dp[i-l][j+200]);
                if (dp[i][j+200] != -1){
                    dp[i][j+200] += a[i];
      //              if (l == 6 && i == 21) cout <<dp[i][l] << endl;
                }
               // if (ans < dp[i][l]) cout << i << "  " << l << "   " << dp[i][l]  << endl;
                ans = max(ans,dp[i][j+200]);
            }
            else{
                dp[i][j+200] = -1;
            }
        }
    }
//    cout << dp[29899][1] << " " << dp[8494][2869] << endl;
    cout << ans;
}