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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }

#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

struct segment_change {
    // Use a sentinel value rather than a boolean to save significant memory (four bytes per object).
    static const int SENTINEL = numeric_limits<int>::lowest();

    int to_set;

    segment_change(int _to_set = SENTINEL) : to_set(_to_set) {}

    bool has_set() const {
        return to_set != SENTINEL;
    }
};

struct segment {
    int minimum;

    segment(int _minimum = numeric_limits<int>::max()) : minimum(_minimum) {}

    void apply(const segment_change &change) {
        if (change.has_set())
            minimum = change.to_set;
    }

    void join(const segment &other) {
        minimum = min(minimum, other.minimum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

int right_half[32];

struct basic_seg_tree {
    static const bool POWER_OF_TWO_MODE = true;

    int tree_n = 0;
    vector<segment> tree;

    basic_seg_tree(int n = -1) {
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

    template<typename T_bool>
    int find_last_prefix(int n, T_bool &&should_join) const;

    template<typename T_bool>
    int find_last_subarray(int n, int start, T_bool &&should_join) const;
};


const int INF = int(1e9) + 5;

struct shortcut {
    array<int, 2> coord;
    int index;

    bool operator<(const shortcut &other) const {
        return coord < other.coord;
    }

    int get_yx() const {
        return coord[1] - coord[0];
    }
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, M;
    cin >> N >> M;
    vector<shortcut> shortcuts[2];
    set<array<int, 2>> bad;

    for (int i = 0; i < N; i++) {
        int x, y;
        cin >> x >> y;
        bad.insert({x, y});
        shortcuts[0].emplace_back();
        shortcuts[0].back().coord = {x, y};
        shortcuts[0].back().index = i;
    }

    bad.insert({0, 0});
    shortcuts[0].emplace_back();
    shortcuts[0].back().coord = {0, 0};
    shortcuts[0].back().index = N;
    N++;

    shortcuts[1] = shortcuts[0];

    for (int i = 0; i < N; i++)
        swap(shortcuts[1][i].coord[0], shortcuts[1][i].coord[1]);

    sort(shortcuts[0].begin(), shortcuts[0].end());
    sort(shortcuts[1].begin(), shortcuts[1].end());
    map<int, int> earliest[2];

    for (auto &shortcut : shortcuts[0]) {
        for (int dim = 0; dim < 2; dim++)
            if (earliest[dim].find(shortcut.coord[dim]) == earliest[dim].end())
                earliest[dim][shortcut.coord[dim]] = shortcut.coord[!dim];
    }

    vector<pair<int, int>> YX[2];

    for (int i = 0; i < N; i++) {
        YX[0].emplace_back(shortcuts[0][i].get_yx(), shortcuts[0][i].index);
        YX[1].emplace_back(shortcuts[1][i].get_yx(), shortcuts[1][i].index);
    }

    for (int d = 0; d < 2; d++)
        sort(YX[d].begin(), YX[d].end());

    auto get_yx_index = [&](int d, int yx, int index = -1) -> int {
        return int(lower_bound(YX[d].begin(), YX[d].end(), make_pair(yx, index)) - YX[d].begin());
    };

    basic_seg_tree tree[2] = {basic_seg_tree(N), basic_seg_tree(N)};

    for (int d = 0; d < 2; d++)
        for (int i = 0; i < N; i++) {
            int index = get_yx_index(d, shortcuts[d][i].get_yx(), shortcuts[d][i].index);
            tree[d].update(index, segment_change(shortcuts[d][i].coord[0]));
        }

    array<int, 2> xy = {0, 0};
    array<int, 2> sweep_idx = {0, 0};
    vector<pair<array<int, 2>, int>> diagonals;

    while (xy[0] < INF && xy[1] < INF) {
        bool skip = false;

        for (int d = 0; d < 2; d++)
            if (earliest[d].find(xy[d]) != earliest[d].end() && earliest[d][xy[d]] <= xy[!d]) {
                xy[d]++;
                skip = true;
            }

        if (skip)
            continue;

        // diagonal starts at x, y
        int length = INF;

        for (int d = 0; d < 2; d++) {
            while (sweep_idx[d] < N && shortcuts[d][sweep_idx[d]].coord[0] < xy[d]) {
                int index = get_yx_index(d, shortcuts[d][sweep_idx[d]].get_yx(), shortcuts[d][sweep_idx[d]].index);
                tree[d].update(index, segment_change(INF));
                sweep_idx[d]++;
            }

            int index = get_yx_index(d, xy[!d] - xy[d] + 1);
            length = min(length, tree[d].query(0, index).minimum - xy[d]);
        }

        diagonals.emplace_back(xy, length);
        dbg(xy, length);
        xy[0] += length;
        xy[1] += length;
    }

    dbg(diagonals);

    for (int q = 0; q < M; q++) {
        int x, y;
        cin >> x >> y;
        bool win = true;

        if (bad.find({x, y}) != bad.end())
            win = false;

        auto it = upper_bound(diagonals.begin(), diagonals.end(), make_pair(array<int, 2>{x, y}, INF));

        if (it != diagonals.begin()) {
            it--;

            if (y - x == it->first[1] - it->first[0] && x - it->first[0] < it->second)
                win = false;
        }

        cout << (win ? "WIN" : "LOSE") << '\n';
    }
}