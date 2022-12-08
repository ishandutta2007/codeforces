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

const int P = 1000000007;

int mpow(int x, ll k, int p = P) {
  int ret = 1;
  while (k) {
    if (k & 1)
      ret = ret * (ll)x % p;
    x = x * (ll)x % p;
    k >>= 1;
  }
  return ret;
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int x;
  ll n;

  scanf("%d%lld", &x, &n);
  int y = x;
  int ans = 1;
  function<void(int, int)> gao = [&](int p, int pk) {
    ll v = 0, nn = n;
    while (nn) {
      v += (nn /= p);
    }
    ans = ans * (ll)mpow(p, v) % P;
  };
  for (int v = 2; v * v <= y; ++v)
    if (y % v == 0) {
      int pk = 1;
      while (y % v == 0) {
        y /= v;
        pk *= v;
      }
      gao(v, pk);
    }
  if (y != 1)
    gao(y, y);
  printf("%d\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}