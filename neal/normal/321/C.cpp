// Solution to https://codeforces.com/contest/321/problem/C
#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9 + 5;

struct edge {
    int node;

    edge(int _node = -INF) : node(_node) {}
};

int N;
vector<vector<edge>> adj;
vector<char> answer;

void add_edge(int a, int b) {
    assert(a != b);
    adj[a].emplace_back(b);
    adj[b].emplace_back(a);
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

vector<int> subtree_size;

int dfs(int node, int parent = -INF) {
    subtree_size[node] = 1;

    for (edge &e : adj[node])
        if (e.node != parent)
            subtree_size[node] += dfs(e.node, node);

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

void solve(int root, char letter = 'A') {
    root = centroid(root);
    answer[root] = letter;

    for (edge &e : adj[root]) {
        // Erase the edge from e.node back to root.
        erase_edge(e.node, root);
    }

    // Recurse after solving root, so that edge erasures don't cause incorrect results.
    for (edge &e : adj[root])
        solve(e.node, letter + 1);
}

int main() {
    scanf("%d", &N);
    adj.assign(N, {});
    subtree_size.resize(N);
    answer.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        add_edge(a, b);
    }

    solve(0);

    for (int i = 0; i < N; i++) {
        putchar(answer[i]);
        putchar(i < N - 1 ? ' ' : '\n');
    }
}