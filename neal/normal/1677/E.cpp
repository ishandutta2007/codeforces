#include <algorithm>
#include <array>
#include <bitset>
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

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }


template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

template<typename T>
struct fenwick_tree {
    static int highest_bit(unsigned x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    int tree_n = 0;
    T tree_sum = T();
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = T();
        tree.assign(tree_n + 1, T());
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        tree_sum = T();

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];
            tree_sum += initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);
        tree_sum += change;

        for (int i = index + 1; i <= tree_n; i += i & -i)
            tree[i] += change;
    }

    // Returns the sum of the range [0, count).
    T query(int count) const {
        count = min(count, tree_n);
        T sum = T();

        for (int i = count; i > 0; i -= i & -i)
            sum += tree[i];

        return sum;
    }

    // Returns the sum of the range [start, tree_n).
    T query_suffix(int start) const {
        return tree_sum - query(start);
    }

    // Returns the sum of the range [a, b).
    T query(int a, int b) const {
        return query(b) - query(a);
    }

    // Returns the element at index a in O(1) amortized across every index. Equivalent to query(a, a + 1).
    T get(int a) const {
        assert(0 <= a && a < tree_n);
        int above = a + 1;
        T sum = tree[above];
        above -= above & -above;

        while (a != above) {
            sum -= tree[a];
            a -= a & -a;
        }

        return sum;
    }

    bool set(int index, T value) {
        assert(0 <= index && index < tree_n);
        T current = get(index);

        if (current == value)
            return false;

        update(index, value - current);
        return true;
    }

    // Returns the largest p in `[0, tree_n]` such that `query(p) <= sum`. Returns -1 if no such p exists (`sum < 0`).
    // Can be used as an ordered set/multiset on indices in `[0, tree_n)` by using the tree as a 0/1 or frequency array:
    // `set(index, 1)` is equivalent to insert(index). `update(index, +1)` is equivalent to multiset.insert(index).
    // `set(index, 0)` or `update(index, -1)` are equivalent to erase(index).
    // `get(index)` provides whether index is present or not, or the count of index (if multiset).
    // `query(index)` provides the count of elements < index.
    // `find_last_prefix(k)` finds the k-th smallest element (0-indexed). Returns `tree_n` for `sum >= set.size()`.
    int find_last_prefix(T sum) const {
        if (sum < T())
            return -1;

        int prefix = 0;

        for (int k = highest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};

// For every i, finds the largest j < i such that `compare(values[j], values[i])` is true, or -1 if no such j exists.
template<typename T, typename T_compare>
vector<int> closest_left(const vector<T> &values, T_compare &&compare) {
    int n = int(values.size());
    vector<int> closest(n);
    vector<int> stack;

    for (int i = 0; i < n; i++) {
        while (!stack.empty() && !compare(values[stack.back()], values[i]))
            stack.pop_back();

        closest[i] = stack.empty() ? -1 : stack.back();
        stack.push_back(i);
    }

    return closest;
}

// For every i, finds the smallest j > i such that `compare(values[j], values[i])` is true, or `n` if no such j exists.
template<typename T, typename T_compare>
vector<int> closest_right(const vector<T> &values, T_compare &&compare) {
    int n = int(values.size());
    vector<int> closest(n);
    vector<int> stack;

    for (int i = n - 1; i >= 0; i--) {
        while (!stack.empty() && !compare(values[stack.back()], values[i]))
            stack.pop_back();

        closest[i] = stack.empty() ? n : stack.back();
        stack.push_back(i);
    }

    return closest;
}


bool contains(array<int, 2> a, array<int, 2> b) {
    return a[0] <= b[0] && b[1] <= a[1];
}

struct interval_end {
    int end, value;

    interval_end() {}

    interval_end(int _end, int _value) : end(_end), value(_value) {}
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<vector<int>> smaller_factors(N + 1);

    for (int x = 1; x <= N; x++)
        for (int64_t y = int64_t(x) * (x + 1); y <= N; y += x)
            smaller_factors[y].push_back(x);

    vector<int> P(N);

    for (auto &p : P)
        cin >> p;

    vector<int> where(N + 1, -1);

    for (int i = 0; i < N; i++)
        where[P[i]] = i;

    vector<int> left = closest_left(P, greater<int>());
    vector<int> right = closest_right(P, greater<int>());

    for (auto &l : left)
        l++;

    vector<vector<interval_end>> intervals(N);

    auto add_interval = [&](int start, int end, int value) -> void {
        intervals[start].emplace_back(end, value);
    };

    for (int i = 0; i < N; i++) {
        int value = P[i];
        vector<array<int, 2>> choices;

        for (int x : smaller_factors[value]) {
            int y = value / x;
            assert(x < y);
            int first = where[x], second = where[y];

            if (first > second)
                swap(first, second);

            first = min(first, i);
            second = max(second, i) + 1;

            if (left[i] <= first && second <= right[i])
                choices.push_back({first, second});
        }

        sort(choices.begin(), choices.end(), [](array<int, 2> a, array<int, 2> b) -> bool {
            if (a[0] != b[0])
                return a[0] > b[0];

            return a[1] < b[1];
        });

        vector<array<int, 2>> nchoices;

        for (auto &choice : choices)
            if (nchoices.empty() || !contains(choice, nchoices.back()))
                nchoices.push_back(choice);

        reverse(nchoices.begin(), nchoices.end());
        choices.swap(nchoices);
        nchoices.clear();

        if (choices.empty())
            continue;

        int C = int(choices.size());

        for (auto &choice : choices)
            add_interval(choice[0], choice[1], +1);

        // Remove overlap
        for (int c = 0; c < C - 1; c++)
            add_interval(choices[c][0], choices[c + 1][1], -1);

        // Remove intervals where P[i] isn't the max
        if (left[i] > 0)
            add_interval(left[i] - 1, choices.front()[1], -1);

        if (right[i] < N)
            add_interval(choices.back()[0], right[i] + 1, -1);

        if (left[i] > 0 && right[i] < N)
            add_interval(left[i] - 1, right[i] + 1, +1);

        // Now the answer for a query (L, R) is the sum over every interval (X, Y) such that L <= X <= Y <= R of
        // (X - L + 1) * (R - Y + 1) * interval_value
    }

    vector<vector<interval_end>> queries(N);

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--;
        queries[L].emplace_back(R, q);
    }

    fenwick_tree<int64_t> tree_1(N), tree_L(N), tree_R(N);
    fenwick_tree<int> tree_LR(N);
    vector<int64_t> answers(Q, 0);

    for (int i = N - 1; i >= 0; i--) {
        int X = i;

        for (interval_end &inter : intervals[i]) {
            int Y = inter.end;
            tree_1.update(Y - 1, int64_t(1 + X) * (1 - Y) * inter.value);
            tree_L.update(Y - 1, (Y - 1) * inter.value);
            tree_R.update(Y - 1, (X + 1) * inter.value);
            tree_LR.update(Y - 1, -1 * inter.value);
        }

        int L = i;

        for (interval_end &qry : queries[i]) {
            int R = qry.end;
            answers[qry.value] = tree_1.query(R) + tree_L.query(R) * L + tree_R.query(R) * R + int64_t(tree_LR.query(R)) * L * R;
        }
    }

    for (auto &ans : answers)
        cout << ans << '\n';
}