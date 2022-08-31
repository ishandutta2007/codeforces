#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

namespace IO {
    const int BUFFER_SIZE = 1 << 15;

    char input_buffer[BUFFER_SIZE];
    int input_pos = 0, input_len = 0;

    void _update_input_buffer() {
        input_len = fread(input_buffer, sizeof(char), BUFFER_SIZE, stdin);
        input_pos = 0;

        if (input_len == 0)
            input_buffer[0] = EOF;
    }

    inline char next_char(bool advance = true) {
        if (input_pos >= input_len)
            _update_input_buffer();

        return input_buffer[advance ? input_pos++ : input_pos];
    }

    template<typename T>
    inline void read_int(T &number) {
        bool negative = false;
        number = 0;

        while (!isdigit(next_char(false)))
            if (next_char() == '-')
                negative = true;

        do {
            number = 10 * number + (next_char() - '0');
        } while (isdigit(next_char(false)));

        if (negative)
            number = -number;
    }

    template<typename T, typename... Args>
    inline void read_int(T &number, Args &... args) {
        read_int(number);
        read_int(args...);
    }
}

const bool CHECK_OVERFLOW64 = false;

struct point {
    long long x, y;

    point() : x(0), y(0) {}

    point(long long _x, long long _y) : x(_x), y(_y) {}

    point operator-(const point &other) const {
        return point(x - other.x, y - other.y);
    }
};

long long cross(const point &a, const point &b) {
    return a.x * b.y - b.x * a.y;
}

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

// dp_hull enables you to do the following two operations in amortized O(log n) time:
// 1. Insert a pair (a_i, b_i) into the structure
// 2. For any value of x, query the maximum value of a_i * x + b_i
// All values a_i, b_i, and x can be positive or negative.
struct dp_hull {
    struct segment {
        point p;
        mutable point next_p;

        segment(point _p = {0, 0}) : p(_p), next_p(_p) {}

        bool operator<(const point &other) const {
            return other.x * (next_p.x - p.x) > (p.y - next_p.y) * other.y;
        }

        bool operator<(const segment &other) const {
            return make_pair(p.x, p.y) < make_pair(other.p.x, other.p.y);
        }
    };

    set<segment, less<>> segments;

    int size() const {
        return segments.size();
    }

    set<segment, less<>>::iterator prev(set<segment, less<>>::iterator it) const {
        return it == segments.begin() ? it : --it;
    }

    set<segment, less<>>::iterator next(set<segment, less<>>::iterator it) const {
        return it == segments.end() ? it : ++it;
    }

    bool bad(set<segment, less<>>::iterator it) const {
        return it != segments.begin() && next(it) != segments.end() && !left_turn(next(it)->p, it->p, prev(it)->p);
    }

    void insert(const point &p) {
        auto next_it = segments.lower_bound(segment(p));

        if (next_it != segments.end() && p.x == next_it->p.x)
            return;

        if (next_it != segments.begin()) {
            auto prev_it = prev(next_it);

            if (p.x == prev_it->p.x)
                segments.erase(prev_it);
            else if (next_it != segments.end() && !left_turn(next_it->p, p, prev_it->p))
                return;
        }

        auto it = segments.insert(next_it, segment(p));

        while (bad(prev(it)))
            segments.erase(prev(it));

        while (bad(next(it)))
            segments.erase(next(it));

        if (it != segments.begin())
            prev(it)->next_p = it->p;

        if (next(it) != segments.end())
            it->next_p = next(it)->p;
    }

    void insert(long long a, long long b) {
        insert(point(a, b));
    }

    // Queries the maximum value of ax + by.
    long long query(long long x, long long y = 1) const {
        assert(size() > 0);
        assert(y > 0);
        auto it = segments.lower_bound(point(x, y));
        return it->p.x * x + it->p.y * y;
    }
};


struct edge {
    int node;

    edge(int _node = -1) : node(_node) {}
};

int N;
vector<long long> value;
vector<vector<edge>> adj;
vector<int> depth;
vector<int> subtree_size;

struct node_info {
    int node = -1, subroot = -1;
    long long node_sum = 0, bottom_up_sum = 0, top_down_sum = 0;

    node_info() {}

    node_info(int _node, int _subroot, long long _node_sum, long long _bottom_up_sum, long long _top_down_sum)
        : node(_node), subroot(_subroot), node_sum(_node_sum), bottom_up_sum(_bottom_up_sum), top_down_sum(_top_down_sum) {}
};

vector<node_info> nodes;

void add_edge(int u, int v) {
    assert(u != v);
    adj[u].emplace_back(v);
    adj[v].emplace_back(u);
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

int dfs(int node, int parent = -1, int subroot = -1, long long node_sum = 0, long long exclusive_sum = 0, long long bottom_up_sum = 0, long long top_down_sum = 0) {
    if (parent < 0) {
        subroot = node;
        nodes.clear();
    }

    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    subtree_size[node] = 1;
    bottom_up_sum += exclusive_sum;
    top_down_sum += (depth[node] + 1) * value[node];

    if (adj[node].size() <= 1)
        nodes.emplace_back(node, subroot, node_sum, bottom_up_sum, top_down_sum);

    for (edge &e : adj[node])
        if (e.node != parent)
            subtree_size[node] += dfs(e.node, node, parent < 0 ? e.node : subroot, node_sum + value[e.node], exclusive_sum + value[e.node], bottom_up_sum, top_down_sum);

    return subtree_size[node];
}

int centroid(int root) {
    int n = dfs(root);
    bool found;

    // Repeatedly move to the subtree that is at least half of the tree, if such a subtree exists.
    do {
        found = false;

        for (edge &e : adj[root])
            if (subtree_size[e.node] < subtree_size[root] && 2 * subtree_size[e.node] >= n) {
                root = e.node;
                found = true;
                break;
            }
    } while (found);

    return root;
}

long long solve_subtree_prefixes() {
    int n = nodes.size();
    dp_hull hull;
    hull.insert(0, 0);
    long long best = 0;

    for (int i = 0, j = 0; i < n; i = j) {
        while (j < n && nodes[i].subroot == nodes[j].subroot)
            j++;

        // Avoid paths within the same subtree by querying each subtree before updating it.
        for (int k = i; k < j; k++) {
            long long here = nodes[k].top_down_sum + hull.query(nodes[k].node_sum);
            best = max(best, here);
        }

        for (int k = i; k < j; k++) {
            int node = nodes[k].node;
            hull.insert(depth[node], nodes[k].bottom_up_sum);
        }
    }

    return best;
}

long long solve(int root) {
    root = centroid(root);

    dfs(root, -1, -1, value[root], 0, 0, 0);
    long long best = solve_subtree_prefixes();

    reverse(nodes.begin(), nodes.end());
    best = max(best, solve_subtree_prefixes());

    // Recurse after solving root, so that edge erasures don't cause incorrect results.
    for (edge &e : adj[root]) {
        erase_edge(e.node, root);
        best = max(best, solve(e.node));
    }

    return best;
}

int main() {
    IO::read_int(N);
    adj.assign(N, {});

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        IO::read_int(u, v);
        u--; v--;
        add_edge(u, v);
    }

    value.resize(N);

    for (int i = 0; i < N; i++)
        IO::read_int(value[i]);

    depth.resize(N);
    subtree_size.resize(N);
    cout << solve(0) << '\n';
}