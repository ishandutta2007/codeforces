#include <algorithm>
#include <array>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
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

using T_tree = int;
const T_tree T_INF = numeric_limits<T_tree>::max() / 2;

struct segment_change {
    T_tree to_add;

    segment_change(T_tree _to_add = 0) : to_add(_to_add) {}
};

struct segment {
    T_tree max_prefix, sum;

    segment(T_tree _max_prefix = -T_INF, T_tree _sum = 0) : max_prefix(_max_prefix), sum(_sum) {}

    void apply(const segment_change &change) {
        max_prefix += change.to_add;
        sum += change.to_add;
    }

    void join(const segment &other) {
        max_prefix = max(max_prefix, sum + other.max_prefix);
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct max_prefix_sum_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    max_prefix_sum_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        if (POWER_OF_TWO_MODE) {
            tree_n = 1;

            while (tree_n < n)
                tree_n *= 2;
        } else {
            tree_n = n;
        }

        tree.assign(2 * tree_n, segment());
    }

    // Builds our tree from an array in O(n).
    void build(const vector<segment> &initial) {
        int n = int(initial.size());
        init(n);
        assert(n <= tree_n);

        for (int i = 0; i < n; i++)
            tree[tree_n + i] = initial[i];

        for (int position = tree_n - 1; position > 0; position--)
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
    }

    segment query(int a, int b) const {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;
        int r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2) {
            if (a & 1)
                answer.join(tree[a++]);

            if (b & 1)
                right_half[r_size++] = --b;
        }

        for (int i = r_size - 1; i >= 0; i--)
            answer.join(tree[right_half[i]]);

        return answer;
    }

    segment query_single(int index) const {
        assert(0 <= index && index < tree_n);
        return tree[tree_n + index];
    }

    void join_up(int position) {
        while (position > 1) {
            position /= 2;
            tree[position].join(tree[2 * position], tree[2 * position + 1]);
        }
    }

    void update(int index, const segment_change &change) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position].apply(change);
        join_up(position);
    }

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};

struct add_max_seg_tree {
    // Build a `max_prefix_sum_tree` on the consecutive differences of the array.
    max_prefix_sum_tree tree;

    add_max_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree.init(n);
    }

    // TODO: make sure to call `build()` to initialize the tree.
    void build(const vector<T_tree> &initial) {
        vector<segment> segment_initial(initial.size());
        T_tree previous = 0;

        for (int i = 0; i < int(initial.size()); i++) {
            T_tree value = initial[i] - previous;
            previous = initial[i];
            segment_initial[i] = segment(value, value);
        }

        tree.build(segment_initial);
    }

    T_tree query(int a, int b) const {
        return tree.query(0, a).sum + tree.query(a, b).max_prefix;
    }

    T_tree query_full() const {
        return tree.tree[1].max_prefix;
    }

    void update(int a, int b, segment_change change) {
        if (a < tree.tree_n)
            tree.update(a, change);

        if (b < tree.tree_n) {
            change.to_add *= -1;
            tree.update(b, change);
        }
    }

    void set_value(int index, T_tree value) {
        T_tree current = query(index, index + 1);
        update(index, index + 1, segment_change(value - current));
    }
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, K, M;
    cin >> N >> K >> M;
    K--;
    add_max_seg_tree tree(2 * N);
    vector<int> initial(2 * N);

    for (int i = 0; i < 2 * N; i++)
        initial[i] = i;

    tree.build(initial);
    map<array<int, 2>, int> pawns;
    multiset<int> coords;

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        int status = pawns[{x, y}]++ % 2;
        status = status == 0 ? +1 : -1;
        int coordinate = y + abs(x - K);

        if (status > 0)
            coords.insert(coordinate);
        else
            coords.erase(coords.find(coordinate));

        tree.update(0, coordinate + 1, segment_change(status));
        int answer = 0;

        if (!coords.empty())
            answer = max(tree.query(0, *coords.rbegin() + 1) - N, 0);

        cout << answer << '\n';
    }
}