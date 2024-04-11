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

template<typename T1, typename T2>
bool minimize(T1 &a, const T2 &b) {
    if (b < a) {
        a = b;
        return true;
    }

    return false;
}


const int INF = 1e9 + 5;

struct transition {
    int add[2][2];

    transition() {
        add[0][0] = add[1][1] = 0;
        add[0][1] = add[1][0] = INF;
    }

    transition(int initial) {
        add[0][0] = add[0][1] = add[1][0] = add[1][1] = initial;
    }

    transition(int m, bool a, bool b) {
        add[0][0] = add[1][1] = 0;
        add[0][1] = add[1][0] = m;

        add[0][a]++;
        add[1][a]++;

        add[0][b]++;
        add[1][b]++;
    }

    array<int, 2> apply(array<int, 2> x) {
        array<int, 2> y = {INF, INF};

        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                minimize(y[b], x[a] + add[a][b]);

        return y;
    }
};

transition tran_join(const transition &x, const transition &y) {
    transition combined(INF);

    for (int a = 0; a < 2; a++)
        for (int b = 0; b < 2; b++)
            for (int c = 0; c < 2; c++)
                minimize(combined.add[a][c], x.add[a][b] + y.add[b][c]);

    return combined;
}


struct segment_change {
    array<bool, 2> flip;

    segment_change(array<bool, 2> _flip = {false, false}) : flip(_flip) {}

    void reset() {
        flip = {false, false};
    }

    bool has_change() const {
        return flip[0] || flip[1];
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change({flip[0] ^ other.flip[0], flip[1] ^ other.flip[1]});
    }
};

struct segment {
    array<int, 2> counts[2];
    transition tran[2][2];

    segment() {
        for (int side = 0; side < 2; side++)
            counts[side] = {0, 0};
    }

    segment(int m, bool x, bool y) {
        for (int side = 0; side < 2; side++)
            counts[side] = {0, 0};

        counts[0][x]++;
        counts[1][y]++;

        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++)
                tran[a][b] = transition(m, x ^ a, y ^ b);
    }

    void apply(int, const segment_change &change) {
        if (change.flip[0]) {
            swap(counts[0][0], counts[0][1]);
            swap(tran[0][0], tran[1][0]);
            swap(tran[0][1], tran[1][1]);
        }

        if (change.flip[1]) {
            swap(counts[1][0], counts[1][1]);
            swap(tran[0][0], tran[0][1]);
            swap(tran[1][0], tran[1][1]);
        }
    }

    void join(const segment &other) {
        for (int a = 0; a < 2; a++)
            for (int b = 0; b < 2; b++) {
                counts[a][b] += other.counts[a][b];
                tran[a][b] = tran_join(tran[a][b], other.tran[a][b]);
            }
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

pair<int, int> right_half[32];

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = -1) {
        if (n >= 0)
            init(n);
    }

    void init(int n) {
        tree_n = 1;

        while (tree_n < n)
            tree_n *= 2;

        tree.assign(2 * tree_n, segment());
        changes.assign(tree_n, segment_change());
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

    void push_down(int position, int length) {
        if (!changes[position].has_change())
            return;

        if (2 * position < tree_n) {
            changes[2 * position] = changes[2 * position].combine(changes[position]);
            changes[2 * position + 1] = changes[2 * position + 1].combine(changes[position]);
        }

        tree[2 * position].apply(length / 2, changes[position]);
        tree[2 * position + 1].apply(length / 2, changes[position]);
        changes[position].reset();
    }

    // Calls push_down for all necessary nodes in order to query the range [a, b).
    void push_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;

        for (int up = 31 - __builtin_clz(tree_n); up > 0; up--) {
            int x = a >> up, y = b >> up;
            push_down(x, 1 << up);
            if (x != y) push_down(y, 1 << up);
        }
    }

    void join_and_apply(int position, int length) {
        tree[position].join(tree[2 * position], tree[2 * position + 1]);
        tree[position].apply(length, changes[position]);
    }

    // Calls join for all necessary nodes after updating the range [a, b).
    void join_all(int a, int b) {
        assert(0 <= a && a < b && b <= tree_n);
        a += tree_n;
        b += tree_n - 1;
        int length = 1;

        while (a > 1) {
            a /= 2;
            b /= 2;
            length *= 2;
            join_and_apply(a, length);
            if (a != b) join_and_apply(b, length);
        }
    }

    template<typename T_range_op>
    void process_range(int a, int b, bool needs_join, T_range_op &&range_op) {
        if (a == b) return;
        push_all(a, b);
        int original_a = a, original_b = b;
        int length = 1, r_size = 0;

        for (a += tree_n, b += tree_n; a < b; a /= 2, b /= 2, length *= 2) {
            if (a & 1)
                range_op(a++, length);

            if (b & 1)
                right_half[r_size++] = {--b, length};
        }

        for (int i = r_size - 1; i >= 0; i--)
            range_op(right_half[i].first, right_half[i].second);

        if (needs_join)
            join_all(original_a, original_b);
    }

    segment query(int a, int b) {
        assert(0 <= a && a <= b && b <= tree_n);
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        assert(0 <= a && a <= b && b <= tree_n);

        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);

            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }

    template<typename T_bool>
    int find_last_prefix(int n, T_bool &&should_join);

    template<typename T_bool>
    int find_last_subarray(int n, int start, T_bool &&should_join);
};


int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N[2], Q;
    cin >> N[0] >> N[1] >> Q;
    array<string, 2> sides[2];

    for (int side = 0; side < 2; side++)
        cin >> sides[side][0] >> sides[side][1];

    seg_tree tree[2];

    auto &&build = [&](int side) {
        vector<segment> initial(N[side]);

        for (int i = 0; i < N[side]; i++)
            initial[i] = segment(N[!side], sides[side][0][i] == 'B', sides[side][1][i] == 'B');

        tree[side].build(initial);
    };

    build(0);
    build(1);

    auto &&update = [&](char where, int L, int R) {
        if (where == 'L')
            tree[0].update(L, R, segment_change({true, false}));
        else if (where == 'R')
            tree[0].update(L, R, segment_change({false, true}));
        else if (where == 'U')
            tree[1].update(L, R, segment_change({true, false}));
        else if (where == 'D')
            tree[1].update(L, R, segment_change({false, true}));
    };

    auto &&query = [&](int side) {
        array<int, 2> counts = tree[side].tree[1].counts[0];
        counts = tree[!side].tree[1].tran[0][0].apply(counts);
        array<int, 2> finish = tree[side].tree[1].counts[1];
        counts[0] += finish[0];
        counts[1] += finish[1];
        return min(counts[0], counts[1]);
    };

    cout << min(query(0), query(1)) << '\n';

    for (int q = 0; q < Q; q++) {
        char where;
        int L, R;
        cin >> where >> L >> R;
        L--;
        update(where, L, R);
        cout << min(query(0), query(1)) << '\n';
    }
}