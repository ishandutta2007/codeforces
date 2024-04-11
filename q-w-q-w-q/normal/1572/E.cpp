#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long ll;

const int N = 205;

int n, k, x[N], y[N];
ll lim, s[N][N];
pair<int, ll> f[N][N];

ll cross(int x1, int y1, int x2, int y2) { return 1ll * x1 * y2 - 1ll * x2 * y1; }

ll get(int a, int b, int c) { return cross(x[b] - x[a], y[b] - y[a], x[c] - x[a], y[c] - y[a]); }

pair<int, ll> &operator+=(pair<int, ll> &a, pair<int, ll> b) {
  a.first += b.first, a.second += b.second;
  return a;
}

pair<int, ll> dfs(int l, int r) {
  if (s[l][r] < lim) return make_pair(0, s[l][r]);
  if (l + 2 == r) return make_pair(1, 0);
  if (r <= l + 1) return make_pair(0, 0);
  if (f[l][r].first) return f[l][r];

  f[l][r] = dfs(l + 1, r - 1);
  f[l][r].second += get(l, l + 1, r - 1) + get(l, r - 1, r);
  if (f[l][r].second >= lim) f[l][r].second = 0, f[l][r].first++;

  for (int i = r - 1; i > l; i--) {
    pair<int, ll> tp{dfs(l, i).first, get(l, i, r)};
    tp += dfs(i, r);
    if (tp.second >= lim) tp.second = 0, tp.first++;
    f[l][r] = max(f[l][r], tp);
  }

  return f[l][r];
}

int main() {
  cin >> n >> k, k++;
  for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

  for (int i = 1; i <= n; i++)
    for (int j = i + 2; j <= n; j++)
      s[i][j] = s[i][j - 1] + get(i, j - 1, j);

  ll l = 2, r = s[1][n] / k, ans = 1;
  while (l <= r) {
    lim = (l + r) >> 1;
    memset(f, 0, sizeof f);
    if (dfs(1, n).first >= k)
      ans = lim, l = lim + 1;
    else
      r = lim - 1;
  }

  cout << ans;
}