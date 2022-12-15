#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int curPos = 0;
  for (int iter = 0; curPos < n; iter ^= 1) {
    if (!iter)
      curPos++;
    else {
      if (curPos + 1 == n or s[curPos] != s[curPos + 1]) {
        cout << "NO\n";
        return;
      }
      curPos += 2;
    }
  }
  cout << "YES\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}