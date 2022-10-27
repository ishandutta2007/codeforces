#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

const int N = 200005;
int n, a[N], k;
i64 sum[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
      cin >> a[i], sum[i] = sum[i - 1] + a[i];
    i64 ans = 0;
    for (int i = 1; i <= n; i++) {
      int l = min(i, k);
      i64 s = sum[i] - sum[i - l] + 1ll * k * (k - 1) / 2 - 1ll * (k - l) * (k - l - 1) / 2;
      ans = max(ans, s);
    }
    cout << ans << '\n';
  }
}