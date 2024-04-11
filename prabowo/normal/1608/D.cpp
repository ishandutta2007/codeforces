#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;

const int N = 200005;

int fact[N], ifact[N];

int inv(int x) {
  int ret = 1;
  for (int y = MOD - 2; y; y >>= 1) {
    if (y & 1) ret = 1LL * ret * x % MOD;
    x = 1LL * x * x % MOD;
  }
  return ret;
}

void init() {
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = 1LL * fact[i - 1] * i % MOD;
  ifact[N - 1] = inv(fact[N - 1]);
  for (int i = N - 2; i >= 0; --i) ifact[i] = 1LL * ifact[i + 1] * (i + 1) % MOD;
}

int n;
char s[N][3];

bool B(char c) { return c == '?' || c == 'B'; }
bool W(char c) { return c == '?' || c == 'W'; }
bool BB(char s[]) { return B(s[0]) && B(s[1]); }
bool BW(char s[]) { return B(s[0]) && W(s[1]); }
bool WB(char s[]) { return W(s[0]) && B(s[1]); }
bool WW(char s[]) { return W(s[0]) && W(s[1]); }

int main() {
  init();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%s", s[i]);
  }

  int ans = 0;
  bool allBW = true, allWB = true;
  for (int i = 0; i < n; ++i) {
    allBW &= BW(s[i]);
    allWB &= WB(s[i]);
  }
  if (allBW) ++ans;
  if (allWB) ++ans;

  int e = n, num = 0, diff = 1;
  for (int i = 0; i < n; ++i) {
    if (BB(s[i]) && WW(s[i])) {  // ??: (1 + x)^2
      num += 2;
    } else if (s[i][0] == '?' || s[i][1] == '?') {  // x^[0|1](1 + x)
      ++num;
      if (WW(s[i])) --e;
    } else if (WW(s[i])) {  // is WW: x^2
      e -= 2;
    } else if (!BB(s[i])) {  // is either BW or WB: x
      e -= 1;
    }

    if (BW(s[i]) && WB(s[i])) diff = 2LL * diff % MOD;
    else if (BW(s[i]) || WB(s[i]));
    else diff = 0;
  }

  if (e >= 0 && e <= num) {
    ans = (ans + 1LL * ifact[e] * ifact[num - e] % MOD * fact[num] - diff) % MOD;
    if (ans < 0) ans += MOD;
  }

  printf("%d\n", ans);
  return 0;
}