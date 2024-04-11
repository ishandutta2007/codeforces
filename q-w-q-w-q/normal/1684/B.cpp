#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int a, b, c;
    cin >> a >> b >> c;
    long long x = 1000000000ll * b + a;
    cout << x << ' ' << b << ' ' << x + c << '\n';
  }
}