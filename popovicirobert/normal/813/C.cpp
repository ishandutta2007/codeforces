#include <bits/stdc++.h>
#define MAXN 200000

using namespace std;

vector <int> g[MAXN + 1];
int dist[2][MAXN + 1];


void dfs(int nod, bool t) {
    for(auto it : g[nod])
      if(dist[t][it] == 0) {
           dist[t][it] = dist[t][nod] + 1;
           dfs(it, t);
      }
}

int main() {
   // fstream cin("A.in");
   // ofstream cout("A.out");
    int i, n, x, a, b;
    ios::sync_with_stdio(false);
    cin >> n >> x;
    for(i = 1; i < n; i++) {
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    dist[0][1] = 1;
    dfs(1, 0);
    dist[1][x] = 1;
    dfs(x, 1);
    int ans = 0;
    for(i = 1; i <= n; i++)
        if(dist[0][i] > dist[1][i])
           ans = max(ans, 2 * dist[0][i] - 2);
    cout << ans;
   // cin.close();
   // cout.close();
    return 0;
}