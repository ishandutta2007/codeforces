#include <bits/stdc++.h>

#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

struct Hull {
  long long A[N], B[N];
  double Cross[N];
  int l, r;

  void Init() {
    l = 1, r = 0;
  }

  long long Get(long long u) {
    while (l < r && Cross[l + 1] <= u) {
      l++;
    }
    Cross[l] = u;
    return A[l] * u + B[l];
  }

  void Set(long long u, long long v) {
    double x = 0.0000000001;
    while (l <= r) {
      x = 1.0 * (B[r] - v) / (u - A[r]);
      if (x >= Cross[r]) {
        break;
      }
      r--;
    }
    A[++r] = u;
    B[r] = v;
    Cross[r] = x;
  }
} h;

int n;
long long f[N], a[N], b[N];

int main() {
  //fi, fo;
  //ios_base::sync_with_stdio(0);
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", b + i);
  }
  h.Init();
  f[1] = 0;
  h.Set(b[1], 0);
  for (int i = 2; i <= n; i++) {
    f[i] = h.Get(a[i]);
    h.Set(b[i], f[i]);
  }
  cout << f[n];
  return 0;
}