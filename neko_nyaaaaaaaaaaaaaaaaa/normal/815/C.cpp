#include <bits/stdc++.h>
using namespace std;

long long INF = 1e18;

int n, b;
vector<int> adj[5001];
vector<long long> a[5000];
long long f[5001][5001];
long long c[5001], d[5001];

void dfs(int now) {
      for (int i = 1; i <= n; i++) {
            f[now][i] = INF;
      }
      f[now][1] = c[now] - d[now];

      a[now] = vector<long long>(1, c[now]);
      int subtr = 1;
      for (auto u: adj[now]) {
            dfs(u);

            a[now].insert(a[now].end(), a[u].begin(), a[u].end());

            for (int i = subtr; i; i--) {
                  for (int j = 1; j <= a[u].size(); j++) {
                        f[now][i + j] = min(f[now][i + j], f[now][i] + f[u][j]);
                  }
            }

            subtr += a[u].size();
      }
      sort(a[now].begin(), a[now].end());

      long long sum = 0;
      for (int i = 1; i <= a[now].size(); i++) {
            sum += a[now][i-1];
            f[now][i] = min(f[now][i], sum);
      }
}

signed main() {
      ios::sync_with_stdio(0); cin.tie(0);

      cin >> n >> b;
      for (int i = 1; i <= n; i++) {
            cin >> c[i] >> d[i];
            if (i > 1) {
                  int x; cin >> x;
                  adj[x].push_back(i);
            }
      }
      dfs(1);

      for (int i = n; i; i--) {
            if (f[1][i] <= b) {cout << i; return 0;}
      }
      cout << 0;

      return 0;
}