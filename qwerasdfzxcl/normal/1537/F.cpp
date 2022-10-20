#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
bool visited[200200], chk = 1;
vector<int> adj[200200];
int x[200200], y[200200];
bool col[200200];

void dfs(int s, bool c = 0){
    visited[s] = 1;
    col[s] = c;
    for (auto &v:adj[s]){
        if (!visited[v]) dfs(v, c^1);
        else if (col[v]==col[s]){
            chk = 0;
        }
    }
}

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++) scanf("%d", x+i);
    for (int j=1;j<=n;j++) scanf("%d", y+j);
    for (int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1);
    if (!chk){
        ll tmp1 = 0, tmp2 = 0;
        for (int i=1;i<=n;i++){
            if (col[i]) tmp1 += x[i], tmp2 += y[i];
            else tmp1 -= x[i], tmp2 -= y[i];
        }
        ll tmp3 = tmp1%2, tmp4 = tmp2%2;
        if (tmp3<0) tmp3 += 2;
        if (tmp4<0) tmp4 += 2;
        if (tmp3==tmp4) printf("YES\n");
        else printf("NO\n");
    }
    else{
        ll tmp1 = 0, tmp2 = 0;
        for (int i=1;i<=n;i++){
            if (col[i]) tmp1 += x[i], tmp2 += y[i];
            else tmp1 -= x[i], tmp2 -= y[i];
        }
        if (tmp1==tmp2) printf("YES\n");
        else printf("NO\n");
    }

    for (int i=1;i<=n;i++){
        adj[i].clear();
        x[i] = 0;
        y[i] = 0;
        col[i] = 0;
        visited[i] = 0;
        chk = 1;
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