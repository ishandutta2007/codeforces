#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


template<typename T>
struct RMQ {
    int n = 0, levels = 0;
    vector<T> values;
    vector<vector<int>> range_high;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    int max_index(int a, int b) const {
        return values[a] > values[b] ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        levels = largest_bit(n) + 1;
        range_high.resize(levels);

        for (int k = 0; k < levels; k++)
            range_high[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_high[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_high[k][i] = max_index(range_high[k - 1][i], range_high[k - 1][i + (1 << (k - 1))]);
    }

    int rmq_index(int a, int b) const {
        assert(a < b);
        int level = largest_bit(b - a);
        return max_index(range_high[level][a], range_high[level][b - (1 << level)]);
    }

    T rmq_value(int a, int b) const {
        return values[rmq_index(a, b)];
    }
};


int N;
long long A;
vector<long long> D, C, diff, ac_sum;
RMQ<long long> diff_rmq, ac_max_rmq, ac_min_rmq;

long long solve(int start, int end) {
    if (end - start <= 0)
        return 0;

    if (end - start == 1)
        return max(A - C[start], 0LL);

    int mid = diff_rmq.rmq_index(start, end - 1);
    long long answer = max(solve(start, mid + 1), solve(mid + 1, end));
    long long ac = ac_max_rmq.rmq_value(mid + 1, end + 1) + ac_min_rmq.rmq_value(start, mid + 1);
    answer = max(answer, ac - diff[mid]);
    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> A;
    D.resize(N);
    C.resize(N);

    for (int i = 0; i < N; i++)
        cin >> D[i] >> C[i];

    diff.resize(N - 1);

    for (int i = 0; i < N - 1; i++)
        diff[i] = (D[i + 1] - D[i]) * (D[i + 1] - D[i]);

    ac_sum.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        ac_sum[i + 1] = ac_sum[i] + A - C[i];

    diff_rmq.build(diff);
    ac_max_rmq.build(ac_sum);

    for (int i = 0; i <= N; i++)
        ac_sum[i] = -ac_sum[i];

    ac_min_rmq.build(ac_sum);
    cout << solve(0, N) << '\n';
}