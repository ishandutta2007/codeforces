#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  int x, k, y;
  cin >> x >> k >> y;
  vector<int> revpos(n);
  vector<int> a(n), b(m);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    revpos[--a[i]] = i;
  }
  for (int i = 0; i < m; i++) {
    cin >> b[i];
    b[i] = revpos[b[i] - 1];
  }
  if (!is_sorted(begin(b), end(b))) {
    cout << -1 << '\n';
    return 0;
  }
  b.insert(begin(b), -1);
  b.emplace_back(n);
  lint ans = 0;
  for (int i = 0; i + 1 < (int) b.size(); i++) {
    int l = b[i] + 1;
    int r = b[i + 1] - 1;
    int pl = (b[i] == -1 ? -1 : a[b[i]]);
    int pr = (b[i + 1] == n ? -1 : a[b[i + 1]]);
    int len = r - l + 1;
    if (l > r) {
      continue;
    }
    int mx = -1;
    for (int j = l; j <= r; j++) {
      mx = max(mx, a[j]);
    }
    if (mx < pl || mx < pr) {
      ans += 1ll * (len % k) * y;
      ans += 1ll * min(1ll * x, 1ll * y * k) * (len / k);
    } else {
      if (len < k) {
        cout << -1 << "\n";
        return 0;
      }
      ans += 1ll * (len % k) * y;
      ans += 1ll * min(1ll * x, 1ll * y * k) * (len / k - 1);
      ans += x;
    }
  }
  cout << ans << "\n";
  return 0;
}