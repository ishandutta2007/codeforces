#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int o = 0, z = 0;
    for (int i = 0; i < n; i++) {
      cin >> b[i];
      if (b[i] == 0) o = 1;
      if (b[i] == 1) z = 1;
    }
    if (o == 1 && z == 1) {
      cout << "YES\n";
    } else {
      if (is_sorted(begin(a), end(a))) {
        cout << "YES\n";
      } else {
        cout << "NO\n";
      }
    }
    
  } 
}