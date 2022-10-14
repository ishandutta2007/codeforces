#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int n;
  cin >> n;
  string s(n, '0');
  cout << "? " << s << endl;
  int ones;
  cin >> ones;
  s[0] = '1';
  cout << "? " << s << endl;
  s[0] = '0';
  int first;
  cin >> first;
  int ans0 = -1, ans1 = -1;
  if (first < ones) {
    ans1 = 1;
  } else {
    ans0 = 1;
  }

  int lo = 2, hi = n;
  while (lo < hi) {
    int md = (lo + hi) / 2;
    for (int i = lo; i <= md; i++) {
      s[i - 1] = '1';
    }
    cout << "? " << s << endl;  
    int q;
    cin >> q;
    for (int i = lo; i <= md; i++) {
      s[i - 1] = '0';
    }
    int val = ones - q; // '1's - '0's ins lo...md
    if ((ans1 == -1 && val != -(md - lo + 1)) || (ans0 == -1 && val != (md - lo + 1))) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  if (ans0 == -1) ans0 = lo;
  if (ans1 == -1) ans1 = lo;
  cout << "! " << ans0 << " " << ans1 << endl;
  return 0;
}