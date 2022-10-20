#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int deg[100100];
vector<int> adj[100100];
bool visited[100100];

void solve(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i=1;i<=n;i++) adj[i].clear();
    fill(deg, deg+n+1, 0);
    fill(visited, visited+n+1, 0);
    for (int i=0;i<m;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        if (x==y) deg[x] = -1;
        else deg[x]++, deg[y]++;
    }
    int ans=0;
    for (int i=1;i<=n;i++) if (!visited[i] && deg[i]==1){
        int cur = i;
        visited[cur] = 1;
        while(!adj[cur].empty()){
            ans++;
            cur = adj[cur][0];
            visited[cur] = 1;
        }
    }
    for (int i=1;i<=n;i++) if (!visited[i] && deg[i]==2){
        int cur = i, cnt=1;
        visited[i] = 1;
        while(adj[cur][0]!=i){
            //printf("YES\n");
            cnt++;
            cur = adj[cur][0];
            visited[cur] = 1;
        }
        ans += cnt+1;
    }
    printf("%d\n", ans);
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}