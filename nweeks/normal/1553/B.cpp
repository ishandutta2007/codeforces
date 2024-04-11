#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve() {
  string s, t;
  cin >> s >> t;

  int szS = s.size(), szT = t.size();
  for (int start = 0; start < szS; ++start) {
    for (int deltaR = 0; start + deltaR < szS and deltaR < szT and
                         s[start + deltaR] == t[deltaR];
         ++deltaR) {
      int lft = szT - deltaR - 1;
      if (start + deltaR - lft >= 0) {
        bool ok = true;
        for (int i = 1; i <= lft; ++i)
          if (s[start + deltaR - i] != t[deltaR + i])
            ok = false;
        if (ok)
          return true;
      }
    }
  }
  return false;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    cout << (solve() ? "YES" : "NO") << '\n';
}