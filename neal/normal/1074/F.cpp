// Solution to https://codeforces.com/contest/1044/problem/F
#include <algorithm>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;


struct segment_change {
    int add;

    // TODO: make sure the default constructor is the identity segment_change.
    segment_change(int _add = 0) : add(_add) {}

    void reset() {
        add = 0;
    }

    bool has_change() const {
        return add != 0;
    }

    // Return the combined result of applying this segment change followed by `other`.
    // TODO: make sure to check for sentinel values.
    segment_change combine(const segment_change &other) const {
        return segment_change(add + other.add);
    }
};

struct segment {
    int minimum, count;

    // TODO: make sure the default constructor is the identity segment.
    segment(int _minimum = INF, int _count = 0) : minimum(_minimum), count(_count) {}

    void apply(int length, const segment_change &change) {
        minimum += change.add;
    }

    void join(const segment &other) {
        if (other.minimum < minimum)
            *this = other;
        else if (other.minimum == minimum)
            count += other.count;
    }

    void join(const segment &a, const segment &b) {
        *this = a;
        join(b);
    }
};

struct seg_tree {
    int tree_n = 0;
    vector<segment> tree;
    vector<segment_change> changes;

    seg_tree(int n = 0) {
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

    // O(n) initialization of our tree.
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

    static pair<int, int> right_half[];

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
        segment answer;

        process_range(a, b, false, [&](int position, int) {
            answer.join(tree[position]);
        });

        return answer;
    }

    void update(int a, int b, const segment_change &change) {
        process_range(a, b, true, [&](int position, int length) {
            tree[position].apply(length, change);

            if (position < tree_n)
                changes[position] = changes[position].combine(change);
        });
    }
};

pair<int, int> seg_tree::right_half[100];


int N, Q;
vector<vector<int>> adj;
vector<int> tour_start, tour_end;
int tour;

void dfs(int node, int parent) {
    if (parent == -1)
        tour = 0;

    tour_start[node] = tour++;

    if (parent != -1)
        adj[node].erase(find(adj[node].begin(), adj[node].end(), parent));

    for (int neighbor : adj[node])
        if (neighbor != parent)
            dfs(neighbor, node);

    tour_end[node] = tour;
}

bool is_ancestor(int u, int v) {
    return tour_start[u] <= tour_start[v] && tour_start[v] < tour_end[u];
}

seg_tree tree;

void update_back_edge(int u, int v, int direction) {
    // Binary search to find the containing child.
    assert(!adj[u].empty());
    int low = 0, high = adj[u].size() - 1;

    while (low < high) {
        int mid = (low + high) / 2;

        if (tour_start[v] < tour_end[adj[u][mid]])
            high = mid;
        else
            low = mid + 1;
    }

    int u_child = adj[u][low];
    assert(is_ancestor(u_child, v));

    // Only u_child's subtree minus v's subtree is invalid.
    tree.update(tour_start[u_child], tour_end[u_child], segment_change(direction));
    tree.update(tour_start[v], tour_end[v], segment_change(-direction));
}

void update_cross_edge(int u, int v, int direction) {
    // Only the subtrees of u and v are valid.
    tree.update(0, tree.tree_n, segment_change(direction));
    tree.update(tour_start[u], tour_end[u], segment_change(-direction));
    tree.update(tour_start[v], tour_end[v], segment_change(-direction));
}

void update(int u, int v, int direction) {
    if (is_ancestor(u, v))
        update_back_edge(u, v, direction);
    else if (is_ancestor(v, u))
        update_back_edge(v, u, direction);
    else
        update_cross_edge(u, v, direction);
}

int main() {
    scanf("%d %d", &N, &Q);
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    tour_start.resize(N);
    tour_end.resize(N);
    dfs(0, -1);

    tree.init(N);
    tree.build(vector<segment>(N, segment(0, 1)));
    set<pair<int, int>> contained;

    for (int q = 0; q < Q; q++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;

        if (u > v)
            swap(u, v);

        int direction = +1;

        if (!contained.insert({u, v}).second) {
            contained.erase({u, v});
            direction = -1;
        }

        update(u, v, direction);
        const segment &all = tree.query(0, tree.tree_n);
        printf("%d\n", all.minimum == 0 ? all.count : 0);
    }
}