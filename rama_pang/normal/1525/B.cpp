#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans;
  if (is_sorted(begin(a), end(a))) {
    ans = 0;
  } else if (a[0] == 1 || a.back() == n) {
    ans = 1;
  } else if (a[0] == n && a.back() == 1) {
    ans = 3;
  } else {
    ans = 2;
  }
  cout << ans << '\n';
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