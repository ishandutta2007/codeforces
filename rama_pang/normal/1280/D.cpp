#include <bits/stdc++.h>
#define int long long
using namespace std;
using lint = long long;
int solve();
int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }    
    return 0;
}

vector<int> G[3005];
int N, M;
int B[3005];
int W[3005];
int A[3005];

pair<int, int> dp[3005][3005]; 
int sz[3005];
// dp[n][k] = (ans in subtree n with k villages, 
// current amount of wasp in this node's village)

void dfs(int n = 0, int p = -1) {
    sz[n] = 1;
    dp[n][0] = {0, A[n]};
    
    for (const auto& i : G[n]) if (i != p) {
        dfs(i, n);
        for (int j = sz[i] - 1; j >= 0; j--) {
            dp[i][j + 1] = max(dp[i][j + 1], {dp[i][j].first + (dp[i][j].second > 0), 0});
        }
        
        for (int s = sz[i] + sz[n] - 1; s >= 0; s--) { // this is O(n ^ 2)
            pair<int, int> best = {-1, 0}; // T = current size of all. Claim: T ^ 2 + T * new + new ^2 <= (T + new) ^ 2
            for (int a = max(0ll, s - sz[i]); a <= min(s, sz[n] - 1); a++) { // So the total is O(|T| ^ 2)
                best = max(best, {dp[n][a].first + dp[i][s - a].first, dp[n][a].second + dp[i][s - a].second});
            }
            dp[n][s] = best;
        }
        sz[n] += sz[i];
    }
}

int solve() {
    cin >> N >> M;
    for (int i = 0; i <= N; i++) {
        for (int j = 0; j <= M; j++) {
            dp[i][j] = {0, 0};
        }
    }

    for (int i = 0; i < N; i++) {
        cin >> B[i];
        G[i].clear();
    }
    for (int i = 0; i < N; i++) {
        cin >> W[i];
        A[i] = W[i] - B[i];
    }

    for (int i = 1; i < N; i++) {
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    dfs();
    cout << dp[0][M - 1].first + (dp[0][M - 1].second > 0) << "\n";
}