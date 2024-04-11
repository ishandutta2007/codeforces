#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e6+10, MOD = 998244353;

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

int n, a[N];

ll get(vector<ar<int, 3>> ed) {
    ll ans = 0;
    d.init(n);
    for (auto [w, a, b] : ed) {
        ans += (long long) w * d.sz[d.find_set(a)] * d.sz[d.find_set(b)];
        d.union_sets(a, b);
    }
    return ans;
}
void solve() {
    cin >> n;
    vector<int> a(n); for (auto& x : a) cin >> x;
    vector<ar<int, 3>> one, two;
    for (int i = 0; i < n-1; i++) {
        int x, y; cin >> x >> y, --x, --y;
        one.push_back({min(a[x], a[y]), x, y});
        two.push_back({max(a[x], a[y]), x, y});
    }
    sort(one.begin(), one.end()); reverse(one.begin(), one.end());
    sort(two.begin(), two.end()); 
    cout << get(two) - get(one) << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    // cin >> T;
    while (T--) solve();
}