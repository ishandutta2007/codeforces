#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

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

    // Returns the largest i in [0, tree_n] such that query(i) <= sum. Returns -1 if no such i exists (sum < 0).
    // Can be used as an ordered set on indices in [0, tree_n) by using the tree as a 0/1 array:
    // update(index, +1) is equivalent to insert(index); be careful not to re-insert.
    // get(index) provides whether index is present or not.
    // query(index) provides the count of elements < index.
    // find_last_prefix(k) finds the k-th smallest element.
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


struct query {
    int k, pos, index;

    bool operator<(const query &other) const {
        return k < other.k;
    }
};

int N, M;
vector<int> A;
vector<pair<int, int>> sorted;
vector<query> queries;
vector<int> answers;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    A.resize(N);

    for (auto &a : A)
        cin >> a;

    for (int i = 0; i < N; i++)
        sorted.emplace_back(-A[i], i);

    sort(sorted.begin(), sorted.end());
    cin >> M;
    queries.resize(M);

    for (query &qry : queries) {
        cin >> qry.k >> qry.pos;
        qry.pos--;
    }

    for (int q = 0; q < M; q++)
        queries[q].index = q;

    sort(queries.begin(), queries.end());
    answers.resize(M);
    fenwick_tree<int> tree(N);
    int index = 0;

    for (query &qry : queries) {
        while (index < qry.k)
            tree.update(sorted[index++].second, +1);

        answers[qry.index] = A[tree.find_last_prefix(qry.pos)];
    }

    for (int q = 0; q < M; q++)
        cout << answers[q] << '\n';
}