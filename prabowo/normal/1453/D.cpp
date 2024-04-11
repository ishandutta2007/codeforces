#include <bits/stdc++.h>
using namespace std;
 
const int N = 100005;
 
char s[N];

int solve() {
  long long k;
  scanf("%lld", &k);

  vector<int> ans;
  for (int i = 60; i > 0; --i) {
    while (k >= (1LL << (i + 1)) - 2) {
      k -= (1LL << (i + 1)) - 2;
      ans.push_back(1);
      for (int j = 1; j < i; ++j) ans.push_back(0);
    }
  }

  if (k != 0) return 0 * printf("-1\n");
  printf("%d\n", (int) ans.size());
  for (int u: ans) printf("%d ", u); printf("\n");
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