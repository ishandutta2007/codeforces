#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

int N, MAX;
vector<int> A, prefix_sums;

int count_range(int a, int b) {
    return prefix_sums[b] - prefix_sums[a];
}

bool possible(int X, int Y, long long sum) {
    // Can we make two X's?
    if (A[0] < 2 * X && (N < 2 || A[1] < X))
        return false;

    if (sum < X)
        return false;

    if (sum - 2 * (X / Y + 1) >= X)
        return true;

    int above_mod = 0, below_mod = 0;
    int above_double = 0, below_double = 0;

    int X_mod_Y = X % Y;
    int X2_mod_Y = (2 * X) % Y;

    for (int start = 0, div = 0; start < MAX; start += Y, div++) {
        int end = start + Y;

        if (start >= X) {
            below_mod += count_range(start, start + X_mod_Y);
            above_mod += count_range(start + X_mod_Y, end);
        } else if (X < end) {
            above_mod += count_range(X, end);
        }

        if (start >= 2 * X) {
            below_double += count_range(start, start + X2_mod_Y);
            above_double += count_range(start + X2_mod_Y, end);
        } else if (2 * X < end) {
            above_double += count_range(2 * X, end);
        }
    }

    if (above_mod + below_mod >= 2) {
        long long single_sum = sum;

        above_mod = min(above_mod, 2);
        single_sum -= above_mod * (X / Y);

        below_mod = min(below_mod, 2 - above_mod);
        single_sum -= below_mod * (X / Y + 1);

        if (single_sum >= X)
            return true;
    }

    if (above_double > 0 || below_double > 0) {
        long long double_sum = sum;

        if (above_double > 0)
            double_sum -= (2 * X) / Y;
        else
            double_sum -= (2 * X) / Y + 1;

        if (double_sum >= X)
            return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    MAX = *max_element(A.begin(), A.end()) + 1;
    prefix_sums.assign(2 * MAX + 1, 0);

    for (int a : A)
        prefix_sums[a + 1]++;

    nth_element(A.begin(), A.begin() + 1, A.end(), greater<int>());

    for (int i = 0; i < 2 * MAX; i++)
        prefix_sums[i + 1] += prefix_sums[i];

    long long best = 0;

    for (int Y = 2; Y < MAX; Y++) {
        long long sum = 0;

        for (int start = 0, div = 0; start < MAX; start += Y, div++)
            sum += (long long) count_range(start, start + Y) * div;

        long long low = best / Y + 1, high = MAX;

        if (low > MAX || !possible(low, Y, sum))
            continue;

        while (low < high) {
            int mid = (low + high + 1) / 2;

            if (possible(mid, Y, sum))
                low = mid;
            else
                high = mid - 1;
        }

        if (low >= 2)
            best = max(best, (long long) Y * low);
    }

    cout << best << '\n';
}