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
    // update(index, -1) is equivalent to erase(index); again be careful not to double erase.
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


const int MASK = (1 << 30) - 1;

string S;
vector<pair<int, int>> W_stack;
fenwick_tree<int> suffixes;
long long current = 0;

// fail[i] = for the prefix [0, i) of `S`, the length of the longest proper prefix that is also a suffix.
vector<int> fail = {0};
int kmp_len = 0;

// link[i] = the closest ancestor of i that takes a different ending character from i.
vector<int> link;

int query_stack_value(int index) {
    assert(!W_stack.empty());
    int low = 0, high = W_stack.size() - 1;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (W_stack[mid].second <= index)
            low = mid;
        else
            high = mid - 1;
    }

    return W_stack[low].first;
}

void add_to_stack(int index, int w) {
    while (!W_stack.empty() && w <= W_stack.back().first) {
        int value = W_stack.back().first;
        int prev_index = W_stack.back().second;
        current -= (long long) suffixes.query(prev_index, index) * (value - w);
        index = prev_index;
        W_stack.pop_back();
    }

    W_stack.emplace_back(w, index);
}

void add_char(char c) {
    S += c;

    if (S.size() > 1) {
        while (kmp_len > 0 && S[kmp_len] != S.back())
            kmp_len = fail[kmp_len];

        if (S[kmp_len] == S.back())
            kmp_len++;
    }

    fail.push_back(kmp_len);
    int index = S.size() - 1;

    if (index > 0 && S[index] == S[fail[index]])
        link.push_back(link[fail[index]]);
    else
        link.push_back(fail[index]);
}

void remove_suffixes(int len, char c) {
    while (len > 0) {
        if (len < (int) S.size() && S[len] != c) {
            int remove = S.size() - len;
            current -= query_stack_value(remove);
            suffixes.update(remove, -1);
        }

        if (len < (int) S.size() && S[len] == c)
            len = link[len];
        else
            len = fail[len];
    }
}

int main() {
    int N;
    scanf("%d", &N);
    suffixes.init(N);

    const long long LOW_BASE = 1e12;
    long long ans_high = 0, ans_low = 0;
    long long ans_mask = 0, ans26 = 0;

    for (int i = 0; i < N; i++) {
        char c;
        int w;
        scanf(" %c %d", &c, &w);

        c = 'a' + (c - 'a' + ans26) % 26;
        w ^= ans_mask;

        remove_suffixes(i, c);
        add_char(c);
        add_to_stack(i, w);

        if (c == S[0]) {
            suffixes.update(i, +1);
            current += w;
        }

        ans_low += current % LOW_BASE;
        ans_high += current / LOW_BASE + ans_low / LOW_BASE;
        ans_low %= LOW_BASE;

        ans_mask = (ans_mask + current) & MASK;
        ans26 = (ans26 + current) % 26;

        if (ans_high != 0)
            printf("%lld%012lld\n", ans_high, ans_low);
        else
            printf("%lld\n", ans_low);
    }
}