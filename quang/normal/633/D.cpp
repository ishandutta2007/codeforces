#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int n;
pair<int, int> a[N];
int b[N], top;

int get(int u, int v) {
  if (u == v && a[u].second <= 1) {
    return 1;
  }
  top = 2;
  b[1] = u;
  b[2] = v;
  a[u].second--, a[v].second--;
  int res = 1;
  while (1) {
    int sum = a[b[top]].first + a[b[top - 1]].first;
    int pos = lower_bound(a + 1, a + n + 1, make_pair(sum, 0)) - a;
    if (pos == n + 1 || sum != a[pos].first || a[pos].second == 0) {
      res = top;
      break;
    }
    a[pos].second--;
    b[++top] = pos;
  }
  for (int i = 1; i <= top; i++) {
    a[b[i]].second++;
  }
  return res;
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = 1;
  }
  sort(a + 1, a + n + 1);
  int newn = 0;
  for (int i = 1; i <= n; i++) {
    if (!newn || a[i].first != a[newn].first) {
      a[++newn] = a[i];
    } else {
      a[newn].second += a[i].second;
    }
  }
  n = newn;
  a[n + 1] = make_pair(1e9 + 10 , 1);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      res = max(res, get(i, j));
    }
  }
  cout << res << endl;
  return 0;
}