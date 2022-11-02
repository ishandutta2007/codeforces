#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    cin >> n >> m >> k;
    int ans = 0;

    int a[k];
    for(int i = 0; i<k; i++){
        cin >> a[i];
        a[i]--;
    }

    int dist[n][2];
    vector<int> g[n];

    for(int i = 0; i<m; i++){
        int x, y;
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    queue<int> bfs;
    bfs.push(0);
    int vis[n];
    fill(vis, vis + n, 0);
    vis[0] = 1;
    dist[0][0] = 0;

    while(!bfs.empty()){
        int x = bfs.front();
        bfs.pop();

        for(int to: g[x]){
            if(!vis[to]){
                vis[to] = 1;
                dist[to][0] = dist[x][0] + 1;
                bfs.push(to);
            }
        }
    }

    bfs.push(n - 1);
    fill(vis, vis + n, 0);
    vis[n - 1] = 1;
    dist[n - 1][1] = 0;

    while(!bfs.empty()){
        int x = bfs.front();
        bfs.pop();

        for(int to: g[x]){
            if(!vis[to]){
                vis[to] = 1;
                dist[to][1] = dist[x][1] + 1;
                bfs.push(to);
            }
        }
    }

    pair<int, int> dist_spec[k];
    for(int i = 0; i<k; i++){
        dist_spec[i] = {dist[a[i]][0], dist[a[i]][1]};
    }

    sort(dist_spec, dist_spec + k);

    int ma[k];
    ma[k - 1] = dist_spec[k - 1].second;
    for(int i = k - 2; i>=0; i--){
        ma[i] = max(ma[i + 1], dist_spec[i].second);
    }

    for(int i = 0; i<k - 1; i++){
        ans = max(ans, dist_spec[i].first + ma[i + 1] + 1);
    }

  /* for(int i = 0; i<n; i++){
    cout << dist[i][0] << " " << dist[i][1] << endl;
   }
    cout << dist[n - 1][0] << " " << dist[0][1] << endl;*/
    cout << min(ans, dist[n - 1][0]);

}