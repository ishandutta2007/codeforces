#include <bits/stdc++.h>
using namespace std;

using lint = long long;

void Main() {
  int n;
  cin >> n;
  for (int i = 2; i <= n + 1; i++) cout << i << ' '; cout <<'\n';
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