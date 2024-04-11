#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

// Computes the radius of the longest palindrome centered at each element in O(n) total.
// Actual palindrome length is `2 * radius[i] + 1`.
template<typename T_string>
vector<int> odd_manacher(const T_string &pattern) {
    int n = pattern.size();
    vector<int> radius(n, 0);
    int loc = 0;

    for (int i = 1; i < n; i++) {
        if (i <= loc + radius[loc])
            radius[i] = min(radius[loc - (i - loc)], loc + radius[loc] - i);

        while (i - radius[i] > 0 && i + radius[i] < n - 1 && pattern[i - radius[i] - 1] == pattern[i + radius[i] + 1])
            radius[i]++;

        if (i + radius[i] > loc + radius[loc])
            loc = i;
    }

    return radius;
}

// Returns a vector `lengths` of size `2 * n + 1` where `lengths[i]` indicates a palindrome starting at
// `(i - lengths[i]) / 2` and ending at `(i + lengths[i]) / 2` (exact division).
template<typename T_string>
vector<int> combined_manacher(const T_string &pattern) {
    int n = pattern.size();
    T_string extended(2 * n + 1, 0);

    for (int i = 0; i < n; i++)
        extended[2 * i + 1] = pattern[i];

    return odd_manacher(extended);
}


void run_case() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> lengths = combined_manacher(S);
    int common = 0;

    while (2 * (common + 1) <= N && S[common] == S[N - 1 - common])
        common++;

    int prefix = 0, suffix = 0;

    for (int i = 0; i <= 2 * N; i++) {
        int start = (i - lengths[i]) / 2, end = (i + lengths[i]) / 2;
        int closer = min(start, N - end);

        if (closer <= common && 2 * closer + end - start > prefix + suffix) {
            prefix = start == closer ? end : closer;
            suffix = start == closer ? closer : N - start;
        }
    }

    cout << S.substr(0, prefix) + S.substr(N - suffix) << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}