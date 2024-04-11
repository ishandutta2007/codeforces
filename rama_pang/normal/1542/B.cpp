#include <bits/stdc++.h>
using namespace std;

void Main() {
  long long n, a, b;
  cin >> n >> a >> b;
  long long x = 1;
  while (x <= n) {
    int diff = n - x;
    if (diff % b == 0) {
      cout << "Yes\n";
      return;
    }
    if (a == 1) break;
    x *= a;
  }
  cout << "No\n";
  return;
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