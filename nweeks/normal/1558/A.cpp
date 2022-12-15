#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int a, b;
  cin >> a >> b;

  set<int> possible;
  int nbJeux = a + b;
  int nbPar[2] = {0, 0};
  for (int i = 0; i < nbJeux; ++i)
    nbPar[i % 2]++;

  for (int i = 0; i < 2; ++i) {
    for (int nbBreakA = 0; nbBreakA <= a; ++nbBreakA) {
      int evenLeft = nbPar[0] - nbBreakA;
      int oddLeft = nbPar[1] - (a - nbBreakA);
      if (evenLeft + oddLeft != b)
        continue;
      if (evenLeft < 0 or oddLeft < 0)
        continue;
      int nbBreakB = oddLeft;
      possible.insert(nbBreakA + nbBreakB);
    }
    swap(a, b);
  }
  cout << possible.size() << '\n';
  for (int x : possible)
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