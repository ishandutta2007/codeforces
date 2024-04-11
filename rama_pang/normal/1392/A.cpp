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
    if (unique(begin(a), end(a)) - begin(a) == 1) {
      cout << n << "\n";
    } else {
      cout << 1 << "\n";
    }
  }
  return 0;
}