#include <bits/stdc++.h>
#define int long long
using namespace std;

int swapToSort(vector<int> p) {
  int n = p.size();
  vector<bool> seen(n);
  int ret = 0;
  for (int i = 0; i < n; ++i)
    if (!seen[i]) {
      ret++;
      seen[i] = true;
      int j = p[i];
      while (j != i) {
        seen[j] = true;
        j = p[j];
      }
    }
  return n - ret;
}

void solve() {
  int n, m;
  cin >> n >> m;

  vector<int> p(n);
  vector<int> cntOcc(n);
  for (int i = 0; i < n; ++i) {
    cin >> p[i];
    --p[i];
    int k = (i >= p[i] ? i - p[i] : i + n - p[i]);
    // cout << k << endl;
    cntOcc[k]++;
  }

  vector<int> ret;
  for (int k = 0; k < n; ++k)
    if (cntOcc[k] >= n - 2 * m) {
      vector<int> q(n);

      for (int i = 0; i < n; ++i)
        q[(i + n - k) % n] = p[i];

      if (swapToSort(q) <= m)
        ret.push_back(k);
    }
  cout << ret.size();
  for (int k : ret)
    cout << ' ' << k;
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