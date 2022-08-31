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
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    static int highest_bit(int x) {
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

        for (int k = highest_bit(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};

template<typename T>
struct query {
    int start, end, index;
    T value;

    query() : start(-1), end(-1), index(-1) {}

    query(int _start, int _end, T _value) : start(_start), end(_end), index(-1), value(_value) {}

    bool operator<(const query &other) const {
        return value < other.value;
    }
};

template<typename T>
vector<int> solve_count_less_than(const vector<T> &A, vector<query<T>> queries) {
    int n = int(A.size()), Q = int(queries.size());
    vector<pair<T, int>> sorted(n);

    for (int i = 0; i < n; i++)
        sorted[i] = {A[i], i};

    sort(sorted.begin(), sorted.end(), [&](const pair<T, int> &x, const pair<T, int> &y) {
        return x.first < y.first;
    });

    for (int q = 0; q < Q; q++)
        queries[q].index = q;

    sort(queries.begin(), queries.end());
    fenwick_tree<int> tree(n);
    vector<int> answers(Q, 0);
    int s = 0;

    for (query<T> &qry : queries) {
        while (s < n && sorted[s].first < qry.value)
            tree.update(sorted[s++].second, +1);

        answers[qry.index] = tree.query(qry.start, qry.end);
    }

    return answers;
}


const int BITS = 18;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<int> C(N);

    for (auto &c : C) {
        cin >> c;
        c--;
    }

    sort(C.begin(), C.end());
    vector<int> prefix_xor(N + 1, 0);

    for (int i = 0; i < N; i++)
        prefix_xor[i + 1] = prefix_xor[i] ^ C[i];

    int Q;
    cin >> Q;
    vector<array<int, 2>> queries(Q);
    vector<array<int, 2>> query_lb(Q);
    vector<int> answers(Q, 0);

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--;
        int start = int(lower_bound(C.begin(), C.end(), L) - C.begin());
        int end = int(lower_bound(C.begin(), C.end(), R) - C.begin());
        queries[q] = {L, R};
        query_lb[q] = {start, end};
        answers[q] = prefix_xor[start] ^ prefix_xor[end];

        for (int b = 0; b < BITS; b++)
            if ((L >> b & 1) && (end - start) % 2 != 0)
                answers[q] ^= 1 << b;
    }

    for (int b = 0; b < BITS; b++) {
        vector<int> CB(N);
        int full = (1 << b) - 1;

        for (int i = 0; i < N; i++)
            CB[i] = C[i] & full;

        vector<query<int>> count_queries(Q);

        for (int q = 0; q < Q; q++) {
            int L = queries[q][0];
            count_queries[q] = query<int>(query_lb[q][0], query_lb[q][1], L & full);
        }

        vector<int> counts = solve_count_less_than(CB, count_queries);

        for (int q = 0; q < Q; q++)
            if (counts[q] % 2 != 0)
                answers[q] ^= 1 << b;
    }

    for (int q = 0; q < Q; q++)
        cout << (answers[q] != 0 ? 'A' : 'B');

    cout << '\n';
}