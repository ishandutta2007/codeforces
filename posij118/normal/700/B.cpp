#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, k, x, y, cent, ans;
    ans = 0;
    cin >> n >> k;

    vector<int> g[n];
    bool is_uni[n];
    fill(is_uni, is_uni + n, 0);
    for(int i = 0; i<2*k; i++){
        cin >> x;
        is_uni[x-1] = 1;
    }

    for(int i = 0; i<n-1; i++){
        cin >> x >> y;
        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    int p[n];
    p[0] = 0;
    vector<int> dfs;
    int vis[n];
    fill(vis, vis + n, 0);
    vis[0] = 1;
    dfs.push_back(0);
    int rem[n];
    fill(rem, rem + n, 0);
    vector<int> sons[n];

    while(!dfs.empty()){
        x = dfs[dfs.size() - 1];
        dfs.pop_back();
        for(int i = 0; i<g[x].size(); i++){
            if(vis[g[x][i]] == 0){
                vis[g[x][i]] = 1;
                p[g[x][i]] = x;
                dfs.push_back(g[x][i]);
                rem[x]++;
                sons[x].push_back(g[x][i]);
            }
        }
    }

    int unis[n];
    fill(unis, unis + n, 0);
    fill(vis, vis + n, 0);
    for(int i = 0; i<n; i++){
        if(rem[i] == 0) dfs.push_back(i);
    }

    while(!dfs.empty()){
        x = dfs[dfs.size() - 1];
        dfs.pop_back();
        for(int i = 0; i <sons[x].size(); i++){
            unis[x] += unis[sons[x][i]];
        }

        if(is_uni[x]) unis[x]++;
        if(unis[x] >= k){
            cent = x;
            break;
        }

        rem[p[x]]--;
        if(rem[p[x]] == 0) dfs.push_back(p[x]);
    }

    dfs.clear();
    fill(vis, vis + n, 0);
    vis[cent] = 1;
    dfs.push_back(cent);
    int dist[n];
    dist[cent] = 0;
    while(!dfs.empty()){
         x = dfs[dfs.size() - 1];
         if(is_uni[x]) ans += dist[x];
         dfs.pop_back();
         for(int i = 0; i<g[x].size(); i++){
            if(vis[g[x][i]] == 0){
                vis[g[x][i]] = 1;
                dfs.push_back(g[x][i]);
                dist[g[x][i]] = dist[x] + 1;
            }
         }
    }

    cout << ans;
}