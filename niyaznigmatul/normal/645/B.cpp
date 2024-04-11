#include <bits/stdc++.h>

using namespace std;

int main() {
  int n, k;
  scanf("%d%d", &n, &k);
  if (n / 2 <= k) {
    cout << (long long) n * (n - 1) / 2 << '\n';
  } else {
    long long ans = 0;
    for (int i = 0; i < k; i++) {
      int x = n - 2 * (i + 1);
      ans += 2 * x + 1;
    }
    cout << ans << '\n';
  }
}