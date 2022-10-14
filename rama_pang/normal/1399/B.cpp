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
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
      cin >> b[i];
    }
    long long ans = 0;
    int mna = *min_element(begin(a), end(a));
    int mnb = *min_element(begin(b), end(b));
    for (int i = 0; i < n; i++) {
      int xa = a[i] - mna;
      int xb = b[i] - mnb;
      ans += min(xa, xb);
      ans += abs(xa - xb);
    }
    cout << ans << "\n";
  }
  return 0;
}