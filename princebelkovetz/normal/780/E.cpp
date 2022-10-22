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

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int root = 212, mod = 1e9 + 7, N = 20;

vector <vector <int>> g;
vector <bool> used;
vector <int> path;

void dfs(int v) {
    path.push_back(v);
    used[v] = true;
    for (auto& u : g[v]) {
        if (used[u]) continue;
        dfs(u);
        path.push_back(v);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(8);
    
    int n, m, k; cin >> n >> m >> k;
    g.resize(n + 1);
    used.resize(n + 1);
    for (int i = 0, u, v; i < m; ++i) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    dfs(1);
    int able = (2 * n + k - 1) / k;

    int lst = 0;
    for (int i = 0; i < k; ++i) {
        if (lst == path.size()) {
            cout << "1 1\n";
            continue;
        }
        int len = min(able, path.size() - lst);
        cout << len << ' ';
        for (int j = lst; j < lst + len; ++j)
            cout << path[j] << ' ';
        lst = min((int)path.size(), lst + able);
        cout << '\n';
    }
    return 0;
}