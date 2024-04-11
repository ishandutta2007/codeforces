#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  array<int, 26> cnt;
  cnt.fill(0);
  for (char c : s)
    cnt[c - 'a']++;
  for (int i = 1; i < 26; ++i)
    cnt[i] += cnt[i - 1];

  int good = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    int strict = (s[i] > 'a' ? cnt[s[i] - 'a' - 1] : 0);
    int large = cnt[s[i] - 'a'];
    if (i >= strict and i < large)
      good++;
  }
  cout << (int)s.size() - good << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}