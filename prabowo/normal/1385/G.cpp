#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int n, m;
int a[2][N];

vector<pair<int, int>> pos[N];
bool vis[N], swp[N];

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    pos[i].clear();
    vis[i] = false;
    swp[i] = false;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[0][i]);
    pos[--a[0][i]].emplace_back(0, i);
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[1][i]);
    pos[--a[1][i]].emplace_back(1, i);
  }

  for (int i = 0; i < n; ++i) {
    if (pos[i].size() != 2) return 0 * printf("-1\n");
  }

  vector<int> ans;
  for (int i = 0; i < n; ++i) {
    if (vis[a[0][i]]) continue;

    vector<int> cyc;
    int lst = -1;
    int cur = a[0][i];
    int cnt = 0;
    bool same = false;
    while (!vis[cur]) {
      vis[cur] = true;

      if (pos[cur][0].second == lst) {
        swap(pos[cur][0], pos[cur][1]);
      }

      cyc.push_back(pos[cur][0].second);
      if (pos[cur][0].first == pos[cur][1].first) same = !same;
      if (same) {
        ++cnt;
        swp[pos[cur][0].second] = true;
      }

      lst = pos[cur][0].second;
      cur = a[pos[cur][0].first ^ 1][pos[cur][0].second];
    }

    if (cnt < (int) cyc.size() - cnt) {
      for (int c: cyc) {
        if (swp[c]) ans.push_back(c);
      }
    } else {
      for (int c: cyc) {
        if (!swp[c]) ans.push_back(c);
      }
    }
  }

  printf("%d\n", (int) ans.size());
  for (int u: ans) printf("%d ", u + 1);
  printf("\n");
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}