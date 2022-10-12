#include <bits/stdc++.h>
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = s.size();

  long long mod = 0;
  int ctz = 0;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '0') continue;
    ctz = i;
    for (int j = i; j < n; ++j) {
      mod |= 1LL * (s[j] - '0') << (j - i);
    }
    break;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (s[i] == '1') break;
    --n;
  }
  n -= ctz;

  if (mod == 0) return 0 * printf("-1\n");
  if (mod == 1) return 0 * printf("%d %d\n", ctz + 1, ctz + 2);

  auto mul = [&](long long x, long long y) {
    long long res = 0;
    for (; y; y >>= 1) {
      if (y & 1) res ^= x;
      x <<= 1;
      if (x >> (n - 1) & 1) x ^= mod;
    }
    return res;
  };

  int m = n / 2;
  unordered_map<long long, int> logs;
  logs[1] = 0;

  long long xp = 1;
  for (int i = 0; i < 1 << m; ++i) {
    logs[xp] = i;
    xp = mul(xp, 2);
  }

  long long ans = 1LL << n;
  long long xpp = xp;
  for (int i = 1; i < 1 << (n - m); ++i) {
    auto it = logs.find(xpp);
    if (it != logs.end()) {
      ans = min(ans, (1LL * i << m) - it->second);
    }
    xpp = mul(xpp, xp);
  }

  printf("%d %lld\n", ctz + 1, ans + ctz + 1);
  return 0;
}