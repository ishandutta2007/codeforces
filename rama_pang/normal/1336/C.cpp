#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 998244353;

string S;
string T;

lint memo[5005][5005];

lint dp(int n, int l) {
  if (n < 0) return 1;
  int r = n + l;
  // cout << l << " " << r << endl;
  lint res = 0;
  if (memo[n][l] != -1) return memo[n][l];
  // if (!st) {
  //   res += dp(n, l, true);
  //   res += dp(n - 1, l, st);
  // } else {
  if (S[n] == T[l] || T[l] == '*') {
    res += dp(n - 1, l + 1);
  }
  if (S[n] == T[r] || T[r] == '*') {
    res += dp(n - 1, l);
  }
  // }
  return memo[n][l] = res % MOD;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  memset(memo, -1, sizeof(memo));
  cin >> S >> T;

  lint ans = 0;
  for (int i = T.size(); i <= S.size(); i++) {
    while (T.size() < i) T.push_back('*');
    ans += dp(i - 1, 0);
    ans %= MOD;
  }
  cout << ans << "\n";
  return 0;
}