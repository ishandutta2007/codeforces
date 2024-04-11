#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<vector<array<int, 2>>> adj;
array<int, 2> Edge[200005];
bool vis[200005];
bool evis[200005];
int par[200005];
int pid[200005];
int dep[200005];
void dfs(int c, int p, int pd, int d) {
    vis[c] = true;
    par[c] = p;
    pid[c] = pd;
    dep[c] = d;
    for(auto it : adj[c]) {
        if(vis[it[0]]) continue;
        evis[it[1]] = true;
        dfs(it[0], c, it[1], d+1);
    }
}
signed main() {
    cin.sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    while(t--) {
        int N, M;
        cin >> N >> M;
        int i, j;
        adj.clear();
        adj.resize(N);
        for(i=0;i<M;i++) {
            int a, b;
            cin >> a >>b;
            adj[a-1].push_back({b-1, i});
            adj[b-1].push_back({a-1, i});
            Edge[i] = {a-1, b-1};
        }
        for(i=0;i<N;i++) vis[i] = false;
        for(i=0;i<M;i++) evis[i] = false;
        dfs(0, -1, -1, 0);
        vector<int> E;
        for(i=0;i<M;i++) {
            if(!evis[i]) E.push_back(i);
        }
        if(E.size() <= 2) {
            for(i=0;i<M;i++) {
                cout << (evis[i]?1:0);
            }
            cout << '\n';
        }
        else {
            set<int> S;
            for(i=0;i<E.size();i++) {
                S.insert(Edge[E[i]][0]);
                S.insert(Edge[E[i]][1]);
            }
            if(S.size()>=4) {
                for(i=0;i<M;i++) {
                    cout << (evis[i] ? 1:0);
                }
                cout << '\n';
            }
            else {
                vector<int> V;
                for(int n : S) V.push_back(n);
                sort(V.begin(),V.end(),[&](int x, int y) {
                     return dep[x] < dep[y];
                     });
                vector<bool> ans;
                ans.resize(M);
                ans[pid[V[2]]] = true;
                for(i=0;i<E.size();i++) {
                    int id = E[i];
                    int x = Edge[id][0], y = Edge[id][1];
                    if(dep[x]>dep[y]) swap(x, y);
                    if(x == V[0] && y == V[1]) ans[id] = true;
                    if(x == V[1] && y == V[2]) ans[id] = true;
                }
                for(i=0;i<M;i++) {
                    cout << (ans[i] ? 1 : 0);
                }
                cout << '\n';
            }
        }
    }
}