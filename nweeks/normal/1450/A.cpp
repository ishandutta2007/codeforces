#include <bits/stdc++.h>
#define int long long
using namespace std;

string solve() {
  int nbCarac;
  cin >> nbCarac;
  string s;
  cin >> s;

  string order = "trygrup";
  map<char, int> hsh;
  for (int i = 0; i < (int)order.size(); ++i) {
    hsh[order[i]] = i;
  }

  for (int i = 0; i < nbCarac; ++i) {
    for (int j = i + 1; j < nbCarac; ++j) {
      if (hsh.count(s[i]) and hsh.count(s[j]) and hsh[s[i]] < hsh[s[j]])
        swap(s[i], s[j]);
    }
  }
  return s;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int tc;
  cin >> tc;
  while (tc--)
    cout << solve() << endl;
}