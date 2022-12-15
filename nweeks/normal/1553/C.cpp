#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  string s;
  cin >> s;

  int ret = 1e9;

  // even win :
  for (int parWin = 0; parWin < 2; ++parWin) {
    int score[2] = {0, 0};
    int restant[2] = {5, 5};
    int curGoal = 0;
    while (curGoal < 10) {
      if (s[curGoal] == '1')
        score[curGoal % 2]++;
      else if (s[curGoal] == '?' and parWin == curGoal % 2)
        score[curGoal % 2]++;
      restant[curGoal % 2]--;
      ++curGoal;
      if (score[parWin] > score[!parWin] + restant[!parWin])
        break;
    }
    ret = min(ret, curGoal);
  }
  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}