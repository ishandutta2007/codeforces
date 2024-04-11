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


int N;
vector<vector<int>> adj;
vector<int> depth;
vector<int> parent;

void dfs(int node, int par) {
    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;

    for (int neighbor : adj[node])
        if (neighbor != par)
            dfs(neighbor, node);
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N;
    adj.assign(N, {});
    parent.assign(N, -1);
    depth.assign(N, -1);

    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    int root = -1;

    for (int i = 0; i < N; i++)
        if (adj[i].size() > 1)
            root = i;

    assert(root >= 0);
    dfs(root, -1);
    bool seen[2] = {false, false};

    for (int i = 0; i < N; i++)
        if (adj[i].size() == 1)
            seen[depth[i] % 2] = true;

    int minimum = seen[0] && seen[1] ? 3 : 1;
    int maximum = N - 1;
    vector<bool> seen_parent(N, false);

    for (int i = 0; i < N; i++)
        if (adj[i].size() == 1) {
            if (seen_parent[parent[i]])
                maximum--;

            seen_parent[parent[i]] = true;
        }

    cout << minimum << ' ' << maximum << '\n';
}