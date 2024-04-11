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

struct segment_change {
    bool flip;

    segment_change(bool _flip = false) : flip(_flip) {}

    void reset() {
        flip = false;
    }

    bool has_change() const {
        return flip;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(flip ^ other.flip);
    }
};

struct segment {
    int length;
    int left[2], right[2];
    bool left_extend[2], right_extend[2];
    int longest[2];

    segment(int _length = 0, char ch = '\0') {
        length = _length;

        for (int f = 0; f < 2; f++) {
            if (ch == '<') {
                left[f] = right[f] = longest[f] = 1;
                left_extend[f] = true;
                right_extend[f] = false;
                ch = '>';
            } else if (ch == '>') {
                left[f] = right[f] = longest[f] = 1;
                left_extend[f] = false;
                right_extend[f] = true;
                ch = '<';
            } else {
                left[f] = right[f] = longest[f] = 0;
                left_extend[f] = right_extend[f] = true;
            }
        }
    }

    void apply(int, const segment_change &change) {
        if (change.flip) {
            swap(left[0], left[1]);
            swap(right[0], right[1]);
            swap(left_extend[0], left_extend[1]);
            swap(right_extend[0], right_extend[1]);
            swap(longest[0], longest[1]);
        }
    }

    void join(const segment &other) {
        segment result;
        result.join(*this, other);
        *this = result;
    }

    void join(const segment &a, const segment &b) {
        dbg("JOIN");
        a.print();
        b.print();
        length = a.length + b.length;

        for (int f = 0; f < 2; f++) {
            longest[f] = max(a.longest[f], b.longest[f]);

            if (a.right_extend[f] || b.left_extend[f])
                longest[f] = max(longest[f], a.right[f] + b.left[f]);

            left[f] = a.left[f];
            left_extend[f] = a.left_extend[f];

            if (a.left[f] == a.length && (a.right_extend[f] || b.left_extend[f])) {
                left[f] = a.length + b.left[f];
                left_extend[f] = a.left_extend[f] && b.left_extend[f];
            }

            right[f] = b.right[f];
            right_extend[f] = b.right_extend[f];

            if (b.right[f] == b.length && (a.right_extend[f] || b.left_extend[f])) {
                right[f] = a.right[f] + b.length;
                right_extend[f] = a.right_extend[f] && b.right_extend[f];
            }
        }

        print();

        for (int f = 0; f < 2; f++) {
            assert(longest[f] >= left[f]);
            assert(longest[f] >= right[f]);
        }
    }

    void print() const {
        dbg(length, left[0], left_extend[0], longest[0], right[0], right_extend[0]);
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

    int N, Q;
    string S;
    cin >> N >> Q >> S;
    seg_tree tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i] = segment(1, S[i]);

    tree.build(initial);

    for (int q = 0; q < Q; q++) {
        int L, R;
        cin >> L >> R;
        L--;
        tree.update(L, R, segment_change(true));
        cout << tree.query(L, R).longest[0] << '\n';
        tree.query(L, R).print();
    }
}