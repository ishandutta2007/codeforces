#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int T;
  cin >> T;
  while (T--) {
    string s;
    cin >> s;
    map<char, int> mp;
    for (auto i : s) {
      mp[i]++;
    }
    int mx = max({mp['S'], mp['R'], mp['P']});
    string ans;
    if (mp['R'] >= mx) {
      ans = string(s.size(), 'P');
    } else if (mp['S'] >= mx) {
      ans = string(s.size(), 'R');
    } else {
      ans = string(s.size(), 'S');
    }
    cout << ans << "\n";
  }
}