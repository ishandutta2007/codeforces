#include <bitset>
#include <cstdio>
#include <algorithm>
#include <cassert>
using namespace std;

void read(int &x) {
  int c = getchar();
  while (c <= 32) c = getchar();
  x = 0;
  while (c > 32) {
    x = x * 10 + c - '0';
    c = getchar();
  }
}

int const N = 1234567;

int was[N], ss[N], dp[N], a[N], z[N];

int main() {
  int n, k;
  read(n);
  read(k);
  for (int i = 0; i < n; i++) {
    read(a[i]);
    a[i]--;
  }
  int cn = 0;
  for (int i = 0; i < n; i++) {
    if (was[i]) continue;
    int v = i;
    int cc = 0;
    while (!was[v]) {
      was[v] = true;
      v = a[v];
      ++cc;
    }
    z[cn++] = cc;
  }
  {
    int sum = 0;
    for (int i = 0; i < cn; i++) sum += z[i];
    assert(sum == n);
  }
  int need = k;
  if (need > n - need) need = n - need;
  std::sort(z, z + cn);
  dp[0] = 1;
  for (int it = 0; it < cn; ) {
    int jt = it;
    while (jt < cn && z[it] == z[jt]) ++jt;
    int cc = jt - it;
    int cw = z[it];
    ss[0] = 1;
    for (int i = 1; i <= need; i++) {
      int olddp = dp[i];
      if (dp[i] == 0 && i - cw >= 0) {
        int prev = i - (cc + 1) * cw;
        dp[i] = ss[i - cw] - (prev >= 0 ? ss[prev] : 0) > 0 ? 1 : 0;
      }
      ss[i] = olddp;
      if (i - cw >= 0) ss[i] += ss[i - cw];
    }
    it = jt;
  }
  // for (int i = 0; i < cn; i++) {
  //   int cw = z[i];
  //   for (int w = need; w >= cw; w--) {
  //     dp[w] |= dp[w - cw];
  //   }
  // }
  int ansmin;
  if (dp[need]) {
    ansmin = k;
  } else {
    ansmin = std::min(k + 1, n);
  }
  int ansmax = 0;
  int have = k;
  for (int i = 0; i < cn; i++) {
    int x = z[i];
    if (have == 0) break;
    if (have >= x / 2) {
      have -= x / 2;
      ansmax += x / 2 * 2;
    } else {
      ansmax += have * 2;
      have = 0;
      break;
    }
  }
  ansmax = std::min(n, ansmax + have);
  printf("%d %d\n", ansmin, ansmax);
}