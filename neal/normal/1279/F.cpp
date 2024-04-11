#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, K, L;
vector<int> prefix_sums;

int get_sum(int start, int end) {
    return prefix_sums[end] - prefix_sums[start];
}

// Solve for the maximum score of changes with ties broken by min number of changes, when each change costs `cost`.
pair<int, int> cost_dp(int cost) {
    vector<pair<int, int>> dp(N + 1, {0, 0});

    for (int end = 1; end <= N; end++) {
        int start = max(end - L, 0);
        dp[end] = max(dp[end - 1], {dp[start].first + get_sum(start, end) - cost, dp[start].second - 1});
    }

    return {dp[N].first, -dp[N].second};
}

int solve(const vector<bool> &A) {
    prefix_sums.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_sums[i + 1] = prefix_sums[i] + A[i];

    // When each change costs C, find the minimum value of C that results in at most K changes.
    int low = 0, high = L;

    while (low < high) {
        int mid = (low + high) / 2;

        if (cost_dp(mid).second > K)
            low = mid + 1;
        else
            high = mid;
    }

    int answer = cost_dp(low).first + K * low;
    return prefix_sums[N] - answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string str;
    cin >> N >> K >> L >> str;
    vector<bool> A(N);

    for (int i = 0; i < N; i++)
        A[i] = isupper(str[i]);

    int answer = solve(A);

    for (int i = 0; i < N; i++)
        A[i] = !A[i];

    answer = min(answer, solve(A));
    cout << answer << '\n';
}