#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int largest_bit(int x) {
    return 31 - __builtin_clz(x);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<long long> A(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end());
    vector<long long> subset_sum(1 << N, 0);
    vector<bool> good_subset(1 << N, false);

    for (int mask = 1; mask < 1 << N; mask++) {
        int bit = __builtin_ctz(mask);
        subset_sum[mask] = subset_sum[mask - (1 << bit)] + A[bit];
        good_subset[mask] = __builtin_popcount(mask) == 1 && subset_sum[mask] == 0;
    }

    int X = 0.27 * N + 1;
    int Y = N - X;

    // Runtime is 3^Y * Y + 2^Y * 3^X * Y to compute `good_subset`.
    for (int y_mask = 0; y_mask < 1 << N; y_mask += 1 << X) {
        vector<long long> candidates;

        // Avoid the empty and full subsets.
        for (int sub = (y_mask - 1) & y_mask; sub != 0; sub = (sub - 1) & y_mask)
            candidates.push_back(subset_sum[y_mask] - 2 * subset_sum[sub]);

        sort(candidates.begin(), candidates.end());

        for (int x_mask = 0; x_mask < 1 << X; x_mask++) {
            int y_count = __builtin_popcount(y_mask);
            int count = __builtin_popcount(x_mask) + y_count;

            if ((subset_sum[x_mask | y_mask] + count) % 2 == 0)
                continue;

            for (int sub = x_mask; ; sub = (sub - 1) & x_mask) {
                long long current = subset_sum[x_mask] - 2 * subset_sum[sub];
                bool good = false;

                // Special cases to avoid the empty and full subsets.
                int sub_count = __builtin_popcount(sub);

                if (0 < sub_count && sub_count < count && abs(current + subset_sum[y_mask]) <= count - 1)
                    good = true;

                if (0 < sub_count + y_count && sub_count + y_count < count && abs(current - subset_sum[y_mask]) <= count - 1)
                    good = true;

                auto lower = lower_bound(candidates.begin(), candidates.end(), -current - (count - 1));
                auto upper = upper_bound(candidates.begin(), candidates.end(), -current + (count - 1));

                if (lower != upper)
                    good = true;

                if (good) {
                    good_subset[x_mask | y_mask] = true;
                    // cerr << (x_mask | y_mask) << " is good" << endl;
                    break;
                }

                if (sub == 0)
                    break;
            }
        }
    }

    // DP is still an optimized 3^N.
    vector<int8_t> dp(1 << N, 0);

    for (int mask = 1; mask < 1 << N; mask++) {
        dp[mask] = good_subset[mask];
        int smaller = mask - (1 << largest_bit(mask));

        for (int sub = smaller; sub != 0; sub = (sub - 1) & smaller)
            dp[mask] = max((int) dp[mask], dp[mask ^ sub] + dp[sub]);
    }

    cout << N - dp[(1 << N) - 1] << '\n';
}