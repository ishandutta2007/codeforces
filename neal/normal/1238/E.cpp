#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int M;
vector<vector<int>> occur;
vector<int> mask_sums;

void apply_subset_sums(int index) {
    vector<int> change(M, 0);
    int sum = 0;

    for (int i = 0; i < M; i++) {
        change[i] = occur[index][i] - sum;
        sum += occur[index][i];
    }

    sum = 0;

    for (int mask = 1; mask < 1 << M; mask++) {
        sum += change[__builtin_ctz(mask)];

        if ((mask >> index & 1) == 0)
            mask_sums[mask] += sum;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    string S;
    cin >> N >> M >> S;
    occur.assign(M, vector<int>(M, 0));

    for (int i = 0; i + 1 < N; i++) {
        int x = S[i] - 'a';
        int y = S[i + 1] - 'a';
        occur[x][y]++;
        occur[y][x]++;
    }

    mask_sums.assign(1 << M, 0);

    for (int i = 0; i < M; i++)
        apply_subset_sums(i);

    vector<int> dp(1 << M, INF);
    dp[0] = 0;

    for (int mask = 0; mask < 1 << M; mask++)
        for (int prefix = mask; prefix != 0; prefix &= prefix - 1) {
            int bit = __builtin_ctz(prefix);
            dp[mask] = min(dp[mask], dp[mask ^ 1 << bit] + mask_sums[mask]);
        }

    cout << dp[(1 << M) - 1] << '\n';
}