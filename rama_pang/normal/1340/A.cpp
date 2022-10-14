#include <bits/stdc++.h>
using namespace std;
using lint = long long;




int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);


  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
      a[i]--;
      pos[a[i]] = i;
    }
    int l = n;
    bool can = true;
    for (int i = 0; i < n && can;) {
      int p = pos[i];
      for (int j = p; j < l; j++) {
        if (a[j] != i) {
          can = false;
          break;
        }
        i++;
      }
      l = p;
    }
    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }

}