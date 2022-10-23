#include "bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
using i128 = __int128;
using str = string;
using pi = pair<int, int>;
using pl = pair<ll, ll>;

using vi = vector<int>;
using vl = vector<ll>;
using vpi = vector<pair<int, int>>;
using vvi = vector<vi>;

int Bit(int mask, int b) { return (mask >> b) & 1; }

template<class T>
bool ckmin(T &a, const T &b) {
    if (b < a) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
bool ckmax(T &a, const T &b) {
    if (b > a) {
        a = b;
        return true;
    }
    return false;
}

const int INFi = 1e9;
const ll INF = 2e18;
const int LG = 20;

struct fenwick {
    int n{};
    vector<vector<ll>> fenw{};

    void build(int k) {
        n = k;
        fenw.resize(n, vector<ll>(n));
    }

    void upd(int x, int y, ll val) {
        for (int i = x; i < n; i = i | (i + 1)) {
            for (int j = y; j < n; j = j | (j + 1)) {
                fenw[i][j] = max(fenw[i][j], val);
            }
        }
    }


    ll get(int x, int y) {
        ll res = 0;
        for (int i = x; i >= 0; i = (i & (i + 1)) - 1) {
            for (int j = y; j >= 0; j = (j & (j + 1)) - 1) {
                res = max(res, fenw[i][j]);
            }
        }
        return res;
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vector<vector<int>> a(n, vi(n));
    rep(i, n) {
        rep(j, n) {
            char x; cin >> x;
            a[i][j] = x - '0';
            a[i][j] ^= 1;
        }
    }
    fenwick f;
    f.build(n);
    int need = n * n - (n - k + 1) * (n - k + 1);
    rep(i, n) {
        rep(j, n) {
            if (a[i][j]) {
                need--;
                ll val = f.get(i - 1, j - 1) + 1;
                if (val >= k) {
                    cout << "NO\n";
                    return;
                }
                f.upd(i, j, val);
            }
        }
    }
    if (need < 0) {
        cout << "NO\n";
        return;
    }
    fenwick f2;
    f2.build(n);
    for(int i = n - 1; i >= 0; --i) {
        if (need == 0) break;
        rep(j, n) {
            if (need == 0) break;
            if (!a[i][j]) {
                ll val1 = f.get(i - 1, j - 1);
                ll val2 = f2.get(n - 1 - i - 1, n - 1 - j - 1);
                ll val = val1 + val2 + 1;
                assert(val <= k);
                if (val < k) {
                    a[i][j] = 1;
                    need--;
                    f.upd(i, j, val1 + 1);
                }
            }
            if (a[i][j]) {
                ll val2 = f2.get(n - 1 - i - 1, n - 1 - j - 1);
                f2.upd(n - 1 - i, n - 1 - j, val2 + 1);
            }
        }
    }
    if (need != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    rep(i, n) {
        rep(j, n) {
            cout << a[i][j];
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}