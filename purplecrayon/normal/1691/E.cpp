#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;

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

void solve() {
    int n; cin >> n;
    vector<ar<int, 3>> a(n);
    for (auto& [c, l, r] : a) cin >> c >> l >> r;
    map<int, int> mp;
    for (auto& [_, l, r] : a) {
        mp[l]++, mp[r]++;
    }
    int cc = 0;
    for (auto& [_, k] : mp) k = cc++;
    for (auto& [_, l, r] : a) {
        l = mp[l], r = mp[r];
    }
    vector<vector<pair<int, int>>> ev(cc);
    for (int i = 0; i < sz(a); i++) {
        ev[a[i][1]].emplace_back(i, +1);
        if (a[i][2] < cc-1) ev[a[i][2] + 1].emplace_back(i, -1);
    }

    set<pair<int, int>> s[2];
    d.init(n);
    for (int i = 0; i < cc; i++) {
        for (auto [x, op] : ev[i]) {
            int c = a[x][0];
            if (op == -1) {
                s[c].erase({a[x][2], x});
            }
        }
        for (auto [x, op] : ev[i]) {
            int c = a[x][0];
            if (op == +1) {
                if (sz(s[c ^ 1])) {
                    for (auto [_, y] : s[c ^ 1]) {
                        d.union_sets(x, y);
                    }
                    while (sz(s[c ^ 1]) > 1) s[c ^ 1].erase(s[c ^ 1].begin());
                }
                s[c].insert({a[x][2], x});
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans += d.p[i] == i;
    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T = 1;
    cin >> T;
    while (T--) solve();
}