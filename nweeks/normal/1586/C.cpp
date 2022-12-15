#include <bits/stdc++.h>
#include <cmath>
#define int long long
using namespace std;

template <class T> class Fenwick {
public:
  int lim;
  vector<T> bit;

  Fenwick(int n) : lim(n + 1), bit(lim) {}

  void upd(int pos, T val) {
    for (pos++; pos < lim; pos += pos & -pos)
      bit[pos] += val;
  }

  T sum(int r) { // < r
    T ret = 0;
    for (; r; r -= r & -r)
      ret += bit[r];
    return ret;
  }

  T sum(int l, int r) { // [l, r)
    return sum(r) - sum(l);
  }
};

const int INF = 1e18;

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbLig, nbCol;
  cin >> nbLig >> nbCol;
  vector<vector<bool>> isFree(nbLig, vector<bool>(nbCol));
  for (int iLig = 0; iLig < nbLig; ++iLig) {
    for (int iCOl = 0; iCOl < nbCol; ++iCOl) {
      char c;
      cin >> c;
      isFree[iLig][iCOl] = c == '.';
    }
  }

  Fenwick<int> fen(nbCol);
  for (int iLig = 1; iLig < nbLig; ++iLig)
    for (int iCol = 1; iCol < nbCol; ++iCol)
      if (!isFree[iLig - 1][iCol] and !isFree[iLig][iCol - 1])
        fen.upd(iCol, 1);

  int q;
  cin >> q;
  while (q--) {
    int deb, fin;
    cin >> deb >> fin;
    if (fen.sum(deb, fin))
      cout << "NO\n";
    else
      cout << "YES\n";
  }
}