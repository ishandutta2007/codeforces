#include <algorithm>
#include <cstdio>
#include <iostream>

#define int long long

using namespace std;

const int N = 1000005;
int n, t[N], tt[N], x[N];
int f[N], fa[N];
pair<int, int> a[N];
bool g[N], ok[N];

int find(int x) {
  while (x != fa[x])
    x = fa[x] = fa[fa[x]];
  return x;
}

int cf(int i, int j) {
  if (x[i] == x[j])
    return f[i] + abs(x[i + 1] - x[i]);
  return max(f[i] + abs(x[j] - x[i]), t[i]) + abs(x[i + 1] - x[j]);
}
bool checkf(int i, int j) { return cf(i, j) <= t[i + 1]; }

int cg(int i, int j) {
  if (x[i] == x[j])
    return t[tt[i]] + abs(x[i + 1] - x[tt[i]]);
  return max(t[i], t[tt[i]] + abs(x[j] - x[tt[i]])) + abs(x[i + 1] - x[j]);
}
bool checkg(int i, int j) { return cg(i, j) <= t[i + 1]; }

signed main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n;
  for (int i = 1; i <= n; i++) {
    f[i] = 1 << 30;
    cin >> t[i] >> x[i];
    if (t[i] - t[i - 1] >= abs(x[i] - x[i - 1]))
      ok[i - 1] = 1;
  }

  for (int l = 0, r; l < n; l = r + 1) {
    for (r = l; ok[r]; r++)
      ;

    int s = 0;
    for (int i = l; i <= r; i++)
      a[++s] = make_pair(x[i], i), fa[s] = s;
    fa[s + 1] = s + 1;
    sort(a + 1, a + s + 1);

    for (int i = l; i <= r; i++) {
      if (f[i] <= t[i]) {
        f[i + 1] = min(f[i + 1], max(x[i + 1] == x[i] ? 0 : t[i], f[i] + abs(x[i + 1] - x[i])));

        int _l = 2, _r = s, al = s + 1, ar = 1, mid = 1;
        while (_l <= _r) {
          int j = (_l + _r) >> 1;
          if (cf(i, a[j].second) < cf(i, a[j - 1].second))
            mid = j, _l = j + 1;
          else
            _r = j - 1;
        }

        _l = 1, _r = mid;
        while (_l <= _r) {
          int j = (_l + _r) >> 1;
          if (checkf(i, a[j].second))
            al = j, _r = j - 1;
          else
            _l = j + 1;
        }

        _l = mid, _r = s;
        while (_l <= _r) {
          int j = (_l + _r) >> 1;

          if (checkf(i, a[j].second))
            ar = j, _l = j + 1;
          else
            _r = j - 1;
        }

        for (int j = find(al); j <= ar; j = find(j + 1)) {
          if (a[j].second > i + 1)
            g[a[j].second] = 1;
          fa[j] = j + 1;
        }

        if (i < r) {
          if (checkf(i, r + 1))
            g[r + 1] = 1;
        } else {
          for (int j = i + 2; j <= n; j++) {
            g[j] |= checkf(i, j);
            if (!ok[j - 1])
              break;
          }
        }
      }

      if (g[i]) {
        if (i > 1 && x[i] == x[i - 1] && g[i - 1])
          tt[i] = tt[i - 1];
        else
          tt[i] = i - 1;
        if (x[i + 1] == x[i])
          g[i + 1] = 1;

        f[i + 1] = min(f[i + 1], max(t[i], t[tt[i]] + abs(x[i + 1] - x[tt[i]])));

        int _l = 2, _r = s, al = s + 1, ar = 1, mid = 1;
        while (_l <= _r) {
          int j = (_l + _r) >> 1;
          if (cg(i, a[j].second) < cg(i, a[j - 1].second))
            mid = j, _l = j + 1;
          else
            _r = j - 1;
        }

        _l = 1, _r = mid;
        while (_l <= _r) {
          int j = (_l + _r) >> 1;
          if (checkg(i, a[j].second))
            al = j, _r = j - 1;
          else
            _l = j + 1;
        }

        _l = mid, _r = s;
        while (_l <= _r) {
          int j = (_l + _r) >> 1;
          if (checkg(i, a[j].second))
            ar = j, _l = j + 1;
          else
            _r = j - 1;
        }

        for (int j = find(al); j <= ar; j = find(j + 1)) {
          if (a[j].second > i + 1)
            g[a[j].second] = 1;
          fa[j] = j + 1;
        }

        if (i < r) {
          if (checkg(i, r + 1))
            g[r + 1] = 1;
        } else {
          for (int j = i + 2; j <= n; j++) {
            g[j] |= checkg(i, j);
            if (!ok[j - 1])
              break;
          }
        }
      }
    }
  }

  puts(f[n] <= t[n] || g[n] ? "YES" : "NO");
}