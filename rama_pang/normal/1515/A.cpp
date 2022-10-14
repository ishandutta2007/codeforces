#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  if (accumulate(begin(a), end(a), 0ll) == x) {
    cout << "NO" << '\n';
    return;
  }
  sort(begin(a), end(a));
  reverse(begin(a), end(a));
  int sum = 0;
  for (int i = 0; i < n; i++) {
    if (sum + a[i] == x) {
      assert(i + 1 < n);
      swap(a[i], a[i + 1]);
    }
    assert(sum + a[i] != x);
    sum += a[i];
  }
  cout << "YES\n";
  for (auto i : a) cout << i << ' '; cout << '\n';

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