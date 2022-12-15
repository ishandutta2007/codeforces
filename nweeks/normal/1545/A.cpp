#include <bits/stdc++.h>
#define int long long
using namespace std;

const int MAXV = 1e5 + 1;

void solve() {
  int nbPersonnes;
  cin >> nbPersonnes;
  vector<int> val(nbPersonnes);
  vector<int> values[2];
  for (int i = 0; i < nbPersonnes; ++i) {
    int x;
    cin >> x;
    values[i % 2].push_back(x);
  }
  for (int i = 0; i < 2; ++i)
    sort(values[i].begin(), values[i].end());
  vector<int> vals;
  for (int i = 0; i < nbPersonnes; ++i)
    vals.push_back(values[i % 2][i / 2]);
  if (is_sorted(vals.begin(), vals.end()))
    cout << "YES\n";
  else
    cout << "NO\n";
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}