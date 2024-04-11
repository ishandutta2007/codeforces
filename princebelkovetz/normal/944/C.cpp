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
const int root = 212, mod = 1e9 + 7, N = 1e6 + 7;

vector <vector <int>> g;
vector <int> ans;
void dfs(int v, int curH) {
    ans[curH] ^= 1;
    for (auto& u : g[v])
        dfs(u, curH + 1);
}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int n; cin >> n;
    g.resize(n + 1);
    ans.resize(n + 1);
    for (int p, i = 2; i <= n; ++i) {
        cin >> p;
        g[p].push_back(i);
    }
    dfs(1, 0);
    int res = 0;
    for (auto& x : ans) res += x;
    cout << res << '\n';
    return 0;
}