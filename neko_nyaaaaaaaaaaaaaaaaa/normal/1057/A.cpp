#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n;
vector<int> adj[200001];
vector<int> ans;

int dfs(int now) {
      if (now == n) {ans.push_back(n); return 1;}
      int a = 0;
      for (int u: adj[now]) {
            a |= dfs(u);
      }
      if (a) ans.push_back(now);
      return a;
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n;
      for (int i = 2; i <= n; i++) {
            int x; cin >> x;
            adj[x].push_back(i);
      }
      dfs(1);

      reverse(ans.begin(), ans.end());
      for (int i: ans) cout << i << " ";

      return 0;
}