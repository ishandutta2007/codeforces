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
  scanf("%s", s);
  int prv = -1;
  for (int i = 0; i < n; ++i) {
    int cur = s[i] - '0';
    if (cur + 1 != prv) {
      printf("1");
      prv = cur + 1;
    } else {
      printf("0");
      prv = cur;
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