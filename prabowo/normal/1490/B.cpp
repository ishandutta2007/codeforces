#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d", &n);
  vector<int> cnt(3);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
    ++cnt[a[i] % 3];
  }

  int ans = 0;

  int tar = n / 3;
  for (int i = 0; i < 10; ++i) {
    if (cnt[i % 3] > tar) {
      int diff = cnt[i % 3] - tar;
      ans += diff;
      cnt[(i + 1) % 3] += diff;
      cnt[i % 3] = tar;
    }
  }

  printf("%d\n", ans);
  return 0;
}

int main() {
  int t = 1;
  scanf("%d", &t);
  for (int tc = 0; tc < t; ++tc) {
    // printf("Case #%d: ", tc+1);
    solve();
  }
  return 0;
}