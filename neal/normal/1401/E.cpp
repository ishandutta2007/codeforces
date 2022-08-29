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

        for (int k = 31 - __builtin_clz(tree_n); k >= 0; k--)
            if (prefix + (1 << k) <= tree_n && tree[prefix + (1 << k)] <= sum) {
                prefix += 1 << k;
                sum -= tree[prefix];
            }

        return prefix;
    }
};


struct horizontal {
    int x1, x2, y;

    bool operator<(const horizontal &other) const {
        return y < other.y;
    }
};

struct vertical_event {
    int x, y, type;

    bool operator<(const vertical_event &other) const {
        if (y != other.y)
            return y < other.y;

        return type > other.type;
    }
};

// Counts intersection points between horizontal and vertical segments. Includes endpoints.
// segments[i] = {{x0, x1}, {y0, y1}}; either x0 == x1 or y0 == y1.
int64_t count_intersection_points(const vector<pair<array<int, 2>, array<int, 2>>> segments) {
    vector<horizontal> horiz;
    vector<vertical_event> events;
    vector<int> Xs;

    for (auto &seg : segments) {
        array<int, 2> x = seg.first;
        array<int, 2> y = seg.second;
        assert(x[0] == x[1] || y[0] == y[1]);

        if (x[0] > x[1]) swap(x[0], x[1]);
        if (y[0] > y[1]) swap(y[0], y[1]);

        if (y[0] == y[1]) {
            horiz.push_back({x[0], x[1], y[0]});
            Xs.push_back(x[0]);
            Xs.push_back(x[1]);
        } else {
            events.push_back({x[0], y[0], +1});
            events.push_back({x[0], y[1], -1});
            Xs.push_back(x[0]);
        }
    }

    sort(Xs.begin(), Xs.end());
    Xs.erase(unique(Xs.begin(), Xs.end()), Xs.end());

    auto &&compress_x = [&](int x) {
        return int(lower_bound(Xs.begin(), Xs.end(), x) - Xs.begin());
    };

    for (auto &h : horiz) {
        h.x1 = compress_x(h.x1);
        h.x2 = compress_x(h.x2);
    }

    for (auto &e : events)
        e.x = compress_x(e.x);

    int E = int(events.size());
    sort(horiz.begin(), horiz.end());
    sort(events.begin(), events.end());
    fenwick_tree<int> tree(int(Xs.size()));
    int64_t total = 0;
    int e = 0;

    for (auto &h : horiz) {
        while (e < E && (events[e].y < h.y || (events[e].y == h.y && events[e].type > 0))) {
            tree.update(events[e].x, events[e].type);
            e++;
        }

        total += tree.query(h.x1, h.x2 + 1);
    }

    return total;
}


const int SQUARE = 1e6;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<pair<array<int, 2>, array<int, 2>>> segments;
    int64_t answer = 1;

    for (int i = 0; i < N; i++) {
        int y, lx, rx;
        cin >> y >> lx >> rx;
        answer += rx - lx == SQUARE;
        segments.emplace_back(array<int, 2>{lx, rx}, array<int, 2>{y, y});
    }

    for (int i = 0; i < M; i++) {
        int x, ly, ry;
        cin >> x >> ly >> ry;
        answer += ry - ly == SQUARE;
        segments.emplace_back(array<int, 2>{x, x}, array<int, 2>{ly, ry});
    }

    answer += count_intersection_points(segments);
    cout << answer << '\n';
}