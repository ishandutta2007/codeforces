#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    int p[n];
    int h[n];
    int edge[n - 1][2];
    vector<int> g[n];

    for(int i = 0; i<n - 1; i++){
        cin >> edge[i][0] >> edge[i][1];
        g[edge[i][0] - 1].push_back(edge[i][1] - 1);
        g[edge[i][1] - 1].push_back(edge[i][0] - 1);
    }


    vector<int> dfs;
    vector<int> sons[n];
    int vis[n];
    fill(vis, vis + n, 0);
    vis[0] = 1;
    dfs.push_back(0);
    p[0] = 0;
    h[0] = 0;

    while(!dfs.empty()){
        int x = dfs.back();
        dfs.pop_back();

        for(int i = 0; i<g[x].size(); i++){
            if(vis[g[x][i]] == 0){
                vis[g[x][i]] = 1;
                p[g[x][i]] = x;
                dfs.push_back(g[x][i]);
                sons[x].push_back(g[x][i]);
                h[g[x][i]] = h[x] + 1;
            }
        }
    }

    int rem[n], son[n], cnt[n];
    fill(son, son + n, -1);
    for(int i = 0; i<n; i++){
        rem[i] = sons[i].size();
        if(rem[i] == 0) dfs.push_back(i);
    }

    while(!dfs.empty()){
        int x = dfs.back();
        dfs.pop_back();
        int ma = 0;
        int pos;
        int sum = 0;

        for(int i = 0; i<sons[x].size(); i++){
            sum += cnt[sons[x][i]];

            if(cnt[sons[x][i]] > ma){
                pos = i;
                ma = cnt[sons[x][i]];
            }
        }

        cnt[x] = sum + 1;
        if(sons[x].size()){
            son[x] = sons[x][pos];
        }

        rem[p[x]]--;
        if(rem[p[x]] == 0) dfs.push_back(p[x]);
    }

    cout << 'd' << " " << 1 << endl;
    fflush(stdout);
    int depth;
    cin >> depth;

    int other_node = 0;

    while(1){
        if(sons[other_node].empty()){
            cout << "! " << other_node + 1 << endl;
            return 0;
        }

        while(son[other_node] != -1){
            other_node = son[other_node];
        }



        cout << "d " << other_node + 1 << endl;
        fflush(stdout);
        int other_dist;
        cin >> other_dist;

        if(other_dist + depth == h[other_node]){
            for(int i = 0; i<other_dist; i++){
                other_node = p[other_node];
            }

            cout << "! " << other_node + 1 << endl;
            return 0;
        }

        other_dist -= (other_dist + depth - h[other_node]) / 2;

        for(int i = 0; i<other_dist; i++){
            other_node = p[other_node];
        }

        cout << "s " << other_node + 1 << endl;
        fflush(stdout);
        cin >> other_node;
        other_node--;

    }

}