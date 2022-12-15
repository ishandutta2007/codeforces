#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> sol(n);
  iota(sol.begin(), sol.end(), 1);
  if (n % 2 == 0)
    reverse(sol.begin(), sol.end() - 2);
  else {
    for (int i = 1; i + 2 < n; i += 2)
      swap(sol[i], sol[i + 1]);
  }
  for (int x : sol)
    cout << x << ' ';
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