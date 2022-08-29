#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K;
    cin >> N >> K;
    vector<uint8_t> dp(K, false);
    dp[0] = true;
    int64_t sum = 0;

    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        sum += a + b;
        vector<uint8_t> next_dp(K, false);

        auto &&add_shift = [&](int shift) {
            shift %= K;

            for (int x = 0; x < K; x++) {
                int add = x + shift < K ? x + shift : x + shift - K;
                next_dp[add] |= dp[x];
            }
        };

        add_shift(a);
        int low = a - min(a, K - 1);
        int high = a - max(K - b, 0);

        if (low <= high) {
            int subtract = low / K;
            low -= subtract * K;
            high -= subtract * K;
            assert(0 <= low && low <= high && high < 2 * K);
            dp.resize(3 * K);

            for (int x = 0; x < K; x++)
                dp[K + x] = dp[2 * K + x] = dp[x];

            vector<int> partial_sum(3 * K + 1, 0);

            for (int x = 0; x < 3 * K; x++)
                partial_sum[x + 1] = partial_sum[x] + dp[x];

            for (int x = 2 * K; x < 3 * K; x++)
                next_dp[x - 2 * K] |= partial_sum[x - low + 1] - partial_sum[x - high] > 0;
        }

        dp = next_dp;
    }

    int64_t answer = 0;

    for (int x = 0; x < K; x++)
        if (dp[x])
            answer = max(answer, (sum - x) / K);

    cout << answer << '\n';
}