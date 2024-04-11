#include <bits/stdc++.h>
using namespace std;
using lint = long long;

lint N;
pair<lint, lint> A[200005];
lint pref[200005];
lint INF = 1e16;
lint memo[200005][2];
lint cur_time = 0;
int ans[200005];

lint dp(lint n, int g) {
    if (N == n) {
        if (g == 1) return A[n].first;
        return INF;
    } else if (N < n) {
        return INF;
    } else if (memo[n][g] != -1) {
        return memo[n][g];
    }

    lint &res = memo[n][g];
    res = INF;

    if (g == 0) res = min(res, -A[n].first + dp(n + 2, 1));
    if (g == 1) {
        res = min(res, A[n].first + dp(n + 1, 0));
        res = min(res, dp(n + 1, 1));
    }

    return res;
}

void backtrack(lint n, int g) {
    if (N == n) {
        ans[A[n].second] = cur_time;
        return;
    }

    if (g == 0) {
        if (dp(n, g) == -A[n].first + dp(n + 2, 1)) {
            cur_time++;
            ans[A[n].second] = cur_time;
            ans[A[n + 1].second] = cur_time;
            backtrack(n + 2, 1);
            return;
        }
    }

    if (g == 1) {
        if (dp(n, g) == dp(n + 1, 1)) {
            ans[A[n].second] = cur_time;
            backtrack(n + 1, 1);
            return;
        }
        if (dp(n, g) == A[n].first + dp(n + 1, 0)) {
            ans[A[n].second] = cur_time;
            backtrack(n + 1, 0);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    memset(memo, -1, sizeof(memo));
    cin >> N;

    for (int i = 1; i <= N; i++) cin >> A[i].first;
    for (int i = 1; i <= N; i++) A[i].second = i, pref[i] = A[i].first + pref[i - 1];
    sort(A + 1, A + N + 1);
    lint res = dp(1, 0);
    backtrack(1, 0);
    cout << res << " " << cur_time << "\n";
    for (int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << "\n";
}