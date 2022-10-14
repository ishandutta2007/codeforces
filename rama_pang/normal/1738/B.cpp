#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<lint> a(n, -1);
  for (int i = n - k; i < n; i++) {
    cin >> a[i];
  }
  if (k == 1) {
    cout << "YES\n";
    return;
  }
  for (int i = n - 1; i > n - k; i--) {
    a[i] -= a[i - 1];
  }
  for (int i = n - k + 1; i + 1 < n; i++) {
    if (a[i] > a[i + 1]) {
      cout << "NO\n";
      return;
    }
  }
  lint sum = a[n - k];
  lint lim = a[n - k + 1];
  lint cnt = n - k + 1;
  // find a[0], a[1], ..., a[n - k] such that sum = s[n - k], and a[n - k] <= limit
  // 
  lint mx = cnt * lim;
  if (mx < sum) {
    cout << "NO\n";
  } else {
    cout << "YES\n";
  }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
}