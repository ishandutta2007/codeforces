#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

int n, m;
char a[N];
int cnt[N], sum[N];
int t[N * 4];

void build(int node, int l, int r) {
  if (l == r) {
    t[node] = sum[l];
    return;
  }
  int m = (l + r) >> 1;
  build(node * 2, l, m);
  build(node * 2 + 1, m + 1, r);
  t[node] = min(t[node * 2], t[node * 2 + 1]);
}

int get(int node, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 1000000000;
  }
  if (x <= l && r <= y) {
    return t[node];
  }
  int m = (l + r) >> 1;
  int p1 = get(node * 2, l, m, x, y);
  int p2 = get(node * 2 + 1, m + 1, r, x, y);
  return min(p1, p2);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin >> (a + 1);
  n = strlen(a + 1);
  for (int i = 1; i <= n; i++) {
    if (a[i] == ')') {
      sum[i] = sum[i - 1] - 1;
      cnt[i] = cnt[i - 1] + 1;
    } else {
      sum[i] = sum[i - 1] + 1;
      cnt[i] = cnt[i - 1];
    }
  }
  build(1, 1, n);
  cin >> m;
  for (int i = 1; i <= m; i++) {
    int l, r;
    cin >> l >> r;
    int x = get(1, 1, n, l, r);
    cout << 2 * (cnt[r] - cnt[l - 1] + min(0, x - sum[l - 1])) << endl;
  }
  return 0;
}