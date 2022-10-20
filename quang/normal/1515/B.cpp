#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  set<int> s;
  for (int i = 1; i * i <= 1e9 + 10; i++) {
    s.insert(i * i);
  }
  while (tc--) {
    int n;
    cin >> n;
    if (n % 2 == 0 && s.count(n / 2)) {
      cout << "YES\n";
      continue;
    }
    if (n % 4 == 0 && s.count(n / 4)) {
      cout << "YES\n";
      continue;
    }
    cout << "NO\n";
  }
  return 0;
}