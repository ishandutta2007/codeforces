#include <bits/stdc++.h>
using namespace std;
vector<vector<long long> > g;
int n, m, L, s, t, x, y, z, si;
long long len, cur, mi, ma, val;


long long dijkstra(){
    long long dist[n], mi;
    int pos;
    bool vis[n];
    fill(vis, vis + n, 0);
    fill(dist, dist + n, 1e18);
    vis[s] = 1;
    dist[s] = 0;
    for(int j = 0; j<n; j++){
        dist[j] = min(dist[j], dist[s] + g[s][j]);
    }

    for(int i = 0; i<n-1; i++){
        mi = 1e18;
        for(int j = 0; j<n; j++){
            if(dist[j] < mi && vis[j] == 0){
                mi = dist[j];
                pos = j;
            }
        }

        vis[pos] = 1;
        for(int j = 0; j<n; j++){
            dist[j] = min(dist[j], dist[pos] + g[pos][j]);
        }
    }

    return dist[t];
}

int main(){
    cin >> n >> m >> L >> s >> t;
    long long M = 1e9;
    g.resize(n);
    for(int i = 0; i<n; i++){
        g[i].resize(n);
    }

    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            g[i][j] = 2 * M;
        }
    }

    int edg[m][3];
    vector<pair<pair<int, int>, int> > ers;
    for(int i = 0; i<m; i++){
        cin >> x >> y >> z;
        edg[i][0] = x;
        edg[i][1] = y;

        if(z == 0){
            g[x][y] = 1;
            g[y][x] = 1;
            edg[i][2] = 1;
            ers.push_back(make_pair(make_pair(x, y), i));
        }

        else{
            g[x][y] = z;
            g[y][x] = z;
            edg[i][2] = z;
        }
    }

    mi = dijkstra();


    for(int i = 0; i<ers.size(); i++){
        g[ers[i].first.first][ers[i].first.second] = 2*M;
        g[ers[i].first.second][ers[i].first.first] = 2*M;
        edg[ers[i].second][2] = 2*M;
    }
    ma = dijkstra();

    if(L < mi || L > ma){
        cout << "NO";
        return 0;
    }

    long long d, h, mid;
    d = 0;
    h = ers.size() * M - ers.size() + 1;

    for(int i = 0; i<50; i++){
        mid = (d + h)/2;
        cur = 0;
        for(int j = 0; j<ers.size(); j++){
            g[ers[j].first.first][ers[j].first.second] = max(0ll, min(mid - cur, M - 1)) + 1;
            g[ers[j].first.second][ers[j].first.first] = max(0ll, min(mid - cur, M - 1)) + 1;
            edg[ers[j].second][2] =  max(0ll, min(mid - cur, M - 1)) + 1;
            cur += M - 1;
        }
        val = dijkstra();
        if(val > L) h = mid;
        else if(val < L) d = mid;

        else{
            cout << "YES" << endl;
            for(int j = 0; j<m; j++){
                cout << edg[j][0] << " " << edg[j][1] << " " << edg[j][2] << endl;
            }
            return 0;
        }

    }

}