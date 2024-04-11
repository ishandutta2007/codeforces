#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    lint a, b, n, m;
    cin >> a >> b >> n >> m;
    if (min(a, b) < m) {
      cout << "NO\n";
      continue;
    }
    if (a > b) {
      b -= m;
    } else {
      a -= m;
    }
    lint dif = abs(a - b);
    if (a > b) {
      a -= min(dif, n);
    } else {
      b -= min(dif, n);
    }
    n -= min(dif, n);
    a -= n / 2;
    b -= n / 2;
    if (n & 1) b--;
    if (a >= 0 && b >= 0) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  } 
}