#include <algorithm>
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

// https://csacademy.com/blog/fast-fourier-transform-and-variations-of-it
namespace walsh_hadamard {
    bool is_power_of_two(int n) {
        return (n & (n - 1)) == 0;
    }

    int round_up_power_two(int n) {
        while (n & (n - 1))
            n = (n | (n - 1)) + 1;

        return max(n, 1);
    }

    template<typename T>
    void fwht_xor(int n, vector<T> &values, bool inverse = false) {
        assert(is_power_of_two(n));
        assert((int) values.size() >= n);

        for (int len = 1; len < n; len *= 2)
            for (int start = 0; start < n; start += 2 * len)
                for (int i = start; i < start + len; i++) {
                    T u = values[i];
                    const T &v = values[i + len];
                    values[i] = u + v;
                    values[i + len] = u - v;
                }

        if (inverse) {
            for (int i = 0; i < n; i++)
                values[i] /= n;
        }
    }

    // Warning: make sure to select the type `T_out` so that it can contain N^2 * max(left) * max(right).
    // One option is to use doubles and round at the end, since we are simply dividing by a power of two to finish.
    template<typename T_out, typename T_in>
    vector<T_out> xor_convolution(const vector<T_in> &_left, const vector<T_in> &_right, bool circular = false) {
        if (_left.empty() || _right.empty())
            return {};

        vector<T_out> left(_left.begin(), _left.end());
        vector<T_out> right(_right.begin(), _right.end());

        int n = left.size();
        int m = right.size();

        int output_size = circular ? round_up_power_two(max(n, m)) : n + m - 1;
        int N = round_up_power_two(output_size);
        left.resize(N, 0);
        right.resize(N, 0);

        if (left == right) {
            fwht_xor(N, left);
            right = left;
        } else {
            fwht_xor(N, left);
            fwht_xor(N, right);
        }

        for (int i = 0; i < N; i++)
            left[i] *= right[i];

        fwht_xor(N, left, true);
        left.resize(output_size);
        return left;
    }
}


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<string> table(N);

    for (string &row : table)
        cin >> row;

    vector<int> cost(1 << N, 0);

    for (int mask = 0; mask < 1 << N; mask++) {
        int count = __builtin_popcount(mask);
        cost[mask] = min(count, N - count);
    }

    vector<int> freq(1 << N, 0);

    for (int col = 0; col < M; col++) {
        int mask = 0;

        for (int i = 0; i < N; i++)
            mask |= (table[i][col] - '0') << i;

        freq[mask]++;
    }

    vector<int64_t> result = walsh_hadamard::xor_convolution<int64_t>(freq, cost, true);
    cout << *min_element(result.begin(), result.end()) << '\n';
}