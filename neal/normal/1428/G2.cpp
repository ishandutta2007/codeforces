#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
template<typename T, size_t size> ostream& operator<<(ostream &os, const array<T, size> &arr) { os << '{'; string sep; for (const auto &x : arr) os << sep << x, sep = ", "; return os << '}'; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int INF = 1e9 + 5;

template<typename T, bool maximum_mode, T T_INF>
struct monotonic_RMQ {
    vector<pair<T, int>> values;
    int front = 0, current_index = 0;

    int size() const {
        return int(values.size()) - front;
    }

    static bool is_better(T a, T b) {
        return maximum_mode ? b < a : a < b;
    }

    int prev_add_index = -INF, prev_query_index = -INF;

    // Adds a value and returns its index.
    int add(const T &x, int index = -INF) {
        if (index == -INF)
            index = current_index++;

        assert(index >= prev_add_index);
        prev_add_index = index;

        while (size() > 0 && !is_better(values.back().first, x))
            values.pop_back();

        values.emplace_back(x, index);
        return index;
    }

    // Queries for the maximum (minimum) with index at least the given `index`. `index` must be non-decreasing.
    T query_index(int index) {
        assert(index >= prev_query_index);
        prev_query_index = index;

        while (size() > 0 && values[front].second < index)
            front++;

        if (size() == 0)
            return maximum_mode ? (is_signed<T>::value ? -T_INF : 0) : T_INF;

        return values[front].first;
    }

    // Warning: does not work when adding with custom indices.
    T query_count(int count) {
        return query_index(current_index - count);
    }

    // Returns whether or not the queue has a result for querying the given index.
    bool has_index(int index) const {
        return !values.empty() && values.back().second >= index;
    }

    bool has_count(int count) const {
        return has_index(current_index - count);
    }
};


const int64_t INF64 = int64_t(2e18) + 5;
const int DIGITS = 6;
const int N_MAX = 1e6;

int64_t F[DIGITS];
vector<int64_t> value(N_MAX, 0);

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int K;
    cin >> K;
    cin >> F[0] >> F[1] >> F[2] >> F[3] >> F[4] >> F[5];

    for (int n = 0; n < N_MAX; n++) {
        value[n] = 0;
        int x = n;

        for (int d = 0; d < DIGITS; d++) {
            int digit = x % 10;

            if (digit % 3 == 0)
                value[n] += (digit / 3) * F[d];

            x /= 10;
        }
    }

    vector<int64_t> dp = value;

    for (int d = DIGITS - 1; d >= 0; d--) {
        int p10 = 1;

        for (int i = 0; i < d; i++)
            p10 *= 10;

        int most = 3 * (K - 1);

        for (int mod = 0; mod < 3 * p10; mod++) {
            monotonic_RMQ<int64_t, true, INF64> rmq;

            for (int n = mod, index = 0; n < N_MAX; n += 3 * p10, index++) {
                rmq.add(dp[n] - index * F[d]);
                dp[n] = max(dp[n], rmq.query_count(most + 1) + index * F[d]);
            }
        }
    }

    int Q;
    cin >> Q;

    for (int q = 0; q < Q; q++) {
        int n;
        cin >> n;
        cout << dp[n] << '\n';
    }
}