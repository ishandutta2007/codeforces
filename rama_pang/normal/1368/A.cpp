#include <bits/stdc++.h>
using namespace std;
using lint = long long;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    lint a, b, n;
    int ans = 0;
    cin >> a >> b >> n;
    while (max(a, b) <= n) {
      if (a > b) swap(a, b);
      a += b;
      ans++;
    }
    cout << ans << "\n";
  }   
}