#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N, C;
vector<int> A, B;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> C;
    A.resize(N - 1);
    B.resize(N - 1);

    for (auto &a : A)
        cin >> a;

    for (auto &b : B)
        cin >> b;

    vector<int> dp(N, INF);
    dp[0] = 0;

    int a_sum = 0, b_sum = 0;
    int min_dp_a = INF, min_dp_b = INF;

    for (int i = 1; i < N; i++) {
        min_dp_a = min(min_dp_a, dp[i - 1] - a_sum);
        min_dp_b = min(min_dp_b, dp[i - 1] - b_sum);
        a_sum += A[i - 1];
        b_sum += B[i - 1];
        dp[i] = min(a_sum + min_dp_a, b_sum + min_dp_b + C);
    }

    for (int i = 0; i < N; i++)
        cout << dp[i] << (i < N - 1 ? ' ' : '\n');
}