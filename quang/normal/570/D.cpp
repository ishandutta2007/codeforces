#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n, m;
int cnt[30][N];
int in[N], out[N], h[N], id, dp[N];
char s[N];
vector <int> a[N];
pair <pair<int, int>, int> b[N];

void dfs(int u) {
  in[u] = ++id;
  dp[u] = h[u];
  for (int v : a[u]) {
    h[v] = h[u] + 1;
    dfs(v);
    dp[u] = max(dp[u], dp[v]);
  }
  out[u] = id;
}

int main() {
  //ios_base::sync_with_stdio(0);
  cin >> n >> m;
  for (int i = 2; i <= n; i++) {
    int u;
    scanf("%d", &u);
    a[u].push_back(i);
  }
  scanf("%s", s + 1);
  h[1] = 1;
  dfs(1);
  for (int i = 1; i <= n; i++) {
    b[i] = make_pair(make_pair(h[i], in[i]), i);
  }
  sort(b + 1, b + n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 26; j++) {
      cnt[j][i] = cnt[j][i - 1];
    }
    int u = b[i].second;
    cnt[s[u] - 'a'][i]++;
  }
  while (m--) {
    int v, h1;
    scanf("%d%d", &v, &h1);
    if (h[v] > h1) {
      printf("Yes\n");
      continue;
    }
    if (dp[v] < h1) {
      printf("Yes\n");
      continue;
    }
    int l = lower_bound(b + 1, b + n + 1, make_pair(make_pair(h1, in[v]), 0)) - b;
    int r = lower_bound(b + 1, b + n + 1, make_pair(make_pair(h1, out[v] + 1), 0)) - b - 1;
    int x = 0;
    for (int i = 0; i < 26; i++) {
      int xx = cnt[i][r] - cnt[i][l - 1];
      if (xx & 1) {
        x++;
      }
    }
    if (x <= 1) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
  }
  return 0;
}