#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<int> g[n];

    long long num[n];
    fill(num, num + n, 0);
    vector<int> dfs;
    bool part[n];

    int vis[n];
    fill(vis, vis + n, 0);

    for(int i = 0; i<n - 1; i++){
        int x, y;
        cin >> x >> y;

        g[x - 1].push_back(y - 1);
        g[y - 1].push_back(x - 1);
    }

    dfs.push_back(0);
    vis[0] = 1;
    part[0] = 0;

    while(!dfs.empty()){
        int x = dfs.back();
        dfs.pop_back();

        for(int to: g[x]){
            if(!vis[to]){
                vis[to] = 1;
                part[to] = part[x] ^ 1;
                dfs.push_back(to);
            }
        }
    }

    int cnt1, cnt2;
    cnt1 = 0;
    cnt2 = 0;

    for(int i = 0; i<n; i++){
        if(part[i]) cnt1++;
        else cnt2++;
    }

    cout << min(cnt1, cnt2) - 1;


}