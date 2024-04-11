#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
const long long INFLL = 1000000000000000000LL;

int n, p, k;
vector<int> a[N];

long long bestK;

long long dp[N][1 << 7];
long long f(int x, int mask) {
  if (x == n) return mask + 1 == (1 << p) ? bestK : -INFLL;
  if (~dp[x][mask]) return dp[x][mask];
  
  long long ret = f(x+1, mask);
  int popcount = __builtin_popcount(mask);
  for (int i = 0; i < p; ++i) {
    if (mask >> i & 1) continue;
    if (x < k + popcount) {
      ret = max(ret, f(x+1, mask | 1 << i) - a[x][0] + a[k + popcount][0] + a[x][i+1]);
    } else {
      ret = max(ret, f(x+1, mask | 1 << i) + a[x][i+1]);
    }
  }
  
  return dp[x][mask] = ret;
}

int solve() {
  scanf("%d %d %d", &n, &p, &k);
  for (int i = 0; i < n; ++i) {
    a[i].resize(p+1);
    scanf("%d", &a[i][0]);
  }
  
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < p; ++j) {
      scanf("%d", &a[i][j+1]);
    }
  }
  
  sort(a, a + n);
  reverse(a, a + n);
  
  bestK = 0;
  for (int i = 0; i < k; ++i) bestK += a[i][0];
  
  memset(dp, -1, sizeof dp);
  printf("%lld\n", f(0, 0));
  return 0;
}

int main() {
  int t = 1;
  while (t--) solve();
  return 0;
}