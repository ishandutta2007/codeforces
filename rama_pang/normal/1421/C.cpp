#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  string s;
  cin >> s;
  int n = s.size();
  int x = n;
  cout << "3\n";
  cout << "L " << n - 1 << "\n";
  n += n - 2;
  cout << "R " << n / 2 << "\n";
  n += n / 2 - 1;
  cout << "R " << n - (x - 3) << "\n";
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  int T = 1;
  // cin >> T;
  while (T--) {
    Main();
  }
  return 0;
}