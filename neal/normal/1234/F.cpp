#include <algorithm>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

const int C = 20;

int N;
string S;
vector<int8_t> max_subset(1 << C, 0);

// For every mask, computes the max of values[sub] where sub is a submask of mask.
template<typename T_out, typename T_in>
vector<T_out> submask_max(int n, const vector<T_in> &values) {
    vector<T_out> dp(values.begin(), values.end());

    for (int bit = 0; bit < n; bit++)
        for (int mask = 0; mask < 1 << n; mask++)
            if (mask >> bit & 1)
                dp[mask] = max(dp[mask], dp[mask ^ 1 << bit]);

    return dp;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> S;
    N = S.size();

    for (int i = 0; i < N; i++) {
        int seen = 0;

        for (int j = i; j < N && (seen >> (S[j] - 'a') & 1) == 0; j++) {
            seen |= 1 << (S[j] - 'a');
            max_subset[seen] = __builtin_popcount(seen);
        }
    }

    max_subset = submask_max<int8_t>(C, max_subset);
    int best = 0;

    for (int mask = 0; mask < 1 << C; mask++)
        best = max(best, max_subset[mask] + max_subset[((1 << C) - 1) ^ mask]);

    cout << best << '\n';
}