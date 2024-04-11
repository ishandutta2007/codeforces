#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 200005;
int n, k;
vector<int> to[N];
int top[N], h[N], son[N];
int st[N], s;

void dfs1(int i, int fa) {
  for (int j : to[i]) {
    if (j == fa)
      continue;
    dfs1(j, i);

    if (h[i] < h[j])
      h[i] = h[j], son[i] = j;
  }

  h[i]++;
}

void dfs2(int i, int len, int fa) {
  if (!son[i]) {
    st[++s] = len;
    return;
  }

  dfs2(son[i], len + 1, i);
  for (int j : to[i])
    if (j != fa && j != son[i])
      dfs2(j, 1, i);
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int x, y;
    cin >> x >> y;
    to[x].push_back(y), to[y].push_back(x);
  }

  dfs1(1, 0), dfs2(1, 1, 0);
  sort(st + 1, st + s + 1, greater<int>());

  if (s > k) {
    long long ans = -(1ll << 60);
    for (int i = 1, t = 0; i <= k; i++) {
      t += st[i];
      int lim = n - t, w = n - i;
      int tp = n / 2;
      if (lim >= tp)
        ans = max(ans, 1ll * (w - tp) * (i - tp));
      else
        ans = max(ans, 1ll * (w - lim) * (i - lim));
    }

    cout << ans;
    return 0;
  }

  long long ans = 0;
  for (int i = s; i <= k; i++)
    ans = max(ans, 1ll * i * (n - i));
  cout << ans;
}