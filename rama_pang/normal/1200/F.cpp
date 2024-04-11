#include <bits/stdc++.h>
using namespace std;
const int MOD = 2520; // lca(1, 2, 3, 4, 5, 6, 7, 8, 9, 10)

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<int> k(n);

    for (int i = 0; i < n; i++) {
        cin >> k[i];
        k[i] %= MOD;
        if (k[i] < 0) {
            k[i] += MOD;
        }
    }

    vector<int> g(n * MOD);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        vector<int> e(m);
        for (int j = 0; j < m; j++) {
            cin >> e[j];
            e[j]--;
        }
        for (int c = 0; c < MOD; c++) {
            g[i * MOD + c] = e[(c + k[i]) % m] * MOD + ((c + k[i]) % MOD);
        }
    }

    vector<int> vis(n * MOD, -1);
    vector<int> ans(n * MOD, -1);
    vector<int> distinct(n * MOD, -1);
    int mark = 0;

    for (int i = 0; i < n * MOD; i++) {
        if (vis[i] == 1) {
            continue;
        }

        int cur = i;
        while (vis[cur] == -1) {
            vis[cur] = -2;
            cur = g[cur];
        }

        if (vis[cur] == 1) {
            int cnt = ans[cur];
            cur = i;
            while (vis[cur] != 1) {
                ans[cur] = cnt;
                vis[cur] = 1;
                cur = g[cur];
            }
            continue;
        }

        int cnt = 0;
        mark++;
        while (vis[cur] == -2) {
            vis[cur] = -3;
            if (distinct[cur / MOD] != mark) {
                cnt++;
                distinct[cur / MOD] = mark;
            }
            cur = g[cur];
        }

        cur = i;
        while (vis[cur] != 1) {
            vis[cur] = 1;
            ans[cur] = cnt;
            cur = g[cur];
        }
    }
    
    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y %= MOD;
        if (y < 0) {
            y += MOD;
        }
        cout << ans[x * MOD + y] << "\n";
    }

    return 0;
}