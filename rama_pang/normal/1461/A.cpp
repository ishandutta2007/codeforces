#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cout << char(i % 3 + 'a');
  }
  cout << '\n';
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