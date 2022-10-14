#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), p(m);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
      cin >> p[i];
      p[i]--;
    }
    int can = 0;
    for (int k = 0; k < 2 * n; k++) {
      for (int i = m - 1; i >= 0; i--) {
        if (a[p[i]] > a[p[i] + 1]) {
          swap(a[p[i]], a[p[i] + 1]);
        }
      }
    }
    if (is_sorted(begin(a), end(a))) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}