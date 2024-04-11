/**
 * Author   : rama_pang
 * Problem  : https://codeforces.com/contest/962/problem/F
 * Time     : O(N log N)
 * Memory   : O(N)
**/

#include <bits/stdc++.h>
using namespace std;

template<int SZ>
struct BCC { // Biconnected Components
    int N;
    vector<int> adj[SZ];
    int disc[SZ], low[SZ], art[SZ];
    vector<pair<int, int>> stk; vector<vector<pair<int, int>>> comps; // edges for each BCC

    int dfs(int n, int p = 0) {
        static int t = 1;

        disc[n] = low[n] = t++;
        int ch = 0;
        
        for (auto &i : adj[n]) if (i != p) {
            if (!disc[i]) {
                stk.emplace_back(i, n);
                ch++;
                dfs(i, n);
                low[n] = min(low[n], low[i]);

                if ((low[i] >= disc[n] && p != 0) || (p == 0 && ch > 1)) { // articulation point
                    vector<pair<int, int>> comp;
                    while (stk.back() != make_pair(i, n)) {
                        comp.emplace_back(stk.back());
                        stk.pop_back();
                    }
                    comp.emplace_back(stk.back());
                    stk.pop_back();
                    comps.emplace_back(comp);
                }
            } else if (disc[i] < disc[n]) {
                stk.emplace_back(i, n);
                low[n] = min(low[n], disc[i]);
            }
        }
    }

    void build(int n) {
        N = n;
        for (int i = 1; i <= N; i++) {
            if (!disc[i]) dfs(i, 0);
            if (stk.size()) comps.emplace_back(stk);
            stk.clear();
        }
    }

    void addEdge(int u, int v) {
        adj[u].emplace_back(v);
        adj[v].emplace_back(u);
    }

};


const int MAXN = 100005;
BCC<MAXN> bcc;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, M;
    cin >> N >> M;

    map<pair<int, int>, int> edgeName;

    for (int i = 1; i <= M; i++) {
        int u, v;
        cin >> u >> v;
        edgeName[{u, v}] = edgeName[{v, u}] = i;
        bcc.addEdge(u, v);
    }

    bcc.build(N);


    set<int> vertices, ans;
    for (auto &comp : bcc.comps) {
        vertices.clear();
        for (auto &i : comp) {
            vertices.emplace(i.first);
            vertices.emplace(i.second);
        }

        if (vertices.size() == comp.size()) { // 1 simple cycle means vertices == edge
            for (auto &i : comp) {
                ans.emplace(edgeName[i]);
            }
        }
    }

    cout << ans.size() << "\n";
    for (auto &i : ans) {
        cout << i << " ";
    }
    cout << "\n";
    return 0;
}