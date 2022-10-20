#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int a[200200], deg[200200];
vector<int> adj[200200], g[200200], inv[200200];
bool chk[200200], visited[200200], chk2[200200];

int dfs(int s){
    visited[s] = 1;
    if (g[s].empty()) return s;
    return dfs(g[s][0]);
}

void solve(){
    int n;
    scanf("%d", &n);
    for (int i=1;i<=n;i++){
        scanf("%d", a+i);
        adj[i].push_back(a[i]);
        deg[a[i]]++;
    }
    int ans = n;
    queue<int> q;
    for (int i=1;i<=n;i++) if(!deg[i]){
        ans--;
        q.push(i);
    }
    while(!q.empty()){
        int cur = q.front(); q.pop();
        chk[cur] = 1;
        for (auto &v:adj[cur]){
            deg[v]--;
            if (!chk2[v]){
                chk2[v] = 1;
                g[cur].push_back(v);
            }
            if (!deg[v]){
                q.push(v);
            }

        }
    }

    for (int i=1;i<=n;i++) if (!chk[i]){
        if (!chk2[adj[i][0]]){
            g[i].push_back(adj[i][0]);
            chk2[adj[i][0]] = 1;
        }
    }

    for (int i=1;i<=n;i++){
        for (auto &v:g[i]) inv[v].push_back(i);
    }

    vector<pair<int, int>> vec;
    for (int i=1;i<=n;i++) if (inv[i].empty()) vec.emplace_back(i, 0);
    for (auto &p:vec){
        p.second = dfs(p.first);
    }
    //printf("YES\n");

    for (int i=0;i<(int)vec.size();i++){
        int nxt = i+1;
        if (nxt==(int)vec.size()) nxt = 0;
        g[vec[i].second].push_back(vec[nxt].first);
    }

    printf("%d\n", ans);
    for (int i=1;i<=n;i++) printf("%d ", g[i][0]);
    printf("\n");
    ///init
    for (int i=1;i<=n;i++){
        adj[i].clear();
        g[i].clear();
        inv[i].clear();
        chk[i] = 0;
        chk2[i] = 0;
        deg[i] = 0;
        visited[i] = 0;
    }
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}