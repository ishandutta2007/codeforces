// ./e-cheap-dinner.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;

const int MN = 150001;
int N[4], M[4], A[4][MN];
vector<int> g[4][MN];

ll dp[4][MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    for (auto i = 0; i < 4; i++) {
        cin >> N[i];
    }
    for (auto i = 0; i < 4; i++)
        for (auto j = 1; j <= N[i]; j++)
            cin >> A[i][j];
    for (auto i = 1; i < 4; i++) {
        cin >> M[i];
        for (auto j = 0; j < M[i]; j++) {
            int a, b; cin >> a >> b;
            g[i][b].push_back(a);
        }
    }

    memset(dp, 0x3f, sizeof dp);
    for (auto i = 1; i <= N[0]; i++)
        dp[0][i] = A[0][i];
    for (auto i = 1; i < 4; i++) {
        set<pair<ll, int>> pre;
        for (auto j = 1; j <= N[i-1]; j++)
            pre.emplace(dp[i-1][j], j);

        for (auto j = 1; j <= N[i]; j++) {
            for (auto to : g[i][j])
                pre.erase({dp[i-1][to], to});
            if (!pre.empty())
                dp[i][j] = pre.begin()->first + A[i][j];
            for (auto to : g[i][j])
                pre.emplace(dp[i-1][to], to);
        }
    }

    ll ans = LLINF;
    for (auto i = 1; i <= N[3]; i++) ans = min(ans, dp[3][i]);
    cout << (ans == LLINF ? -1 : ans) << '\n';

    return 0;
}