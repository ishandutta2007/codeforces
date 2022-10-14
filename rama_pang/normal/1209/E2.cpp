#include <bits/stdc++.h>
using namespace std;

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> A(N, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> A[i][j];
        }
    }

    vector<pair<int, int>> use;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            use.emplace_back(A[i][j], j);
        }
    }
    sort(use.begin(), use.end());
    reverse(use.begin(), use.end());

    vector<int> used(M);
    int cnt = 0;
    for (int i = 0; i < N * M; i++) {
        if (used[use[i].second]) continue;
        used[use[i].second] = 1;
        cnt++;
        if (cnt == N) break;
    }

    vector<int> DP(1 << N);
    DP[0] = 0;
    for (int j = 0; j < M; j++) {
        if (!used[j]) {
            continue;
        }

        vector<int> cost(1 << N, -1);
        for (int shift = 0; shift < N; shift++) {
            for (int mask = 0; mask < (1 << N); mask++) {
                int sum = 0;
                for (int i = 0; i < N; i++) {
                    if (mask & (1 << i)) {
                        sum += A[(i + shift) % N][j];
                    }
                }
                cost[mask] = max(cost[mask], sum);
            }
        }

        for (int mask = (1 << N) - 1; mask >= 0; mask--) {
            int inv = ((1 << N) - 1) - mask;
            int nxt = inv;
            while (nxt > 0) {
                DP[mask | nxt] = max(DP[mask | nxt], DP[mask] + cost[nxt]);
                nxt = (nxt - 1) & inv;
            }
        }
    }

    cout << DP[(1 << N) - 1] << "\n";

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int t; cin >> t;
    while (t--) solve();

}