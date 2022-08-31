#include <vector>
#include <iostream>
#include <cstdio>

using namespace std;

typedef long long ll;

int main() {
  int n;
  int m;
  scanf("%d", &n);
  scanf("%d", &m);
  vector<vector<vector<ll> > >g(5, vector<vector<ll> >(n, vector<ll>(n)));
  vector<int> deg(n);
  for (int i = 0; i < m; ++i) {
    int a;
    int b;
    scanf("%d", &a);
    scanf("%d", &b);
    --a;
    --b;
    ++g[0][a][b];
    ++g[0][b][a];
    ++deg[a];
    ++deg[b];
  }
  for (int len = 2; len <= 5; ++len) {
    for (int a = 0; a < n; ++a)
      for (int b = 0; b < n; ++b)
        for (int c = a; c < n; ++c)
          g[len - 1][a][c] += g[len - 2][a][b] * g[0][b][c];
    for (int a = 0; a < n; ++a)
        for (int c = 0; c < a; ++c)
          g[len - 1][a][c] = g[len - 1][c][a];
  }
  ll res = 0;
  for (int a = 0; a < n; ++a) {
    res += g[4][a][a];
    if (deg[a] >= 3) {
      res -= g[2][a][a] * (deg[a] - 2) * 5;
    }
    if (deg[a] >= 2) {
      res -= g[2][a][a] * 5;
    }
  }
  cout << res / 10 << endl;
  return 0;
}