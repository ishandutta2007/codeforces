#include <bits/stdc++.h>

#define range(i, n) for (int i = 0; i < (n); ++i)
#define all(a) (a).begin(), (a).end()
#define rall(a) (a).rbegin(), (a).rend()
#define ar array

using namespace std;

typedef long long ll;
typedef double ld;
typedef unsigned long long ull;

const ll INF = 2e18;
const int INFi = 2e9 + 5;
const int maxN = 5e5 + 1;
const int md = 1e9 + 7;


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
    if (b <= 0) return 1;
    if (b % 2) return mul(a, binpow(a, b - 1));
    int m = binpow(a, b / 2);
    return mul(m, m);
}

int rev(int a) {
    return binpow(a, md - 2);
}

vector<int> g[maxN];

vector<int> stk;
vector<int> path;
void dfs1(int v, int p, int f) {
    stk.push_back(v);
    if (v == f) {
        path = stk;
    }
    for(auto &u : g[v]) {
        if (u == p) continue;
        dfs1(u, v, f);
    }
    stk.pop_back();
}

int dfs2(int v, int p1, int p2 = -1) {
    int result = 1;
    for(auto &u : g[v]) {
        if (u == p1 || u == p2) continue;
        result += dfs2(u, v);
    }
    return result;
}

void solve() {
    int n;
    cin >> n;
    range(_, n - 1) {
        int x, y; cin >> x >> y;
        g[x].emplace_back(y);
        g[y].emplace_back(x);
    }
    int ans = 0;
    int rv = rev(2);
    vector<vector<int>> probs(n, vector<int> (n));
    range(i, n) {
        range(j, n) {
            if (i == 0) {
                probs[i][j] = 1;
                continue;
            }
            if (j == 0) {
                probs[i][j] = 0;
                continue;
            }
            probs[i][j] = mul(add(probs[i - 1][j], probs[i][j - 1]), rv);
        }
    }
    for(int x = 1; x <= n; ++x) {
        for(int y = 1; y < x; ++y) {
            stk.clear();
            path.clear();
            dfs1(x, -1, y);
            // x, w, .., t, y
            int len = path.size();
            assert(len > 1);
            for(int i = len - 2; i >= 0; --i) {
                int p1 = -1, p2 = -1;
                if (i) p1 = path[i - 1];
                if (i + 1 < len) p2 = path[i + 1];
                int cnt = dfs2(path[i], p1, p2);
                ans = add(ans, mul(cnt, probs[i][len - 1 - i]));
            }
        }
    }
    ans = mul(ans, rev(n));
    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    // cout << setprecision(15) << fixed;
    int tests = 1;
    // cin >> tests;
    range(_, tests) {
        solve();
    }
    return 0;
}