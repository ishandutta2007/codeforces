#include <bits/stdc++.h>
#define int long long
using namespace std;

int solve() {
  int nbElem;
  cin >> nbElem;
  vector<int> arr(nbElem);
  map<int, int> cntOcc;
  for (int iEl = 0; iEl < nbElem; ++iEl) {
    cin >> arr[iEl];
    cntOcc[arr[iEl]]++;
  }
  for (auto [u, v] : cntOcc)
    if (v > (nbElem + 1) / 2)
      return -1;

  vector<pair<int, int>> segs;
  int cur = 0;
  while (cur < nbElem) {
    int fst = arr[cur];
    while (cur + 1 < nbElem and arr[cur] != arr[cur + 1])
      ++cur;
    int lst = arr[cur];
    segs.emplace_back(fst, lst);
    cur++;
  }

  cntOcc.clear();
  int nbSegs(segs.size());
  for (int i(0); i < nbSegs; ++i) {
    auto [deb, fin] = segs[i];
    cntOcc[deb]++;
    cntOcc[fin]++;
  }
  int sol = 0;
  for (auto [u, v] : cntOcc) {
    sol = max(sol, nbSegs - 1 + max(0LL, v - nbSegs - 1));
  }
  return sol;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  int t;
  cin >> t;
  ;
  while (t--)
    cout << solve() << '\n';
}