#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
long long k;
long long a[N], b[N];

struct bit {
  int t[N];

  void init() {
    for (int i = 1; i <= n; i++) {
      t[i] = 0;
    }
  }

  void add(int x, int u) {
    while (x <= n) {
      t[x] += u;
      x += (x & -x);
    }
  }

  int get(int x) {
    int res = 0;
    while (x) {
      res += t[x];
      x -= (x & -x);
    }
    return res;
  }
} t;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    a[i] += a[i - 1];
    b[i] = a[i - 1];
  }
  sort(b + 1, b + n + 1);
  long long l = -1e15, r = 1e15;
  while (r - l > 1) {
    long long m = (l + r) >> 1;
    t.init();
    long long cnt = 0;
    for (int i = 1; i <= n; i++) {
      int pos = lower_bound(b + 1, b + n + 1, a[i - 1]) - b;
      t.add(pos, 1);
      long long val = a[i] - m;
      pos = upper_bound(b + 1, b + n + 1, val) - b;
      cnt += t.get(pos - 1);
    }
    if (cnt >= k) {
      l = m;
    } else {
      r = m;
    }
  }
  cout << l << endl;
  return 0;
}