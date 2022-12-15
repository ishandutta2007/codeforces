#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n, k;

  cin >> n >> k;
  vector<int> arr(n + 1);
  for (int i = 1; i <= n; ++i)
    cin >> arr[i];
  int sol = -1e18;
  for (int i = 1; i < n; ++i)
    for (int j = n; j > i and (n - j) * i < 2 * n * k; --j) {
      sol = max(sol, i * j - k * (arr[i] | arr[j]));
    }
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