#include <bits/stdc++.h>
#define int long long
using namespace std;

bool solve() {
  string s, t;
  cin >> s >> t;
  int szS = s.size(), szT = t.size();
  if (szT > szS)
    return false;
  int longestPar[2] = {-1, -1};
  int parEnd = (szS + 1) % 2;
  int parStart = (parEnd + szT - 1) % 2;
  for (int i = 0; i < szS; ++i) {
    int par = i % 2;
    int longest = -1;
    if (par == parStart and s[i] == t[0])
      longest = 1;
    if (longestPar[!par] != -1 and t[longestPar[!par]] == s[i])
      longest = 1 + longestPar[!par];

    if (longest == szT)
      return true;
    longestPar[par] = max(longestPar[par], longest);
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