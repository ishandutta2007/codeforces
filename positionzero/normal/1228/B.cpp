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

const int N = 1010, P = 1000000007;

int vis[N][N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n, m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int r;
    scanf("%d", &r);
    for (int j = 1; j <= r; ++j)
      vis[i][j] = 1;
    vis[i][r + 1] = -1;
  }
  for (int j = 1; j <= m; ++j) {
    int c;
    scanf("%d", &c);
    for (int i = 1; i <= c; ++i)
      if (vis[i][j] == -1) {
        puts("0");
        return 0;
      } else
        vis[i][j] = 1;
    if (vis[c + 1][j] == 1) {
      puts("0");
      return 0;
    }
    vis[c + 1][j] = -1;
  }
  int ans = 1;
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= m; ++j)
      if (vis[i][j] == 0)
        ans = ans * 2 % P;
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}