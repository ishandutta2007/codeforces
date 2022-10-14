#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  string s;
  cin >> s;
  if (count(begin(s), end(s), 'B') * 2 == int(s.size())) {
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