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

int N;
vector<vector<int>> adj;
vector<int> subtree_size;
vector<array<int, 2>> edges;

void dfs(int node, int parent) {
    subtree_size[node] = 1;

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            dfs(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
        }
}

vector<int> find_centroids() {
    dfs(0, -1);
    assert(subtree_size[0] == N);
    int current = 0, parent = -1;
    bool found;

    // Repeatedly move to the subtree that is at least half of the tree, if such a subtree exists.
    do {
        found = false;

        for (int neighbor : adj[current])
            if (neighbor != parent && 2 * subtree_size[neighbor] >= N) {
                parent = current;
                current = neighbor;
                found = true;
                break;
            }
    } while (found);

    if (2 * subtree_size[current] == N)
        return {current, parent};

    return {current};
}


void run_case() {
    cin >> N;
    adj.assign(N, {});
    subtree_size.resize(N);
    edges.resize(N - 1);

    for (auto &e : edges) {
        cin >> e[0] >> e[1];
        e[0]--; e[1]--;
        adj[e[0]].push_back(e[1]);
        adj[e[1]].push_back(e[0]);
    }

    vector<int> centroids = find_centroids();

    if (centroids.size() == 1) {
        cout << edges[0][0] + 1 << ' ' <<edges[0][1] + 1 << '\n';
        cout << edges[0][0] + 1 << ' ' <<edges[0][1] + 1 << '\n';
        return;
    }

    int a = centroids[0], b = centroids[1];
    int a_neigh = -1;

    for (int x : adj[a])
        if (x != b) {
            a_neigh = x;
            break;
        }

    cout << a_neigh + 1 << ' ' << a + 1 << '\n';
    cout << a_neigh + 1 << ' ' << b + 1 << '\n';
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