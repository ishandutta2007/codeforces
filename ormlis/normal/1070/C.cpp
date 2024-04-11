#include <bits/stdc++.h>

#define range(i, n) for(int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;

struct fenwick {
    vector<ll> fenw;
    int n;

    void init(int k) {
        fenw.resize(k);
        n = k;
    }

    void upd(int i, ll x) {
        for(; i < n; i |= (i + 1)) fenw[i] += x;
    }

    ll get(int i) {
        ll res = 0;
        for(; i >= 0; i = (i & (i + 1)) - 1) res += fenw[i];
        return res;
    }

    int lower_bound(ll x) {
        int i = -1;
        for(int j = 19; j >= 0; --j) {
            if (i + (int)(1 << j) < n && fenw[i + (int)(1 << j)] < x) {
                i += (int)(1 << j);
                x -= fenw[i];
            }
        }
        return i + 1;
    }
};

void solve() {
    int n, k, m; cin >> n >> k >> m;
    vector<ar<int, 4>> a(m);
    vector<vector<int>> start(n);
    vector<vector<int>> finish(n);
    range(i, m){
        range(j, 4) cin >> a[i][j];
        a[i][0]--;
        a[i][1]--;
        start[a[i][0]].push_back(i);
        finish[a[i][1]].push_back(i);
    }
    fenwick fc, fp;
    const int W = 1e6 + 5;
    fc.init(W);
    fp.init(W);
    ll ans = 0;
    range(i, n) {
        for(auto &j : start[i]) {
            fc.upd(a[j][3], a[j][2]);
            fp.upd(a[j][3], 1ll * a[j][2] * a[j][3]);
        }
        int r = fc.lower_bound(k);
        if (r == W) {
            ans += fp.get(W - 1);
        } else {
            ll res = fp.get(r - 1);
            res += 1ll * r * (k - fc.get(r - 1));
            ans += res;
        }

        for(auto &j : finish[i]) {
            fc.upd(a[j][3], -a[j][2]);
            fp.upd(a[j][3], -1ll * a[j][2] * a[j][3]);
        }
    }
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int tests = 1;
    range(_, tests) {
        solve();
    }
    return 0;
}