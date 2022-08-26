#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

// using namespace __gnu_pbds;
/*
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;
typedef __int128 i128;

const int INFi = 1e9 + 5;
const int maxN = 1e5 + 5;
const int md = 998244353;
const ll INF = 2e18;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct fenwick {
    int n{};
    vector<ll> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    void upd(int i, ll x) {
        for (; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for (; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    ll get(int l, int r) {
        if (l > r) return 0;
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> pts(n);
    range(i, n) cin >> pts[i].second >> pts[i].first;
    sort(rall(pts));
    vector<int> xx;
    range(i, n) xx.push_back(pts[i].second);
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    fenwick f;
    f.build(n + 5);
    ll ans = 0;
    set<int> was;
    range(i, n) pts[i].second = lower_bound(all(xx), pts[i].second) - xx.begin();
    for(int i = 0, j = 0; i < n; i = j) {
        while(j < n && pts[j].first == pts[i].first) j++;
        {
            int t = f.get(pts[i].second + 1, n);
            ans -= 1ll * t * (t + 1) / 2;
        }
        {
            int t = f.get(pts[j - 1].second - 1);
            ans -= 1ll * t * (t + 1) / 2;
        }
        for(int e = j - 1; e > i; --e) {
            if (pts[e].second + 1 == pts[e - 1].second) continue;
            int t = f.get(pts[e].second + 1, pts[e - 1].second - 1);
            ans -= 1ll * t * (t + 1) / 2;
        }
        for(int e = i; e < j; ++e) {
            if (was.count(pts[e].second)) continue;
            was.insert(pts[e].second);
            f.upd(pts[e].second, 1);
        }
        int t = was.size();
        ans += 1ll * t * (t + 1) / 2;
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}