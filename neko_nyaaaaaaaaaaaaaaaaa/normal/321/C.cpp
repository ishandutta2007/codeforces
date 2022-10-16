#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int n, sz; 
char cur = 'A' - 1;
vector<int> adj[100001];
vector<int> vis(100001);
vector<char> ans(100001);
vector<int> subtr(100001);

void reset() {
      cur++;
      fill(vis.begin(), vis.end(), 0);
      fill(subtr.begin(), subtr.end(), 1);
}

void dfs1(int now) {
      vis[now] = 1; sz++;
      for (auto u: adj[now]) {
            if (vis[u] || ans[u]) continue;
            dfs1(u);
            subtr[now] += subtr[u];
      }
}

int dfs2(int now, int prev) {
      for (auto u: adj[now]) {
            if (u == prev) continue;
            if (subtr[u] > (sz+1)/2) return dfs2(u, now); 
      }
      return now;
}

void find_centroid(int start) {
      sz = 0; dfs1(start);
      int k = dfs2(start, 0);
      ans[k] = cur;
}

void output() {
      for (int i = 1; i <= n; i++) {
            cout << ans[i] << " ";
      }
      exit(0);
}

void solve() {
      bool flag = 0;
      for (int i = 1; i <= n; i++) {
            if (ans[i] || vis[i]) continue;
            find_centroid(i); flag = 1;
      }
      if (!flag) output();
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);
      
      cin >> n;
      for (int i = 1; i < n; i++) {
            int x, y; cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
      }
      while (1) {
            reset();
            solve();
      }

      return 0;
}