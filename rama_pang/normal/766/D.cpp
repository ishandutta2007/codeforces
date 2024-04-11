#include <bits/stdc++.h>
using namespace std;
using lint = long long;

class DisjointSet {
 public:
  int n;
  vector<int> p;
  DisjointSet() {}
  DisjointSet(int n) : n(n), p(n) {
    iota(begin(p), end(p), 0);
  }
  int Find(int x) {
    return p[x] == x ? x : p[x] = Find(p[x]);
  }
  int Unite(int x, int y) {
    x = Find(x);
    y = Find(y);
    if (x == y) {
      return 0;
    }
    p[x] = y;
    return 1;
  }
  bool SameSet(int x, int y) {
    return Find(x) == Find(y);
  }
};

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, q;
  cin >> n >> m >> q;
  vector<string> a(n);
  map<string, int> mp;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mp[a[i]] = i;
  }
  DisjointSet D(2 * n);
  for (int i = 0; i < m; i++) {
    int t;
    cin >> t;
    string xs, ys;
    cin >> xs >> ys;
    int x = mp[xs];
    int y = mp[ys];
    if (t == 1) { // same
      if (D.SameSet(x, y + n) || D.SameSet(x + n, y)) {
        cout << "NO\n";
      } else {
        D.Unite(x, y);
        D.Unite(x + n, y + n);
        cout << "YES\n";
      }
    } else { // different
      if (D.SameSet(x, y) || D.SameSet(x + n, y + n)) {
        cout << "NO\n";
      } else {
        D.Unite(x, y + n);
        D.Unite(x + n, y);
        cout << "YES\n";
      }
    }
  }
  for (int i = 0; i < q; i++) {
    string xs, ys;
    cin >> xs >> ys;
    int x = mp[xs];
    int y = mp[ys];
    if (D.SameSet(x, y) || D.SameSet(x + n, y + n)) {
      cout << 1 << "\n";
    } else if (D.SameSet(x, y + n) || D.SameSet(x + n, y)) {
      cout << 2 << "\n";
    } else {
      cout << 3 << "\n";
    }
  }
  return 0;
}