#include <bits/stdc++.h>
#include <iterator>
#define int long long
using namespace std;

void solve() {
  int nbSommets;
  cin >> nbSommets;
  vector<int> dis(nbSommets);
  for (auto &v : dis)
    cin >> v;
  sort(dis.begin(), dis.end());
  int tot = 0;
  for (int i = 1; i < nbSommets; ++i)
    tot += dis[i] - dis[i - 1];
  int curSum = 0;
  for (int i = 1; i < nbSommets; ++i) {
    tot -= i * dis[i] - curSum;
    curSum += dis[i];
  }
  cout << tot << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}