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

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    T tree_sum = 0;
    vector<T> tree;

    fenwick_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree_sum = 0;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    template<typename T_array>
    void build(const T_array &initial) {
        assert((int) initial.size() == tree_n);
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
        assert(count <= tree_n);
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

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


const int64_t INF64 = (int64_t) 2e18 + 5;

int N, M;
vector<int> A, P, B;
vector<int64_t> P_sum;
vector<vector<int>> locations;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    A.resize(N);
    P.resize(N);

    for (int &a : A)
        cin >> a;

    for (int &p : P)
        cin >> p;

    P_sum.assign(N + 1, 0);

    for (int i = 0; i < N; i++)
        P_sum[i + 1] = P_sum[i] + P[i];

    locations.assign(N + 1, {});

    for (int i = 0; i < N; i++)
        locations[A[i]].push_back(i);

    cin >> M;
    B.resize(M);

    for (int &b : B)
        cin >> b;

    vector<int64_t> dp(N + 1, INF64);
    dp[N] = 0;
    fenwick_tree<int64_t> p_tree(N);
    vector<int64_t> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = max(P[i], 0);

    p_tree.build(initial);
    vector<int> previous = {N};
    int highest = N;

    for (int b = M - 1; b >= 0; b--) {
        int current = B[b];

        while (highest > current) {
            for (int loc : locations[highest]) {
                int p = max(P[loc], 0);
                p_tree.update(loc, -p);
            }

            highest--;
        }

        vector<pair<int, int64_t>> options;

        for (int loc : previous)
            options.emplace_back(loc, dp[loc] + P_sum[loc] - p_tree.query(loc));

        int L = locations[current].size();
        int opt = (int) options.size() - 1;
        int64_t minimum = INF64;

        for (int i = L - 1; i >= 0; i--) {
            int loc = locations[current][i];

            while (opt >= 0 && loc < options[opt].first)
                minimum = min(minimum, options[opt--].second);

            dp[loc] = minimum - P_sum[loc + 1] + p_tree.query(loc + 1);
        }

        previous = locations[current];
    }

    int64_t best = INF64;

    for (int i = 0; i < N; i++)
        if (A[i] == B.front())
            best = min(best, dp[i] + P_sum[i]);

    if (best < INF64 / 2) {
        cout << "YES" << '\n';
        cout << best << '\n';
    } else {
        cout << "NO" << '\n';
    }
}