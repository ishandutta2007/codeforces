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
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] == 0) {
        cnt0++;
      } else {
        cnt1++;
      }
    }
    if (cnt0 == 0 || cnt1 == 0) {
      cout << n << "\n";
      for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
      }
      cout << "\n";
      continue;
    }
    if (cnt0 >= n / 2) {
      cout << cnt0 << "\n";
      for (int i = 0; i < cnt0; i++) {
        cout << 0 << " ";
      }
      cout << "\n";
    } else {
      if (cnt1 & 1) cnt1--;
      cout << cnt1 << "\n";
      for (int i = 0; i < cnt1; i++) {
        cout << 1 << " ";
      }
      cout << "\n";
    }
  }
  return 0;
}