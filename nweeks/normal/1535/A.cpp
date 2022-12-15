#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int s1, s2, s3, s4;
  cin >> s1 >> s2 >> s3 >> s4;
  int s = max(s1, s2);
  int t = max(s3, s4);
  vector<int> x = {s1, s2, s3, s4};
  sort(x.begin(), x.end());
  if (s < t)
    swap(s, t);
  if (s != x[3] or t != x[2])
    cout << "NO\n";
  else
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