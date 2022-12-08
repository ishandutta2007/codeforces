#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m;
  vector<string> grid(n);
  cin >> grid;
  vector<vector<int>> sum(n + 1, vector<int>(m + 1));
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      sum[i][j] = sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1] + (grid[i - 1][j - 1] == 'X');
  int l = 1, r = (min(n, m) + 1) / 2;
  function<bool(int)> pred = [&](int x) {
    vector<vector<int>> a(n + 2, vector<int>(m + 2));
    for (int i = x; i + x - 1 <= n; ++i)
      for (int j = x; j + x - 1 <= m; ++j)
        if (sum[i + x - 1][j + x - 1] - sum[i - x][j + x - 1] - sum[i + x - 1][j - x] + sum[i - x][j - x] == (x * 2 - 1) * (x * 2 - 1)) {
          ++a[i + x - 1][j + x - 1];
          --a[i - x][j + x - 1];
          --a[i + x - 1][j - x];
          ++a[i - x][j - x];
        }
    for (int i = n; i >= 0; --i)
      for (int j = m; j >= 0; --j)
        a[i][j] += a[i + 1][j] + a[i][j + 1] - a[i + 1][j + 1];
    for (int i = 1; i <= n; ++i)
      for (int j = 1; j <= m; ++j)
        if (grid[i - 1][j - 1] == 'X' && a[i][j] == 0)
          return false;
    return true;
  };
  while (l < r) {
    int mid = (l + r + 1) / 2;
    if (pred(mid))
      l = mid;
    else
      r = mid - 1;
  }
  cout << l - 1 << '\n';
  vector<string> ans(n, string(m, '.'));
  int x = l;
  for (int i = x; i + x - 1 <= n; ++i)
    for (int j = x; j + x - 1 <= m; ++j)
      if (sum[i + x - 1][j + x - 1] - sum[i - x][j + x - 1] - sum[i + x - 1][j - x] + sum[i - x][j - x] == (x * 2 - 1) * (x * 2 - 1))
        ans[i - 1][j - 1] = 'X';
  for (int i = 0; i < n; ++i)
    cout << ans[i] << '\n';

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}