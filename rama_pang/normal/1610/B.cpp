#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

#define int lint

void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ok = 0;
  const auto Check = [&](int x) {
    vector<int> b;
    for (auto i : a) if (i != x) b.emplace_back(i);
    for (int i = 0; i < int(b.size()); i++) {
      if (b[i] != b[int(b.size()) - 1 - i]) {
        return;
      }
    }
    ok = 1;
    return;
  };
  Check(0);
  for (int i = 0; i < n; i++) {
    if (a[i] != a[n - 1 - i]) {
      Check(a[i]);
      Check(a[n - 1 - i]);
      break;
    }
  }
  if (ok) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
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