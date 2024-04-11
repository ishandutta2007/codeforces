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
const int maxN = 5000 + 10;
const int LG = 30;


struct dsu {
    vector<int> dsu;
    vector<bool> good;
    int n;

    int get_dsu(int a) {
        if (dsu[a] == a) return a;
        return dsu[a] = get_dsu(dsu[a]);
    }

    void build(int k) {
        n = k;
        good.resize(n);
        dsu.resize(n);
        range(i, n)dsu[i] = i;
    }

    bool unio(int a, int b) {
        a = get_dsu(a), b = get_dsu(b);
        if (rand() % 2) {
            swap(a, b);
        }
        dsu[a] = b;
        if (good[a]) good[b] = true;
        return a == b;
    }

    void make_good(int x) {
        good[get_dsu(x)] = true;
    }

};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<ar<int, 3>> edges(m);
    rep(i, m) {
        rep(j, 3) cin >> edges[i][j];
    }
    vector<dsu> path0(LG);
    rep(i, LG) {
        path0[i].build(n + 1);
        for (auto &[a, b, w] : edges) {
            if (w & (1 << i)) {
                path0[i].unio(a, b);
            }
            if ((w & 1) == 0) {
                path0[i].make_good(a);
                path0[i].make_good(b);
            }
        }
    }
    int q;
    cin >> q;
    rep(_, q) {
        int u, v;
        cin >> u >> v;
        int ans = 2;
        rep(i, LG) {
            if (path0[i].get_dsu(u) == path0[i].get_dsu(v)) {
                ans = min(ans, 0);
            }
            if (i != 0 && path0[i].good[path0[i].get_dsu(u)]) {
                ans = min(ans, 1);
            }
        }
        cout << ans << '\n';
    }
}


signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}