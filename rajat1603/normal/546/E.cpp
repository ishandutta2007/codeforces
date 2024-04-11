#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;
const int N = 203;
int source;
int sink;
int a[N];
int b[N];
int adj[N][N] = {0};
int ans[N][N];
int n , m;
int parent[N];
bool visited[N];
int sum = 0;
int sum2 = 0;
bool bfs(){
    memset(visited , 0 , sizeof(bool)*N);
    queue <int> q;
    q.push(source);
    visited[source] = 1;
    parent[source] = -1;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        for(int i = 0 ; i <= n + n + 1 ; ++i){
            if(!visited[i] && adj[node][i]){
                q.push(i);
                visited[i] = 1;
                parent[i] = node;
            }
        }
    }
    return visited[sink];
}
int flow(){
    int maxflow = 0;
    while(bfs()){
        int tempflow = 999999;
        for(int i = sink ; i != source ; i = parent[i]){
            tempflow = min(tempflow , adj[parent[i]][i]);
        }
        for(int i = sink ; i != source ; i = parent[i]){
            adj[parent[i]][i] -= tempflow;
            adj[i][parent[i]] += tempflow;
        }
        maxflow += tempflow;
    }
    return maxflow;
}
int main(){
    cin>>n>>m;
    source = 0;
    sink = n + n + 1;
    for(int i = 1 ; i <= n ; ++i){
        cin>>a[i];
        ans[i][i] = a[i];
        sum += a[i];
    }
    for(int i = 1 ; i <= n ; ++i){
        cin>>b[i];
        sum -= b[i];
        sum2 += b[i];
    }
    if(sum){
        printf("NO");
        return 0;
    }
    while(m--){
        int x , y;
        cin>>x>>y;
        adj[x][y+n] = 999999;
        adj[y][x+n] = 999999;
    }
    for(int i = 1 ; i <= n ; ++i){
        adj[0][i] = a[i];
        adj[i][i + n] = 999999;
        adj[i + n][n + n + 1] = b[i];
    }
    if(flow()^sum2){
        printf("NO");
        return 0;
    }
    printf("YES\n");
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1 ; j <= n ; ++j){
            ans[i][j] = adj[n+j][i];
        }
    }
    for(int i = 1 ; i <= n ; ++i){
        for(int j = 1; j <= n ; ++j){
            printf("%d ",ans[i][j]);
        }
        printf("\n");
    }
}