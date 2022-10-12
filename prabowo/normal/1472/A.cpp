#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;
const int MOD = 1000000007;
const int INF = 1e9;

int n, m, k;
int a[N];
char s[N];

int solve() {
  scanf("%d %d %d", &n, &m, &k);

  int area = n * m;

  while (n % 2 == 0) n /= 2;
  while (m % 2 == 0) m /= 2;
  printf(area / (n * m) >= k ? "YES\n" : "NO\n");
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