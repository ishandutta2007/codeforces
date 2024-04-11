#include <bits/stdc++.h>
//#pragma GCC target("sse,sse2,avx2")
#pragma GCC optimize("unroll-loops,O2")
#define rep(i,l,r) for (int i = l; i < r; i++)
#define repr(i,r,l) for (int i = r; i >= l; i--)
#define X first
#define Y second
#define all(x) (x).begin() , (x).end()
#define pb push_back
#define endl '\n'
#define debug(x) cerr << #x << " : " << x << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pll;
constexpr int N = 1e6+15,mod = 998244353,inf = 1e9+10;
inline int mkay(int a,int b){
    if (a+b >= mod) return a+b-mod;
   // if (a+b < 0) return a+b+mod;
    return a+b;
}
 
inline int poww(int a,int k){
    if (k < 0) return 0;
    int z = 1;
    while (k){
        if (k&1) z = 1ll*z*a%mod;
        a = 1ll*a*a%mod;
        k >>= 1;
    } 
    return z; 
}

vector<int> adj[N],ve;
int sz[N],le,mx[N],h[N],ans,dp[N][2];

void dfs(int v){
	mx[v] = h[v];
	if (adj[v].empty()){
		sz[v] = 1;
		return;
	}
	for (int u : adj[v]){
		h[u] = h[v]+1;
		dfs(u);
		mx[v] = max(mx[v],mx[u]);
		sz[v] += sz[u];
	}
	ans = max(ans,le-sz[v]+1+mx[v]-h[v]);
}

void dfs2(int v){
	dp[v][1] = mx[v]-h[v]+1;
	dp[v][0] = mx[v]-h[v];
	if (adj[v].empty()) return;
	int s = 0,mi = inf;
	for (int u : adj[v]){
		dfs2(u);
		s += max(dp[u][0],dp[u][1]);
		mi = min(mi,max(dp[u][0],dp[u][1])-dp[u][1]);
	}
	dp[v][0] = s;
}
void solve(){
	int n;
	cin >> n;
	rep(i,2,n+1){
		int p;
		cin >> p;
		adj[p].pb(i);
	}
	rep(i,2,n+1){
		if (adj[i].empty()) le++;
	}
	ans = le;
	dfs(1);
	dfs2(1);
	cout << max(dp[1][1],dp[1][0]) << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
	//cin >> T;
	while (T--){
		solve();
	}
    return 0;
}