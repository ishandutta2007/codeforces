#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  while (tc--) {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto &u : a) {
      cin >> u;
    }
    int sum = 0;
    bool f = 0;
    vector<int> res;
    for (int i = 0; i < a.size(); i++) {
      if (sum + a[i] == x) {
        if (i + 1 == a.size()) {
          f = 1;
          break;
        } else {
          swap(a[i], a[i + 1]);
          i--;
        }
      } else {
        sum += a[i];
        res.push_back(a[i]);
      }
    }
    if (f) cout << "NO\n";
    else {
      cout << "YES\n";
      for (auto u : res) cout << u << ' ';
        cout << '\n';
    }
  }
  return 0;
}