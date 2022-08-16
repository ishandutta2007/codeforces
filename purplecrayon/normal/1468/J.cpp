#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 2e5+10, MOD = 1e9+7;
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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    vector<ar<int, 3>> ed(m);
    for (auto& [a, b, x] : ed)
        cin >> a >> b >> x, --a, --b;


    auto get = [&]() -> ll {
        vector<int> use; use.reserve(n);
        d.init(n);
        int cnt = 0;
        for (auto& [a, b, w] : ed) {
            if (d.union_sets(a, b)) {
                use.push_back(w);
                cnt++;
            }
        }
        if (cnt != n-1) return INF;
        sort(use.begin(), use.end());
        if (use.back() >= k) {
            ll ans = 0;
            for (int x : use) if (x >= k) ans += x - k;
            return ans;
        } else {
            return k - use.back();
        }
    };

    ll ans = INF;

    sort(ed.begin(), ed.end(), [&](auto one, auto two){
        if ((one[2] <= k) == (two[2] <= k)) return abs(one[2] - k) < abs(two[2] - k);
        else return (one[2] <= k);
    });

    ans = min(ans, get());

    vector<ar<int, 3>> one, two;
    for (auto& [a, b, w] : ed) {
        if (w >= k) one.push_back({w, a, b});
        else two.push_back({w, a, b});
    }
    ed.clear();
    sort(one.begin(), one.end());
    sort(two.rbegin(), two.rend());

    if (sz(one)) ed.push_back({one[0][1], one[0][2], one[0][0]});
    for (auto x : two) ed.push_back({x[1], x[2], x[0]});
    for (int i = 1; i < sz(one); i++) ed.push_back(ar<int, 3>{one[i][1], one[i][2], one[i][0]});
    ans = min(ans, get());

    cout << ans << '\n';
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    cin >> T;
    while (T--) solve();
}