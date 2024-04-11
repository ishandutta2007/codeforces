#include <algorithm>
#include <cassert>
#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;

const int MOD = 1e9 + 7;

int N, M, K;
vector<long long> keys;
map<long long, vector<pair<int, int>>> x_edges;
vector<vector<int>> adj;
vector<int> seen;
int seen_index = 0;

long long mod_pow(long long a, long long b) {
    long long result = 1;

    while (b > 0) {
        if (b & 1)
            result = result * a % MOD;

        a = a * a % MOD;
        b >>= 1;
    }

    return result;
}

void dfs(int v) {
    seen[v] = seen_index;

    for (int neighbor : adj[v])
        if (seen[neighbor] != seen_index)
            dfs(neighbor);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M >> K;
    keys.resize(N);
    adj.resize(N);
    seen.resize(N);

    for (int i = 0; i < N; i++)
        cin >> keys[i];

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        x_edges[keys[u] ^ keys[v]].emplace_back(u, v);
    }

    long long total = 0;

    for (auto it = x_edges.begin(); it != x_edges.end(); it++) {
        seen_index++;
        vector<pair<int, int>> &edges = it->second;
        set<int> vertices;

        for (auto &p : edges) {
            vertices.insert(p.first);
            vertices.insert(p.second);
            adj[p.first].push_back(p.second);
            adj[p.second].push_back(p.first);
        }

        int components = 0;

        for (int v : vertices)
            if (seen[v] != seen_index) {
                dfs(v);
                components++;
            }

        total = (total + mod_pow(2, N - vertices.size() + components)) % MOD;

        for (int v : vertices)
            adj[v].clear();
    }

    total += (mod_pow(2, K) - x_edges.size()) * mod_pow(2, N) % MOD;
    total = (total % MOD + MOD) % MOD;
    cout << total << '\n';
}