#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  vector<lint> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  lint ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      for (int k = j + 1; k < n; k++) {
        ans = max(ans, a[i] | a[j] | a[k]);
      }
      ans = max(ans, a[i] | a[j]);
    }
    ans = max(ans, a[i]);
  }



  cout << ans << "\n";
  return 0;
}