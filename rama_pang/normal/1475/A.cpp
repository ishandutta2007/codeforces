#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  cin >> T;
  while (T--) {
    long long n;
    cin >> n;
    // vector<int> a(n);
    // for (auto &i : a) cin >> i;
    while (n % 2 == 0) {
      n /= 2;
    }
    if (n > 1) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
    
  }
  return 0;
}