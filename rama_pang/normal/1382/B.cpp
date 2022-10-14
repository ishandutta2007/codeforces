#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int win = 1;
    for (int i = n - 2; i >= 0; i--) {
      if (a[i] == 1) {
        win ^= 1;
      } else {
        win = 1;
      }
    }
    if (win) {
      cout << "First\n";
    } else {
      cout << "Second\n";
    }
  }
  return 0;
}