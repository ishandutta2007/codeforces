#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void solve() {
  int n;
  cin >> n;
  cout << n / 3 + (n % 3 == 1) << ' ' << n / 3 + (n % 3 == 2) << '\n';
}

int main() {
  int tests;
  cin >> tests;
  while (tests--) {
    solve();
  }
}