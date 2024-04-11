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

const int N = 100010, M = 300010;

int n, m;
int u[M], v[M];
int color[N];
set<int> g[N];

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &u[i], &v[i]);
    g[u[i]].insert(v[i]);
    g[v[i]].insert(u[i]);
  }
  int a = 1, b = -1, c = -1;
  for (int i = 1; i <= m; ++i)
    if (u[i] == 1) {
      color[v[i]] = -1;
    }
  for (int i = 1; i <= m; ++i)
    if (color[u[i]] == -1 && color[v[i]] == -1) {
      b = u[i];
      c = v[i];
      break;
    }
#define GG do{puts("-1"); return 0;}while(false)
  if (b == -1) {
    GG;
  }
  for (int i = 1; i <= n; ++i) {
    bool fa = g[i].count(a), fb = g[i].count(b), fc = g[i].count(c);
    if (fa + fb + fc != 2)
      GG;
    if (!fa)
      color[i] = 1;
    else if (!fb)
      color[i] = 2;
    else
      color[i] = 3;
  }
  for (int i = 1; i <= m; ++i)
    if (color[u[i]] == color[v[i]]) {
      GG;
    }
  int ta= count(color + 1, color + n + 1, 1), tb=count(color + 1, color + n + 1, 2), tc=count(color + 1, color + n + 1, 3);
  if (m != ta*(ll)tb+tb*(ll)tc+tc*(ll)ta)
    GG;
  for (int i = 1; i <= n; ++i)
    printf("%d ", color[i]);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}