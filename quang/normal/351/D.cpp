#include <bits/stdc++.h>

using namespace std;

const int N = 100010;

int n;
int q;
int a[N];
int pre[N], now[N];
vector <pair<int, int> > query[N];
int res[N];
int last[N];

struct bit {
  int t[N];

  void add(int x, int v) {
    while (x <= n) {
      t[x] += v;
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
} t1, t2;

int main() {
  //freopen("input.txt", "r", stdin);
  scanf("%d", &n);
  for (int i = 1; i < N; i++) {
    now[i] = n + 1;
  }
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  for (int i = n; i; i--) {
    pre[i] = now[a[i]];
    now[a[i]] = i;
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    int l, r;
    scanf("%d %d", &l, &r);
    query[l].push_back(make_pair(r, i));
  }
  for (int i = n; i; i--) {
    t1.add(i, 1);
    if (pre[i] != n + 1) {
      t1.add(pre[i], -1);
    }
    if (pre[i] == n + 1) {
      last[i] = n + 1;
      t2.add(i, 1);
    } else {
      int x = pre[i];
      int y = pre[x];
      if ((y == n + 1) || (x - i == y - x)) {
        last[i] = last[x];
        t2.add(i, 1);
        t2.add(x, -1);
      } else {
        last[i] = y;
        t2.add(i, 1);
        t2.add(last[i], -1);
        t2.add(x, -1);
        t2.add(last[x], 1);
      }
    }
    for (auto u : query[i]) {
      int r = u.first;
      int id = u.second;
      int cnt = t1.get(r);
      int cnt2 = t2.get(r);
      cnt += (cnt2 == 0);
      res[id] = cnt;
    }
  }
  for (int i = 1; i <= q; i++) {
    printf("%d\n", res[i]);
  }
  return 0;
}