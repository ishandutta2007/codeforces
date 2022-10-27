#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 100005, V = 1000005;
int n, mx, a[N];
int pr[V], h[V][2];
vector<pair<int, int>> g[V];
bool np[V], u[N];

void prep(int n) {
  static int p[V / 5];

  for (int i = 2, tot = 0; i <= n; i++) {
    if (!np[i])
      p[++tot] = pr[i] = i;
    for (int j = 1; j <= tot && i * p[j] <= n; j++) {
      np[i * p[j]] = 1, pr[i * p[j]] = p[j];
      if (i % p[j] == 0)
        break;
    }
  }
}

void del(int p, int x) {
  int y = 0;
  while (x % p == 0)
    x /= p, y++;
  if (y == h[p][0])
    h[p][0] = -1;
  else if (y == h[p][1])
    h[p][1] = -1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++)
    cin >> a[i], mx = max(mx, a[i]);
  prep(mx);

  for (int i = 1; i <= n; i++) {
    int x = a[i];
    while (x != 1) {
      int s = 0, y = pr[x];
      while (x % y == 0)
        s++, x /= y;
      g[y].push_back({s, i});
    }
  }

  for (int i = 2; i <= mx; i++)
    if (!np[i])
      if ((int)g[i].size() > n - 2) {
        sort(g[i].begin(), g[i].end());
        if ((int)g[i].size() == n - 1)
          h[i][1] = g[i][0].first;
        else
          h[i][0] = g[i][0].first, h[i][1] = g[i][1].first;
      }

  vector<int> ans;
  for (int i = 2; i <= mx; i++)
    if (!np[i]) {
      for (int j = 0; j != 2; j++)
        if (h[i][j] != -1) {
          for (int k = 1; k <= n; k++)
            if (!u[k]) {
              int x = a[k], y = 0;
              while (x % i == 0)
                x /= i, y++;
              if (y <= h[i][j]) {
                u[k] = 1;
                ans.push_back(k);
                for (int l = i; l <= mx; l++)
                  if (!np[l])
                    del(l, a[k]);
                break;
              }
            }
        }
    }

  int q = ans.size();
  sort(ans.begin(), ans.end());
  int k = 0;
  for (int s = 1; s != (1 << q); s++)
    k += abs(__builtin_popcount(s) - 2);
  cout << k << '\n';
  for (int s = 1; s != (1 << q); s++) {
    int x = __builtin_popcount(s), y = abs(x - 2);
    bool op = (x & 1) ^ (x < 2);
    while (y--) {
      cout << op << ' ' << x << ' ';
      for (int i = 0; i != q; i++)
        if (s >> i & 1)
          cout << ans[i] << ' ';
      cout << '\n';
    }
  }
}