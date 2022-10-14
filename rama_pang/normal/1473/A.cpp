#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    int n, d;
    cin >> n >> d;
    vector<int> a(n);
    for (auto &i : a) cin >> i;
    sort(begin(a), end(a));
    if (a.back() <= d || a[0] + a[1] <= d) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
  return 0;
}