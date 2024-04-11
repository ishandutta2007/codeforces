#include <bits/stdc++.h>
using namespace std;



int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n;
  cin >> n;
  const int MOD = 1e9 + 7;
  int ans = 1;
  for (int i = 1; i <= n; i++) {
    ans = 1ll * ans * i % MOD;
  }
  int two = 1;
  for (int i = 1; i < n; i++) {
    two = 1ll * two * 2 % MOD;
  }
  ans = (ans - two + MOD) % MOD;
  cout << ans << "\n";
  return 0;
}