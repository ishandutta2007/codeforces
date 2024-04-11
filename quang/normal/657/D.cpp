#include <bits/stdc++.h>

using namespace std;

const int N = 150010;

int n;
long long T;

struct problem {
  int p, t;
  long double minVal, maxVal;
} a[N], b[N];

bool cmp(const problem &u, const problem &v) {
  return 1ll * u.p * v.t > 1ll * u.t * v.p;
}

bool cmp1(const problem &u, const problem &v) {
  return u.p < v.p;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n ;i++) {
    scanf("%d", &a[i].p);
  }
  for (int i = 1; i <= n ;i++) {
    scanf("%d", &a[i].t);
    T += a[i].t;
  }
  sort(a + 1, a + n + 1, cmp);
  long double low = 0.0, high = 1.0;
  for (int times = 1; times <= 40; times++) {
    long double mid = 0.5 * (low + high);
    long long tot = 0;
    long double curVal = -1.;
    int f = 0;
    for (int i = 1; i <= n; i++) {
      int last = i;
      long long now = a[i].t;
      while (last < n && 1ll * a[i].p * a[last + 1].t == 1ll * a[last + 1].p * a[i].t) {
        last++;
        now += a[last].t;
      }
      for (int j = i; j <= last; j++) {
        b[j] = a[j];
        b[j].minVal = (1.0 - mid * (now + tot) / T) * b[j].p;
        b[j].maxVal = (1.0 - mid * (b[j].t + tot) / T) * b[j].p;
      }
      tot += now;
      i = last;
    }
    sort(b + 1, b + n + 1, cmp1);
    for (int i = 1; i <= n; i++) {
      int last = i;
      while (last < n && b[last + 1].p == b[i].p) {
        last++;
      }
      for (int j = i; j <= last; j++) {
        if (b[j].minVal < curVal) {
          f = 1;
          break;
        }
      }
      for (int j = i; j <= last; j++) {
        curVal = max(curVal, b[j].maxVal);
      }
      i = last;
    }
    if (f) {
      high = mid;
    } else {
      low = mid;
    }
  }
  printf("%0.17f", (double)low);
  return 0;
}