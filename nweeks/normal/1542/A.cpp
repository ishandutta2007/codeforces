#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  int nb[2] = {0, 0};
  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;
    nb[x % 2]++;
  }
  if (nb[0] != nb[1])
    cout << "No";
  else
    cout << "Yes";
  cout << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}