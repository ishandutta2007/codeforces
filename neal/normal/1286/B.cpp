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
    // update(index, +1) is equivalent to insert(index); be careful not to double insert.
    // update(index, -1) is equivalent to erase(index); again, be careful not to double erase.
    // get(index) provides whether index is present or not.
    // query(index) provides the count of elements < index.
    // find_last_prefix(k) finds the k-th smallest element (0-indexed).
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


int N, ROOT;
vector<int> C;
vector<int> parent;
vector<vector<int>> children;
vector<int> subtree_size;

fenwick_tree<int> tree;
vector<int> answer;

void dfs(int node) {
    subtree_size[node] = 1;

    for (int child : children[node]) {
        dfs(child);
        subtree_size[node] += subtree_size[child];
    }
}

void build_ordering(int node, int start) {
    answer[node] = tree.find_last_prefix(tree.query(start) + C[node]);
    tree.update(answer[node], -1);

    for (int child : children[node]) {
        build_ordering(child, start);
        start += subtree_size[child];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N;
    parent.resize(N);
    C.resize(N);
    children.assign(N, {});
    ROOT = -1;

    for (int i = 0; i < N; i++) {
        cin >> parent[i] >> C[i];
        parent[i]--;

        if (parent[i] < 0)
            ROOT = i;
        else
            children[parent[i]].push_back(i);
    }

    subtree_size.resize(N);
    dfs(ROOT);

    for (int i = 0; i < N; i++)
        if (C[i] < 0 || C[i] > subtree_size[i] - 1) {
            cout << "NO" << '\n';
            return 0;
        }

    tree.init(N);
    tree.build(vector<int>(N, 1));
    answer.assign(N, -1);
    build_ordering(ROOT, 0);
    cout << "YES" << '\n';

    for (int i = 0; i < N; i++)
        cout << answer[i] + 1 << (i < N - 1 ? ' ' : '\n');
}