#include <bits/stdc++.h>
#define MAXN 1000000

using namespace std;

vector <int> g[MAXN + 1];
int lvl[MAXN + 1];

vector <int> dist;

void dfs(int nod) {
    int cnt = 0;
    for(auto it : g[nod])
      if(lvl[it] == 0) {
          lvl[it] = lvl[nod] + 1;
          dfs(it);
          cnt++;
      }
    if(cnt == 0)
      dist.push_back(lvl[nod] - 2);
}


int main() {
    //fstream cin("A.in");
    //ofstream cout("A.out");
    int i, n;
    ios::sync_with_stdio(false);
    cin >> n;
    for(i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    int ans = 0;
    lvl[1] = 1;
    for(auto it : g[1]) {
        lvl[it] = 2;
        dist.clear();
        dfs(it);
        if(!dist.empty()) {
            sort(dist.begin(), dist.end());
            for(i = 1; i < dist.size(); i++)
                dist[i] = max(dist[i - 1] + 1, dist[i]);
            ans = max(ans, dist.back() + 1);
        }
    }
    cout << ans;
    //cin.close();
    //cout.close();
    return 0;
}