#include <cstdio>
#include <iostream>
using namespace std;
typedef long long ll;
inline ll gcd(ll n, ll m) { return !m ? n : gcd(m, n % m); }
int main() {
  int te;
  cin >> te;
  while (te--) {
    int n, ans = 0;
    scanf("%d", &n);
    ll *a = new ll[n], lt, *v = new ll[n];
    scanf("%lld", &lt);
    for (int i = 1; i < n; i++) {
      ll x;
      scanf("%lld", &x);
      a[i] = abs(x - lt), lt = x;
    }
    int h = 1, t = 0, *p = new int[n];
    for (int i = 1; i < n; i++) {
      for (int j = t; j >= h; j--) {
        ll tp = gcd(v[j], a[i]);
        if (tp == v[j]) break;
        v[j] = tp;
      }
      while (v[h] == 1 && h <= t) h++;
      t++, v[t] = a[i], p[t] = i;
      if (v[h] > 1) ans = max(ans, i - p[h] + 1);
    }
    printf("%d\n", ans + 1);
    delete[] a;
    delete[] p;
    delete[] v;
  }
}