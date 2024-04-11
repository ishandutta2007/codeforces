#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <random>
#include <vector>
using namespace std;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));

int N, M;
vector<vector<int>> A;

void solve_case() {
    cin >> N >> M;
    A.assign(M, vector<int>(N));

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> A[j][i];

    shuffle(A.begin(), A.end(), rng);
    stable_sort(A.begin(), A.end(), [&](const vector<int> &x, const vector<int> &y) {
        return *max_element(x.begin(), x.end()) > *max_element(y.begin(), y.end());
    });

    M = min(N, M);
    A.resize(M);
    vector<int> dp(1 << N, 0), next_dp(1 << N, 0), max_sum(1 << N, 0);

    for (vector<int> &row : A) {
        next_dp = dp;
        max_sum.assign(1 << N, 0);

        for (int i = 0; i < N; i++)
            row.push_back(row[i]);

        for (int mask = 0; mask < 1 << N; mask++)
            for (int offset = 0; offset < N; offset++) {
                int sum = 0;

                for (int i = 0; i < N; i++)
                    if (mask >> i & 1)
                        sum += row[offset + i];

                max_sum[mask] = max(max_sum[mask], sum);
            }

        for (int mask = 0; mask < 1 << N; mask++) {
            int other = ((1 << N) - 1) ^ mask;

            for (int sub = other; sub != 0; sub = (sub - 1) & other)
                next_dp[mask | sub] = max(next_dp[mask | sub], dp[mask] + max_sum[sub]);
        }

        dp = next_dp;
    }

    cout << dp[(1 << N) - 1] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}