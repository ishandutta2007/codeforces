#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, lvmx;
vector<vector<int>> adj(200008);
vector<int> b(200008);
vector<int> lv(200008);
vector<int> lvc(200008);
vector<int> lva(200008);
vector<int> ind(200008);
vector<int> par(200008);

void dfs(int now, int prev) {
      lv[now] = lv[prev] + 1;
      par[now] = prev;
      lvc[lv[now]]++;
      lvmx = max(lvmx, lv[now]);
      for (auto u: adj[now]) {
            if (u != prev) dfs(u, now);
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      srand(time(NULL));

      cin >> n;
      for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      for (int i = 1; i <= n; i++) {
            cin >> b[i];
      }
      if (b[1] != 1) {cout << "No"; return 0;}
      dfs(1, 0);

      for (int i = 1; i <= n; i++) {
            lva[b[i]] = lv[b[i]];
            ind[b[i]] = i;
      }

      for (int i = 2; i <= n; i++) {
            if (ind[par[b[i]]] < ind[par[b[i - 1]]]) {cout << "No"; return 0;}
      }
      cout << "Yes";

      return 0;
}