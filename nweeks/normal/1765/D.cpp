#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbVideos, tailleDisque;
  cin >> nbVideos >> tailleDisque;

  vector<int> longueur(nbVideos);
  for (int &l : longueur)
    cin >> l;

  multiset<int> lft;
  for (int &x : longueur)
    lft.insert(x);

  int befSpace = 0;
  int sol = 0;
  for (int i = 0; i < nbVideos; ++i) {
    auto it = lft.upper_bound(befSpace);
    if (it != lft.begin()) {
      it--;
      int len = *it;
      lft.erase(it);
      sol += len;
      befSpace = tailleDisque - len;
    } else {
      it = lft.end();
      --it;
      int len = *it;
      sol += len + 1;
      befSpace = tailleDisque - len;
      lft.erase(it);
    }
  }
  cout << sol << endl;
}