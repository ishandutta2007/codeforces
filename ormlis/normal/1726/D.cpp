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
        if (a == b) return false;
        dsu[a] = b;
        return true;
    }
};

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vpi> g(n);
    vi ans(m);
    vector<ar<int, 3>> kek;
    vi deg(n);
    dsu d;
    d.build(n);
    rep(i, m) {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        if (d.unio(u, v)) {
            ans[i] = 1;
            g[u].emplace_back(v, i);
            g[v].emplace_back(u, i);
        } else {
            kek.push_back({i, u, v});
            deg[u]++;
            deg[v]++;
        }
    }
    if (kek.size() == 3) {
        bool ok = true;
        rep(i, n) ok &= (deg[i] % 2 == 0);
        if (ok) {
            vi path;
            int A = kek[0][1];
            int B = kek[0][2];
            function<bool(int, int)> dfs = [&] (int v, int p) {
                if (v == B) return true;
                for(auto [u, i] : g[v]) {
                    if (u == p) continue;
                    path.push_back(i);
                    if (dfs(u, v)) return true;
                    path.pop_back();
                }
                return false;
            };
            assert(dfs(A, -1));
            ans[path[0]] = 0;
            ans[kek[0][0]] = 1;
        }
    }
    rep(i, m) cout << ans[i];
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}