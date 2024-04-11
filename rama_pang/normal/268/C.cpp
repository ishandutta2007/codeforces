#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m;
  cin >> n >> m;
  int ans = min(n, m) + 1;
  cout << ans << "\n";
  for (int i = 0; i < ans; i++) {
    cout << ans - i - 1 << " " << i << "\n";
  }
  return 0;
}