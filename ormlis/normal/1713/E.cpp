#include <bits/stdc++.h>

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
const int maxN = 2e5 + 10;


struct dsu {
    vector<int> dsu;
    vi x;
    int n;

    pi get_dsu(int a) {
        if (dsu[a] == a) return {a, x[a]};
        auto res = get_dsu(dsu[a]);
        dsu[a] = res.first;
        x[a] ^= res.second ^ x[dsu[a]];
        return {dsu[a], x[a] ^ x[dsu[a]]};
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        x.resize(n, 0);
        range(i, n)
            dsu[i] = i;
    }

    bool unio(int a, int b, int c) {
        auto ra = get_dsu(a);
        auto rb = get_dsu(b);
        a = ra.first;
        b = rb.first;
        if (a == b) {
            if ((ra.second ^ rb.second) == c) return true;
            return false;
        }
        if (x[b] != 0) {
            x[b] ^= 1;
            rb.second ^= 1;
        }
        if ((ra.second ^ rb.second) != c) x[a] ^= 1;
        dsu[a] = b;
        return true;
    }
};

void solve() {
    int n; cin >> n;
    vvi a(n, vi(n));
    rep(i, n) {
        rep(j, n) {
            cin >> a[i][j];
        }
    }
    dsu d;
    d.build(n);
    rep(i, n) {
        rep(j, n) {
            if (a[i][j] == a[j][i]) continue;
            if (a[i][j] < a[j][i]) {
                d.unio(i, j, 0);
            } else {
                d.unio(i, j, 1);
            }
        }
    }
    rep(i, n) {
        rep(j, i) {
            if ((d.get_dsu(i).second ^ d.get_dsu(j).second)) {
                swap(a[i][j], a[j][i]);
            }
        }
    }
    rep(i, n) {
        rep(j, n) {
            cout << a[i][j] << ' ';
        }
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}