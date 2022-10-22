#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <cassert>

using namespace std;
#define int long long
#define ld long double
#define debug(x) cout << #x << " actually equals " << x << '\n';
const int mod = 998244353;
vector <vector <int>> g;
vector <int> h, p, ans;
void dfs(int v) {
    for (auto u : g[v]) {
        h[u] = h[v] + 1;
        dfs(u);
    }
}
void dfs2(int v, vector <int>& ban, int cur, int &left) {
    ans.push_back(v);
    for (auto u : g[v]) {
        if (left and u != ban[cur + 1]) {
            left--;
            dfs2(u, ban, cur, left);
            ans.push_back(v);
        }
    }
    if (ban[cur] == v and cur != ban.size() - 1) {
        cur++;
        dfs2(ban[cur], ban, cur, left);
    }
}
signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    cout << fixed << setprecision(6);
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        g.resize(n + 1);
        h.resize(n + 1);
        p.resize(n + 1);
        for (int i = 2; i <= n; ++i) {
            int x; cin >> x;
            g[x].push_back(i);
            p[i] = x;
        }
        h[1] = 1;
        dfs(1);
        int id = 0;
        for (int i = 1; i <= n; ++i)
            if (h[i] > h[id]) id = i;
        vector <int> way;
        while (id != 0) {
            way.push_back(id);
            id = p[id];
        }
        reverse(way.begin(), way.end());
        if (way.size() >= k) {
            cout << k - 1 << '\n';
            for (int i = 0; i < k; ++i)
                cout << way[i] << ' ';
            cout << '\n';
        }
        else {
            int left = k - way.size();
            dfs2(1, way, 0, left);
            cout << ans.size() - 1 << '\n';
            for (auto x : ans) cout << x << ' ';
            cout << '\n';
            assert(ans.size() - 1 == 2 * k - 1 - way.size());
        }
        ans.resize(0);
        g.resize(0);
        h.resize(0);
        p.resize(0);
    }
    return 0;
}