#include <bits/stdc++.h>

using namespace std;

const int N = 200010;

int n;
int a[N];
pair<int, int> b[N];

struct it {
  int t[N * 4], a[N * 4];

  int sum(int node) {
    return max(a[node], t[node]);
  }

  void add(int node, int l, int r, int x, int y, int val) {
    if (x > r || y < l) {
      return;
    }
    if (x <= l && r <= y) {
      a[node] = max(a[node], val);
      return;
    }
    int m = (l + r) >> 1;
    add(node * 2, l, m, x, y, val);
    add(node * 2 + 1, m + 1, r, x, y, val);
    t[node] = max(sum(node * 2), sum(node * 2 + 1));
  }

  int get(int node, int l, int r, int x, int y) {
    if (x > r || y < l) {
      return 0;
    }
    if (x <= l && r <= y) {
      return sum(node);
    }
    int m = (l + r) / 2;
    int res = a[node];
    res = max(res, get(node * 2, l, m, x, y));
    res = max(res, get(node * 2 + 1, m + 1, r, x, y));
    return res;
  }
} t;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> b[i].first >> b[i].second;
    a[i] = b[i].first + b[i].second;
  }
  a[n + 1] = -2e9 - 1;
  a[n + 2] = 2e9 + 1;
  sort(b + 1, b + n + 1);
  sort(a + 1, a + n + 3);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    int pos = upper_bound(a + 1, a + n + 3, b[i].first - b[i].second) - a - 1;
    int x = t.get(1, 1, n + 2, 1, pos);
    res = max(res, x + 1);
    pos = lower_bound(a + 1, a + n + 3, b[i].first + b[i].second) - a;
    t.add(1, 1, n + 2, pos, n + 2, x + 1);
  }
  cout << res << endl;
  return 0;
}