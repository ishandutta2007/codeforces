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

  if (n & 1) {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (j - i & 1) printf("1 ");
        else printf("-1 ");
      }
    }
  } else {
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        if (i % 2 == 0 && i + 1 == j) printf("0 ");
        else if (j - i & 1) printf("1 ");
        else printf("-1 ");
      }
    }
  }

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