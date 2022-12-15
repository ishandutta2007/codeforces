#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  vector<int> cnt(n);
  for (int &x : cnt)
    cin >> x;
  for (int i = 0; i < n; ++i)
    for (int j = i + 1; j < n; ++j) {
      int m = min(cnt[i], cnt[j]);
      cnt[i] -= m, cnt[j] -= m;
    }
  for (int i = 0; i < n; ++i)
    if (cnt[i])
      cout << i + 1 << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}