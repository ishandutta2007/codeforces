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

// Note: if there is a cycle, the size of the return will be less than n.
vector<int> topological_sort(const vector<vector<int>> &adj) {
    int n = int(adj.size());
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < int(order.size())) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}


struct edge {
    int type, x, y;
};

void run_case() {
    int N, M;
    cin >> N >> M;
    vector<edge> edges(M);
    vector<vector<int>> adj(N);

    for (edge &e : edges) {
        cin >> e.type >> e.x >> e.y;
        e.x--; e.y--;

        if (e.type == 1)
            adj[e.x].push_back(e.y);
    }

    vector<int> order = topological_sort(adj);

    if (int(order.size()) < N) {
        cout << "NO" << '\n';
        return;
    }

    vector<int> location(N, -1);

    for (int i = 0; i < N; i++)
        location[order[i]] = i;

    cout << "YES" << '\n';

    for (edge &e : edges) {
        if (location[e.x] > location[e.y])
            swap(e.x, e.y);

        cout << e.x + 1 << ' ' << e.y + 1 << '\n';
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    int tests;
    cin >> tests;

    while (tests-- > 0)
        run_case();
}