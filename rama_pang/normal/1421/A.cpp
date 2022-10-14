#include <bits/stdc++.h>
using namespace std;
using lint = long long;

void Main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  for (int bit = 30; bit >= 0; bit--) {
    if (((a >> bit) & 1) != ((b >> bit) & 1)) {
      ans += 1 << bit;
    }
  }  
  cout << ans << "\n";
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