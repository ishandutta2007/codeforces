#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

int N;
vector<int> A;
vector<vector<int>> reduce;

// Gets the end of the range starting at `start` that can be reduced to the single value `value`, or -1 if impossible.
int get_reduce(int start, int value) {
    if (start >= N)
        return -1;

    int offset = value - A[start];

    if (offset < 0 || offset >= (int) reduce[start].size())
        return -1;

    return reduce[start][offset];
}

int main() {
    cin >> N;
    A.resize(N);
    reduce.assign(N + 1, {});

    for (int &a : A)
        cin >> a;

    for (int start = N - 1; start >= 0; start--) {
        reduce[start] = {start + 1};
        int next = A[start];

        while (get_reduce(reduce[start].back(), next) >= 0) {
            reduce[start].push_back(get_reduce(reduce[start].back(), next));
            next++;
        }
    }

    // `reduce_total` is O(N log N).
    int reduce_total = 0;

    for (int start = 0; start < N; start++)
        reduce_total += reduce[start].size();

    int max_reduce = 0;

    for (int length = 1; length <= N; length *= 2)
        max_reduce += N - length + 1;

    assert(reduce_total <= max_reduce);

    vector<int> dp(N + 1, INF);
    dp[0] = 0;

    for (int start = 0; start < N; start++)
        for (int end : reduce[start])
            dp[end] = min(dp[end], dp[start] + 1);

    cout << dp[N] << '\n';
}