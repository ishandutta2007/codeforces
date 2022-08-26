#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array
using namespace std;

/*
using namespace __gnu_pbds;

typedef tree<
        pair<int, int>,
        null_type,
        less<pair<int, int>>,
        rb_tree_tag,
        tree_order_statistics_node_update>
        ordered_set;
*/

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const int INFi = 1e9 + 5;
const int md = 998244353;
const ll INF = 2e18;
const int maxN = 5e5 + 1;

double getTime() { return clock() / (double) CLOCKS_PER_SEC; }

struct sparse_table {
    vector<vector<ll>> sp;
    function<ll(ll, ll)> f;

    void init(const vector<ll> &a, const function<ll(ll, ll)> &g) {
        f = g;
        int n = a.size();
        int lgN = __lg(n) + 1;
        sp.resize(lgN, vector<ll>(n));
        range(i, n) {
            sp[0][i] = a[i];
        }
        range(j, lgN - 1) {
            for (int i = 0; i + (1 << (j + 1)) <= n; ++i) {
                sp[j + 1][i] = f(sp[j][i], sp[j][i + (1 << j)]);
            }
        }
    }

    // [l, r)
    ll get(int l, int r) {
        int k = __lg(r - l);
        return f(sp[k][l], sp[k][r - int(1 << k)]);
    }
};

void solve() {
    int n; cin >> n;
    ll cnt = 0;
    ll ans = 0;
    range(i, n) {
        ll x; cin >> x;
        ll c = min(cnt, x / 2);
        x -= c * 2;
        ans += c;
        cnt -= c;
        ans += x / 3;
        x %= 3;
        cnt += x;
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