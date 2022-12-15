#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Contract {
  int x, cost, y;
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbContrats, nbClients;
  cin >> nbContrats >> nbClients;
  vector<Contract> contracts(nbContrats);
  for (Contract &c : contracts) {
    cin >> c.x >> c.cost >> c.y;
  }

  sort(contracts.begin(), contracts.end(), [&](Contract l, Contract r) {
    return tuple(l.x, l.cost, l.y) < tuple(r.x, r.cost, r.y);
  });

  vector<double> dp(nbContrats);
  double sol = 0;
  for (int i = 0; i < nbContrats; ++i) {
    dp[i] = -contracts[i].cost;
    for (int j = 0; j < i; ++j) {
      dp[i] = max(dp[i], -contracts[i].cost +
                             (contracts[i].x - contracts[j].x) *
                                 (contracts[i].y + contracts[j].y) / 200. *
                                 nbClients +
                             dp[j]);
    }
    sol = max(sol, dp[i]);
  }
  cout << setprecision(15) << fixed << sol << endl;
}