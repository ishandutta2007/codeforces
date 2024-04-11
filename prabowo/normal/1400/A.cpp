#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
const int MOD = 1000000007;

int n;
char s[N];

int solve() {
  scanf("%d", &n);
  scanf("%s", s);

  for (int i = 0; i < n; ++i) printf("%c", s[n-1]);
  printf("\n");
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