#include <cstdio>
#include <iostream>
#include <random>
#include <set>
using namespace std;
int t, n, m, a[100005];
set<int> q;
mt19937 rnd(19260817);
inline int add(int x, int y) { return x + y < m ? x + y : x + y - m; }
inline int sub(int x, int y) { return x < y ? x + m - y : x - y; }
inline int power(int a, int n) {
  int tp = 1;
  while (n) {
    if (n & 1) tp = 1ll * tp * a % m;
    a = 1ll * a * a % m, n >>= 1;
  }
  return tp;
}
bool check(int x, int d) {
  for (int i = 0; i < n; i++, x = add(x, d))
    if (q.find(x) == q.end()) return 0;
  cout << sub(x, 1ll * n * d % m) << ' ' << d << endl;
  return 1;
}
int main() {
  cin >> m >> n;
  int s = 0;
  q.clear();
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
    q.insert(a[i]), s = add(s, a[i]);
  }
  if (n == 1) {
    cout << a[1] << ' ' << 0 << endl;
    return 0;
  }
  if (n == m) {
    cout << 0 << ' ' << 1 << endl;
    return 0;
  }
  s = 1ll * s * power(n, m - 2) % m;
  if (n & 1) {
    auto it = q.find(s);
    if (it == q.end()) {
      cout << -1 << endl;
      return 0;
    }
    int g = 1;
    for (int i = 1; i <= n; i++)
      if (a[i] != s) g = 1ll * g * sub(s, a[i]) % m;
    int tp = 1;
    for (int i = 1; i <= (n - 1) / 2; i++) tp = 1ll * tp * i % m;
    tp = 1ll * tp * tp % m;
    if (((n - 1) / 2) & 1) tp = m - tp;
    g = 1ll * g * power(tp, m - 2) % m;
    bool ok = 0;
    for (int i = 2; i <= n; i++) {
      int x = sub(a[i], a[1]);
      if (power(x, n - 1) != g) continue;
      if (check(sub(s, (n - 1) / 2ll * x % m), x)) {
        ok = 1;
        break;
      }
    }
    if (!ok) cout << -1 << endl;
    return 0;
  }
  int g = 1, tp = 1;
  for (int i = 1; i <= n; i++)
    if (a[i] != s) g = 1ll * g * sub(s, a[i]) % m;
  for (int i = 1; i <= n / 2; i++) tp = 1ll * tp * (2 * i - 1) % m;
  tp = 1ll * tp * tp % m;
  if ((n / 2) & 1) tp = m - tp;
  tp = 1ll * tp * power(power(2, m - 2), n) % m;
  g = 1ll * g * power(tp, m - 2) % m;
  bool ok = 0;
  for (int i = 2; i <= n; i++) {
    int x = sub(a[i], a[1]);
    if (power(x, n) != g) continue;
    if (check(sub(s, 1ll * (n - 1) * power(2, m - 2) % m * x % m), x)) {
      ok = 1;
      break;
    }
  }
  if (!ok) cout << -1 << endl;
}