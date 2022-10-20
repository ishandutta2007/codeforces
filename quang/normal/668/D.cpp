#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int a[N], t[N], x[N];
int val[N], top;

struct bit {
  vector <int> val;
  vector <int> t;
  int n;

  void add(int x, int v) {
    x = lower_bound(val.begin(), val.end(), x) - val.begin();
    x++;
    while (x <= n) {
      t[x] += v;
      x += (x & -x);
    }
  }

  int get(int x) {
    x = lower_bound(val.begin(), val.end(), x) - val.begin();
    x++;
    int res = 0;
    while (x) {
      res += t[x];
      x -= (x & -x);
    }
    return res;
  }
} b[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d %d %d", a + i, t + i, x + i);
    val[i] = x[i];
  }
  sort(val + 1, val + n + 1);
  top = unique(val + 1, val + n + 1) - val - 1;
  for (int i = 1; i <= n; i++) {
    x[i] = lower_bound(val + 1, val + top + 1, x[i]) - val;
    b[x[i]].val.push_back(t[i]);
  }
  for (int i = 1; i <= n; i++) {
    sort(b[i].val.begin(), b[i].val.end());
    b[i].t.resize(b[i].val.size() + 1);
    b[i].n = b[i].val.size();
  }
  for (int i = 1; i <= n; i++) {
    if (a[i] == 1) {
      b[x[i]].add(t[i], 1);
    }
    if (a[i] == 2) {
      b[x[i]].add(t[i], -1);
    }
    if (a[i] == 3) {
      int res = b[x[i]].get(t[i]);
      printf("%d\n", res);
    }
  }
  return 0;
}