#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (n & 1) {
      cout << 1 + n / 2 << "\n";
    } else {
      cout << n / 2 << "\n";
    }
  }  
}