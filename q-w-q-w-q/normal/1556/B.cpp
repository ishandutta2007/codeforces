#include <bits/stdc++.h>
using namespace std;
int t, n;
int a[100005];
int main() {
  cin >> t;
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", a + i), a[i] %= 2;
    long long ans = 0;
    int s1 = 0, s2 = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] == 1)
        s1++;
      else
        s2++;
    if (max(s1, s2) > (n + 1) / 2) {
      cout << -1 << endl;
      continue;
    }
    if (n & 1) {
      if (s1 < s2)
        for (int i = 1; i <= n; i++) a[i] ^= 1;
      int cnt = 1;
      for (int i = 1; i <= n; i++)
        if (a[i] == 1) ans += abs(cnt - i), cnt += 2;
      cout << ans << endl;
      continue;
    }
    long long ss1 = 0, ss2 = 0;
    int c1 = 1, c2 = 2;
    for (int i = 1; i <= n; i++)
      if (a[i] == 1) ss1 += abs(c1 - i), ss2 += abs(c2 - i), c1 += 2, c2 += 2;
    cout << min(ss1, ss2) << endl;
  }
}