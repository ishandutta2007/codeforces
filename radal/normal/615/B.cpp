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
typedef long long  int ll;
typedef pair<ll,ll> pll;
const long long int N=1e5+20,mod = 1e9+7,inf=2e9,maxq = 1e5+30;
const long double eps = 0.0000001;
ll poww(ll a, ll b) {
	return (!b ? 1 : (b & 1 ? a * poww(a * a % mod, b / 2) % mod : poww(a * a % mod, b / 2) % mod));
}
vector<int> adj[N];
ll dp[N];
int main(){
    ios :: sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin >> n >> m; 
    rep(i,0,m){
        int x,y;
        cin >> x >> y;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    rep(i,1,n+1)  dp[i] = 1;
    rep(i,2,n+1){
        for (int u : adj[i]) if (u < i) dp[i] = max(dp[i],dp[u]+1);
    }
    ll ans = 0;
    rep(i,1,n+1){
        ll w = 1ll*adj[i].size()*dp[i];
        ans = max(ans,w);
    }
    cout << ans;
    return 0;
}