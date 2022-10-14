#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

#define int lint

void Main() {
  int n, m;
  cin >> n >> m;
  if (n == 1 && m == 1) {
    cout << 0 << '\n';
  } else if (n == 1 || m == 1) {
    cout << 1  <<'\n';
  } else {
    cout << 2 << '\n';
  }
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