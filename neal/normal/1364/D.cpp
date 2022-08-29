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


int N, M, K;
vector<vector<int>> adj;

void output_independent(vector<int> independent) {
    assert(int(independent.size()) >= (K + 1) / 2);

    while (int(independent.size()) > (K + 1) / 2)
        independent.pop_back();

    cout << 1 << '\n';
    output_vector(independent, true);
    exit(0);
}

void output_cycle(vector<int> cycle) {
    assert(int(cycle.size()) <= K);
    cout << 2 << '\n';
    cout << cycle.size() << '\n';
    output_vector(cycle, true);
    exit(0);
}

vector<int> parent;
vector<int> depth;

void find_cycle(int a, int b) {
    vector<int> left, right;

    while (a >= 0) {
        left.push_back(a);
        a = parent[a];
    }

    while (b >= 0) {
        right.push_back(b);
        b = parent[b];
    }

    assert(left.back() == right.back());
    int common = left.back();

    while (!left.empty() && !right.empty() && left.back() == right.back()) {
        common = left.back();
        left.pop_back();
        right.pop_back();
    }

    right.push_back(common);
    reverse(right.begin(), right.end());
    left.insert(left.end(), right.begin(), right.end());
    output_cycle(left);
}

void dfs(int node, int par) {
    parent[node] = par;
    depth[node] = par < 0 ? 0 : depth[par] + 1;

    for (int neigh : adj[node]) {
        if (depth[neigh] >= 0 && depth[node] % 2 == depth[neigh] % 2)
            find_cycle(node, neigh);

        if (depth[neigh] < 0)
            dfs(neigh, node);
    }
}

int main() {
    ios::sync_with_stdio(false);
#ifndef NEAL_DEBUG
    cin.tie(nullptr);
#endif

    cin >> N >> M >> K;
    N = K;
    adj.assign(K, {});

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;

        if (u < K && v < K) {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }

    depth.assign(K, -1);
    parent.assign(K, -1);

    for (int i = 0; i < K; i++)
        if (depth[i] < 0)
            dfs(i, -1);

    vector<int> side[2];

    for (int i = 0; i < K; i++)
        side[depth[i] % 2].push_back(i);

    output_independent(side[0].size() < side[1].size() ? side[1] : side[0]);
}