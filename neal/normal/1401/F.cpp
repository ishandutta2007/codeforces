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

struct segment {
    int64_t sum;

    segment(int64_t _sum = 0) : sum(_sum) {}

    void join(const segment &other) {
        sum += other.sum;
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

    void update(int index, const segment &seg) {
        assert(0 <= index && index < tree_n);
        int position = tree_n + index;
        tree[position] = seg;
        join_up(position);
    }
};

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int N, Q;
    cin >> N >> Q;
    vector<segment> initial(1 << N);

    for (segment &seg : initial)
        cin >> seg.sum;

    basic_seg_tree tree(1 << N);
    tree.build(initial);
    int change = 0;

    auto &&get_sum = [&](int prefix) {
        int64_t sum = 0;

        while (prefix > 0) {
            int level = __builtin_ctz(prefix);
            int start = prefix - (prefix & -prefix);
            int relevant = (change >> level) << level;
            int tree_start = start ^ relevant;
            int down = (31 - __builtin_clz(tree.tree_n)) - level;
            int node = (1 << down) + (tree_start >> level);
            sum += tree.tree[node].sum;
            prefix = start;
        }

        return sum;
    };

    for (int q = 0; q < Q; q++) {
        int type;
        cin >> type;

        if (type == 1) {
            int x, k;
            cin >> x >> k;
            x--;
            tree.update(x ^ change, segment(k));
        } else if (type == 2) {
            int k;
            cin >> k;
            change ^= (1 << k) - 1;
        } else if (type == 3) {
            int k;
            cin >> k;
            change ^= 1 << k;
        } else if (type == 4) {
            int L, R;
            cin >> L >> R;
            L--;
            cout << get_sum(R) - get_sum(L) << '\n';
        } else {
            assert(false);
        }
    }
}