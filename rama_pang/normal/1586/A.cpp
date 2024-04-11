#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  int ans = n;
  vector<int> out(n, 1);
  const auto Prime = [&](int x) {
    for (int i = 2; i < x; i++) {
      if (x % i == 0) return false;
    }
    return true;
  };
  if (Prime(sum)) {
    assert(sum % 2 == 1);
    for (int i = 0; i < n; i++) {
      if (a[i] % 2 == 1) {
        out[i] = 0;
        ans--;
        break;
      }
    }
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    if (out[i]) {
      cout << i + 1<< ' ';
    }
  }
  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}