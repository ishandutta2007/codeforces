#include <bits/stdc++.h>
using namespace std;

const int N = 20;

int n;
long long a[N];

// Destructible only by operation 2 in |S|-1 operations
// sum(S') - sum(S \ S') in {|S| - 1, |S| - 3, ..., 0}
// 2sum(S') in sum(S) + |S|-1, ...
long long sums[1 << N];
long long cums[1 << N];
bool destructible(int mask) {
  int sz = __builtin_popcount(mask);
  int n1 = sz >> 1;
  int n2 = sz - n1;

  int lmask = 0;
  for (int i = 0; i < n1; ++i) lmask |= (lmask ^ mask) & -(lmask ^ mask);
  int rmask = mask ^ lmask;

  if (sums[mask] + sz + 1 & 1) return false;

  long long target = (sums[mask] + (sums[mask] & 1)) / 2;
  long long targetHi = target + (sz + 1) / 2;

  int cnt = 0;
  if (target <= 0 && 0 < targetHi) --cnt;
  if (target <= sums[mask] && sums[mask] < targetHi) --cnt;

  cums[0] = 0;
  for (int cur = 1, smask = rmask; smask > 0; smask = (smask - 1) & rmask, ++cur) {
    cums[cur] = sums[smask];
  }
  sort(cums, cums + (1 << n2));

  cnt += lower_bound(cums, cums + (1 << n2), targetHi)
       - lower_bound(cums, cums + (1 << n2), target);
  for (int smask = lmask; smask > 0; smask = (smask - 1) & lmask) {
    cnt += lower_bound(cums, cums + (1 << n2), targetHi - sums[smask])
         - lower_bound(cums, cums + (1 << n2), target - sums[smask]);
  }

  return cnt > 0;
}

int popcount[6][N + 1][1 << N];

void zeta(int n, int a[]) {
  for (int i = 0; i < n; ++i) {
    for (int mask = 1; mask < 1 << n; ++mask) {
      if (mask >> i & 1) a[mask] += a[mask ^ (1 << i)];
    }
  }
}

void izeta(int n, int a[]) {
  for (int i = 0; i < n; ++i) {
    for (int mask = 1; mask < 1 << n; ++mask) {
      if (mask >> i & 1) a[mask] -= a[mask ^ (1 << i)];
    }
  }
}

void subsetConvolution(int n, int a[][1 << N], int b[][1 << N], int c[][1 << N]) {
  for (int i = 0; i <= n; ++i) for (int mask = 0; mask < 1 << n; ++mask) c[i][mask] = 0;
  for (int i = 0; i <= n; ++i) for (int j = 0; j <= i; ++j) for (int mask = 0; mask < 1 << n; ++mask) {
    c[i][mask] += a[j][mask] * b[i-j][mask];
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%lld", &a[i]);
    if (a[i] == 0) --i, --n;
  }

  for (int mask = 0; mask < 1 << n; ++mask) {
    for (int i = 0; i < n; ++i) {
      if (mask >> i & 1) sums[mask] += a[i];
    }
  }

  bool zero = true;
  for (int mask = 1; mask < 1 << n; ++mask) {
    if (destructible(mask)) {
      popcount[0][__builtin_popcount(mask)][mask] = 1;
      zero = false;
    }
  }

  if (zero) return 0 * printf("%d\n", n);

  for (int i = 0; i <= n; ++i) zeta(n, popcount[0][i]);

  int ans = 1;

  int cur = 0;
  for (; 1 << (cur + 1) < n; ++cur) {
    subsetConvolution(n, popcount[cur], popcount[cur], popcount[cur+1]);
    for (int i = 0; i <= n; ++i) izeta(n, popcount[cur+1][i]);

    bool zeroes = true;
    for (int i = 0; i <= n; ++i) for (int mask = 0; mask < 1 << n; ++mask) {
      // if (__builtin_popcount(mask) > i) assert(popcount[cur*2][i][mask] == 0);
      if (__builtin_popcount(mask) == i) {
        if (popcount[cur+1][i][mask] != 0) {
          zeroes = false;
          popcount[cur+1][i][mask] = 1;
        }
      } else {
        popcount[cur+1][i][mask] = 0;
      }
    }

    for (int i = 0; i <= n; ++i) zeta(n, popcount[cur+1][i]);

    if (zeroes) break;
    ans <<= 1;
  }

  for (int k = cur - 1; k >= 0; --k) {
    if (ans + (1 << k) >= n) continue;
    subsetConvolution(n, popcount[cur], popcount[k], popcount[cur + 1]);
    for (int i = 0; i <= n; ++i) izeta(n, popcount[cur + 1][i]);

    bool zeroes = true;
    for (int i = 0; i <= n; ++i) for (int mask = 0; mask < 1 << n; ++mask) {
      if (__builtin_popcount(mask) == i) {
        if (popcount[cur + 1][i][mask] != 0) {
          zeroes = false;
          popcount[cur + 1][i][mask] = 1;
        }
      } else {
        popcount[cur + 1][i][mask] = 0;
      }
    }

    if (!zeroes) {
      ans += 1 << k;
      for (int i = 0; i <= n; ++i) {
        for (int mask = 0; mask < 1 << n; ++mask) {
          popcount[cur][i][mask] = popcount[cur + 1][i][mask];
        }
        zeta(n, popcount[cur][i]);
      }
    }
  }

  printf("%d\n", n - ans);
  return 0;
}