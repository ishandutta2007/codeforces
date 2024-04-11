#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  array<int, 10> best;
  best.fill(-1);
  for (int i = 0; i < n; ++i) {
    int b, d;
    cin >> b >> d;
    best[d - 1] = max(best[d - 1], b);
  }
  for (int i = 0; i < 10; ++i)
    if (best[i] < 0) {
      cout << "MOREPROBLEMS\n";
      return;
    }
  int s = 0;
  for (int x : best)
    s += x;
  cout << s << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}