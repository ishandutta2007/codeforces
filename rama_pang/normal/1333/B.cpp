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
    vector<int> a(n), b(n);
    for (auto &i : a) cin >> i;
    for (auto &i : b) cin >> i;
    
    bool pos = false, neg = false, zer = false;
    bool can = true;
    for (int i = 0; i < n; i++) {
      if (a[i] < b[i]) {
        if (!pos) can = false;
      }
      if (a[i] > b[i]) {
        if (!neg) can = false;
      }
      if (a[i] > 0) pos = true;
      if (a[i] < 0) neg = true;

    }

    if (can) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }  

}