#include <bits/stdc++.h>

using namespace std;

const int N = 200010;
const long long INF = (1ll << 60);

int n, k;
int a[N];
long long b[N];
int pos;

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i <= n; i++) {
    scanf("%d", a + i);
  }
  long long now = 0;
  pos = -1;
  for (int i = 0; i <= n; i++) {
    now += a[i];
    b[i] = now;
    if (now & 1) {
      pos = i;
      break;
    }
    now >>= 1ll;
  }
  if (pos == -1) {
    pos = n;
  }
  now = 0;
  int res = 0;
  for (int i = n; i >= 0; i--) {
    if (i <= pos) {
      long long foo = (now << 1ll) + b[i];
      foo = a[i] - foo;
      if (abs(foo) <= k && (i != n || foo != 0)) {
        res++;
      }
    }
    now = (now << 1ll) + a[i];
    if (abs(now) >= INF) {
      break;
    }
  }
  cout << res << endl;
  return 0;
}