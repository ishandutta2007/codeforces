                         /* in the name of Allah */
#include <iostream>
#include <memory.h>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <queue>
#include <map>

using namespace std;

#define int64 long long
#define P pair<int, int>

int n;
vector <P> adj[3010];

P dfs(int idx, int mx, int par){
    int sum = 0, bef = mx;
    for(int i = 0; i < adj[idx].size(); i++){
        int j = adj[idx][i].first;
        if(j == par) continue;
        P tmp = dfs(j, max(0, mx + adj[idx][i].second), idx);
        sum += tmp.first + (adj[idx][i].second + 1) / 2;
        bef = max(bef, tmp.second);
    }
    return P(sum, bef);
}

int main(){
    cin >> n;
    int a, b;
    for(int i = 0; i < n - 1; i++){
        cin >> a >> b;
        a--, b--;
        adj[a].push_back(P(b, -1));
        adj[b].push_back(P(a, 1));
    }
    int res = 100000;
    for(int i = 0; i < n; i++){
        P tmp = dfs(i, 0, -1);
        res = min(res, tmp.first - tmp.second);
    }
    cout << res << endl;
    return 0;
}