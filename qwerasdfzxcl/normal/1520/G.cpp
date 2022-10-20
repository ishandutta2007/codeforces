#include <bits/stdc++.h>

typedef long long ll;
using namespace std;
int matrix[2020][2020], cnt=0, dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};
vector<pair<int, int>> portal;
ll dist[2020][2020], dist2[2020][2020];
bool visited[2020][2020], visited2[2020][2020];

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, m, w;
    cin >> n >> m >> w;
    for (int i=0;i<=n+1;i++){
        fill(matrix[i], matrix[i]+m+2, -1);
        fill(dist[i], dist[i]+m+2, 1e18);
        fill(dist2[i], dist2[i]+m+2, 1e18);
    }
    for (int i=1;i<=n;i++){
        for (int j=1;j<=m;j++){
            cin >> matrix[i][j];
            if (matrix[i][j]>0) portal.push_back({i, j});
        }
    }
    queue<pair<int, int>> q;
    q.push({1, 1});
    dist[1][1] = 0;
    visited[1][1] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for (int k=0;k<4;k++) if (!visited[cur.first+dx[k]][cur.second+dy[k]] && matrix[cur.first+dx[k]][cur.second+dy[k]]!=-1){
            dist[cur.first+dx[k]][cur.second+dy[k]] = dist[cur.first][cur.second]+w;
            visited[cur.first+dx[k]][cur.second+dy[k]] = 1;
            q.push({cur.first+dx[k],cur.second+dy[k]});
        }
    }
    q.push({n, m});
    dist2[n][m] = 0;
    visited2[n][m] = 1;
    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        for (int k=0;k<4;k++) if (!visited2[cur.first+dx[k]][cur.second+dy[k]] && matrix[cur.first+dx[k]][cur.second+dy[k]]!=-1){
            dist2[cur.first+dx[k]][cur.second+dy[k]] = dist2[cur.first][cur.second]+w;
            visited2[cur.first+dx[k]][cur.second+dy[k]] = 1;
            q.push({cur.first+dx[k],cur.second+dy[k]});
        }
    }
    ll ans = dist[n][m];
    for (auto &p:portal) dist[p.first][p.second] += matrix[p.first][p.second], dist2[p.first][p.second] += matrix[p.first][p.second];
    vector<ll> d1, d2;
    for (auto &p:portal){
        //cout << dist[p.first][p.second] << ' ' << dist2[p.first][p.second] << '\n';
        d1.push_back(dist[p.first][p.second]);
        d2.push_back(dist2[p.first][p.second]);
    }
    sort(d1.begin(), d1.end());
    sort(d2.begin(), d2.end());
    if (!portal.empty())ans = min(d1[0]+d2[0], ans);
    if (ans==1e18) cout << -1;
    else cout << ans;
    //cout << d1[0] << ' ' << d2[0];
    return 0;
}