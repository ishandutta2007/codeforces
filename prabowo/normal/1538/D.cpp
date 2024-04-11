#include <bits/stdc++.h>
using namespace std;
 
const int N = 200005;

int n, m, k;
int a[N];
char s[N];

int countPrimes(int n) {
  int ret = 0;
  for (int i = 2; i*i <= n; ++i) {
    while (n % i == 0) {
      n /= i;
      ++ret;
    }
  }
  if (n > 1) ++ret;
  return ret;
}

int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }

int solve() {
  scanf("%d %d %d", &n, &m, &k);

  int g = gcd(n, m);

  int mini = -1;
  if (n == m) mini = 0;
  else if (n == g || m == g) mini = 1;
  else mini = 2;

  int maxi = countPrimes(n) + countPrimes(m);

  if (mini <= k && k <= maxi && (n != m || k != 1)) printf("YES\n");
  else printf("NO\n");

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