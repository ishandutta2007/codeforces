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
const int maxN = 5e5 + 20;
const int LG = 30;

bool eq[100][100][100];

// mid, l, r
void solve() {
    int n;
    cin >> n;
    rep(i, n - 1) {
        rep(j, n - i - 1) {
            rep(t, n) {
                char x;
                cin >> x;
                eq[t][i][i + j + 1] = (x == '1');
                eq[t][i + j + 1][i] = eq[t][i][i + j + 1];
            }
        }
    }
    rep(i, n) rep(j, n) eq[i][j][j] = true;
    for (int t = 1; t < n; ++t) {
        vi p(n, -1);
        p[0] = t;
        p[t] = 0;
        queue<int> q;
        q.push(t);
        q.push(0);
        vvi g(n);
        g[t].push_back(0);
        g[0].push_back(t);
        while (!q.empty()) {
            int v = q.front();
            q.pop();
            rep(u, n) {
                if (p[u] != -1) continue;
                if (eq[v][u][p[v]]) {
                    q.push(u);
                    p[u] = v;
                    g[u].push_back(v);
                    g[v].push_back(u);
                }
            }
        }
        bool ok = true;
        rep(v, n) {
            if (!ok) break;
            q.push(v);
            vi d(n, -1);
            d[v] = 0;
            while (!q.empty()) {
                int u = q.front();
                q.pop();
                for (auto &w : g[u]) {
                    if (d[w] == -1) {
                        d[w] = d[u] + 1;
                        q.push(w);
                    }
                }
            }
            rep(l, n) {
                if (d[l] == -1) {
                    ok = false;
                }
                if (!ok) break;
                rep(r, n) {
                    bool val = (d[l] == d[r]);
                    if (val != eq[v][l][r]) {
                        ok = false;
                    }
                }
            }
        }
        if (!ok) continue;
        cout << "YES\n";
        rep(i, n) {
            for (auto &j : g[i]) {
                if (j > i) cout << i + 1 << ' ' << j + 1 << '\n';
            }
        }
        return;
    }
    cout << "NO\n";
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int t = 1;
    cin >> t;
    range(i, t) {
        solve();
    }
    return 0;
}