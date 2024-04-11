#include <cstdio>
#include <algorithm>

const int N = 501;

int n, mod;

int sz;
// 0: lex <, 1: lex >=.
int dp0[N * N], dp1[N * N];

int incdp0[N * N], incdp1[N * N], decdp0[N * N], decdp1[N * N];
int ndp0[N * N], ndp1[N * N];

void widen(int v[], int len) {
  for (int i = sz - len; i >= len; --i) v[i] = v[i - len];
  for (int i = len - 1; i >= 0; --i) v[i] = 0;
}

// if (!rev) v * [1, 2, ..., len]
// if ( rev) v * [len, ..., 2, 1]
void convolve(int ret[], int v[], int len, bool rev=false) {
  if (rev) std::reverse(v, v + sz);

  int sum = 0, pre = 0;
  for (int i = 0; i < len; ++i) ret[i] = 0;
  for (int i = len; i < sz; ++i) {
    pre = (pre + mod - sum + 1LL * len * v[i]) % mod;
    sum = (sum + v[i] - v[i - len]) % mod;
    if (sum < 0) sum += mod;
    ret[i] = pre;
  }

  if (rev) {
    std::reverse(v, v + sz);
    std::reverse(ret, ret + sz);
  }
}

int main() {
  scanf("%d %d", &n, &mod);

  dp0[0] = 0, dp1[0] = 1; sz = 1;
  for (int len = 1; len <= n; ++len) {
    sz += len * 2;
    widen(dp0, len); widen(dp1, len);
    convolve(incdp0, dp0, len), convolve(decdp0, dp0, len, true);
    convolve(incdp1, dp1, len), convolve(decdp1, dp1, len, true);

    for (int j = 0; j < sz; ++j) {
      ndp0[j] = (incdp0[j] + incdp1[j]) % mod;
      ndp1[j] = (decdp0[j] + decdp1[j]) % mod;

      if (len <= j && j + len < sz) {
        ndp0[j] = (-1LL * len * dp1[j] + ndp0[j]) % mod;
        ndp1[j] = (-1LL * len * dp0[j] + ndp1[j]) % mod;
        if (ndp0[j] < 0) ndp0[j] += mod;
        if (ndp1[j] < 0) ndp1[j] += mod;
      }
    }

    for (int j = 0; j < sz; ++j) {
      dp0[j] = ndp0[j];
      dp1[j] = ndp1[j];
    }
  }

  int ans = 0;
  for (int i = 0; i < sz / 2; ++i) {
    ans = (ans + dp0[i]) % mod;
  }
  printf("%d\n", ans);
  return 0;
}