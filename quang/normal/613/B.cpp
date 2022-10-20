#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n, A, cf, cm;
long long m;
pair<int, int> a[N];
int b[N];
long long s[N];
long long res = -1, res1 = 0;
int c = 0;

bool cmp(pair<int, int> u, pair<int, int> v) {
  return u.second < v.second;
}

int main() {
  scanf("%d %d %d %d %I64d", &n, &A, &cf, &cm, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i;
  }
  sort(a + 1, a + n + 1);
  for (int i = 1; i <= n; i++) {
    b[i] = a[i].first;
    s[i] = s[i - 1] + b[i];
  }
  b[n + 1] = A;
  long long xx = m;
  for (int i = n + 1; i; i--) {
    if (A - b[i] > xx) {
      break;
    }
    xx -= A - b[i];
    b[i] = A;
    int l = -1, r = A + 1;
    while (r - l > 1) {
      int f = (r + l) >> 1;
      int pos = lower_bound(b + 1, b + n + 1, f) - b - 1;
      long long foo = 1ll * f * pos - s[pos];
      if (foo <= xx) {
        l = f;
      } else {
        r = f;
      }
    }
    long long val = 1ll * cf * (n - i + 1) + 1ll * cm * l;
    if (val > res) {
      res = val;
      c = i;
      res1 = l;
    }
  }
  cout << res << endl;
  for (int i = n; i >= c; i--) {
    a[i].first = A;
  }
  for (int i = 1; i <= n; i++) {
    if (a[i].first < res1) {
      a[i].first = res1;
    }
  }
  sort(a + 1, a + n + 1, cmp);
  for (int i = 1; i <= n; i++) {
    printf("%d ", a[i].first);
  }
  return 0;
}