#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cmath>
#include <map>
#include <unordered_set>
#include <tuple>
#include <queue>
#include <set>
#include <cstring>
#include <functional>
#include <random>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>

#define ar array
#define all(arr) (arr).begin(), (arr).end()
#define range(i, n) for (int i=0; i < n; ++i)
#define rall(arr) (arr).rbegin(), (arr).rend()

typedef long long ll;
typedef long double ld;

using namespace std;
using namespace __gnu_pbds;

using ordered_set = tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>;

const ll INF = 1e18;
const int INFi = 2e9;
const int maxN = 305;
const int md2 = 998244353;
const int md = 1e9 + 7;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; };

struct fenwick {
    vector<ll> fenw{};
    int n{};

    void build(int k) {
        n = k;
        fenw.resize(n);
    }

    ll get(int i) {
        ll res = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    void upd(int i, ll x) {
        for(; i < n; i = i | (i + 1)) fenw[i] += x;
    }

    ll get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

void solve() {
    int n; cin >> n;
    vector<pair<int, int>> req(n);
    range(i, n) cin >> req[i].first >> req[i].second;
    vector<int> a(n);
    range(i, n) a[i] = abs(req[i].second);
    sort(all(a));
    a.resize(unique(all(a)) - a.begin());
    map<int, int> mp;
    range(i, (int)a.size()) mp[a[i]] = i;
    fenwick f;
    f.build((int)a.size() + 50);
    ordered_set s;
    set<int> s2;
    int cnt = 0;
    range(i, n) {
        int tp = req[i].first;
        int d = req[i].second;
        if (tp) {
            if (d < 0) {
                cnt--;
                f.upd(mp[-d], d);
                s.erase(-d);
            } else {
                cnt++;
                f.upd(mp[d], d);
                s.insert(d);
            }
        } else {
            if (d < 0) {
                f.upd(mp[-d], d);
                s2.erase(-d);
                s.erase(-d);
            } else {
                f.upd(mp[d], d);
                s2.insert(d);
                s.insert(d);
            }
        }
        ll ans = f.get((int)a.size());
        if (cnt) {
            int e = -1;
            if (!s2.empty()) {
                e = *s2.rbegin();
                f.upd(mp[e], -e);
                s.erase(e);
                ans += e;
            }
            if (cnt != 1) {
                int k = *s.find_by_order(max(0, (int)s.size() - (cnt - 1)));
                ans += f.get(mp[k], (int)a.size());
            }
            if (e != -1) {
                f.upd(mp[e], e);
                s.insert(e);
            }
        }
        cout << ans << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    //cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}