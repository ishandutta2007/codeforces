#include <algorithm>
#include <cassert>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct segment_change {
    int to_add;

    segment_change(int _to_add = 0) : to_add(_to_add) {}

    void reset() {
        to_add = 0;
    }

    bool has_change() const {
        return to_add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    segment_change combine(const segment_change &other) const {
        return segment_change(to_add + other.to_add);
    }
};

struct segment {
    int maximum;

    segment(int _maximum = -INF) : maximum(_maximum) {}

    void apply(int, const segment_change &change) {
        maximum += change.to_add;
    }

    void join(const segment &other) {
        maximum = max(maximum, other.maximum);
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct add_max_seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    add_max_seg_tree(int n = 0) {
        if (n > 0)
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
        int n = initial.size();
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

    pair<int, int> right_half[32];

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
};


struct frnd {
    int t, a, b, index;

    bool operator<(const frnd &other) const {
        return b > other.b;
    }
};

bool compare_time(const frnd &x, const frnd &y) {
    return x.t < y.t;
}

void solve_case() {
    int N, M, C, C0;
    cin >> N >> M >> C >> C0;
    vector<frnd> friends(N);

    for (frnd &f : friends)
        cin >> f.t >> f.a >> f.b;

    friends.push_back({0, C0, 0, 0});
    friends.push_back({M, 0, 0, 0});
    sort(friends.begin(), friends.end(), compare_time);
    N = (int) friends.size();

    for (int i = 0; i < N; i++)
        friends[i].index = i;

    add_max_seg_tree tree(N);
    vector<segment> initial(N);

    for (int i = 0; i < N; i++)
        initial[i].maximum = -friends[i].t;

    tree.build(initial);
    long long total = 0;
    priority_queue<frnd> cheapest;

    for (int i = 1; i < N; i++) {
        int have = tree.query(i, i + 1).maximum;
        cheapest.push(friends[i - 1]);

        while (have < 0 && !cheapest.empty()) {
            frnd top = cheapest.top(); cheapest.pop();
            int current = tree.query(top.index, N).maximum;
            int take = min({C - current, top.a, -have});
            have += take;
            top.a -= take;
            total += (long long) take * top.b;
            tree.update(top.index, N, segment_change(take));

            if (top.a > 0 && current + take < C) {
                cheapest.push(top);
                assert(have == 0);
            }
        }

        if (have < 0) {
            cout << -1 << '\n';
            return;
        }
    }

    cout << total << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    while (Q-- > 0)
        solve_case();
}