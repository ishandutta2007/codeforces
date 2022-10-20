#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[100100];
int dist[100100], n;

int bfs(int s){
    fill(dist+1, dist+n+1, 1e9);
    queue<int> q;
    q.push(s);
    dist[s] = 0;
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for (auto &v:adj[cur]) if (dist[v]>dist[cur]+1){
            dist[v] = dist[cur]+1;
            q.push(v);
        }
    }
    int ret = 0, val = -1;
    for (int i=1;i<=n;i++) if(val<dist[i]){
        val = dist[i];
        ret = i;
    }
    return ret;
}

void solve(){
    int a, b, c, d;
    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
    for (int i=0;i<n-1;i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int tmp1 = bfs(a);
    if (dist[b]<=c){
        printf("Alice\n");
        ///init
        for (int i=1;i<=n;i++) adj[i].clear();

        return;
    }
    int tmp2 = bfs(tmp1);
    int MX = dist[tmp2];
    if (MX<=c*2 || d<=c*2) printf("Alice\n");
    else printf("Bob\n");

    ///init
    for (int i=1;i<=n;i++) adj[i].clear();
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}