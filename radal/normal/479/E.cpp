#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O3")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define ll long long int
#define endl '\n'
#define mp make_pair
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
const long long int N=5e3+30,mod = 1e9+7,inf=1e18;
ll dp[N][N],sum[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n,a,b,k;
    cin >> n >> a >> b >> k;
    dp[0][a] = 1;
    rep (i,1,k+1){
        sum[0] = 0;
        rep(j,1,n+1){
            sum[j] = (sum[j-1] + dp[i-1][j])%mod;
        }
        rep (j,1,n+1){
            if (j == b){
                dp[i][j] = 0;
                continue;
            }
            if(j < b){
                dp[i][j] = sum[(j+b)/2-1+(j+b)%2]+mod-dp[i-1][j];
                dp[i][j] %= mod;
               // if (i == 2 && j == 3) debug(i);debug(j);
                continue;
            }
            
            if (sum[n] > dp[i-1][j]+sum[(b+j)/2]) dp[i][j] = sum[n]-dp[i-1][j]-sum[(b+j)/2];
            else dp[i][j] = sum[n]+5*mod-dp[i-1][j]-sum[(b+j)/2];
            dp[i][j]%= mod;
        }
    }
 //   debug(dp[2][3]);debug(dp[2][2]);
    ll ans=0;
    rep (i,1,n+1){
        ans+=dp[k][i];
        ans = ans%mod;
       // debug(i); debug(dp[1][i]);
    }
    cout << ans%mod;
    return 0;
}