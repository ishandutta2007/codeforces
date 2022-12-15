#include <bits/stdc++.h>
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

void solve() {
  int nbLig, nbCol;
  cin >> nbLig >> nbCol;
  map<int, vector<int>> withSight;
  for (int i = 0; i < nbLig * nbCol; ++i) {
    int x;
    cin >> x;
    withSight[x].push_back(i);
  }

  int curLig = 0, curCol = 0;
  vector<pair<int, int>> pos(nbLig * nbCol);
  vector<Fenwick<int>> fen(nbLig, Fenwick<int>(nbCol));
  for (auto [sight, vec] : withSight) {
    int curPos = 0;
    int nbWith = vec.size();
    while (curPos < nbWith) {
      int take = min(nbCol - curCol, nbWith - curPos);
      for (int i = curPos + take - 1; i >= curPos; --i) {
        assert(curCol < nbCol);
        pos[vec[i]] = make_pair(curLig, curCol++);
      }
      curPos += take;
      if (curCol == nbCol)
        curCol = 0, curLig++;
    }
  }
  int ret = 0;
  for (auto [lig, col] : pos) {
    ret += fen[lig].sum(col);
    fen[lig].upd(col, 1);
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