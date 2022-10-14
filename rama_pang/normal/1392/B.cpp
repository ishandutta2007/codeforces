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
    long long k;
    cin >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int mx = *max_element(begin(a), end(a));
    for (int i = 0; i < n; i++) {
      a[i] = mx - a[i];
    }
    if (k % 2 == 0) {
      int mx = *max_element(begin(a), end(a));
      for (int i = 0; i < n; i++) {
        a[i] = mx - a[i];
      }
    }
    for (int i = 0; i < n; i++) {
      cout << a[i] << " \n"[i + 1 == n];
    }
  }
  return 0;
}