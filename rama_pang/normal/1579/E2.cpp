#include <bits/stdc++.h>
using namespace std;

using lint = long long;

class Fenwick {
 public:
  int sz;
  vector<int> tree;
  Fenwick(int sz) : sz(sz), tree(sz) {}
  void Modify(int p, int x) {
    for (int i = p; i < sz; i |= i + 1) {
      tree[i] += x;
    }
  }
  int Query(int p) {
    int z = 0;
    for (int i = p; i > 0; i &= i - 1) {
      z += tree[i - 1];
    }
    return z;
  }
};

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> c = a;
  sort(begin(c), end(c));
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(begin(c), end(c), a[i]) - begin(c);
  }
  Fenwick F(n);
  for (int i = 0; i < n; i++) {
    F.Modify(a[i], 1);
  }
  lint ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    F.Modify(a[i], -1);
    ans += min(F.Query(a[i]), F.Query(n) - F.Query(a[i] + 1));
  }
  cout << ans << '\n';
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}