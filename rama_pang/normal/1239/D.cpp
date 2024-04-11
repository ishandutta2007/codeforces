/**
 * Observation: all indices must be picked
 * Thus if a is picked, and there exists edges
 * from a to cats c, resident c must be picked
 * (since all indices must be picked). Thus we
 * can get rid of the cats, and build a directed
 * graph.
 * 
 * If SCC of this graph is 1, then there is no
 * answer (as we must pick all residents). Otherwise,
 * there exists an SCC which has no outgoing edge
 * (just compress the SCC to 1 node, and since it 
 * becomes a new DAG, there is atleast 1 node (SCC)
 * which doesn't have an outgoing edge).
 * 
 * Pick residents of that SCC, and complement it with
 * cats of other indices.
 * 
**/

#include <bits/stdc++.h>
using namespace std;

void solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}

void solve() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> G(N), Gi(N);
    vector<pair<int, int>> E;
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        if (a == b) {
            continue;
        }
        a--, b--;
        G[a].emplace_back(b);
        Gi[b].emplace_back(a);
        E.emplace_back(a, b);
    }
    M = E.size();

    vector<int> vis(N, 0), ord;
    function<void(int)> dfs = [&](int n) {
        if (vis[n]) {
            return;
        }
        vis[n] = 1;
        for (auto i : G[n]) {
            dfs(i);
        }
        ord.emplace_back(n);
    };
    
    for (int i = 0; i < N; i++) {
        if (vis[i] == 0) {
            dfs(i);
        }
    }

    reverse(begin(ord), end(ord));
    G = Gi;
    
    vis.assign(N, 0);
    vector<vector<int>> scc;
    vector<int> topo = ord;
    for (int i : topo) {
        if (vis[i] == 0) {
            ord.clear();
            dfs(i);
            scc.emplace_back(ord);
        }
    }

    if (scc.size() == 1) {
        cout << "No\n";
        return;
    }

    vector<int> name(N, -1);
    for (int i = 0; i < scc.size(); i++) {
        for (int j = 0; j < scc[i].size(); j++) {
            name[scc[i][j]] = i;
        }
    }

    vector<int> out_deg(scc.size(), 0);
    for (int i = 0; i < M; i++) {
        if (name[E[i].first] == name[E[i].second]) {
            continue;
        }
        out_deg[name[E[i].first]]++;
    }

    int resident_scc = -1;
    for (int i = 0; i < scc.size(); i++) {
        if (out_deg[i] == 0) {
            resident_scc = i;
            break;
        }
    }

    vector<int> ans(N, 0); // 1 = resident, 0 = cat
    for (int i = 0; i < scc[resident_scc].size(); i++) {
        ans[scc[resident_scc][i]] = 1;
    }

    cout << "Yes\n";
    cout << scc[resident_scc].size() << " " << (N - scc[resident_scc].size()) << "\n";
    for (int i = 0; i < N; i++) {
        if (ans[i] == 1) {
            cout << (i + 1) << " ";
        }
    }
    cout << "\n";
    for (int i = 0; i < N; i++) {
        if (ans[i] == 0) {
            cout << (i + 1) << " ";
        }
    }
    cout << "\n";
    
    return;

}