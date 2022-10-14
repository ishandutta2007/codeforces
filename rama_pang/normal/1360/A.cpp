#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    int a, b;
    cin >> a >> b;
    if (a > b) swap(a, b);
    a *= 2;
    cout << max(a, b) * max(a, b) << "\n";
  }
}