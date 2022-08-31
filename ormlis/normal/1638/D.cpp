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

void solve() {
    int n, m;
    cin >> n >> m;
    vvi a(n, vi(m));
    rep(i, n) rep(j, m) cin >> a[i][j];
    vvi u(n - 1, vi(m - 1, 0));
    vector<ar<int, 3>> ans;
    queue<pair<int, int>> q;
    auto check = [&](int i, int j) {
        if (u[i][j] == 1) return;
        vector<int> cols;
        for (int x = i; x <= i + 1; ++x) {
            for (int y = j; y <= j + 1; ++y) {
                if (a[x][y] != -1) cols.emplace_back(a[x][y]);
            }
        }
        cols.resize(unique(all(cols)) - cols.begin());
        if (cols.empty()) cols.push_back(1);
        if (cols.size() > 1) return;
        u[i][j] = 1;
        ans.push_back({i + 1, j + 1, cols.back()});
        for (int x = i; x <= i + 1; ++x) {
            for (int y = j; y <= j + 1; ++y) {
                a[x][y] = -1;
            }
        }
        for (int x = i - 1; x <= i + 1; ++x) {
            for (int y = j - 1; y <= j + 1; ++y) {
                if (x < 0 || x >= n - 1 || y >= m - 1 || y < 0) continue;
                if (u[x][y] == -1) {
                    q.push({x, y});
                    u[x][y] = 0;
                }
            }
        }
    };
    rep(i, n - 1) {
        rep(j, m - 1) {
            q.push({i, j});
        }
    }
    while (!q.empty()) {
        auto[i, j] = q.front();
        q.pop();
        u[i][j] = 0;
        check(i, j);
        if (u[i][j] == 0) {
            u[i][j] = -1;
        }
    }
    if (ans.size() != (n - 1) * (m - 1)) {
        cout << "-1\n";
        return;
    }
    reverse(all(ans));
    cout << ans.size() << '\n';
    for (auto &[i, j, c] : ans) {
        cout << i << ' ' << j << ' ' << c << '\n';
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    //cout << setprecision(20 - 7) << fixed;
    int t = 1;
    // cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}