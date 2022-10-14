#include <bits/stdc++.h>
using namespace std;
using lint = long long;


void Main() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (auto &i : a) {
    cin >> i;
  }

  int mn = 1;
  set<int> active;
  for (int i = 1; i <= n; i++) {
    active.emplace(i);
  }
  active.emplace(n + 1);
  int last = n - 1;
  for (int i = n - 1; i >= 0; i--) {
    while (active.count(mn) == 0) {
      mn++;
    }
    if (a[i] == mn) {
      for (int j = i; j + 1 <= last; j++) {
        active.erase(a[j]);
      }
      a[i] = a[last];
      last = i;
    }
  }
  if (last == 0) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
  // int mn = min_element(begin(a), end(a)) - begin(a);
  // int mx = max_element(begin(a), end(a)) - begin(a);
  // if (mn == n - 1 || mx == 0) {
  //   cout << "NO\n";
  // } else {
  //   cout << "YES\n";
  // }
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}