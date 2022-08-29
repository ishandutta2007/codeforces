#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) { os << '{'; string sep; for (const auto &x : v) os << sep << x, sep = ", "; return os << '}'; }
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
    int n = adj.size();
    vector<int> in_degree(n, 0);
    vector<int> order;

    for (int i = 0; i < n; i++)
        for (int neighbor : adj[i])
            in_degree[neighbor]++;

    for (int i = 0; i < n; i++)
        if (in_degree[i] == 0)
            order.push_back(i);

    int current = 0;

    while (current < (int) order.size()) {
        int node = order[current++];

        for (int neighbor : adj[node])
            if (--in_degree[neighbor] == 0)
                order.push_back(neighbor);
    }

    return order;
}


int N, M;
vector<vector<int>> adj, rev_adj;
vector<bool> dead_forward, dead_backward;

void mark_forward(int node) {
    if (dead_forward[node])
        return;

    dead_forward[node] = true;

    for (int neigh : adj[node])
        mark_forward(neigh);
}

void mark_backward(int node) {
    if (dead_backward[node])
        return;

    dead_backward[node] = true;

    for (int neigh : rev_adj[node])
        mark_backward(neigh);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M;
    adj.assign(N, {});
    rev_adj.assign(N, {});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        rev_adj[v].push_back(u);
    }

    if ((int) topological_sort(adj).size() < N) {
        cout << -1 << '\n';
        return 0;
    }

    dead_forward.assign(N, false);
    dead_backward.assign(N, false);
    int all = 0;
    string answer;

    for (int i = 0; i < N; i++) {
        if (!dead_forward[i] && !dead_backward[i]) {
            all++;
            answer += 'A';
        } else {
            answer += 'E';
        }

        mark_forward(i);
        mark_backward(i);
    }

    cout << all << '\n';
    cout << answer << '\n';
}