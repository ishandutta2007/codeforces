#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

void solve_case() {
    string S;
    cin >> S;
    int N = S.size();
    vector<int> prefix_sums(N + 1, 0);
    const int longest = 32 - __builtin_clz(N);

    for (int i = 0; i < N; i++)
        prefix_sums[i + 1] = prefix_sums[i] + (S[i] - '0');

    auto &&get_sum = [&](int start, int end) {
        return prefix_sums[end] - prefix_sums[start];
    };

    int total = 0;

    for (int end = 0; end < N; end++) {
        int value = 0;

        for (int i = end; i >= 0 && i > end - longest; i--) {
            value += (S[i] - '0') << (end - i);
            int start = end + 1 - value;

            if (S[i] == '1' && start >= 0 && get_sum(start, i) == 0)
                total++;
        }
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T-- > 0)
        solve_case();
}