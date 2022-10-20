#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
bool chk[200200], visited[200200], visited2[200200];
vector<int> adj[200200], inv[200200];
int deg[200200], cur=1, dp1[200200], dp2[200200];
bool test=0, test2=0;

int dfs(int s){
    if (dp1[s]!=1e9) return dp1[s];
    int ret = s;
    for (int v:adj[s]){
        ret = min(dfs(v), ret);
    }
    dp1[s]=ret;
    return ret;
}

int dfs2(int s){
    if (dp2[s]!=1e9) return dp2[s];
    int ret = s;
    for (int v:inv[s]){
        ret = min(dfs2(v), ret);
    }
    dp2[s]=ret;
    return ret;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    fill(dp1+1, dp1+n+1, 1e9);
    fill(dp2+1, dp2+n+1, 1e9);
    for (int i=0;i<m;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        adj[a].push_back(b);
        inv[b].push_back(a);
        deg[b]++;
        //if (a>b) swap(a, b);
    }
    int c=0;
    queue<int> q;
    for (int i=1;i<=n;i++) if (!deg[i]) q.push(i);
    while(!q.empty()){
        int s = q.front();
        q.pop();
        if (visited[s]) continue;
        visited[s]=1;
        c++;
        for (int v:adj[s]){
            deg[v]--;
            if (!deg[v]) q.push(v);
        }
    }
    if (c!=n){
        printf("-1\n");
        return 0;
    }
    int ans=0;
    for (int i=1;i<=n;i++){
        if (min(dfs(i), dfs2(i))>=i){
            ans++; chk[i]=1;
        }
    }
    printf("%d\n", ans);
    for (int i=1;i<=n;i++){
        if (chk[i]) printf("A");
        else printf("E");
    }
    return 0;
}