#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 3e5+10, MOD = 1e9+7;

struct DSU {
	vector<int> p, sz;
	void init(int n) { 
        p.resize(n); iota(p.begin(), p.end(), 0);
        sz.assign(n, 1);
    }
	int find_set(int v) { 
        return v == p[v] ? v : p[v] = find_set(p[v]);
    }
	bool union_sets(int a, int b) {
        a = find_set(a), b = find_set(b);
        if (a == b) return false;
		if (sz[a] < sz[b]) swap(a, b);
		p[b] = a, sz[a] += sz[b], sz[b] = 0;
		return true;
	}
} d;


int n, m;
int need[N];
vector<ar<int, 2>> adj[N];
vector<int> ans;

bool dfs(int c, int p) { // true = keeping parent edge
    bool tot_deg = 0;
    for (auto [nxt, i] : adj[c]) if (nxt != p) {
        bool use = dfs(nxt, c);
        if (use) ans.push_back(i);

        tot_deg ^= use;
    }
    return tot_deg ^ need[c];
}
void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> need[i];
    d.init(n);
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b, --a, --b;
        if (d.union_sets(a, b)) {
            adj[a].push_back({b, i}), adj[b].push_back({a, i});
        }
    }

    int sum = 0;
    for (int i = 0; i < n; i++) if (need[i] != -1)
        sum ^= need[i];

    for (int i = 0; i < n; i++) if (need[i] == -1) {
        need[i] = sum;
        sum ^= need[i];
    }
    if (sum) {
        cout << -1 << '\n';
        return;
    }
    assert(!dfs(0, -1));

    cout << sz(ans) << '\n';
    for (int x : ans) cout << x+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}