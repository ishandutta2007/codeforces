#include <algorithm>
#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve() {
  int nbVert, nbHoriz, nbPersonnes;
  cin >> nbVert >> nbHoriz >> nbPersonnes;

  vector<int> vert(nbVert), horiz(nbHoriz);
  for (int &x : vert)
    cin >> x;
  for (int &x : horiz)
    cin >> x;
  nbVert++, nbHoriz++;
  vert.push_back(1e6 + 1);
  horiz.push_back(1e6 + 1);

  vector<int> surVert(nbVert), surHoriz(nbHoriz);
  vector<map<int, int>> onVert(nbVert), onHoriz(nbHoriz);
  int ret = 0;
  for (int i = 0; i < nbPersonnes; ++i) {
    int x, y;
    cin >> x >> y;
    int iVert = lower_bound(vert.begin(), vert.end(), x) - vert.begin();
    int iHoriz = lower_bound(horiz.begin(), horiz.end(), y) - horiz.begin();
    if (vert[iVert] == x and horiz[iHoriz] == y)
      continue;
    if (vert[iVert] == x) {
      ret += surHoriz[iHoriz] - onHoriz[iHoriz][iVert];
      surHoriz[iHoriz]++;
      onHoriz[iHoriz][iVert]++;
    } else {
      ret += surVert[iVert] - onVert[iVert][iHoriz];
      onVert[iVert][iHoriz]++;
      surVert[iVert]++;
    }
  }
  cout << ret << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}