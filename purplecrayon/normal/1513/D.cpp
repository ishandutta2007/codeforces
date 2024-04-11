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


void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n); for (auto& x : a) cin >> x;
    d.init(n);
    vector<int> p(n); iota(p.begin(), p.end(), 0);
    sort(p.begin(), p.end(), [&](int x, int y) { return a[x] < a[y]; });

    vector<ar<int, 3>> ed;
    for (int c : p) {
        for (int r = c + 1; r < n; r++) {
            if (a[r] < a[c] || a[r] % a[c] || !d.union_sets(c, r)) {
                break;
            }
            ed.push_back({a[c], c, r});
        }
        for (int l = c - 1; l >= 0; l--) {
            if (a[l] < a[c] || a[l] % a[c] || !d.union_sets(l, c)) {
                break;
            }
            ed.push_back({a[c], c, l});
        }
    }
    for (int i = 1; i < n; i++) ed.push_back({x, i-1, i});
    sort(ed.begin(), ed.end());
    d.init(n);
    ll ans = 0;
    for (auto [w, a, b] : ed) {
        if (d.union_sets(a, b))
            ans += w;
    }
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}