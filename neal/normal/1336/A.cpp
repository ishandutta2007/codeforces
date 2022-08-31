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


int N, K;
vector<vector<int>> adj;
vector<int> depth;
vector<int> subtree_size;

void dfs(int node, int parent) {
    depth[node] = parent < 0 ? 0 : depth[parent] + 1;
    subtree_size[node] = 1;

    for (int neighbor : adj[node])
        if (neighbor != parent) {
            dfs(neighbor, node);
            subtree_size[node] += subtree_size[neighbor];
        }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> K;
    adj.assign(N, {});
    depth.resize(N);
    subtree_size.resize(N);

    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs(0, -1);
    vector<int> sorted(N);

    for (int i = 0; i < N; i++)
        sorted[i] = depth[i] - (subtree_size[i] - 1);

    sort(sorted.rbegin(), sorted.rend());
    int64_t sum = 0;

    for (int k = 0; k < K; k++)
        sum += sorted[k];

    cout << sum << '\n';
}