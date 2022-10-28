#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

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
} col;

int qry(int c) {
    cout << "? " << c+1 << endl;
    int x; cin >> x;
    return x - 1;
}
void solve() {
    int n; cin >> n;
    vector<int> d(n); for (auto& x : d) cin >> x;
    vector<int> p(n); std::iota(p.begin(), p.end(), 0);

    vector<bool> vis(n);
    col.init(n);
    sort(p.begin(), p.end(), [&](int a, int b) { return d[a] > d[b]; });
    for (int c : p) if (!vis[c]) {
        if (d[c] <= 1) break;

        vis[c] = 1;
        int k = d[c];
        for (int i = 0; i < k; i++) {
            int nxt = qry(c);
            col.union_sets(c, nxt);
            
            if (vis[nxt]) break;
            vis[nxt] = 1;
        }
    }
    cout << "! ";
    for (int i = 0; i < n; i++) cout << col.find_set(i) + 1 << ' ';
    cout << endl;
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}