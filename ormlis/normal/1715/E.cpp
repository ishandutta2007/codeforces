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

// CHT: minimum,     k
struct convex_hull_trick {
    struct Line {
        ll k, b;

        ll get(ll x) {
            return k * x + b;
        }
    };

    vector<ll> xx;
    vector<Line> lines;

    ll intersect(Line &a, Line &b) {
        if (a.k == b.k) {
            if (a.b < b.b) return -INF;
            return INF;
        }
        // x = (a.b - b.b) / (b.k - a.k)
        if (a.b >= b.b) {
            return (a.b - b.b + (b.k - a.k - 1)) / (b.k - a.k);
        } else {
            return (a.b - b.b) / (b.k - a.k);
        }
    }

    void add(ll k, ll b) {
        Line A = {k, b};
        while (!lines.empty() && intersect(A, lines.back()) <= xx.back()) {
            xx.pop_back();
            lines.pop_back();
        }
        if (lines.empty()) {
            xx.push_back(-INF);
        } else {
            xx.push_back(intersect(A, lines.back()));
        }
        lines.push_back(A);
    }

    ll get(ll x) {
        int i = upper_bound(all(xx), x) - xx.begin();
        return lines[i - 1].get(x);
    }
};


void solve() {
    int n, m, k;
    // u^2 + v^2 - 2(uv)
    cin >> n >> m >> k;
    vector<vector<pair<int, int>>> g(n);
    rep(_, m) {
        int u, v, w;
        cin >> u >> v >> w;
        u--;
        v--;
        g[u].emplace_back(v, w);
        g[v].emplace_back(u, w);
    }
    vl dp(n, INF);
    dp[0] = 0;
    auto dijsktra = [&]() {
        set<pair<ll, int>> q;
        rep(i, n) q.insert({dp[i], i});
        while (!q.empty()) {
            auto[dist, i] = *q.begin();
            q.erase(q.begin());
            for (auto[j, w] : g[i]) {
                if (dp[j] > dist + w) {
                    q.erase({dp[j], j});
                    dp[j] = dist + w;
                    q.insert({dp[j], j});
                }
            }
        }
    };
    dijsktra();
    rep(_, k) {
        convex_hull_trick cht;
        rep(i, n) {
            cht.add(-1ll * 2 * i, 1ll * i * i + dp[i]);
        }
        rep(i, n) dp[i] = cht.get(i) + 1ll * i * i;
        dijsktra();
    }
    rep(i, n) cout << dp[i] << ' ';
    cout << '\n';
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(15) << fixed;
    int t = 1;
//    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}