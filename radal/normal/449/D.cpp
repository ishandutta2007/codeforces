#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define mp make_pair
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=20,mod = 1e9+7,inf=2e18,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int dp[maxm][N],a[maxm];
int main(){
    int n;
    cin >> n;
    rep(i,0,n){
        cin >> a[i];
        dp[a[i]][0]++;
        if (a[i]&1)dp[a[i]-1][0]++;
    }
    int y = (1 << 20);
    rep(i,1,N){
        rep(j,0,y){
            dp[j][i] += dp[j][i-1];
            if(!((1<<i)&j)) dp[j][i] += dp[j+(1<<i)][i-1];
        }
    }
    ll ans = 0;
    rep(i,0,y){
        int pc = __builtin_popcount(i);
        if (pc&1)
            ans = (ans+mod+1-poww(2,dp[i][N-1]))%mod;
        
        else
            ans = (ans+poww(2,dp[i][N-1])-1)%mod;
    }
    cout << ans;
}