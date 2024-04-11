#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> g[n];
    int p[n], h[n];
    p[0] = 0;
    h[0] = 0;

    for(int i = 0; i<n - 1; i++){
        int x, y;
        cin >> x >> y;

        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    vector<int> dfs;
    dfs.push_back(0);

    int vis[n];
    fill(vis, vis + n, 0);
    vis[0] = 1;

    while(!dfs.empty()){
        int x = dfs.back();
        dfs.pop_back();

        for(auto to: g[x]){
            if(vis[to] == 0){
                vis[to] = 1;
                dfs.push_back(to);
                p[to] = x;
                h[to] = h[x] + 1;
            }
        }
    }

    set<int> anc;

    int cnt = 0;
    bool flag1 = 0;
    bool flag2 = 0;
    for(int i = 0; i<n; i++){
        if(g[i].size() == 1){
            if(h[i] & 1) flag1 = 1;
            else flag2 = 1;

            if(i != 0) anc.insert(p[i]);
            else anc.insert(g[i][0]);
            cnt++;
        }
    }

    if(flag2 & flag1) cout << 3 << " ";
    else cout << 1 << " ";

    cout << n - 1 - cnt + anc.size();



}