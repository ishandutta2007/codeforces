#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <string>
#include <cmath>
#include <set>
#include <stack>
#include <map>
#include <queue>
#include <iterator>
#include <sstream>
#include <cassert>
#include <locale>
#include <numeric>

#define ld long double
#define debug(x) cout << #x << " is " << x << '\n';
#define int long long

using namespace std;
const int mod = 998244353;

vector <vector <int>> g, d;

void dfs(int v, int p, int st) {
    for (auto u: g[v]){
        if (u == p) continue;
        d[st][u] = d[st][v] + 1;
        dfs(u, v, st);
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);

    int tt; cin >> tt;
    while (tt --> 0){
        int n; cin >> n;
        g.assign(n + 1, {});
        d.assign(n + 1, vector <int>(n + 1));
        for (int i = 0, u, v; i < n - 1; ++i){
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        for (int i = 1; i <= n; ++i){
            dfs(i, i, i);
        }
        vector <int> ans(n + 1, mod);
        vector <vector <int>> ds(n, vector <int>(3));
        for (int i = 2; i <= n; ++i){
            for (int j = 1; j <= n; ++j) {
                ds[j - 1] = {d[1][j] - d[i][j], d[1][j], d[i][j]};
            }
            sort(ds.begin(), ds.end());
            vector <int> pref(n + 1), suf(n + 1);
            pref[0] = suf[n] = -mod;
            for (int j = 0; j < n; ++j)
                pref[j + 1] = max(pref[j], ds[j][1]);
            for (int j = n - 1; j >= 0; --j)
                suf[j] = max(suf[j + 1], ds[j][2]);
            int lst = 0;
            for (int j = 1; j <= n; ++j){
                while (lst < n and ds[lst][0] - j <= 0) lst++;
                ans[j] = min(ans[j], max(pref[lst], suf[lst] + j));
            }

        }
        for (int i = 1; i <= n; ++i)
            cout << ans[i] << ' ';
        cout << '\n';
    }
    //
    return 0;
}