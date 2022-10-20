#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
vector<int> adj[100100];
int dist[100100], visited[100100], cur = 2, p[100100], col[100100], inv[100100];

void dnc(vector<int> &v, int k){
    /*printf("%d: ", k);
    for (auto &x:v) printf("%d ", x);
    printf("\n");*/
    if ((int)v.size()==1){
        p[k] = v[0], inv[v[0]] = k; return;
    }
    queue<int> q;
    q.push(v[0]);
    dist[v[0]] = 0;
    visited[v[0]] = cur+1;
    for (int i=1;i<(int)v.size();i++) dist[v[i]] = 1e9, visited[v[i]] = cur;
    while(!q.empty()){
        int x = q.front(); q.pop();
        for (auto &y:adj[x]) if (visited[y]==cur){
            visited[y] = cur+1;
            dist[y] = dist[x]+1;
            q.push(y);
        }
    }

    vector<int> v1, v2;
    int s;
    for (int i=0;i<(int)v.size();i++) if (dist[v[i]]==1) {s = v[i]; break;}
    q.push(s);
    visited[s] = cur+2;
    while(!q.empty()){
        int x = q.front(); q.pop();
        v1.push_back(x);
        for (auto &y:adj[x]) if (visited[y]==cur+1 && dist[x]<dist[y]){
            visited[y] = cur+2;
            q.push(y);
        }
    }
    int tmp = cur+1;
    cur += 3;

    dnc(v1, k);
    for (int i=0;i<(int)v1.size();i++){
        for (auto &x:adj[v1[i]]) if (visited[x]==tmp) p[inv[v1[i]]+(int)v1.size()] = x, inv[x] = inv[v1[i]]+(int)v1.size();
    }
}

void solve(){
    int n;
    scanf("%d", &n);
    cur = 2;
    fill(visited, visited+(1<<n), 0);
    vector<int> v;
    for (int i=0;i<(1<<n);i++) v.push_back(i);
    for (int i=0;i<n*(1<<(n-1));i++){
        int x, y;
        scanf("%d %d", &x, &y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dnc(v, 0);

    for (int i=0;i<(1<<n);i++) adj[i].clear();
    for (int i=0;i<(1<<n);i++) col[i] = 0;

    for (int i=0;i<(1<<n);i++) printf("%d ", p[i]);
    printf("\n");
    if (__builtin_popcount(n)!=1){printf("-1\n"); return;}
    for (int i=0;i<(1<<n);i++){
        inv[p[i]] = i;
        for (int j=0;j<n;j++) if (i&(1<<j)) col[i] ^= j;
    }
    /*for (int i=0;i<(1<<n);i++) printf("%d ", col[i]);
    printf("\n");*/
    for (int i=0;i<(1<<n);i++) printf("%d ", col[inv[i]]);
    printf("\n");
}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        solve();
    }
    return 0;
}