#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbElem;
  cin >> nbElem;
  vector<int> perm(nbElem);
  for (int i = 0; i < nbElem; ++i)
    cin >> perm[i];

  vector<int> incL(nbElem), incR(nbElem), decL(nbElem), decR(nbElem);
  for (int i = 1; i < nbElem; ++i) {
    if (perm[i - 1] > perm[i])
      incL[i] = 1 + incL[i - 1];
    else
      decL[i] = 1 + decL[i - 1];
  }
  for (int i = nbElem - 2; i >= 0; --i) {
    if (perm[i + 1] > perm[i])
      incR[i] = 1 + incR[i + 1];
    else
      decR[i] = 1 + decR[i + 1];
  }
  int lms = 0;
  for (int i = 0; i < nbElem; ++i)
    lms = max({lms, incL[i], incR[i]});
  int nbOcc = 0;
  for (int i = 0; i < nbElem; ++i) {
    if (incL[i] == lms)
      nbOcc++;
    if (incR[i] == lms)
      nbOcc++;
  }

  int ret = 0;
  for (int i = 0; i < nbElem; ++i) {
    if (decL[i] == lms and decR[i] == lms and lms % 2 == 0 and nbOcc == 2)
      ret++;
  }

  cout << ret << endl;
}