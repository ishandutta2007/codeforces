#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <set>
#include <array>
#include <assert.h>

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

vpi g[maxN];
pi mt[maxN];
int used[maxN];
int T = 1;

bool kuhn(int v) {
    if (used[v] == T) return false;
    used[v] = T;
    for(auto [u, i] : g[v]) {
        if (mt[u].first == -1 || kuhn(mt[u].first)) {
            mt[u] = {v, i};
            return true;
        }
    }
    return false;
}

vector<ar<int, 3>> U, D;

void dfs(int v) {
    if (used[v] == T) return;
    used[v] = T;
    for(auto [u, i] : g[v]) {
        assert(mt[u].first != -1);
        if (used[mt[u].first] != T) {
            U.push_back({mt[u].first, u, mt[u].second});
            dfs(mt[u].first);
        }
    }
}

void solve() {
    int n1, n2, m, q; cin >> n1 >> n2 >> m >> q;
    for(int i = 1; i <= m; ++i) {
        int u, v; cin >> u >> v;
        g[u].emplace_back(v, i);
    }
    for(int i = 1; i <= n2; ++i) mt[i] = {-1, -1};
    vi res;
    for(int i = 1; i <= n1; ++i) {
        T++;
        if (!kuhn(i)) {
            res.push_back(i);
        }
    }
    T++;
    for(auto i : res) {
        dfs(i);
    }
    ll ans = 0;
    for(int i = 1; i <= n2; ++i) {
        if (mt[i].first == -1) continue;
        if (used[mt[i].first] != T) {
            D.push_back({mt[i].first, i, mt[i].second});
        }
        ans += mt[i].second;
    }
    assert(U.size() + D.size() == (int)n1 - (int)res.size());
    rep(_, q) {
        int t; cin >> t;
        if (t == 1) {
            if (!D.empty()) {
                cout << "1\n" << D.back()[0] << "\n";
                ans -= D.back()[2];
                D.pop_back();
            } else {
                assert(!U.empty());
                cout << "1\n" << -U.back()[1] << "\n";
                ans -= U.back()[2];
                U.pop_back();
            }
            cout << ans << endl;
        } else {
            cout << U.size() + D.size() << '\n';
            ll val = 0;
            for(auto [kek,lol, i] : U) val += i;
            for(auto [kek,lol, i] : D) val += i;
            assert(val == ans);

            for(auto [kek,lol, i] : U) cout << i << ' ';
            for(auto [kek, lol, i] : D) cout << i << ' ';
            cout << endl;
        }
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}