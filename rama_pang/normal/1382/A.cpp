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
    vector<int> a(n), b(m);
    for (auto &i : a) {
      cin >> i;
    }
    int ans = -1;
    for (auto &i : b) {
      cin >> i;
      if (find(begin(a), end(a), i) != end(a)) {
        ans = i;
      }
    }
    if (ans == -1) {
      cout << "NO\n";
    } else {
      cout << "YES\n";
      cout << 1 << " " << ans << "\n";
    }
  }
  return 0;
}