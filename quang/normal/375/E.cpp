#include <bits/stdc++.h>

using namespace std;

const int N = 510;

typedef long double ld;
const ld EPS = 1e-8;
struct LPSolver {
    static vector<ld> simplex(vector<vector<ld>> a) {
        int n = (int) a.size() - 1;
        int m = (int) a[0].size() - 1;
        vector<int> left(n + 1);
        vector<int> up(m + 1);
        iota(left.begin(), left.end(), m);
        iota(up.begin(), up.end(), 0);
        auto pivot = [&](int x, int y) {
            swap(left[x], up[y]);
            ld k = a[x][y];
            a[x][y] = 1;
            vector<int> pos;
            for (int j = 0; j <= m; j++) {
                a[x][j] /= k;
                if (fabs(a[x][j]) > EPS) pos.push_back(j);
            }
            for (int i = 0; i <= n; i++) {
                if (fabs(a[i][y]) < EPS || i == x) continue;
                k = a[i][y];
                a[i][y] = 0;
                for (int j : pos) a[i][j] -= k * a[x][j];
            }
        };
        while (1) {
            int x = -1;
            for (int i = 1; i <= n; i++) {
                if (a[i][0] < -EPS && (x == -1 || a[i][0] < a[x][0])) {
                    x = i;
                }
            }
            if (x == -1) break;
            int y = -1;
                for (int j = 1; j <= m; j++) {
                    if (a[x][j] < -EPS && (y == -1 || a[x][j] < a[x][y])) {
                    y = j;
                }
            }
            if (y == -1) return vector<ld>(); // infeasible
            pivot(x, y);
        }
        while (1) {
            int y = -1;
            for (int j = 1; j <= m; j++) {
                if (a[0][j] > EPS && (y == -1 || a[0][j] > a[0][y])) {
                    y = j;
                }
            }
            if (y == -1) break;
            int x = -1;
            for (int i = 1; i <= n; i++) {
                if (a[i][y] > EPS && (x == -1 || a[i][0] / a[i][y] < a[x][0] / a[x][y])) {
                    x = i;
                }
            }
            if (x == -1) return vector<ld>(); // unbounded
            pivot(x, y);
        }
        vector<ld> ans(m + 1);
        for (int i = 1; i <= n; i++) {
            if (left[i] <= m) ans[left[i]] = a[i][0];
        }
        ans[0] = -a[0][0];
        return ans;
    }
};

long long d[N][N];
int n, x;
vector<pair<int, int> > adj[N];
int a[N];

void dfs(int u, int p, int root, long long s) {
    d[root][u] = s;
    for (auto v : adj[u]) {
        if (v.first == p) continue;
        dfs(v.first, u, root, s + v.second);
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> x;
    int numRed = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        numRed += (a[i] == 0);
    }
    for (int i = 1; i < n; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].emplace_back(v, w);
        adj[v].emplace_back(u, w);
    }
    for (int i = 1; i <= n; i++) {
        dfs(i, -1, i, 0ll);
    }
    vector<vector<ld> > lp;
    vector<ld> foo(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        foo[i] = -(a[i] == 0);
    }
    lp.push_back(foo);
    for (int i = 1; i <= n; i++) {
        vector<ld> foo(n + 1, 0);
        foo[0] = -1;
        for (int j = 1; j <= n; j++) {
            foo[j] = -(d[i][j] <= x);
        }
        lp.push_back(foo);
    }
    foo[0] = n - numRed;
    for (int i = 1; i <= n; i++) {
        foo[i] = 1;
    }
    lp.push_back(foo);
    vector<ld> res = LPSolver::simplex(lp);
    if (res.size() == 0) {
        cout << -1 << endl;
        return 0;
    }
    cout << -round(res[0]) << endl;
    return 0;
}