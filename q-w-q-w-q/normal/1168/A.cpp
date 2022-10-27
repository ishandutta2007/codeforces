#include <cstdio>
#include <iostream>

using namespace std;

const int N = 300005;
int n, m, a[N];

bool check(int q) {
  static int l[N], r[N], f[N];
  for (int i = 1; i <= n; i++)
    l[i] = a[i], r[i] = (a[i] + q) % m;

  for (int i = 1; i <= n; i++) {
    if (l[i] <= r[i] && r[i] < f[i - 1])
      return 0;
    if (l[i] <= r[i])
      f[i] = max(f[i - 1], l[i]);
    else if (r[i] >= f[i - 1])
      f[i] = f[i - 1];
    else
      f[i] = max(f[i - 1], l[i]);
  }

  return 1;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];

  int l = 0, r = m - 1, ans = m;
  while (l <= r) {
    int mid = (l + r) >> 1;
    if (check(mid))
      ans = mid, r = mid - 1;
    else
      l = mid + 1;
  }
  cout << ans;
}