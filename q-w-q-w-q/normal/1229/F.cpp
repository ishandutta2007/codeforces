#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;

typedef long long i64;

const int N = 35005;
int n, a[N], r[N];

i64 query(int q) {
  priority_queue<int> ql(n + 5, q);
  priority_queue<int, vector<int>, greater<int>> qr(n + 5, q);

  int d = 0, dl = 0, p = q;
  i64 v = 0;
  for (int i = 1; i <= n; i++) {
    d += a[i], dl += r[i];
    int x = qr.top();
    qr.pop(), qr.push(x - r[i]);
    if (qr.top() + d <= 0) {
      qr.push(-d), qr.push(-d);
      int x = qr.top();
      qr.pop(), ql.push(x + dl);
    } else {
      ql.push(-d + dl), ql.push(-d + dl);
      int x = ql.top();
      ql.pop(), qr.push(x - dl);
    }
    p = p + a[i] - r[i], v += abs(p);
  }

  priority_queue<int> tp = ql;
  i64 sum = 0;
  int x = qr.top() + dl, cnt = 1;
  while (!tp.empty()) {
    if (tp.top() + d - dl <= p) {
      sum += 1ll * cnt * (x + d - dl - p);
      break;
    }
    sum += 1ll * cnt * (x - tp.top()), cnt++;
    x = tp.top(), tp.pop();
  }
  v -= sum;

  if (qr.top() + d <= q) {
    qr.push(1 << 30);
    int cnt = 0;
    while (1) {
      int x = qr.top();
      qr.pop();
      if (qr.top() + d >= q)
        return v + 1ll * cnt * (q - (x + d));
      v += 1ll * cnt * (qr.top() - x), cnt++;
    }
  }

  ql.push(-(1 << 30));
  cnt = 1, x = qr.top() + dl;
  while (1) {
    if (ql.top() + d - dl <= q)
      return v + 1ll * cnt * (x + d - dl - q);
    v += 1ll * cnt * (x - ql.top()), cnt++;
    x = ql.top(), ql.pop();
  }
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int tot = 0;
  cin >> n;
  for (int i = 1; i <= n; i++) {
    int l;
    cin >> a[i] >> l >> r[i];
    a[i] -= l, r[i] -= l, tot += max(r[i], a[i]);
  }

  int l = -tot, r = tot;
  i64 ans = 1ll << 60;
  while (l <= r) {
    int mid = l + (r - l) / 2;
    i64 v1 = query(mid), v2 = query(mid + 1);
    if (v1 < v2)
      ans = min(ans, v1), r = mid - 1;
    else
      ans = min(ans, v2), l = mid + 1;
  }
  cout << ans;
}