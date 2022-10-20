#include <bits/stdc++.h>

using namespace std;

int n;
int a[100010];
long long sum, sum2, foo;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  sort(a + 1, a + n + 1);
  for (int i = 2; i <= n; i++) {
    foo += 1ll * (a[i] - a[i - 1]) * (i - 1) ;
    sum2 += foo;
  }
  sum2 *= 2;
  sum2 += sum;
  long long x = __gcd(sum2, 1ll * n);
  cout << sum2 / x << " " << n / x << endl;
  return 0;
}