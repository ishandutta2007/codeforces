#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;
//using namespace __gnu_pbds;


typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

/*
typedef tree<
        pair<ll, int>,
        null_type,
        less<pair<ll, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

const int INFi = 1e9 + 5;
const int md = 1e9 + 7;
const ll INF = 2e18;
const int maxN = 1e5 + 5;

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
    int n, m; cin >> n >> m;
    vector<int> a(n * m);
    range(i, n * m) cin >> a[i];
    /*vector<int> ord(n * m);
    iota(all(ord), 0);
    sort(all(ord), [&] (const int &i, const int &j) {
        return make_pair(a[i], i) < make_pair(a[j], j);
    });
*/
    vector<int> xx;
    vector<int> start;
    xx = a;
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    int sz = xx.size();
    start.resize(sz + 1);
    range(i, n * m) {
        a[i] = lower_bound(all(xx), a[i]) - xx.begin();
        start[a[i] + 1]++;
    }
    for(int i = 1; i <= sz; ++i) start[i] += start[i - 1];
    vector<vector<int>> b(n, vector<int> (m));
    vector<int> was(sz);
    range(i, n * m) {
        int l = start[a[i]];
        int r = start[a[i] + 1] - 1;
        int lq = l / m;
        int rq = r / m;
        if (lq != rq) {
            int need = (lq + 1) * m - l;
            if (need > was[a[i]]) {
                b[lq][m - 1 - was[a[i]]] = i;
                was[a[i]]++;
                continue;
            } else {
                int to = l + was[a[i]];
                if ((to / m) == rq) {
                    int have = to % m;
                    b[rq][r % m - have] = i;
                    was[a[i]]++;
                    continue;
                }
                int have = to % m;
                b[to / m][m - 1 - have] = i;
                was[a[i]]++;
            }
        } else {
            b[lq][r % m - was[a[i]]] = i;
            was[a[i]]++;
        }
    }
    fenwick f;
    f.build(n * m + 1);
    ll ans = 0;
    range(i, n) {
        range(j, m) {
            ans += f.get(b[i][j]);
            f.upd(b[i][j], 1);
        }
        range(j, m) f.upd(b[i][j], -1);
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}