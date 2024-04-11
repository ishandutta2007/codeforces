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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = max_element(begin(a), end(a)) - begin(a);
    int oth = 0;
    for (int i = 0; i < n; i++) {
      if (i != mx) {
        oth += a[i];
      }
    }
    if (a[mx] > oth) {
      cout << "T\n";
    } else {
      oth += a[mx];
      if (oth & 1) {
        cout << "T\n";
      } else {
        cout << "HL\n";
      }
    }
  }
  return 0;
}