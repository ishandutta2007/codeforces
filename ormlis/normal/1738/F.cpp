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

struct dsu {
    vi dsu;
    vl sum;
    vi rnk;

    void build(int n, vl &a) {
        dsu.resize(n);
        iota(all(dsu), 0);
        sum = a;
        rnk.resize(n, 1);
    }

    int get(int x) {
        return dsu[x] == x ? x : dsu[x] = get(dsu[x]);
    }

    bool unio(int a, int b) {
        a = get(a);
        b = get(b);
        if (a == b) return false;
        if (rnk[a] > rnk[b]) swap(a, b);
        rnk[b] += rnk[a];
        sum[b] += sum[a];
        dsu[a] = b;
        return true;
    }

    bool check(int x) {
        x = get(x);
        return sum[x] <= 1ll * rnk[x] * rnk[x];
    }
};

void solve() {
    dsu d;
    int n;
    cin >> n;
    vl a(n);
    rep(i, n) cin >> a[i];
    auto ask = [&](int v) {
        cout << "? " << v + 1 << endl;
        int u;
        cin >> u;
        return u - 1;
    };
    d.build(n, a);
    vi ord(n);
    iota(all(ord), 0);
    sort(all(ord), [&](const int &i, const int &j) {
        return a[i] > a[j];
    });
    for (auto v: ord) {
        while (!d.check(v)) {
            int u = ask(v);
            assert(d.unio(u, v));
        }
    }
    cout << "! ";
    rep(i, n) cout << d.get(i) + 1 << ' ';
    cout << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    //cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    rep(_, t) {
        solve();
    }
    return 0;
}