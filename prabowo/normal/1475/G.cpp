#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n;
int a[N];

int cnt[N];
vector<int> divs[N];

void sieve() {
  for (int i = 1; i < N; ++i) {
    for (int j = i*2; j < N; j += i) {
      divs[j].push_back(i);
    }
  }
}

int dp[N];
int f(int x) {
  if (~dp[x]) return dp[x];
  int ret = cnt[x];
  for (int v : divs[x]) {
    ret = max(ret, cnt[x] + f(v));
  }
  return dp[x] = ret;
}

int solve() {
  scanf("%d", &n);
  for (int i = 0; i < N; ++i) cnt[i] = 0;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i]];
  }
  memset(dp, -1, sizeof dp);

  int ans = n;
  for (int i = 0; i < n; ++i) {
    ans = min(ans, n - f(a[i]));
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  sieve();
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}