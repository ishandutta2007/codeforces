#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
const int N = 100005;
int n;
ll a[N];
ll st0[N], st1[N];
int f[N], g[N];
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) scanf("%lld", a + i);
  memset(f, 0x3f, sizeof f);
  f[n] = 0;
  for (int d = 0; d <= 58; d++) {
    memset(g, 0x3f, sizeof g);
    int ts0 = 0, ts1 = 0;
    for (int i = 1; i <= n; i++)
      if (a[i] >> d & 1)
        st1[++ts1] = a[i];
      else
        st0[++ts0] = a[i];
    for (int i = n, s0 = 0, s1 = 0; ~i; i--) {
      g[n - ts1 - s0] = min(g[n - ts1 - s0], f[i] + ts1 - s1 + s0);
      g[n - s1] = min(g[n - s1], f[i] + s1 + ts0 - s0);
      if (a[i] >> d & 1)
        s1++;
      else
        s0++;
    }
    for (int i = 1; i <= ts0; i++) a[i] = st0[i];
    for (int i = 1; i <= ts1; i++) a[ts0 + i] = st1[i];
    memcpy(f, g, sizeof g);
  }
  cout << f[n];
}