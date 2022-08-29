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
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


struct edge {
    int node, weight;

    edge() {}

    edge(int _node, int _weight) : node(_node), weight(_weight) {}
};

int N, M, K;
vector<bool> is_special;
vector<int> special_count;
vector<vector<edge>> tree_adj;
vector<int> C;

// down[node] = the best profit we can make in `node`'s subtree given that we must saturate `node`.
// up[node] = the best profit we can make in the subtree of `node` that its parent is responsible for.
// combined[node] = answer for the whole tree when rooted at `node`.
vector<int64_t> down;
vector<int64_t> up;
vector<int64_t> combined;

bool all_or_nothing(int node) {
    return special_count[node] == 0 || special_count[node] == K;
}

void solve_down(int node, int parent) {
    vector<edge> &children = tree_adj[node];
    down[node] = C[node];
    special_count[node] = is_special[node];

    for (edge &e : children) {
        int child = e.node;
        assert(child != parent);
        solve_down(child, node);
        special_count[node] += special_count[child];
        down[node] += max(down[child] - (all_or_nothing(child) ? 0 : e.weight), INT64_C(0));
    }
}

void solve_up(int node, int parent) {
    vector<edge> &children = tree_adj[node];

    for (edge &e : children) {
        int child = e.node;
        int64_t child_down = max(down[child] - (all_or_nothing(child) ? 0 : e.weight), INT64_C(0));
        up[child] = max(down[node] - child_down + up[node] - (all_or_nothing(child) ? 0 : e.weight), INT64_C(0));
    }

    for (edge &e : children) {
        int child = e.node;
        assert(child != parent);
        solve_up(child, node);
    }

    combined[node] = up[node] + down[node];
}

void solve_tree() {
    down.resize(N);
    special_count.resize(N);
    solve_down(0, -1);

    up.resize(N);
    up[0] = 0;
    combined.resize(N);
    solve_up(0, -1);

    output_vector(combined);
}

vector<vector<edge>> adj;
vector<int> tour_start;
vector<int> low_link;
vector<bool> visited;
int tour;

void bridge_dfs(int node, int parent) {
    assert(!visited[node]);
    visited[node] = true;
    tour_start[node] = tour++;
    low_link[node] = tour_start[node];
    int parent_count = 0;

    for (edge &e : adj[node]) {
        if (e.node == parent && parent_count++ == 0)
            continue;

        if (visited[e.node]) {
            // e.node is a candidate for low_link.
            low_link[node] = min(low_link[node], tour_start[e.node]);
        } else {
            bridge_dfs(e.node, node);

            // If `e` is not a bridge, set its weight to 0.
            if (low_link[e.node] != tour_start[e.node])
                e.weight = 0;

            tree_adj[node].emplace_back(e.node, e.weight);
            // e.node is part of our subtree.
            low_link[node] = min(low_link[node], low_link[e.node]);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M >> K;
    is_special.assign(N, false);

    for (int i = 0; i < K; i++) {
        int x;
        cin >> x;
        x--;
        is_special[x] = true;
    }

    C.resize(N);

    for (auto &c : C)
        cin >> c;

    vector<int> weight(M);

    for (auto &w : weight)
        cin >> w;

    adj.assign(N, {});

    for (int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--; y--;
        adj[x].emplace_back(y, weight[i]);
        adj[y].emplace_back(x, weight[i]);
    }

    tree_adj.assign(N, {});
    tour_start.resize(N);
    low_link.resize(N);
    visited.assign(N, false);
    tour = 0;
    bridge_dfs(0, -1);
    solve_tree();
}