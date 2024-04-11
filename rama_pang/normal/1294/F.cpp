#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> G[200005];
int DP[200005][5];

vector<int> opt[200005][5];

void dfs(int n, int p) {
    DP[n][1] = 0;
    DP[n][2] = -1e9;
    DP[n][3] = -1e9;

    opt[n][1] = {n};
    opt[n][2] = {-1, -1};
    opt[n][3] = {-1, -1, -1};
    
    for (auto &i : G[n]) if (i != p) {
        dfs(i, n);

        if (DP[n][3] < DP[n][2] + DP[i][1] + 1) {
            DP[n][3] = max(DP[n][3], DP[n][2] + DP[i][1] + 1);
            opt[n][3] = opt[n][2];
            opt[n][3].push_back(opt[i][1][0]);
        }

        if (DP[n][3] < DP[n][1] + DP[i][2] + 1) {
            DP[n][3] = max(DP[n][3], DP[n][1] + DP[i][2] + 1);
            opt[n][3] = opt[i][2];
            opt[n][3].push_back(opt[n][1][0]);
        }

        if (DP[n][2] < DP[n][1] + DP[i][1] + 1) {
            DP[n][2] = max(DP[n][2], DP[n][1] + DP[i][1] + 1);
            opt[n][2] = opt[n][1];
            opt[n][2].push_back(opt[i][1][0]);
        }

        if (DP[n][1] < DP[i][1] + 1) {
            DP[n][1] = max(DP[n][1], DP[i][1] + 1);
            opt[n][1] = opt[i][1];
        }

        if (DP[n][2] < DP[i][2] + 1) {
            DP[n][2] = max(DP[n][2], DP[i][2] + 1);
            opt[n][2] = opt[i][2];
        }
    }
    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 0; i + 1 < N; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    dfs(0, -1);
    int ans = 0;
    vector<int> a;
    for (int i = 0; i < N; i++) {
        if (ans < DP[i][3]) {
            ans = max(ans, DP[i][3]);
            a = opt[i][3];
        }
    }
    cout << ans << "\n";
    cout << a[0] + 1 << " " << a[1] + 1 << " " << a[2] + 1 << "\n";
    return 0;
}