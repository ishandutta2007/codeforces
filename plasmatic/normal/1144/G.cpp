// ./g-two-merged-sequences.yml
#include "bits/stdc++.h"
using namespace std;
using ll = long long;
const ll INF = 0x3f3f3f3f, LLINF = 0x3f3f3f3f3f3f3f3f;
using pii = pair<int, int>;

const int MN = 2e5 + 1;
int N,
    dp[2][MN], A[MN];
pii par[2][MN];
// dp[0][i] -> increasing sequence, max value of dec.
// dp[1][i] -> decreasing sequence, min value of inc.

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (auto i = 1; i <= N; i++) {
        cin >> A[i];
    }

    fill(dp[0], dp[0]+N+1, -INF);
    fill(dp[1], dp[1]+N+1, INF);
    dp[0][0] = INF;
    dp[1][0] = -INF;
    auto push = [&] (int t, int i, int v, int pt, int pi) {
        if ((t == 0 && v > dp[t][i]) || (t == 1 && v < dp[t][i])){
            dp[t][i] = v;
            par[t][i] = {pt, pi};
        }
    };
    for (auto i = 0; i < N; i++) {
        // trans from dp0 (inc)
        if (i == 0 || A[i] < A[i+1])
            push(0, i+1, dp[0][i], 0, i);
        if (dp[0][i] > A[i+1])
            push(1, i+1, i == 0 ? -INF : A[i], 0, i);
        // trans from dp1 (dec)
        if (i == 0 || A[i] > A[i+1])
            push(1, i+1, dp[1][i], 1, i);
        if (dp[1][i] < A[i+1])
            push(0, i+1, i == 0 ? INF : A[i], 1, i);
    }

    // output
    auto output = [&] (int t, int i) {
        vector<bool> ans(N);
        while (i > 0) {
            auto [pt, pi] = par[t][i];
            ans[i-1] = t;
            t = pt;
            i = pi;
        }
        cout << "YES\n";
        for (auto i = 0; i < N; i++) cout << ans[i] << ' ';
        cout << '\n';
    };
    if (dp[0][N] != -INF) output(0, N);
    else if (dp[1][N] != INF) output(1, N);
    else cout << "NO\n";

    return 0;
}