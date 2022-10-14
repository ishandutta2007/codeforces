#include <bits/stdc++.h>
using namespace std;
using lint = long long;
// a and b is articulation point

int N, M, A, B;
vector<int> G[200005];
int vis[200005];
int low[200005];
int bridge[200005];
int mark[200005];
int cur;

int dfs(int n, int p) {
    cur++;
    low[n] = vis[n] = cur;
    int ch = 0;
    for (auto i : G[n]) if (i != p) {
        if (vis[i] == 0) {
            dfs(i, n);
            low[n] = min(low[n], low[i]);
            if (low[i] >= vis[n] && p != -1) {
                bridge[n] = 1;
            }
            ch++;
        } else {
            low[n] = min(low[n], vis[i]);
        }
    }
    if (p == -1 && ch > 1) {
        bridge[n] = 1;
    }
}

int color(int n, int p, int c) {
    if (n == A || n == B || mark[n] == c) {
        return 0;
    }
    mark[n] = c;
    for (auto i : G[n]) {
        color(i, n, c);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        cin >> N >> M >> A >> B;
        cur = 0;
        for (int i = 0; i <= N; i++) {
            G[i].clear();
            vector<int>().swap(G[i]);
            vis[i] = 0;
            low[i] = 0;
            bridge[i] = 0;
            mark[i] = 0;
        }
        for (int i = 0; i < M; i++) {
            int u, v;
            cin >> u >> v;
            G[u].emplace_back(v);
            G[v].emplace_back(u);
        }

        dfs(1, -1);
        if (bridge[A] == 1 && bridge[B] == 1) {
            for (auto j : G[A]) {
                color(j, -1, 1);
            }
            for (auto j : G[B]) {
                if (mark[j] == 1) {
                    color(j, -1, 3);
                } else if (mark[j] == 0) {
                    color(j, -1, 2);
                }
            }
            lint cnta = 0, cntb = 0;
            for (int i = 1; i <= N; i++) {
                if (mark[i] == 1) cnta++;
                if (mark[i] == 2) cntb++;
            }
            lint ans = 0;
            ans = 1ll * cnta * cntb;
            cout << ans << "\n";
        } else {
            cout << 0 << "\n";
        }
    }
}
/*
8 9 3 4
1 7
6 8
1 3
1 2
2 3
3 4
4 5
5 6   
4 6

*/