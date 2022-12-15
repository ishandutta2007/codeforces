#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1e9 + 7;

vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47};
vector<int> candidats;

void solve() {
  int n;
  cin >> n;

  int nbCandidats = candidats.size();
  int sol = 0;
  for (int i = 0; i < nbCandidats; ++i) {
    __int128 prodAvant = 1;
    for (int j = 0; j < i and prodAvant <= n; ++j) {
      prodAvant = lcm((int)prodAvant, candidats[j]);
    }
    int p = candidats[i] / gcd((int)prodAvant, candidats[i]);
    int cb = n / prodAvant - n / (prodAvant * p);
    // cout << primes[i] << ' ' << cb << endl;
    cb %= MOD;
    prodAvant *= candidats[i];
    sol += candidats[i] * cb % MOD;
    sol %= MOD;
    if (sol < 0)
      sol += MOD;
  }
  cout << sol << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for (int i = 0; i < (int)primes.size(); ++i) {
    int cur = primes[i];
    while (cur <= primes.back()) {
      candidats.push_back(cur);
      cur *= primes[i];
    }
  }
  sort(candidats.begin(), candidats.end());

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}