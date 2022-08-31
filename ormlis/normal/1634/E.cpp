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
const int maxN = 1e6 + 30;
const int LG = 100;

vector<pair<int, int>> g[maxN];
vector<ar<int, 3>> path;
bool used[maxN];

void dfs(int v) {
    while (!g[v].empty()) {
        auto[u, i] = g[v].back();
        g[v].pop_back();
        if (used[i]) continue;
        used[i] = true;
        dfs(u);
        path.push_back({i, v, u});
    }
}

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> a(m);
    vector<int> xx;
    rep(i, m) {
        int n;
        cin >> n;
        a[i].resize(n);
        rep(j, n) cin >> a[i][j];
        rep(j, n) xx.push_back(a[i][j]);
    }
    sort(all(xx));
    xx.resize(unique(all(xx)) - xx.begin());
    int sz = xx.size();
    int t = 0;
    rep(i, m) {
        rep(j, (int) a[i].size()) {
            a[i][j] = lower_bound(all(xx), a[i][j]) - xx.begin();
        }
        for (int j = 0; j < (int) a[i].size(); j += 2) {
            int x = a[i][j];
            int y = a[i][j + 1];
            g[x].emplace_back(y, t);
            g[y].emplace_back(x, t);
            t++;
        }
    }
    rep(i, sz) {
        if (g[i].size() % 2 == 1) {
            cout << "NO\n";
            return;
        }
    }
    vector<int> w(t);
    rep(i, sz) {
        path.clear();
        dfs(i);
        reverse(all(path));
        int was = i;
        for (auto &[edge, u, v] : path) {
            if (u != was) swap(u, v);
            w[edge] = u;
            was = v;
        }
    }
    t = 0;
    cout << "YES\n";
    rep(i, m) {
        for (int j = 0; j < (int) a[i].size(); j += 2) {
            int x = a[i][j];
            int y = a[i][j + 1];
            if (w[t] == x) {
                cout << "LR";
            } else {
                cout << "RL";
            }
            t++;
        }
        cout << "\n";
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}