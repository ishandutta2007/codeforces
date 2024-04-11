#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

const int N = 200005;
int n, k, a[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    long long sum = 0, ans = 1ll << 60;
    for (int i = 1; i <= n; i++)
      cin >> a[i], sum += a[i], a[i] -= n - i;
    sort(a + 1, a + n + 1, greater<int>());
    for (int i = 1; i <= k; i++)
      sum -= a[i], ans = min(ans, sum - 1ll * i * (i - 1) / 2);
    cout << ans << '\n';
  }
}