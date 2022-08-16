#include <bits/stdc++.h>
using namespace std;
 
#define sz(v) int(v.size())
#define ar array
typedef long long ll;
const int N = 1e5+10, MOD = 998244353;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
ll rnd() {
    return rng() % LLONG_MAX;
}

struct FT {
    int n, m;
    vector<vector<ll>> bit;

    FT() {}
    FT(int _n, int _m): n(_n), m(_m) {
        bit.assign(n, vector<ll>(m));
    }

    void point_add(int x, int y, ll d) {
        for (int i = x; i < n; i = i | (i + 1))
            for (int j = y; j < m; j = j | (j + 1))
                bit[i][j] ^= d;
    }
    ll prefix_qry(int x, int y) {
        ll ans = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
                ans ^= bit[i][j];

        return ans;
    }
    void upd(int i1, int j1, int i2, int j2, ll x) {
        point_add(i1, j1, x);
        point_add(i1, j2+1, x);
        point_add(i2+1, j1, x);
        point_add(i2+1, j2+1, x);
    } 
    ll qry(int i, int j) {
        return prefix_qry(i, j);
    }
};

void solve() {
    int n, m, q; cin >> n >> m >> q;
    FT bit(n, m);
    vector<vector<ll>> a(n, vector<ll>(m, -1LL));
    while (q--) {
        int t; cin >> t;
        int i1, j1, i2, j2; cin >> i1 >> j1 >> i2 >> j2, --i1, --j1, --i2, --j2;
        if (t == 1) {
            a[i1][j1] = rnd();
            bit.upd(i1, j1, i2, j2, a[i1][j1]);
        } else if (t == 2) {
            bit.upd(i1, j1, i2, j2, a[i1][j1]);
            a[i1][j1] = -1;
        } else if (t == 3) {
            bool ans = bit.qry(i1, j1) == bit.qry(i2, j2);
            cout << (ans ? "Yes\n" : "No\n");
        } else assert(false);
    }
}
int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    int T=1;
    // cin >> T;
    while (T--) solve();
}