#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
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

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = v.size();

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}

template<typename T, bool maximum_mode = false>
struct RMQ {
    int n = 0;
    vector<T> values;
    vector<vector<int>> range_low;

    RMQ(const vector<T> &_values = {}) {
        if (!_values.empty())
            build(_values);
    }

    static int largest_bit(int x) {
        return 31 - __builtin_clz(x);
    }

    // Note: when `values[a] == values[b]`, returns b.
    int better_index(int a, int b) const {
        return (maximum_mode ? values[b] < values[a] : values[a] < values[b]) ? a : b;
    }

    void build(const vector<T> &_values) {
        values = _values;
        n = values.size();
        int levels = largest_bit(n) + 1;
        range_low.resize(levels);

        for (int k = 0; k < levels; k++)
            range_low[k].resize(n - (1 << k) + 1);

        for (int i = 0; i < n; i++)
            range_low[0][i] = i;

        for (int k = 1; k < levels; k++)
            for (int i = 0; i <= n - (1 << k); i++)
                range_low[k][i] = better_index(range_low[k - 1][i], range_low[k - 1][i + (1 << (k - 1))]);
    }

    // Note: breaks ties by choosing the largest index.
    int query_index(int a, int b) const {
        assert(0 <= a && a < b && b <= n);
        int level = largest_bit(b - a);
        return better_index(range_low[level][a], range_low[level][b - (1 << level)]);
    }

    T query_value(int a, int b) const {
        return values[query_index(a, b)];
    }
};


struct range {
    int a, b, index;
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<range> ranges(N);

    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
        ranges[i].a = A[i];
        ranges[i].b = B[i];
        ranges[i].index = i;
    }

    sort(ranges.begin(), ranges.end(), [](const range &x, const range &y) {
        return x.a < y.a;
    });
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> order(N);
    vector<int> location(N + 1, -1);

    for (int x = 1, r = 0; x <= N; x++) {
        while (r < N && x >= ranges[r].a) {
            pq.emplace(ranges[r].b, ranges[r].index);
            r++;
        }

        pair<int, int> top = pq.top(); pq.pop();
        order[top.second] = x;
        location[x] = top.second;
    }

    dbg(order);
    dbg(location);
    vector<int> minimum(N + 1, 0);

    for (int x = 1; x <= N; x++)
        minimum[x] = A[location[x]];

    RMQ<int> rmq(minimum);

    for (int x = 1; x <= N; x++)
        if (B[location[x]] > x && rmq.query_value(x + 1, B[location[x]] + 1) <= x) {
            cout << "NO" << '\n';
            int y = rmq.query_index(x + 1, B[location[x]] + 1);
            output_vector(order);
            swap(order[location[x]], order[location[y]]);
            output_vector(order);
            return 0;
        }

    cout << "YES" << '\n';
    output_vector(order);
}