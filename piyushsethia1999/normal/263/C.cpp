#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

std::vector<int> pp;

void dfs(int u, std::vector<std::vector<int> >& gr, std::vector<bool>& vis) {
    pp.pb(u);
    vis[u] = true;
    for (int v : gr[u]) {
        if (vis[v] != true) {
            dfs(v, gr, vis);
        } 
    }
}

int32_t main()
{
    ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
    int n; cin >> n;
    std::vector<set<int> > gr(n);
    std::vector<std::vector<int> > adj(n);
    for (int i = 0; i < 2 * n; ++i) {
        int u; cin >> u; u--;
        int v; cin >> v; v--;
        gr[u].insert(v);
        gr[v].insert(u);
        adj[u].pb(v);
        adj[v].pb(u);
    }
    for (int i = 0; i < n; ++i) {
        if (gr[i].size() != 4) {
            cout << -1l;
            exit(0);
        } 
        sort(adj[i].begin(), adj[i].end());
    }
    if (n == 5) {
        for (int i = 0; i < n; ++i) {
            cout << i + 1 << " "; 
        }
        return 0;
    } else if(n == 6) {
        int op[n] = {};
        int ii[n] = {};
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && gr[i].find(j) == gr[i].end()) {
                    op[i] = j;
                    op[j] = i;
                    break;
                } 
            }
            ii[op[i]]++;
        }
        for (int i = 0; i < n; ++i) {
            if (ii[i] != 1) {
                cout << -1;
                exit(0);
            } 
        }
        int y = 0;
        int u[6] = {};
        bool vis[6] = {};
        for (int i = 0; i < 6; ++i) {
            if (!vis[i]) {
                vis[i] = true;
                vis[op[i]] = true;
                u[y] = i;
                u[(y + 3) % 6] = op[i];
                y++;
            } 
        }
        for (int i = 0; i < 6; ++i) cout << u[i] + 1 << " ";
        exit(0);
    }
    std::vector<int> vu(10);
    std::vector<std::vector<int> > vv(n);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 4; ++j) {
            int u = adj[i][j];
        	vv[i].pb(u);
            auto it = set_intersection(adj[i].begin(), adj[i].end(), adj[u].begin(), adj[u].end(), vu.begin());
            if (it - vu.begin() == 1)
                vv[i].pop_back();
        }
    }
    for (int i = 0; i < n; ++i) {
        if (vv[i].size() != 2) {
            cout << -1;
            return 0;
        } 
    }
    for (int i = 0; i < n; ++i) {
        int u = vv[i][0], v = vv[i][1];
        if (vv[u][0] != i && vv[u][1] != i) {
            cout << -1;
            return 0;
        } 
        if (vv[v][0] != i && vv[v][1] != i) {
            cout << -1;
            return 0;
        } 
    }
    std::vector<bool> vis(n, false);
    dfs(0, vv, vis);
    if (pp.size() != n) {
        cout << -1;
        return 0;
    } 
    for (int i = 0; i < n; ++i) {
        cout << pp[i] + 1 << " ";
    }
}