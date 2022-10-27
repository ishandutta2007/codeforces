#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

typedef long long i64;

const int N = 105;
int n, m, b[N];
i64 a[N], s1, s3;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  for (int s = 2; s <= 2 * m; s++) {
    for (int i = 1; i <= n; i++)
      b[i] = a[i] % s;
    sort(b + 1, b + n + 1);
    if (s % 2 == 0) {
      int t = s / 2;
      int p = lower_bound(b + 1, b + n + 1, t) - b;
      if ((n - p + 1) % 2 == 0)
        s3++;
    }
    int up = s / 2;
    if (s % 2 == 0)
      up--;
    if (!up)
      continue;
    int l = 1, r = up, qwq = -1;
    while (l <= r) {
      int mid = (l + r) >> 1;
      if (lower_bound(b + 1, b + n + 1, mid) != lower_bound(b + 1, b + n + 1, s - mid))
        l = mid + 1;
      else
        r = mid - 1, qwq = mid;
    }
    if (qwq == -1) {
      s1 += up - max(1, s - m) + 1;
      continue;
    }
    if (qwq > max(1, s - m))
      s1 += qwq - max(1, s - m);
    int p = lower_bound(b + 1, b + n + 1, qwq) - b;
    qwq = max(qwq, max(1, s - m));
    if ((n - p + 1) & 1) {
      int z = b[n - 1] / 2;
      if (z >= qwq)
        s1 += z - qwq + 1;
    } else {
      int z = b[n] / 2;
      if (z >= qwq)
        s1 += z - qwq + 1, s3 += 2 * (up - z);
      else
        s3 += 2 * (up - qwq + 1);
    }
  }

  cout << s1 << ' ' << s1 << ' ' << 1ll * m * m - 2 * s1 - s3 << ' ' << s3;
}