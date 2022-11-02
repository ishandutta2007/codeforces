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
constexpr int N = 3e5+15,mod = 998244353,inf = 1e9+10;
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

vector<pll> adj[N];
pll e[N];
pll par[N];
bool vis[N],mark[N];
int h[N];
set<int> st;

void dfs(int v){
	mark[v] = 1;
	for (auto u : adj[v]){
		if (!mark[u.X]){
			par[u.X] = {v,u.Y};
			vis[u.Y] = 1;
			h[u.X] = h[v]+1;
			dfs(u.X);
		}
	}
}

void solve(){
	int n,m;
	cin >> n >> m;
	rep(i,1,n+1){
	   	adj[i].clear();
		mark[i] = 0;
	}
	rep(i,0,m){
		int u,v;
		cin >> u >> v;
		adj[u].pb({v,i});
		adj[v].pb({u,i});
		vis[i] = 0;
		e[i] = {u,v};
	}
	dfs(1);
	if (m < n+2){
		rep(i,0,m) cout << vis[i];
		cout << endl;
		return;
	}
	st.clear();
	rep(i,0,m){
		if (vis[i]) continue;
		st.insert(e[i].X);
		st.insert(e[i].Y);
	}
	if (st.size() > 3){
        rep(i,0,m) cout << vis[i];
        cout << endl;
        return;
	}
	int v[3];
	rep(i,0,3){
		int u = *(st.begin());
		st.erase(st.begin());
		v[i] = u;
	}
	if (h[v[0]] > h[v[1]]) swap(v[0],v[1]);
	if (h[v[1]] > h[v[2]]) swap(v[1],v[2]);
	if (h[v[0]] > h[v[1]]) swap(v[0],v[1]);
	rep(i,0,m){
		if (vis[i]) continue;
		if (h[e[i].X] > h[e[i].Y]) swap(e[i].X,e[i].Y);
		if (e[i].X == v[1] && e[i].Y == v[2]){
			vis[i] = 1;
		}
	}
	int u = v[2];
	while (par[u].X != v[1]) u = par[u].X;
	vis[par[u].Y] = 0;
	rep(i,0,m) cout << vis[i];
	cout << endl;
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
	int T = 1;
	cin >> T;
	while (T--){
		solve();
	}
    return 0;
}