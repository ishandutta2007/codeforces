#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[300300], ans;
bool visited[300300];

void dfs(int s){
    visited[s] = 1;
    ans.push_back(s);
    vector<int> tmp;
    for (auto &v:adj[s]) if (!visited[v]){
        visited[v] = 1;
        tmp.push_back(v);
    }
    for (auto &v: tmp){
        for (auto &w:adj[v]) if (!visited[w]) dfs(w);
    }
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    fill(visited, visited+n+1, 0);
    for (int i=1;i<=m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    bool chk=1;
    for (int i=1;i<=n;i++) if (!visited[i]) chk=0;
    if (chk){
        printf("YES\n");
        printf("%d\n", (int)ans.size());
        for (auto &x:ans) printf("%d ", x);
        printf("\n");
    }
    else printf("NO\n");
    for (int i=1;i<=n;i++) adj[i].clear();
    ans.clear();
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}