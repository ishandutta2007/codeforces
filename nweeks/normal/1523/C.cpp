#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbLig;
  cin >> nbLig;
  vector<int> der(nbLig);
  auto printArr = [](const vector<int> &arr) {
    cout << arr.front();
    for (int i(1); i < (int)arr.size(); ++i)
      cout << "." << arr[i];
    cout << '\n';
  };
  vector<int> cur;
  for (int i(0); i < nbLig; ++i) {
    int x;
    cin >> x;
    if (x == 1)
      cur.push_back(1);
    else {
      while (!cur.empty() and cur.back() + 1 != x)
        cur.pop_back();
      assert(!cur.empty());
      cur.back()++;
    }
    printArr(cur);
  }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}