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

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    static int largest_bit(int x) {
        return x == 0 ? -1 : 31 - __builtin_clz(x);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert(int(initial.size()) == tree_n);
        tree_sum = 0;

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
        T sum = 0;

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
        if (sum < 0)
            return -1;

        int prefix = 0;

        for (int k = largest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    int64_t L, R;
    cin >> N >> M >> L >> R;
    int NM = max(N, M);
    vector<array<int, 4>> solution(N + 1, {-1, -1, -1, -1});
    vector<vector<int>> factor_list(NM + 1);

    for (int i = 1; i <= NM; i++)
        for (int j = i; j <= NM; j += i)
            factor_list[j].push_back(i);

    auto &&get_y_range = [&](int x) -> array<int64_t, 2> {
        int64_t y_low = max(INT64_C(1), (L + x - 1) / x);
        int64_t y_high = min(int64_t(M), R / x);
        return {y_low, y_high};
    };

    fenwick_tree<int> tree(M + 1);
    int start = 1, end = 1;

    for (int x = N; x > 0; x--) {
        array<int64_t, 2> y_range = get_y_range(x);

        if (y_range[0] > y_range[1])
            continue;

        while (end <= y_range[1]) {
            for (int f : factor_list[end])
                tree.update(f, +1);

            end++;
        }

        while (start < y_range[0]) {
            for (int f : factor_list[start])
                tree.update(f, -1);

            start++;
        }

        for (int f : factor_list[x]) {
            int yf = tree.find_last_prefix(tree.query(f + 1));

            if (yf <= int64_t(f) * N / x) {
                int y = y_range[0];

                if (y % yf != 0)
                    y += yf - y % yf;

                if (y_range[0] <= y && y <= y_range[1]) {
                    solution[x] = {x, y, x / f * yf, y / yf * f};
                    break;
                }
            }
        }
    }

    for (int x = 1; x <= N; x++)
        if (solution[x][0] < 0)
            cout << -1 << '\n';
        else
            cout << solution[x][0] << ' ' << solution[x][1] << ' ' << solution[x][2] << ' ' << solution[x][3] << '\n';
}