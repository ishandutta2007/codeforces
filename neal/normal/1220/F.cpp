#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    int better_index(int a, int b) const {
        return (values[a] < values[b]) ^ maximum_mode ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        levels = largest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};


int N;
vector<int> A;
RMQ<int> rmq;

int evaluate(int start, int end) {
    if (start >= end)
        return 0;

    int minimum = rmq.query_index(start, end);
    return 1 + max(evaluate(start, minimum), evaluate(minimum + 1, end));
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (int &a : A)
        cin >> a;

    int one = find(A.begin(), A.end(), 1) - A.begin();
    rotate(A.begin(), find(A.begin(), A.end(), 1), A.end());

    for (int i = 0; i < N; i++)
        A.push_back(A[i]);

    rmq.build(A);
    int low = 0, high = N - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (evaluate(N - mid, N + 1) < evaluate(N, 2 * N - mid))
            low = mid + 1;
        else
            high = mid;
    }

    int best = evaluate(N - low, 2 * N - low);
    int start = (N - low + one) % N;
    cout << best << ' ' << start << '\n';
}