#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbCol;
  cin >> nbCol;
  vector<int> height(nbCol + 2);
  for (int i(1); i <= nbCol; ++i)
    cin >> height[i];

  int nbOps = 0;
  for (int i(1); i <= nbCol; ++i) {
    if (height[i - 1] < height[i] and height[i] > height[i + 1]) {
      int goTo = max(height[i - 1], height[i + 1]);
      nbOps += height[i] - goTo;
      height[i] = goTo;
    }
  }

  for (int i(1); i <= nbCol + 1; ++i)
    nbOps += abs(height[i] - height[i - 1]);
  cout << nbOps << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}