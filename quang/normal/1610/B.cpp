#include <bits/stdc++.h>

using namespace std;

void Solve(int test) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &u : a) {
    cin >> u;
  }
  int l = 0, r = a.size() - 1;
  while (l < r) {
    if (a[l] == a[r]) {
      l++, r--;
    } else {
      break;
    }
  }
  if (l >= r) {
    cout << "YES\n";
    return;
  }

  auto Try = [&](int u) {
    int l = 0, r = a.size() - 1;
    while (l < r) {
      if (a[l] == a[r]) {
        l++, r--;
        continue;
      }
      if (a[l] == u) {
        l++;
        continue;
      }
      if (a[r] == u) {
        r--;
        continue;
      }
      break;
    }
    return l >= r;
  };

  if (Try(a[l])) {
    cout << "YES\n";
    return;
  }
  if (Try(a[r])) {
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int32_t main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) Solve(test);
  return 0;
}