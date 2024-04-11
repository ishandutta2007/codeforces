#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    if (n == 1) {
        return 0;
    }
    vector<vector<int>> g(n);
    for (int i = 0; i + 1 < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].emplace_back(v);
        g[v].emplace_back(u);
    }

    /*  Find centroid, then all subtrees will have size <= n / 2
        Partition children of centorid into two: P1 and P2, such that
        |P1| * |P2| + |P1| + |P2| + 1 >= floor(n * n / 9)

        Just sort children based on their size and try every possible segment.

        For P1, enumerate vertices to have distances 1, 2, 3, ..., |P1|
        For P2, enumerate vertices to have distances 1(|P| + 1), 2(|P| + 1), 3(|P| + 1), ..., (|P2|)(|P1| + 1)        
    
    */

    vector<int> sz(n, 0), par(n, -1), col(n, -1);
    function<void(int, int)> dfs = [&](int n, int p) {
        sz[n] = 1;
        par[n] = p;
        for (auto i : g[n]) if (i != p) {
            dfs(i, n);
            sz[n] += sz[i];
        }
    };

    function<int()> centroid = [&]() {
        int u = 0;
        dfs(u, -1);
        while (true) {
            pair<int, int> mx = {-1, -1};
            for (auto i : g[u]) if (i != par[u]) {
                mx = max(mx, {sz[i], i});
            }
            if (mx.first * 2 <= n) {
                return u;
            }
            u = mx.second;
        }
        return -1;
    };

    int c = centroid();
    dfs(c, -1);

    sort(begin(g[c]), end(g[c]), [&](int a, int b) { return sz[a] < sz[b]; });
    int sum = 0, pv = -1;
    for (int i = 0; i < g[c].size(); i++) {
        sum += sz[g[c][i]];
        if (1ll * sum * (n - sum - 1) + sum + (n - sum - 1) >= (2ll * n * n) / 9) {
            pv = i + 1;
            break;
        }
    }

    assert(pv != -1);

    function<void(int, int, int, deque<int>&)> color = [&](int n, int p, int delta, deque<int>& c) {
        col[n] = c.front() - delta;
        c.pop_front();
        for (auto i : g[n]) if (i != p) {
            color(i, n, delta + col[n], c);
        }
    };

    int cnt = 1;
    deque<int> clr(sum);
    iota(begin(clr), end(clr), 1);
    for (int i = 0; i < pv; i++) {
        color(g[c][i], c, 0, clr);
    }

    clr.resize(n - sum - 1);
    for (int i = 0; i < clr.size(); i++) {
        clr[i] = (i + 1) * (sum + 1);
    }

    for (int i = pv; i < g[c].size(); i++) {
        color(g[c][i], c, 0, clr);
    }
    
    for (int i = 0; i < n; i++) {
        if (i == c) {
            continue;
        }
        cout << i + 1 << " " << par[i] + 1 << " " << col[i] << "\n";
    }
    return 0;
}