#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(begin(a), end(a));
  for (auto i : a) {
    if (binary_search(begin(a), end(a), i + k)) {
      cout << "YES\n";
      return;
    }
  }
  cout << "NO\n";
  // a, b, c, d
  // a - c, b - c, 0, d - c
  // a - c - b + c, 0, d - c - b + c
  // a - b, d - b
  // a - d
  // a - b, 0, 0, d - c
  // a - b - d + c
  //
  // a, b
  // a - b
  //
  // a, b, c
  // a - b, c - b
  // a - c
  // c - a
  //
  // a, b, c, d

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