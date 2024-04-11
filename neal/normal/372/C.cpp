// Solution to https://codeforces.com/contest/372/problem/C
#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
using namespace std;

// Note: make sure T can handle sums of values, not just individual values.
template<typename T>
struct convex_piecewise_linear {
    priority_queue<T> negative;
    priority_queue<T, vector<T>, greater<T>> positive;
    T neg_offset = 0, pos_offset = 0, minimum = 0;

    T get_min() const {
        return minimum;
    }

    // Equivalent to dp[x] = min(dp[x], ..., dp[x + shift]).
    void expand_negative(T shift) {
        neg_offset -= shift;
    }

    // Equivalent to dp[x] = min(dp[x - shift], ..., dp[x]).
    void expand_positive(T shift) {
        pos_offset += shift;
    }

    // Equivalent to dp[x] = min(dp[x - shift], ..., dp[x + shift]).
    void expand_both(T shift) {
        expand_negative(shift);
        expand_positive(shift);
    }

    // Equivalent to dp[x] += max(a - x, 0).
    void add_negative(T a) {
        if (positive.empty() || a <= positive.top() + pos_offset) {
            negative.push(a - neg_offset);
            return;
        }

        T pos_start = positive.top() + pos_offset;
        minimum += a - pos_start;
        negative.push(pos_start - neg_offset);
        positive.pop();
        positive.push(a - pos_offset);
    };

    // Equivalent to dp[x] += max(x - a, 0).
    void add_positive(T a) {
        if (negative.empty() || a >= negative.top() + neg_offset) {
            positive.push(a - pos_offset);
            return;
        }

        T neg_start = negative.top() + neg_offset;
        minimum += neg_start - a;
        positive.push(neg_start - pos_offset);
        negative.pop();
        negative.push(a - neg_offset);
    };

    // Equivalent to dp[x] += abs(x - a).
    void add_abs(T a) {
        add_negative(a);
        add_positive(a);
    }
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int64_t _, M, D;
    cin >> _ >> M >> D;
    int64_t B_sum = 0, prev_t = 1;
    convex_piecewise_linear<int64_t> dp;

    for (int64_t f = 0; f < M; f++) {
        int64_t a, b, t;
        cin >> a >> b >> t;
        a--;
        B_sum += b;
        dp.expand_both((t - prev_t) * D);
        dp.add_abs(a);
        prev_t = t;
    }

    cout << B_sum - dp.get_min() << '\n';
}