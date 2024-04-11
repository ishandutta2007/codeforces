#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;

  const auto Query = [&](int a, int b) {
    if (a == b) return -1;
    cout << "? " << a + 1 << ' ' << b + 1 << endl;
    int r;
    cin >> r;
    return r - 1;
  };

  int x = Query(0, n - 1);
  if (Query(0, x) == x) {
    int lo = 0, hi = x - 1;
    while (lo < hi) {
      int md = (lo + hi + 1) / 2;
      if (Query(md, n - 1) == x) {
        lo = md;
      } else {
        hi = md - 1;
      }
    }
    cout << "! " << lo + 1 << endl;
  } else {
    int lo = x + 1, hi = n - 1;
    while (lo < hi) {
      int md = (lo + hi) / 2;
      if (Query(0, md) == x) {
        hi = md;
      } else {
        lo = md + 1;
      }
    }
    cout << "! " << lo + 1 << endl;
  }
}