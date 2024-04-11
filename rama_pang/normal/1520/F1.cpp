#include <bits/stdc++.h>
using namespace std;

void Main() {
  int n, t, k;
  cin >> n >> t >> k;

  const auto Query = [&](int l, int r) { // number of 0s
    cout << "? " << l << ' ' << r << endl;
    int foo;
    cin >> foo;
    return (r - l + 1) - foo;
  };

  int lo = 1, hi = n;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (Query(1, md) >= k) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  
  cout << "! " << lo << endl;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}