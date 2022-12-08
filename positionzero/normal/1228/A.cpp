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

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int l, r;
  scanf("%d%d", &l, &r);
  for (int i = l; i <= r; ++i) {
    static bool m[10];
    memset(m, 0, sizeof(m));
    int x = i;
    bool flag = false;
    while (x) {
      if (m[x % 10]) {
        flag = true;
        break;
      }
      m[x % 10] = true;
      x /= 10;
    }
    if (!flag) {
      printf("%d\n", i);
      return 0;
    }
  }
  puts("-1");

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}