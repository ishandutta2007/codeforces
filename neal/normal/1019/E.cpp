#include <algorithm>
#include <cassert>
#include <deque>
#include <iostream>
#include <vector>
using namespace std;

const bool CHECK_OVERFLOW64 = true;
const long long LL_INF = (long long) 2e18 + 5;

struct point {
    long long x, y;

    point() : x(0), y(0) {}

    point(long long _x, long long _y) : x(_x), y(_y) {}

    point& operator+=(const point &other) { x += other.x; y += other.y; return *this; }
    point& operator-=(const point &other) { x -= other.x; y -= other.y; return *this; }

    point operator+(const point &other) const { return point(*this) += other; }
    point operator-(const point &other) const { return point(*this) -= other; }

    bool operator==(const point &other) const { return x == other.x && y == other.y; }
    bool operator!=(const point &other) const { return !(*this == other); }

    friend ostream& operator<<(ostream &stream, const point &p) {
        return stream << '(' << p.x << ", " << p.y << ')';
    }
};

int cross_sign(const point &a, const point &b) {
    if (CHECK_OVERFLOW64) {
        long double double_value = (long double) a.x * b.y - (long double) b.x * a.y;

        if (abs(double_value) > 1e18)
            return double_value > 0 ? +1 : -1;
    }

    uint64_t uint64_value = (uint64_t) a.x * b.y - (uint64_t) b.x * a.y;

    if (uint64_value == 0)
        return 0;

    return uint64_value >> 63 ? -1 : +1;
}

bool left_turn(const point &a, const point &b, const point &c) {
    return cross_sign(b - a, c - a) > 0;
}

bool compare_x(const point &a, const point &b) {
    return a.x < b.x;
}

// monotonic_dp_hull enables you to do the following two operations in amortized O(1) time:
// 1. Insert a pair (a_i, b_i) into the structure. a_i must be non-decreasing.
// 2. For any value of x, query the maximum value of a_i * x + b_i. x must be non-decreasing.
// All values a_i, b_i, and x can be positive or negative.
struct monotonic_dp_hull {
    deque<point> points;

    void clear() {
        points.clear();
        prev_x = -LL_INF;
        prev_y = 1;
    }

    int size() const {
        return points.size();
    }

    void insert(const point &p) {
        assert(points.empty() || p.x >= points.back().x);

        if (!points.empty() && p.x == points.back().x) {
            if (p.y <= points.back().y)
                return;

            points.pop_back();
        }

        while (size() >= 2 && !left_turn(p, points.back(), points[size() - 2]))
            points.pop_back();

        points.push_back(p);
    }

    void insert(long long a, long long b) {
        insert(point(a, b));
    }

    long long prev_x = -LL_INF, prev_y = 1;

    // Queries the maximum value of ax + by.
    long long query(long long x, long long y = 1) {
        assert(size() > 0);
        assert(prev_x == -LL_INF || x * prev_y >= prev_x * y);
        prev_x = x; prev_y = y;

        while (size() >= 2 && x * (points[1].x - points[0].x) >= (points[0].y - points[1].y) * y)
            points.pop_front();

        return points[0].x * x + points[0].y * y;
    }

    void print() const {
        for (point p : points)
            cerr << p << ' ';

        cerr << endl;
    }
};

monotonic_dp_hull minkowski_sum(const monotonic_dp_hull &h1, const monotonic_dp_hull &h2) {
    assert(h1.size() > 0 && h2.size() > 0);
    monotonic_dp_hull sum;
    int index1 = 0, index2 = 0;

    while (index1 < h1.size() - 1 || index2 < h2.size() - 1) {
        sum.insert(h1.points[index1] + h2.points[index2]);

        if (index1 == h1.size() - 1) {
            index2++;
            continue;
        }

        if (index2 == h2.size() - 1) {
            index1++;
            continue;
        }

        point delta1 = h1.points[index1 + 1] - h1.points[index1];
        point delta2 = h2.points[index2 + 1] - h2.points[index2];

        if (left_turn(point(0, 0), delta2, delta1))
            index1++;
        else
            index2++;
    }

    sum.insert(h1.points.back() + h2.points.back());
    return sum;
}

struct edge {
    int node = -1;
    point p = {0, 0};

    edge() {}

    edge(int _node, const point &_p) : node(_node), p(_p) {}
};

int N, M, V;
vector<vector<edge>> adj;
vector<int> depth;
vector<int> subtree_size;

struct node_info {
    int node = -1, parent = -1;
    point p = {0, 0};

    node_info() {}

    node_info(int _node, int _parent, point _p)
        : node(_node), parent(_parent), p(_p) {}
};

vector<node_info> nodes;

void add_edge(int u, int v, const point &p) {
    assert(u != v);
    adj[u].emplace_back(v, p);
    adj[v].emplace_back(u, p);
}

void add_default_edge(int u, int v) {
    add_edge(u, v, point(0, 0));
}

void add_edge_from_edge(int u, int v, const edge &e) {
    add_edge(u, v, e.p);
}

