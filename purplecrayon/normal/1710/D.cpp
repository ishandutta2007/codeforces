#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 998244353;

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
    int n; cin >> n;
    vector<vector<bool>> g(n, vector<bool>(n));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = i; j < n; j++) {
            g[i][j] = s[j - i] - '0';
        }
    }
    vector<pair<int, int>> ans;
    d.init(n);
    for (int r = 0; r < n; r++) {
        for (int l = r-1; l >= 0; l--) if (g[l][r] && d.find_set(l) != d.find_set(r)) {
            // can enter at most n times

            if (l == r-1) {
                d.union_sets(l, r);
                ans.emplace_back(l, r);
                continue;
            }

            vector<int> comps;
            for (int i = l; i <= r; i++) {
                if (!sz(comps) || comps.back() != d.find_set(i))
                    comps.push_back(d.find_set(i));
            }
            comps[0] = l, comps.back() = r;

            vector<int> ord;
            for (int rep = 0; rep < 2; rep++) {
                for (int i = sz(comps)-1; i >= 0; i--) if (i % 2 == rep ^ (sz(comps) % 2))
                    ord.push_back(comps[i]);
            }
            if (sz(ord) % 2) {
                swap(ord[sz(ord)-2], ord[sz(ord)-1]);
            }
            for (int i = 1; i < sz(ord); i++) {
                ans.emplace_back(ord[i-1], ord[i]);
                d.union_sets(ord[i-1], ord[i]);
            }
        }
    }
    assert(sz(ans) == n-1);
    for (auto [a, b] : ans) cout << a+1 << ' ' << b+1 << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}