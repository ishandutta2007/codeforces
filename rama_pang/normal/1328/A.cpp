#include <bits/stdc++.h>
using namespace std;
using lint = long long;

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());


int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    lint c = 1ll * ceil(1.00 * a / b) * b;
    cout << c - a << '\n';
  }

}