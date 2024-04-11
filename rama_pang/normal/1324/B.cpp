#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) {
      cin >> i;
    }
    map<int, int> mp;
    bool can = false;
    for (int i = 0; i < n; i++) {
      if (mp[a[i]] > 0) {
        can = true;
      }
      if (i > 0) {
        mp[a[i - 1]]++;
      }
    }
    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}