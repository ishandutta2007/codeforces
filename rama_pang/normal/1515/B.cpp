#include <bits/stdc++.h>
using namespace std;

using lint = long long;
const lint INF = 1e18;

void Main() {
  int n;
  cin >> n;
  if (n & 1) {
    cout << "NO\n";
    return;
  }
  const auto IsSquare = [&](int n) {
    int sq = sqrt(n);
    for (int i = max(1, sq - 5); i <= sq + 5; i++) {
      if (1ll * i * i == n) return true;
    }
    return false;
  };
  n /= 2;
  while (n % 2 == 0) {
    n /= 2;
  }
  if (IsSquare(n)) {
    cout << "YES\n";
  } else {
    cout << "NO\n";
  }
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