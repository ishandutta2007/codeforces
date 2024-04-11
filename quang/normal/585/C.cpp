#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  long long x, y;
  cin >> x >> y;
  if (__gcd(x, y) != 1) {
    cout << "Impossible";
    return 0;
  }
  vector <pair<long long, char> > res;
  while (x + y > 2) {
    if (x > y) {
      long long q = (x - 1) / y;
      res.push_back(make_pair(q, 'A'));
      x -= y * q;
    } else {
      long long q = (y - 1) / x;
      res.push_back(make_pair(q, 'B'));
      y -= x * q;
    }
  }
  for (auto x : res) {
    cout << x.first << x.second;
  }
  return 0;
}