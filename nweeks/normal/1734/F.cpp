#include <bits/stdc++.h>
#define int long long
using namespace std;

map<pair<int, int>, int> dp;

int solve(int n, int m) {
  if (!n)
    return 0;
  if (dp.count({n, m}))
    return dp[{n, m}];
  int &sol = dp[{n, m}];

  if (n % 2 == 1) {
    sol =
        __builtin_popcountll(n - 1) % 2 == __builtin_popcountll(n - 1 + m) % 2;
    sol += solve(n - 1, m);
  } else {
    if (m % 2 == 0)
      sol = 2 * solve(n / 2, m / 2);
    else {
      sol = n - solve(n / 2, m / 2) - solve(n / 2, (m + 1) / 2);
    }
  }

  return sol;
}

void solve() {
  int n, m;
  cin >> n >> m;
  cout << m - solve(m, n) << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}