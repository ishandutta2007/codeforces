#include <bits/stdc++.h>


#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, n) for (int i = 1; i < (n); ++i)
#define rep1n(i, n) for (int i = 1; i <= (n); ++i)
#define repr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define pb push_back
#define eb emplace_back
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define sz(a) (int)(a.size())
#define each(x, a) for (auto &x : a)
#define ar array
#define vec vector
#define range(i, n) rep(i, n)

using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
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

const int INFi = 1e9 + 10;
const ll INF = 2e18;
const int maxN = 1e6 + 20;
const int LG = 100;

struct dsu {
    vector<int> dsu;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        dsu.resize(n);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        return a == b;
    }
};

const int md = 1e9 + 7; //1e9 + 7, 1e9 + 9

inline int add(const int &a, const int &b) {
    return a + b >= md ? a + b - md : a + b;
}

inline int sub(const int &a, const int &b) {
    return a - b < 0 ? a - b + md : a - b;
}

inline int mul(const int &a, const int &b) {
    return (1ll * a * b) % md;
}

int binpow(int a, int b) {
    int res = 1;
    for (; b; b >>= 1, a = mul(a, a)) if (b & 1) res = mul(res, a);
    return res;
}

int rev(int a) {
    return binpow(a, md - 2);
}

void solve() {
    int n;
    cin >> n;
    vi a(n), b(n), d(n);
    rep(i, n) {
        cin >> a[i];
        a[i]--;
    }
    rep(i, n) {
        cin >> b[i];
        b[i]--;
    }
    rep(i, n) {
        cin >> d[i];
        d[i]--;
    }
    rep(i, n) {
        if (a[i] == b[i]) {
            d[i] = a[i];
        }
    }
    vi p1(n), p2(n);
    vi t(n);
    rep(i, n) {
        p1[a[i]] = i;
        p2[b[i]] = i;
    }
    dsu D;
    D.build(n);
    rep(i, n) {
        D.unio(p1[i], p2[i]);
    }
    rep(i, n) {
        if (d[i] != -1) t[D.get_dsu(i)] = -1;
    }
    int ans = 1;
    rep(i, n) if (D.get_dsu(i) == i && t[i] != -1) ans = mul(ans, 2);
    cout << ans << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}