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
const int LG = 30;

vpi g[maxN];
bool used[maxN];
vi res;

void dfs(int v) {
    while(!g[v].empty()) {
        auto [u, i] = g[v].back();
        g[v].pop_back();
        if (used[i]) continue;
        used[i] = 1;
        dfs(u);
    }
    res.push_back(v);
}

void solve() {
    int n; cin >> n;
    rep(i, n) {
        int x, y; cin >> x >> y;
        g[x].emplace_back(y, i);
        g[x].emplace_back(y, i + n);
        g[y].emplace_back(x, i);
        g[y].emplace_back(x, i + n);
    }
    for(int i = 1; i <= 2 * n; ++i) {
        if (g[i].size() % 2 == 1) {
            cout << "-1\n";
            return;
        }
    }
    vvi mat(2, vi(n));
    vector<vector<char>> a(2, vector<char>(n)), b(2, vector<char> (n));
    int cur = 0;
    for(int i = 1; i <= 2 * n; ++i) {
        if (g[i].empty()) continue;
        dfs(i);
        assert(g[i].empty());
        res.pop_back();
        if (res.size() % 2 != 0 || res.size() == 2) {
            cout << "-1\n";
            return;
        }
        vpi kek;
        int len = res.size() / 2;
        rep(j, len) kek.emplace_back(0, j + cur);
        rep(j, len) kek.emplace_back(1, cur + len - 1 - j);
        rep(j, len * 2) {
            auto [x, y] = kek[j];
            mat[x][y] = res[j];
        }
        for(int j = 0; j < len * 2; j += 2) {
            auto [x1, y1] = kek[j];
            auto [x2, y2] = kek[j + 1];
            if (x1 == x2) {
                if (y1 > y2) {
                    swap(y1, y2);
                }
                assert(y1 < y2);
                a[x1][y1] = 'L';
                a[x2][y2] = 'R';
            } else {
                assert(y1 == y2);
                if (x1 > x2) swap(x1, x2);
                assert(x1 < x2);
                a[x1][y1] = 'U';
                a[x2][y2] = 'D';
            }
        }
        for(int j = 1; j < len * 2; j += 2) {
            auto [x1, y1] = kek[j];
            auto [x2, y2] = kek[(j + 1) % (len * 2)];
            if (x1 == x2) {
                if (y1 > y2) {
                    swap(y1, y2);
                }
                assert(y1 < y2);
                b[x1][y1] = 'L';
                b[x2][y2] = 'R';
            } else {
                assert(y1 == y2);
                if (x1 > x2) swap(x1, x2);
                assert(x1 < x2);
                b[x1][y1] = 'U';
                b[x2][y2] = 'D';
            }
        }
        res.clear();
        cur += len;
    }
    cout << "2 " << n << '\n';
    rep(i, 2) {
        rep(j, n) cout << mat[i][j] << ' ';
        cout << '\n';
    }
    rep(i, 2) {
        rep(j, n) cout << a[i][j];
        cout << '\n';
    }
    rep(i, 2) {
        rep(j, n) cout << b[i][j];
        cout << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}