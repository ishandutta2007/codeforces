#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
struct monotonic_rmq {
    deque<pair<T, int>> values;
    int current_index;
    bool maximum_mode;

    monotonic_rmq(bool _maximum_mode) : current_index(0), maximum_mode(_maximum_mode) {}

    bool compare(const T &a, const T &b) {
        return (a < b) ^ maximum_mode;
    }

    int add(const T &x) {
        while (!values.empty() && !compare(values.back().first, x))
            values.pop_back();

        values.emplace_back(x, current_index);
        return current_index++;
    }

    T query(int index) {
        while (values.front().second < index)
            values.pop_front();

        assert(!values.empty());
        return values.front().first;
    }
};


const long long LL_INF = (long long) 2e18 + 5;

int N, K, X;
vector<int> pictures;

int main() {
    scanf("%d %d %d", &N, &K, &X);
    pictures.resize(N + 1);

    for (int i = 1; i <= N; i++)
        scanf("%d", &pictures[i]);

    vector<long long> dp(N + 1, -LL_INF);
    dp[0] = 0;

    for (int x = 0; x < X; x++) {
        vector<long long> next_dp(N + 1, -LL_INF);
        monotonic_rmq<long long> rmq(true);
        rmq.add(dp[0]);

        for (int i = 1; i <= N; i++) {
            next_dp[i] = rmq.query(i - K) + pictures[i];
            rmq.add(dp[i]);
        }

        swap(dp, next_dp);
    }

    long long best = -LL_INF;

    for (int i = N - (K - 1); i <= N; i++)
        best = max(best, dp[i]);

    printf("%lld\n", best < 0 ? -1 : best);
}