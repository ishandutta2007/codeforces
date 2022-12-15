#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  if (n == 1)
    cout << "a\n";
  else if (n % 2 == 0) {
    int k = (n - 2) / 2;
    cout << string(k, 'a') << 'b' << string(k + 1, 'a') << '\n';
  } else {
    int k = (n - 3) / 2;
    cout << 'c' << string(k, 'a') << 'b' << string(k + 1, 'a') << '\n';
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