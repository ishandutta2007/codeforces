#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, m;
vector <int> a[N];
int used[N];
int cnt[N];
int dp[N];
vector <pair<int, int> > b;

void dfs(int u, int &cur) {
  cur++;
  used[u] = 1;
  for (int v : a[u]) {
    if (used[v]) {
      continue;
    }
    dfs(v, cur);
  }
}

bool check(int u) {
  while (u) {
    int x = u % 10;
    if (x != 7 && x != 4) {
      return 0;
    }
    u /= 10;
  }
  return 1;
}

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= m; i++) {
    int u, v;
    scanf("%d %d", &u, &v);
    a[u].push_back(v);
    a[v].push_back(u);
  }
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      int cur = 0;
      dfs(i, cur);
      cnt[cur]++;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (!cnt[i]) {
      continue;
    }
    int x = 1;
    while (x <= cnt[i]) {
      b.push_back(make_pair(x * i, x));
      cnt[i] -= x;
      x <<= 1;
    }
    if (cnt[i]) {
      b.push_back(make_pair(cnt[i] * i, cnt[i]));
    }
  }
  memset(dp, 60 ,sizeof dp);
  dp[0] = 0;
  int tot = 0;
  for (pair<int, int> u : b) {
    for (int i = tot; i >= 0; i--) {
      int foo = i + u.first;
      dp[foo] = min(dp[foo], dp[i] + u.second);
    }
    tot += u.first;
  }
  int res = 1e9;
  for (int i = 1; i <= n; i++) {
    if (check(i)) {
      res = min(res, dp[i]);
    }
  }
  if (res >= 1e9) {
    res = 0;
  }
  cout << res - 1 << endl;
  return 0;
}