#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

const lint PRIME[9] = {3, 11, 101, 1009, 10007, 100003, 1000003, 10000019, 100000007};

void Main() {
  int a, b, c;
  cin >> a >> b >> c;
  lint aa = 1, bb = 1, cc = PRIME[c - 1];

  lint lo = 1, hi = 1e9;
  while (lo < hi) {
    lint md = (lo + hi) / 2;
    if (to_string(cc * md).size() >= a) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  aa = cc * lo;
  lo = 1, hi = 1e9;
  while (lo < hi) {
    lint md = (lo + hi) / 2;
    if (to_string(cc * md).size() >= b) {
      hi = md;
    } else {
      lo = md + 1;
    }
  }
  bb = cc * lo;
  while (to_string(__gcd(aa, bb)).size() != c) {
    bb += cc;
  }
  // if (aa == bb) bb += cc;
  cout << aa << ' ' << bb << endl;
  assert(to_string(aa).size() == a);
  assert(to_string(bb).size() == b);
  assert(to_string(__gcd(aa, bb)).size() == c);
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