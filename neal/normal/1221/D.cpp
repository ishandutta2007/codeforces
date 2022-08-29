#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const long long LL_INF = (long long) 2e18 + 5;

int N;
vector<long long> A, B;

void solve_case() {
    cin >> N;
    A.resize(N);
    B.resize(N);

    for (int i = 0; i < N; i++)
        cin >> A[i] >> B[i];

    vector<long long> dp = {0, B[0], 2 * B[0]};

    for (int i = 0; i + 1 < N; i++) {
        vector<long long> next_dp(3, LL_INF);

        for (int a = 0; a < 3; a++)
            for (int b = 0; b < 3; b++)
                if (A[i] + a != A[i + 1] + b)
                    next_dp[b] = min(next_dp[b], dp[a] + b * B[i + 1]);

        dp = next_dp;
    }

    cout << *min_element(dp.begin(), dp.end()) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}