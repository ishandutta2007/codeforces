#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9 + 7;


lint dist[2000005];
bool vis[2000005];
vector<int> G[2000005][10]; // split the edges into single digits
int cnt;

void add_edge(int u, int v, int x) {
    while (x >= 10) {
        G[++cnt][x % 10].emplace_back(v);
        v = cnt;
        x /= 10;
    }
    G[u][x % 10].emplace_back(v);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M; 
    cin >> N >> M;
    cnt = N;

    for (int i = 1; i <= M; i++) {
        int u, v; cin >> u >> v;
        add_edge(u, v, i);
        add_edge(v, u, i);
    }

    vector<vector<int>> Q1, Q2;
    Q1.emplace_back(vector<int>(1, 1));

    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    vis[1] = true;

    /*  Do BFS prioritising digit 0, then 1, then 2, ...
        As we do BFS, then the lower digits will all be visited first.
        Thus this way we guarantee a shortest path.
    */
    
    while (!Q1.empty()) {
        for (auto x : Q1) {
            for (int digit = 0; digit < 10; digit++) {
                vector<int> nxt;
                for (auto i : x) for (auto v : G[i][digit]) if (!vis[v]) {
                    vis[v] = 1;
                    dist[v] = (10ll * dist[i] + digit) % MOD;
                    nxt.emplace_back(v);
                }
                if (!nxt.empty()) Q2.emplace_back(nxt);
            }
        }

        Q1 = Q2;
        Q2.clear();
    }

    for (int i = 2; i <= N; i++) {
        cout << dist[i] << "\n";
    }

    return 0;

}