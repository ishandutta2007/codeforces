#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string s;
  cin >> s;
  int n = s.size();

  // -1 : lose, 1 : draw, 1 : win
  vector<vector<int>> dp(n, vector<int>(n + 1));
  for (int deb = n - 1; deb >= 0; --deb)
    for (int fin = deb + 2; fin <= n; fin += 2) {
      if (fin == deb + 2) {
        dp[deb][fin] = s[deb] != s[fin - 1];
        continue;
      }
      // On prend  gauche
      int valGauche = 1;
      if (s[deb] == s[deb + 1])
        valGauche = min(valGauche, dp[deb + 2][fin]);
      if (s[deb] == s[fin - 1])
        valGauche = min(valGauche, dp[deb + 1][fin - 1]);
      // On prend  droite
      int valDroite = 1;
      if (s[fin - 2] == s[fin - 1])
        valDroite = min(valDroite, dp[deb][fin - 2]);
      if (s[deb] == s[fin - 1])
        valDroite = min(valDroite, dp[deb + 1][fin - 1]);
      dp[deb][fin] = max(valGauche, valDroite);
    }
  if (dp[0][n] == 1)
    cout << "Alice\n";
  else if (dp[0][n] == -1)
    cout << "Bob\n";
  else
    cout << "Draw\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}