#include <algorithm>
#include <cassert>
#include <chrono>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct safe_hash32 {
    static unsigned hash32(unsigned x) {
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        x = (x ^ (x >> 16)) * 0x45d9f3b;
        return x ^ (x >> 16);
    }

    size_t operator()(unsigned x) const {
        static const unsigned FIXED_RANDOM = hash32(
            chrono::steady_clock::now().time_since_epoch().count() * ((uint64_t) new char | 1));
        return hash32(x ^ FIXED_RANDOM);
    }
};

template<typename T>
struct fenwick_tree {
    int tree_n = 0;
    vector<T> tree;

    fenwick_tree(int n = 0) {
        if (n > 0)
            init(n);
    }

    void init(int n) {
        tree_n = n;
        tree.assign(tree_n + 1, 0);
    }

    // O(n) initialization of the Fenwick tree.
    void build(const auto &initial) {
        assert((int) initial.size() == tree_n);

        for (int i = 1; i <= tree_n; i++) {
            tree[i] = initial[i - 1];

            for (int k = (i & -i) >> 1; k > 0; k >>= 1)
                tree[i] += tree[i - k];
        }
    }

    // index is in [0, tree_n).
    void update(int index, const T &change) {
        assert(0 <= index && index < tree_n);

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

    // Returns the last i in [0, N] such that tree_query(i) <= sum, or -1 if no such i exists.
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
    bool add;
    int x;
    int index;
};

int Q;
vector<query> queries;
vector<pair<int, int>> X;

int main() {
    scanf("%d", &Q);
    queries.resize(Q);

    for (int q = 0; q < Q; q++) {
        char op;
        int x;
        scanf(" %c %d", &op, &x);
        queries[q].add = op == '+';
        queries[q].x = x;

        if (queries[q].add)
            X.emplace_back(x, q);
    }

    sort(X.begin(), X.end());
    map<int, int> next_erase;

    for (int q = 0; q < Q; q++)
        if (queries[q].add) {
            queries[q].index = lower_bound(X.begin(), X.end(), make_pair(queries[q].x, q)) - X.begin();
        } else {
            if (next_erase.find(queries[q].x) == next_erase.end())
                next_erase[queries[q].x] = lower_bound(X.begin(), X.end(), make_pair(queries[q].x, 0)) - X.begin();

            queries[q].index = next_erase[queries[q].x]++;
        }

    fenwick_tree<long long> tree(Q + 1);
    int inside = 0;

    for (int q = 0; q < Q; q++) {
        if (queries[q].add) {
            tree.update(queries[q].index, queries[q].x);
            inside++;
        } else {
            tree.update(queries[q].index, -queries[q].x);
            inside--;
        }

        long long sum = 0;
        int bad = 0;

        while (true) {
            int index = tree.find_last_prefix(3 * sum);

            if (index >= Q)
                break;

            long long at = tree.get(index);
            long long before = tree.query(index);

            if (at > 2 * before)
                bad++;

            sum = before + at;
        }

        printf("%d\n", inside - bad);
    }
}