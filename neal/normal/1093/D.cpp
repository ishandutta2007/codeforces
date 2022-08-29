#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
using namespace std;


struct check_bipartite {
    int V;
    vector<vector<int>> adj;
    vector<int> depth;
    vector<bool> visited;

    check_bipartite(int v = 0) {
        if (v > 0)
            init(v);
    }

    void init(int v) {
        V = v;
        adj.assign(V, {});
        depth.assign(V, -1);
        visited.assign(V, false);
    }

    void add_edge(int a, int b) {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    pair<int, int> dfs(int node, int parent) {
        assert(!visited[node]);
        depth[node] = parent < 0 ? 0 : depth[parent] + 1;
        visited[node] = true;
        pair<int, int> sizes = {0, 0};

        if (depth[node] % 2 == 0)
            sizes.first++;
        else
            sizes.second++;

        for (int neighbor : adj[node])
            if (neighbor != parent) {
                if (!visited[neighbor]) {
                    pair<int, int> p = dfs(neighbor, node);

                    if (p.first < 0)
                        return {-1, -1};

                    sizes.first += p.first;
                    sizes.second += p.second;
                }

                if (depth[node] % 2 == depth[neighbor] % 2)
                    return {-1, -1};
            }

        return sizes;
    }

    vector<pair<int, int>> solve() {
        vector<pair<int, int>> sizes;

        for (int i = 0; i < V; i++)
            if (!visited[i])
                sizes.push_back(dfs(i, -1));

        return sizes;
    }

    static bool is_valid(const vector<pair<int, int>> &sizes) {
        for (pair<int, int> p : sizes)
            if (p.first < 0)
                return false;

        return true;
    }
};


const int MOD = 998244353;

long long mod_pow(long long a, long long p, long long m = MOD) {
    long long result = 1;

    while (p > 0) {
        if (p & 1)
            result = result * a % m;

        a = a * a % m;
        p >>= 1;
    }

    return result;
}

void solve_case() {
    int N, M;
    scanf("%d %d", &N, &M);
    check_bipartite solver(N);

    for (int i = 0; i < M; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        u--; v--;
        solver.add_edge(u, v);
    }

    vector<pair<int, int>> sizes = solver.solve();

    if (!check_bipartite::is_valid(sizes)) {
        puts("0");
        return;
    }

    long long answer = 1;

    for (pair<int, int> p : sizes)
        answer = answer * (mod_pow(2, p.first) + mod_pow(2, p.second)) % MOD;

    printf("%lld\n", answer);
}

int main() {
    int T;
    scanf("%d", &T);

    while (T-- > 0)
        solve_case();
}