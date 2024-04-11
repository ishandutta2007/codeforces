#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<pair<int, int>> adj0[200200], adj[200200];
int a[200200], visited[200200];
bool flag;

void dfs(int s, int c){
    visited[s] = 1;
    a[s] = c;
    for (auto &v:adj[s]){
        if (visited[v.first]){
            if ((c^v.second)!=a[v.first]) flag = 0;
        }
        else dfs(v.first, c^v.second);
    }
}

void dfs2(int s, int pa){
    for (auto &v:adj0[s]) if (v.first!=pa){
        if (v.second==-1) v.second = a[s]^a[v.first];
        printf("%d %d %d\n", s, v.first, v.second);
        dfs2(v.first, s);
    }
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);

    ///init
    for (int i=1;i<=n;i++){
        visited[i] = a[i] = 0;
        adj0[i].clear();
        adj[i].clear();
    }

    for (int i=0;i<n-1;i++){
        int x, y, p, p2;
        scanf("%d %d %d", &x, &y, &p);
        if (p>=0) p2 = __builtin_popcount(p) &1;
        else p2 = -1;
        adj0[x].emplace_back(y, p);
        adj0[y].emplace_back(x, p);

        if (p>=0){
            adj[x].emplace_back(y, p2);
            adj[y].emplace_back(x, p2);
        }

    }

    for (int i=0;i<m;i++){
        int x, y, p;
        scanf("%d %d %d", &x, &y, &p);
        adj[x].emplace_back(y, p);
        adj[y].emplace_back(x, p);
    }

    flag = 1;
    for (int i=1;i<=n;i++) if (!visited[i]) dfs(i, 0);
    if (!flag) {printf("NO\n"); return;}


    printf("YES\n");
    dfs2(1, -1);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}