#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  const auto Query = [&](int x) {
    cout << "? " << x << endl;
    int foo;
    cin >> foo;
    return foo;
  };

  int lo = 1, hi = n;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    if (Query(md) < Query(md + 1)) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }

  cout << "! " << lo << endl;
  return 0;
}