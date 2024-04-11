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

struct eulerian_solver {
    struct edge {
        int node, rev, index;
        bool done = false;

        edge() {}

        edge(int _node, int _rev, int _index) : node(_node), rev(_rev), index(_index) {}
    };

    int n, edges;
    vector<vector<edge>> adj;

    eulerian_solver(int _n = 0) {
        init(_n);
    }

    void init(int _n) {
        n = _n;
        edges = 0;
        adj.assign(n, {});
    }

    void add_edge(int u, int v, int index) {
        edge uv_edge(v, int(adj[v].size()) + (u == v ? 1 : 0), index);
        edge vu_edge(u, int(adj[u].size()), index);
        adj[u].push_back(uv_edge);
        adj[v].push_back(vu_edge);
        edges++;
    }

    edge &reverse_edge(const edge &e) {
        return adj[e.node][e.rev];
    }

    vector<size_t> edge_index;

    void eulerian_dfs(int node, edge *from_edge, vector<pair<int, edge*>> &tour) {
        while (edge_index[node] < adj[node].size()) {
            edge &e = adj[node][edge_index[node]];

            if (!e.done) {
                e.done = true;
                reverse_edge(e).done = true;
                eulerian_dfs(e.node, &e, tour);
            }

            edge_index[node]++;
        }

        // Generate the actual tour in reverse.
        tour.emplace_back(node, from_edge);
    }

    vector<pair<int, edge*>> solve(bool path_ok) {
        if (edges == 0)
            return {};

        int odd_count = 0;

        for (int i = 0; i < n; i++)
            if (adj[i].size() % 2 != 0)
                odd_count++;

        if (odd_count > 2)
            return {};

        if (!path_ok && odd_count > 0)
            return {};

        int start = -1;

        for (int i = 0; i < n; i++)
            if (adj[i].size() % 2 != 0 || (odd_count == 0 && !adj[i].empty())) {
                start = i;
                break;
            }

        assert(start >= 0);
        edge_index.assign(n, 0);
        vector<pair<int, edge*>> tour;
        eulerian_dfs(start, nullptr, tour);
        reverse(tour.begin(), tour.end());
        int T = int(tour.size());

        if (T - 1 != edges) {
            cerr << "Not connected!" << endl;
            return {};
        }

        // Shift the edges down one index.
        for (int i = 0; i < T - 1; i++)
            tour[i].second = tour[i + 1].second;

        tour.back().second = nullptr;
        return tour;
    }
};

template<typename T>
void output_vector(const vector<T> &v, bool add_one = false, int start = -1, int end = -1) {
    if (start < 0) start = 0;
    if (end < 0) end = int(v.size());

    for (int i = start; i < end; i++)
        cout << v[i] + (add_one ? 1 : 0) << (i < end - 1 ? ' ' : '\n');
}


int N;
vector<int> solution;

bool possible(vector<array<int, 2>> necklace, int bits) {
    for (auto &a : necklace) {
        a[0] %= 1 << bits;
        a[1] %= 1 << bits;
    }

    eulerian_solver solver(1 << bits);

    for (int i = 0; i < N; i++) {
        auto &a = necklace[i];
        solver.add_edge(a[0], a[1], i);
    }

    auto tour = solver.solve(false);
    int T = int(tour.size());

    if (T == 0)
        return false;

    solution = {};

    for (int i = 0; i < T - 1; i++) {
        int index = tour[i].second->index;
        int a = tour[i].first, b = tour[i + 1].first;
        int ai = 0, bi = 1;

        if (necklace[index][ai] != a)
            swap(ai, bi);

        assert(necklace[index][ai] == a);
        assert(necklace[index][bi] == b);

        solution.push_back(2 * index + ai);
        solution.push_back(2 * index + bi);
    }

    return true;
}

const int BITS = 20;

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    vector<array<int, 2>> necklace(N);

    for (auto &a : necklace)
        cin >> a[0] >> a[1];

    int low = 0, high = BITS;

    while (low < high) {
        int mid = (low + high + 1) / 2;

        if (possible(necklace, mid))
            low = mid;
        else
            high = mid - 1;
    }

    possible(necklace, low);
    cout << low << '\n';
    output_vector(solution, true);
}