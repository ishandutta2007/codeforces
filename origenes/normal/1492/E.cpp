#include <bits/stdc++.h>
using namespace std;

const int maxn = 251234;

int n, m;
vector<int> G[maxn];

bool dfs(int cnt) {
  if (cnt > 2) return false;
  for (int i = 1; i < n; i++) {
    int d = 0;
    for (int j = 0; j < m; j++) if (G[i][j] != G[0][j]) d++;
    if (d > 4) return false;
    if (d > 2) {
      for (int j = 0; j < m; j++) if (G[i][j] != G[0][j]) {
        int pre = G[0][j];
        G[0][j] = G[i][j];
        if (dfs(cnt + 1)) return true;
        G[0][j] = pre;
      }
      return false;
    }
  }
  return true;
}

int main() {
#ifdef ONLINE_JUDGE
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    G[i].resize(m);
    for (auto &x : G[i]) cin >> x;
  }
  if (dfs(0)) {
    cout << "Yes\n";
    for (auto x : G[0]) cout << x << ' ';
  } else cout << "No\n";
}