void erase_edge(int from, int to) {
    for (edge &e : adj[from])
        if (e.node == to) {
            swap(e, adj[from].back());
            adj[from].pop_back();
            return;
        }

    assert(false);
}

/*
Adds vertices and edges to the tree so that no node has degree > 3. Example:
    1             1
 / / \ \   ->    / \\
2 3   4 5       2   o
                   / \\
                  3   o
                     / \
                    4   5
The o's are dummy vertices. The \\ edges (coming upward from each o) are dummy edges as well.
*/
void binarize_dfs(int node, int parent) {
    edge parent_edge;

    for (edge &e : adj[node])
        if (e.node == parent) {
            parent_edge = e;
            swap(e, adj[node].back());
            adj[node].pop_back();
            break;
        }

    for (edge &e : adj[node])
        binarize_dfs(e.node, node);

    auto &&reassign_parent = [&](int parent_node) {
        const edge &e = adj[node].back();
        erase_edge(e.node, node);
        add_edge_from_edge(parent_node, e.node, e);
        adj[node].pop_back();
    };

    if (adj[node].size() > 2) {
        int current_node = adj.size();
        adj.emplace_back();

        reassign_parent(current_node);
        reassign_parent(current_node);

        while (adj[node].size() > 1) {
            int new_node = adj.size();
            adj.emplace_back();

            reassign_parent(new_node);
            add_default_edge(new_node, current_node);
            current_node = new_node;
        }

        add_default_edge(node, current_node);
    }

    if (parent >= 0)
        adj[node].push_back(parent_edge);
}

void binarize_tree() {
    binarize_dfs(0, -1);
}

int dfs(int node, int parent = -1, point p = {0, 0}) {
    if (parent < 0)
        nodes.clear();

    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    subtree_size[node] = 1;
    nodes.emplace_back(node, parent, p);

    for (edge &e : adj[node])
        if (e.node != parent)
            subtree_size[node] += dfs(e.node, node, p + e.p);

    return subtree_size[node];
}

pair<int, int> centroid_edge(int root) {
    int n = dfs(root);
    assert((int) nodes.size() == n);
    int best = -1;
    pair<int, int> centroid(-1, -1);

    for (int i = 0; i < n; i++) {
        int node = nodes[i].node, parent = nodes[i].parent;
        int smaller = min(subtree_size[node], n - subtree_size[node]);

        if (smaller > best) {
            best = smaller;
            centroid = {node, parent};
        }
    }

    assert(centroid.first >= 0);
    int bigger = max(subtree_size[centroid.first], n - subtree_size[centroid.first]);
    assert(bigger <= (2 * n + 2) / 3);
    return centroid;
}

monotonic_dp_hull global_optimal;
vector<point> global_candidates;

void add_candidate(point candidate) {
    global_candidates.push_back(candidate);
}

void solve(int root) {
    pair<int, int> centroid = centroid_edge(root);
    int below = centroid.first;
    int above = centroid.second;

    if (below < 0 || above < 0)
        return;

    edge centroid_edge;

    for (edge &e : adj[below])
        if (e.node == above) {
            centroid_edge = e;
            break;
        }

    erase_edge(above, below);
    erase_edge(below, above);

    int n = dfs(below, -1, centroid_edge.p);
    vector<node_info> below_nodes = nodes;

    int m = dfs(above);
    vector<node_info> &above_nodes = nodes;

    vector<point> below_points(n), above_points(m);

    for (int i = 0; i < n; i++)
        below_points[i] = below_nodes[i].p;

    for (int i = 0; i < m; i++)
        above_points[i] = above_nodes[i].p;

    sort(below_points.begin(), below_points.end(), compare_x);
    sort(above_points.begin(), above_points.end(), compare_x);
    monotonic_dp_hull below_hull, above_hull;

    for (point &p : below_points)
        below_hull.insert(p);

    for (point &p : above_points)
        above_hull.insert(p);

    monotonic_dp_hull sum = minkowski_sum(below_hull, above_hull);

    for (point &p : sum.points)
        add_candidate(p);

    solve(below);
    solve(above);
}

int main() {
    // monotonic_dp_hull a, b;
    // a.insert(0, 5);
    // a.insert(3, 4);
    // a.insert(4, 3);
    // a.insert(5, 1);
    // b.insert(0, 4);
    // b.insert(3, 4);
    // b.insert(5, 0);
    // minkowski_sum(a, b).print();
    // return 0;

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v, a, b;
        cin >> u >> v >> a >> b;
        u--; v--;
        add_edge(u, v, point(a, b));
    }

    // Binary trees always contain an edge that can be used to split the tree into at worst 1/3 and 2/3.
    binarize_tree();
    V = adj.size();

    depth.resize(V);
    subtree_size.resize(V);
    solve(0);
    sort(global_candidates.begin(), global_candidates.end(), compare_x);
    global_optimal.insert(0, 0);

    for (point &candidate : global_candidates)
        global_optimal.insert(candidate);

    for (int t = 0; t < M; t++)
        cout << global_optimal.query(t) << (t < M - 1 ? ' ' : '\n');
}