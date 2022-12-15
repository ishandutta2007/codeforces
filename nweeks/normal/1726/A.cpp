#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int &x : arr)
    cin >> x;
  int sol = -1e18;
  for (int i = 0; i < n; ++i)
    sol = max(sol, arr[(i + n - 1) % n] - arr[i]);
  for (int i = 1; i < n; ++i)
    sol = max(sol, arr[i] - arr[0]);
  for (int i = 0; i < n - 1; ++i)
    sol = max(sol, arr[n - 1] - arr[i]);
  cout << sol << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}