#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  int nbElem = n * k;

  vector<vector<int>> withCol(n);
  vector<int> col(nbElem);
  for (int i = 0; i < nbElem; ++i) {
    cin >> col[i];
    --col[i];
    withCol[col[i]].push_back(i);
  }

  vector<pair<int, int>> segments;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < k - 1; ++j)
      segments.emplace_back(withCol[i][j], withCol[i][j + 1]);
  vector<bool> used(n);
  sort(segments.begin(), segments.end(),
       [&](auto a, auto b) { return a.second < b.second; });
  vector<int> cnt(nbElem);
  vector<pair<int, int>> sol(n);
  int mxuse = (n + k - 2) / (k - 1);
  for (auto [deb, fin] : segments) {
    if (used[col[deb]])
      continue;
    bool ok = true;
    for (int i = deb; i <= fin; ++i)
      ok &= cnt[i] < mxuse;
    if (ok) {
      used[col[deb]] = true;
      for (int i = deb; i <= fin; ++i)
        cnt[i]++;
      sol[col[deb]] = make_pair(deb + 1, fin + 1);
    }
  }
  for (auto [deb, fin] : sol) {
    assert(deb);
    cout << deb << ' ' << fin << endl;
  }
}