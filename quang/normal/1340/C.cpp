#include <bits/stdc++.h>

using namespace std;

const int N = 10010;
const int P = 2010;
const int INF = 1e9;

int n, m;
int d[N];
int g, r;
int dp[N][P];
bool used[N][P];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> d[i];
    }
    cin >> g >> r;
    sort(d + 1, d + m + 1);
    m = unique(d + 1, d + m + 1) - d - 1;
    for (int i = 1; i <= m; i++) {
        fill(dp[i], dp[i] + P, INF);
    }
    dp[1][0] = 0;
    deque<pair<int, int>> dq;
    dq.push_back({1, 0});
    while (!dq.empty()) {
        int u, t;
        tie(u, t) = dq.front();
        dq.pop_front();
        if (used[u][t]) continue;
        used[u][t] = 1;
        if (t < g) {
            if (u > 1) {
                int newT = t + d[u] - d[u - 1];
                if (newT <= g && dp[u - 1][newT] > dp[u][t]) {
                    dp[u - 1][newT] = dp[u][t];
                    dq.push_front({u - 1, newT});
                }
            }
            if (u < m) {
                int newT = t + d[u + 1] - d[u];
                if (newT <= g && dp[u + 1][newT] > dp[u][t]) {
                    dp[u + 1][newT] = dp[u][t];
                    dq.push_front({u + 1, newT});
                }
            }
        } else {
            if (dp[u][0] > dp[u][t] + 1) {
                dp[u][0] = dp[u][t] + 1;
                dq.push_back({u, 0});
            }
        }
    }
    long long res = 1e18;
    for (int i = 0; i <= g; i++) {
        if (used[m][i]) res = min(res, 1ll * dp[m][i] * (r + g) + i);
    }
    if (res >= INF) {
        cout << -1 << endl;
    } else cout << res << endl;
    return 0;
}