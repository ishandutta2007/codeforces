#include <algorithm>
#include <cstdio>
#include <iostream>
#include <unordered_map>

using namespace std;

typedef long long i64;

const int N = 300005;
int n, a[N], b[N];
int f[N][2], g[N][2], h[N];
int t1[N], t2[N], t3[N];
unordered_map<i64, int> p;

void chk(int *f, int x, int y) {
  if (f[0] < x)
    f[0] = x, f[1] = y;
  else if (f[0] == x && f[1] > y)
    f[1] = y;
}

int main() {
  ios::sync_with_stdio(0), cout.tie(0), cout.tie(0);

  cin >> n, p.reserve(2 * n);

  for (int i = 1; i <= n; i++)
    cin >> a[i];

  i64 sum = 0;
  p[0] = n + 1;
  for (int i = n, lt = n + 2; i; i--) {
    sum += a[i];
    if (p.find(sum) != p.end())
      lt = min(lt, p[sum]);
    p[sum] = i, t1[i] = lt;
  }
  p.clear(), sum = 0;

  for (int i = 1; i <= n; i++)
    cin >> b[i];
  p[0] = n + 1;
  for (int i = n, lt = n + 2; i; i--) {
    sum += b[i];
    if (p.find(sum) != p.end())
      lt = min(lt, p[sum]);
    p[sum] = i, t2[i] = lt;
  }
  p.clear(), sum = 0;

  p[0] = n + 1;
  for (int i = n, lt = n + 2; i; i--) {
    sum += a[i] + b[i];
    if (p.find(sum) != p.end())
      lt = min(lt, p[sum]);
    p[sum] = i, t3[i] = lt;
  }

  for (int i = 1; i <= n; i++) {
    if (f[i][1] == i)
      f[i][0]++, f[i][1] = t2[i];
    if (g[i][1] == i)
      g[i][0]++, g[i][1] = t1[i];

    h[i] = max({h[i], h[i - 1], f[i][0], g[i][0]});
    h[t3[i]] = max(h[t3[i]], h[i] + 1);
    if (t1[i] <= t2[i])
      chk(f[t1[i]], h[i] + 1, t2[i]);
    if (t2[i] <= t1[i])
      chk(g[t2[i]], h[i] + 1, t1[i]);

    if (f[i][1]) {
      if (t1[i] <= f[i][1])
        chk(f[t1[i]], f[i][0] + 1, f[i][1]);
      if (f[i][1] <= t1[i])
        chk(g[f[i][1]], f[i][0] + 1, t1[i]);
    }

    if (g[i][1]) {
      if (t2[i] <= g[i][1])
        chk(g[t2[i]], g[i][0] + 1, g[i][1]);
      if (g[i][1] <= t2[i])
        chk(f[g[i][1]], g[i][0] + 1, t2[i]);
    }
  }
  if (f[n + 1][1] == n + 1)
    f[n + 1][0]++;
  if (g[n + 1][1] == n + 1)
    g[n + 1][0]++;

  int ans = 0;
  for (int i = 1; i <= n + 1; i++)
    ans = max({ans, h[i], f[i][0], g[i][0]});
  cout << ans;
}