#include <bits/stdc++.h>
#pragma GCC target ("avx,avx2,fma")
#pragma GCC optimization ("O8")
#pragma GCC optimization ("unroll-loops")
#define X first
#define Y second
#define debug(x) cerr << #x << ": " << x << endl;
#define endl '\n'
#define pb push_back
#define rep(i,l,r) for (int i=l; i<r; i++)
#define repr(i,r,l) for (int i=r; i>=l; i--)
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pll;
const long long int N=(1<<24)+20,mod = 1e9+7,inf=2e9,dlt = 12250,maxm = 2e6;
int poww(ll a,int k){
    if (!k) return 1;
    if (k == 1) return a;
    ll r = poww(a,k/2);
    return (((r*r)%mod)*poww(a,k&1))%mod;
}
int dp[2][N];
int main(){
    int n;
    cin >> n;
    rep(i,0,n){
        string s;
        cin >> s;
        int sm = 0;
        rep(j,0,3){
            int x = s[j]-'a';
            sm |= (1<<x);
        }
        debug(sm);
        dp[0][sm]++;
        if (!(sm&1)) dp[0][sm+1]++;
    }
    int y = (1<<24);
    rep(i,1,24){
        rep(j,0,y){
            dp[i&1][j] = dp[1-(i&1)][j];
            if (j&(1<<i)) dp[i&1][j] += dp[1-(i&1)][j-(1<<i)];
        }
    }
    ll ans = 0;
    rep(i,0,y){
        ll u = 1ll*(n-dp[1][i])*(n-dp[1][i]);
        ans ^= u;
    }
    cout << ans;
    return 0;
}