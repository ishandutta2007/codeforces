#include "bits/stdc++.h"
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int MAXN = 2e5+10, MOD = 1e9+7;
const ll INF = 1e18+10;

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
} d;

int n, col[MAXN];
vector<int> adj[MAXN];

vector<int> nw[MAXN];

pair<int, int> dfs(int c, int p, int d) {
    pair<int, int> ans{d, c};
    for (auto nxt : nw[c]) if (nxt != p) {
        ans = max(ans, dfs(nxt, c, d+1));
    }
    return ans;
}
void solve(){
    cin >> n;
    for (int i = 0; i < n; i++) cin >> col[i];
    d.init(n);
    for (int i = 0; i < n-1; i++) {
        int a, b; cin >> a >> b, --a, --b;
        adj[a].push_back(b), adj[b].push_back(a);

        if (col[a] == col[b]) d.union_sets(a, b);
    }
    map<int, int> root;
    for (int i = 0; i < n; i++) if (d.p[i] == i) { int c = sz(root); root[i] = c; }
    for (int a = 0; a < n; a++) for (int b : adj[a]) {
        if (col[a] != col[b]) {
            int pa = root[d.find_set(a)];
            int pb = root[d.find_set(b)];

            nw[pa].push_back(pb);
        }
    }

    pair<int, int> far = dfs(0, -1, 0);
    cout << (dfs(far.second, -1, 0).first+1)/2 << '\n';
}
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    //cin >> T;
    while (T--) solve();
}