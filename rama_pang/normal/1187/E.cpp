#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int N;
vector<int> G[200005];
lint DP[200005];
lint SZ[200005];

void computeDP(int n, int p) {
    SZ[n] = 1;
    for (auto i : G[n]) if (i != p) {
        computeDP(i, n);
        SZ[n] += SZ[i];
        DP[n] += DP[i];
    }
    DP[n] += SZ[n];
}

lint ans = 0;

void dfsReroot(int n, int p) {
    ans = max(ans, DP[n]);
    for (auto i : G[n]) if (i != p) {
        DP[n] -= DP[i];
        DP[n] -= SZ[i];
        SZ[n] -= SZ[i];
        DP[i] += SZ[n];
        DP[i] += DP[n];
        SZ[i] += SZ[n];

        dfsReroot(i, n);
        
        DP[i] -= DP[n];
        DP[i] -= SZ[n];
        SZ[i] -= SZ[n];
        DP[n] += SZ[i];
        DP[n] += DP[i];
        SZ[n] += SZ[i];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> N;
    for (int i = 1; i < N; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    computeDP(0, -1);
    dfsReroot(0, -1);
    cout << ans << "\n";

    return 0;
}