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
constexpr int N = 2e5+15,mod = 998244353,inf = 1e9+10;
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

int a[N],par[N][20],h[N],tin[N],tout[N],T;
vector<int> pr,taj[N],vec[N];
vector<int> adj[N];
vector<int> out[N];
bool mk[N];
int cnt,sz[N];
int ans;

int calc(int x,int y){
	int ret = 1ll*x*(x-1)/2%mod*y%mod;
	ret = mkay(ret,1ll*y*(y-1)/2%mod*x%mod);
	return ret;
}

void dfs2(int v,int p){
	sz[v] = (a[v] % p == 0);
	for (int u : out[v]){
	   	dfs2(u,p);
		sz[v] += sz[u];
		ans = mkay(ans,1ll*(h[u]-h[v])*calc(sz[u],cnt-sz[u])%mod);
	}
}

void dfs(int v,int p){
	par[v][0] = p;
	tin[v] = T++;
	for (int u : adj[v]){
		if (u != p){
			h[u] = h[v]+1;
			dfs(u,v);
		}
	}
	tout[v] = T++;
}

bool cmp(int u,int v){
	return (tin[u] < tin[v]);
}

inline int lca(int u,int v){
	if (h[u] > h[v]) swap(u,v);
	while (h[v]-h[u]){
		int i = __builtin_ctz(h[v]-h[u]);
		v = par[v][i];
	}
	if (u == v) return u;
	repr(i,19,0){
		if (par[v][i] != par[u][i]){
			v = par[v][i];
			u = par[u][i];
		}
	}
	return par[v][0];
}

int main(){
    ios_base :: sync_with_stdio(0); cin.tie(0);
	int n;
	cin >> n;
	rep(i,2,N){
		if (mk[i]) continue;
		pr.pb(i);
		for (int j = 1; j*i < N; j++){
			taj[j*i].pb(i);
			if (j > 1) mk[j*i] = 1;
		}
	}

	rep(i,1,n+1){
		cin >> a[i];
		for (int p : taj[a[i]]){
			vec[p].pb(i);
		}
	}

	rep(i,1,n){
		int u,v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}

	dfs(1,0);

	rep(j,1,20){
		rep(i,2,n+1){
			par[i][j] = par[par[i][j-1]][j-1];
		}
	}

	vector<int> tmp;
	for (int p : pr){
		int sz = vec[p].size();
		if (sz < 3) continue;
		sort(all(vec[p]),cmp);
		tmp.clear();
		for (int u : vec[p]) tmp.pb(u);
		rep(i,1,sz){
			tmp.pb(lca(vec[p][i-1],vec[p][i]));
		}
		tmp.pb(lca(vec[p][0],vec[p][sz-1]));
		sort(all(tmp),cmp);
		tmp.resize(unique(all(tmp))-tmp.begin());
		for (int u : tmp) out[u].clear();
		sz = tmp.size();
		stack<int> st;
		st.push(tmp[0]);
		rep(i,1,sz){
			while (tout[st.top()] < tout[tmp[i]]) st.pop();
			out[st.top()].pb(tmp[i]);
			st.push(tmp[i]);
		}
		cnt = vec[p].size();
		dfs2(tmp[0],p);
	}
	cout << ans;
    return 0;
}