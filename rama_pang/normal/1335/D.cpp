#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    vector<string> a(9);
    for (auto &i : a) cin >> i;
    for (int i = 0; i < 9; i++) {
      for (int j = 0; j < 9; j++) {
        if (a[i][j] == '1') a[i][j] = '9';
      }
    }
    // cout << "\n";
    for (int i = 0; i < 9; i++) {
      cout << a[i] << "\n";
    }
  }

}