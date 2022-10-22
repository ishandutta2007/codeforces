#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <unordered_map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>
#include <random>
#include <bitset>

#define int long long
#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';

using namespace std;
const int root = 212, mod = 1e9 + 7;

struct DisjointSet {
    vector <int> p, val;
    DisjointSet(int n = 0) {
        p.resize(n), val.resize(n, 1);
        iota(p.begin(), p.end(), 0);
    }
    int get(int a) {
        return p[a] = p[a] == a ? a : get(p[a]);
    }
    void unite(int a, int b) {
        a = get(a), b = get(b);
        p[a] = b;
    }
};

int n, m;
int get(int i, int j) {
    return i * m + j;
}

vector <vector <int>> g;
DisjointSet dsu;
vector <bool> used;
vector <int> ts;

void addEdge(int u, int v) {
    g[dsu.get(u)].push_back(dsu.get(v));
}

void dfs(int v) {
    used[v] = true;
    for (auto& u : g[v])
        if (!used[u]) dfs(u);
    ts.push_back(v);
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);

    cin >> n >> m;
    vector <vector <int>> a(n, vector <int>(m));
    for (auto& x : a)
        for (auto& y : x) cin >> y;
    g.resize(n * m);
    used.resize(n * m);
    dsu = DisjointSet(n * m);
    for (int i = 0; i < n; ++i) {
        vector <int> cur(m);
        iota(cur.begin(), cur.end(), 0);
        sort(cur.begin(), cur.end(), [&](int A, int B) {
            return a[i][A] < a[i][B];
            });
        for (int j = 0; j < m - 1; ++j) {
            if (a[i][cur[j]] == a[i][cur[j + 1]])
                dsu.unite(get(i, cur[j]), get(i, cur[j + 1]));
        }
    }
    for (int i = 0; i < m; ++i) {
        vector <int> cur(n);
        iota(cur.begin(), cur.end(), 0);
        sort(cur.begin(), cur.end(), [&](int A, int B) {
            return a[A][i] < a[B][i];
            });
        for (int j = 0; j < n - 1; ++j) {
            if (a[cur[j]][i] == a[cur[j + 1]][i])
                dsu.unite(get(cur[j], i), get(cur[j + 1], i));
        }
    }
    for (int i = 0; i < n; ++i) {
        vector <int> cur(m);
        iota(cur.begin(), cur.end(), 0);
        sort(cur.begin(), cur.end(), [&](int A, int B) {
            return a[i][A] < a[i][B];
            });
        for (int j = 0; j < m - 1; ++j) {
            if (a[i][cur[j]] != a[i][cur[j + 1]])
                addEdge(get(i, cur[j]), get(i, cur[j + 1]));
        }
    }
    for (int i = 0; i < m; ++i) {
        vector <int> cur(n);
        iota(cur.begin(), cur.end(), 0);
        sort(cur.begin(), cur.end(), [&](int A, int B) {
            return a[A][i] < a[B][i];
            });
        for (int j = 0; j < n - 1; ++j) {
            if (a[cur[j]][i] != a[cur[j + 1]][i])
                addEdge(get(cur[j], i), get(cur[j + 1], i));
        }
    }
    
    for (int i = 0; i < n * m; ++i) {
        if (!used[i]) dfs(i);
    }
    reverse(ts.begin(), ts.end());
    vector <int> dp(n * m , 1);
    for (auto& x : ts) {
        for (auto& u : g[x])
            dp[u] = max(dp[u], dp[x] + 1);
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) cout << dp[dsu.get(get(i, j))] << ' ';
        cout << '\n';
    }
    

    return 0;
}