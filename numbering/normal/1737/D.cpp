#include <bits/stdc++.h>
#define int long long
using namespace std;
const int INF = 1e18;
int adj[505][505];
int dis[505][505];
int D[505][505];
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
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) adj[i][j] = INF;
        }
        for(i=0;i<N;i++) adj[i][i] = 0;
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) D[i][j] = INF;
        }
        for(i=0;i<M;i++) {
            int u, v, w;
            cin >> u >> v >> w;
            u--, v--;
            adj[u][v] = min(adj[u][v], w);
            adj[v][u] = min(adj[v][u], w);
            D[u][v] = D[v][u] = 1;
        }
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) dis[i][j] = INF;
        }
        queue<array<int, 2>> Q;
        dis[0][N-1] = 0;
        Q.push({0, N-1});
        while(!Q.empty()) {
            array<int, 2> k = Q.front();
            Q.pop();
            for(i=0;i<N;i++) {
                if((k[0]==k[1]||D[k[1]][i]==1)&&dis[k[0]][i]> dis[k[0]][k[1]] + 1) {
                    dis[k[0]][i] = dis[k[0]][k[1]] + 1;
                    Q.push({k[0], i});
                }
            }
            for(i=0;i<N;i++) {
                if((k[0]==k[1]||D[k[0]][i]==1)&&dis[i][k[1]]> dis[k[0]][k[1]] + 1) {
                    dis[i][k[1]] = dis[k[0]][k[1]] + 1;
                    Q.push({i, k[1]});
                }
            }
        }
        int ans = INF;
        for(i=0;i<N;i++) {
            for(j=0;j<N;j++) {
                if(i!=j&&adj[i][j]!=INF) ans = min(ans, adj[i][j] * (1+dis[i][j]));
            }
        }
        cout << ans << '\n';
    }
}