#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e3+10, MOD = 1e9+7;

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


void solve() {
    // make bipartite row-column graph, an operation merges two rows/cols
    
    int n, m, q; cin >> n >> m >> q;
    d.init(n + m);
    while (q--) {
        int r, c; cin >> r >> c, --r, --c;
        d.union_sets(r, c + n);
    }
    int ans = 0;
    for (int i = 0; i < n + m; i++) ans += d.p[i] == i;
    cout << ans - 1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}