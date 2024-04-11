#include <bits/stdc++.h>
using namespace std;

using lint = long long;
#define int lint

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  if (n == 1) cout << "0\n";
  else cout << end(a)[-1] + end(a)[-2] << '\n';
}

int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}