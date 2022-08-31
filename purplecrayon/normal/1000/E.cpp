#include "bits/stdc++.h"
using namespace std;

template<class T> using min_pq=priority_queue<T, vector<T>, greater<T>>;

#define sz(v) (int)v.size()
#define ar array
// #define f first
// #define s second
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef unsigned int ui;
const int MAXN = 3e5+10, MAXQ = 3e5+10, MAXL = 20, ALP = 26, MOD = 998244353, MAXK = 17, INF = 1e9+10, MAXA = 1e6+10, MAXB = 24, MAXBB = (1<<MAXB);
const string  no = "NO\n", yes = "YES\n";
const int hA[4] = {1, 0, -1, 0}, kA[4] = {0, 1, 0, -1};

struct DSU {
	vector<int> p, sz;
	void init(int n){ p.resize(n); sz.assign(n, 1); iota(p.begin(), p.end(), 0); }
	int find_set(int v){ return v==p[v]?v:p[v]=find_set(p[v]); }
	bool union_sets(int a, int b){
		if ((a=find_set(a))==(b=find_set(b))) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b]=a, sz[a]+=sz[b], sz[b]=0;
		return true;
	}
};

int n, m, tin[MAXN], low[MAXN], tt=0;
vector<ar<int, 2>> adj[MAXN];
bool vis[MAXN];
ar<int, 2> ed[MAXN];
bool bridge[MAXN];

vector<int> na[MAXN];

void dfs_bridge(int v=0, int p=-1) {
    vis[v] = 1;
    tin[v] = low[v] = tt++;
    for (auto nxt : adj[v]) {
        int to=nxt[0];
        if (to == p) continue;
        if (vis[to]) {
            low[v] = min(low[v], tin[to]);
        } else {
            dfs_bridge(to, v);
            low[v] = min(low[v], low[to]);
            if (low[to] > tin[v])
                bridge[nxt[1]] = 1;
        }
    }
}
ar<int, 2> dfs_diam(int c, int p, int d) {
    ar<int, 2> ans{d, c};
    for (auto nxt : na[c]) if (nxt != p)
        ans = max(ans, dfs_diam(nxt, c, d+1));
    return ans;
}
void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back({b, i}), adj[b].push_back({a, i});
        ed[i] = {a, b};
    }
    memset(vis, 0, sizeof(vis));
    dfs_bridge();

    DSU d; d.init(n);
    for (int i = 0; i < m; i++) if (!bridge[i]) {
        d.union_sets(ed[i][0], ed[i][1]);
    }
    for (int i = 0; i < m; i++) if (bridge[i]) {
        int a=d.find_set(ed[i][0]), b=d.find_set(ed[i][1]);
        na[a].push_back(b), na[b].push_back(a);
    }
    ar<int, 2> a=dfs_diam(d.find_set(0), -1, 0);
    cout << dfs_diam(a[1], -1, 0)[0] << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int t_c=1;
    //cin >> t_c;
    while (t_c--) solve();
}