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

const int INFi = 2e9 + 5;
const int maxN = 2e5 + 5;
const int md = 31607;
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
    const int N = 3e5 + 1;
    fenwick f;
    f.build(N);
    fenwick f2;
    f2.build(N);
    fenwick f3;
    f3.build(N);
    ll ans = 0;
    range(i, n) {
        int x; cin >> x;
        {
            ans += 1ll * i * x + f.get(x);
            for(int j = 1; j * x < N; ++j) {
                f.upd(j * x, -x);
            }
        }
        {
            ll p = 0;
            ll p2 = 0;
            for(int j = 0; j * x < N; ++j) {
                int l = j * x;
                int r = min((j + 1) * x, N);
                ll c = f2.get(r - 1);
                ans += c - p;
                ll c2 = f3.get(r - 1);
                ans -= (c2 - p2) * l;
                p2 = c2;
                p = c;
            }
            f2.upd(x, x);
            f3.upd(x, 1);
        }
        cout << ans << ' ';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    //cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}