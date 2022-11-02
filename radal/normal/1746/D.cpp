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

int lw[N],hi[N],s[N];
ll dp[N][2];
vector<int> adj[N];

bool cmp(int u,int v){
	return (dp[u][1]-dp[u][0] > dp[v][1]-dp[v][0]);
}

void dfs(int v){
	int sz = adj[v].size();
	if (!sz){
		dp[v][0] = 1ll*lw[v]*s[v];
		dp[v][1] = 1ll*hi[v]*s[v];
		return;
	}
	int l = lw[v]/sz,h = (hi[v]+sz-1)/sz;
	vector<int> ve;
	ll su = 0;
	for (int u : adj[v]){
		lw[u] = l;
		hi[u] = h;
		dfs(u);
		ve.pb(u);
		su += dp[u][0];
	}
	sort(all(ve),cmp);
	dp[v][0] = 1ll*lw[v]*s[v]+su;
	rep(i,0,sz){
        if (i == lw[v]%sz) break;
		dp[v][0] += dp[ve[i]][1]-dp[ve[i]][0];
	}
	dp[v][1] = 1ll*hi[v]*s[v]+su;
    rep(i,0,sz){
        if (i == hi[v]%sz) break;
        dp[v][1] += dp[ve[i]][1]-dp[ve[i]][0];
    }	
	if (hi[v]%sz == 0){
		rep(i,0,sz) dp[v][1] += dp[ve[i]][1]-dp[ve[i]][0];
	}
}
void solve(){
	int n,k;
	cin >> n >> k;
	lw[1] = hi[1] = k;
	rep(i,1,n+1) adj[i].clear();
	rep(i,2,n+1){
		int p;
		cin >> p;
		adj[p].pb(i);
	}
	rep(i,1,n+1) cin >> s[i];
	dfs(1);
	cout << dp[1][0] << endl;
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