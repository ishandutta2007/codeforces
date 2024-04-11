#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// Enables online insertion of (key, value) pairs and querying of maximum value over keys less than a given limit.
// To query minimums instead, set maximum_mode = false.
template<typename T_key, typename T_value, T_value V_INF, bool maximum_mode = true>
struct online_prefix_max {
    map<T_key, T_value> optimal;

    static bool better(T_value a, T_value b) {
        return (a < b) ^ maximum_mode;
    }

    // Queries the maximum value in the map over all entries with key < `key_limit`.
    // TODO: when calling query, make sure to handle the empty case.
    T_value query(T_key key_limit) const {
        auto it = optimal.lower_bound(key_limit);

        if (it == optimal.begin())
            return maximum_mode ? (is_signed<T_value>::value ? -V_INF : 0) : V_INF;

        it--;
        return it->second;
    }

    // Adds an entry to the map and discards entries that are now obsolete.
    void insert(T_key key, T_value value) {
        auto it = optimal.lower_bound(key);

        // Quit if value is suboptimal.
        if (it != optimal.end() && it->first == key) {
            if (!better(value, it->second))
                return;
        } else if (it != optimal.begin()) {
            auto prev_it = it;
            prev_it--;

            if (!better(value, prev_it->second))
                return;
        }

        while (it != optimal.end() && !better(it->second, value))
            it = optimal.erase(it);

        optimal.insert(it, {key, value});
    }
};

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0, levels = 0;
    vector<vector<T>> range_min;

    RMQ(const vector<T> &values = {}) {
        if (!values.empty())
            build(values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    static T better(T a, T b) {
        return (a < b) ^ maximum_mode ? a : b;
    }

    void build(const vector<T> &values) {
        n = values.size();
        levels = largest_bit(n) + 1;
        range_min.resize(levels);

        for (int k = 0; k < levels; k++)
            range_min[k].resize(n - (1 << k) + 1);

        range_min[0] = values;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_min[k][i] = better(range_min[k - 1][i], range_min[k - 1][i + (1 << (k - 1))]);
    }

    T query(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better(range_min[level][a], range_min[level][b - (1 << level)]);
    }
};


const int INF = 1e9 + 5;

int N;
vector<int> A;
vector<int> over_double;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < 2 * N; i++)
        A.push_back(A[i]);

    over_double.assign(3 * N, -INF);
    online_prefix_max<int, int, INF> DS;

    for (int i = 0; i < 3 * N; i++) {
        over_double[i] = DS.query(-2 * A[i]);
        DS.insert(-A[i], i);
    }

    RMQ<int, true> rmq(over_double);

    for (int i = 0; i < N; i++) {
        int low = 1, high = 2 * N;

        while (low < high) {
            int mid = (low + high) / 2;

            if (rmq.query(i, i + mid + 1) >= i)
                high = mid;
            else
                low = mid + 1;
        }

        cout << (low < 2 * N ? low : -1) << (i < N - 1 ? ' ' : '\n');
    }
}