#include <bits/stdc++.h>
using namespace std;
using lint = long long;


void Main() {
  lint a, b, c;
  cin >> a >> b >> c;

  // We play as first player
  // assume a < b < c, we forbid c (initially, output the largest integer y to force 
  // highest pile to becom restricted)
  // let y = 2c - a - b
  // if a += y, then becomes (2c - b, b, c). Then we can pick c - b and win
  // if b += y, then becomes (a, 2c - a, c). Then we can pick c - a and win

  cout << "First" << endl;
  lint inf = 1e10;
  cout << inf << endl;
  int in;
  cin >> in;
  if (in == 0) {
    return;
  } else if (in == 1) {
    a += inf;
  } else if (in == 2) {
    b += inf;
  } else if (in == 3) {
    c += inf;
  }

  lint y = 3 * max({a, b, c}) - (a + b + c);
  cout << y << endl;
  cin >> in;
  if (in == 0) {
    return;
  } else if (in == 1) {
    a += y;
  } else if (in == 2) {
    b += y;
  } else if (in == 3) {
    c += y;
  }
  vector<lint> all = {a, b, c};
  sort(begin(all), end(all));
  assert(all[2] - all[1] == all[1] - all[0]); // arithmetic sequence
  cout << (all[1] - all[0]) << endl;
  cin >> in;
  assert(in == 0);
  return;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}