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

using T_tree = int;
const T_tree T_INF = numeric_limits<T_tree>::max() / 2;

struct segment_change {
    T_tree to_add;

    segment_change(T_tree _to_add = 0) : to_add(_to_add) {}
};

struct segment {
    T_tree min_prefix, sum;

    segment(T_tree _min_prefix = T_INF, T_tree _sum = 0) : min_prefix(_min_prefix), sum(_sum) {}

    void apply(const segment_change &change) {
        min_prefix += change.to_add;
        sum += change.to_add;
    }

    void join(const segment &other) {
        min_prefix = min(min_prefix, sum + other.min_prefix);
        sum += other.sum;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct min_prefix_sum_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    min_prefix_sum_tree(int n = -1) {
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

    segment query_full() const {
        assert(POWER_OF_TWO_MODE);
        return tree[1];
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

struct add_min_seg_tree {
    // Build a `min_prefix_sum_tree` on the consecutive differences of the array.
    min_prefix_sum_tree tree;

    add_min_seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree.init(n);
    }

    template<typename T_array>
    void build(const T_array &initial) {
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
        return tree.query(0, a).sum + tree.query(a, b).min_prefix;
    }

    T_tree query_full() const {
        return tree.query_full().min_prefix;
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
        T_tree current = tree.query(0, index + 1).sum;
        update(index, index + 1, value - current);
    }

    void minimize(int index, T_tree value) {
        T_tree current = tree.query(0, index + 1).sum;

        if (value < current)
            update(index, index + 1, value - current);
    }
};

int64_t ceil_div(int64_t a, int64_t b) {
    return a / b + ((a ^ b) > 0 && a % b != 0);
}


void run_case() {
    int N, M;
    cin >> N >> M;
    vector<int> A(N);

    for (auto &a : A)
        cin >> a;

    sort(A.begin(), A.end(), greater<int>());
    A.resize(M);
    N = M;
    vector<int> teachers = A;
    sort(teachers.begin(), teachers.end());
    vector<int> groups(N);
    vector<int64_t> group_sums(N, 0);
    vector<vector<int>> students(N);

    for (int i = 0; i < N; i++) {
        int k;
        cin >> k;
        students[i].resize(k);

        for (auto &s : students[i]) {
            cin >> s;
            group_sums[i] += s;
        }

        groups[i] = int(ceil_div(group_sums[i], k));
    }

    auto get_teacher_index = [&](int x) -> int {
        return int(lower_bound(teachers.begin(), teachers.end(), x) - teachers.begin());
    };

    add_min_seg_tree tree(N);
    tree.build(vector<int>(N, 0));

    for (int i = 0; i < N; i++) {
        tree.update(0, i, segment_change(+1));
        tree.update(0, get_teacher_index(groups[i]), segment_change(-1));
    }

    for (int i = 0; i < N; i++) {
        int k = int(students[i].size());
        int group_index = get_teacher_index(groups[i]);
        tree.update(0, group_index, segment_change(+1));

        for (auto &s : students[i]) {
            int64_t sum = group_sums[i] - s;
            int group = int(ceil_div(sum, k - 1));
            int index = get_teacher_index(group);
            tree.update(0, index, segment_change(-1));
            cout << (tree.query_full() >= 0);
            tree.update(0, index, segment_change(+1));
        }

        tree.update(0, group_index, segment_change(-1));
    }

    cout << '\n';
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}