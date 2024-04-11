#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    int n, m, k, ss, x, y;
    long long ans;
    pair<int, int> lst;
    cin >> n >> m >> k >> ss;

    vector<int> occ[k];
    int s[k];
    int a[n];
    for(int i=0; i<n; i++){
        cin >> a[i];
        occ[a[i] - 1].push_back(i);
    }
    int mincost[n][k];
    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            mincost[i][j]=1e9;
        }
    }

    vector<int> g[n];
    for(int i=0; i<m; i++){
        cin >> x >> y;
        g[x-1].push_back(y-1);
        g[y-1].push_back(x-1);
    }

    queue<pair<int, int> > bfs;
    bool vis[n];

    for(int i=0; i<k; i++){
        fill(vis, vis + n, 0);
        for(int j=0; j<occ[i].size(); j++){
            bfs.push(make_pair(occ[i][j], 0));
            vis[occ[i][j]] = 1;
            mincost[occ[i][j]][i] = 0;
        }

        while(!bfs.empty()){
            lst = bfs.front();
            bfs.pop();

            for(int k=0; k<g[lst.first].size(); k++){
                if(vis[g[lst.first][k]] == 0){
                    vis[g[lst.first][k]] = 1;
                    mincost[g[lst.first][k]][i] = min(mincost[g[lst.first][k]][i], lst.second + 1);
                    bfs.push(make_pair(g[lst.first][k], lst.second + 1));
                }
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<k; j++){
            s[j]=mincost[i][j];
        }

        sort(s, s + k);
        ans = 0;
        for(int j=0; j<ss; j++){
            ans += s[j];
        }

        cout << ans << " ";
    }

}