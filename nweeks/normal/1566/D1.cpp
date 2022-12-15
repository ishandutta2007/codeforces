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
  Fenwick<int> fen(nbCol);
  vector<pair<int, int>> sights(nbCol);
  for (int i = 0; i < nbCol; ++i) {
    cin >> sights[i].first;
    sights[i].second = -i;
  }
  sort(sights.begin(), sights.end());
  vector<int> seat(nbCol);
  for (int i = 0; i < nbCol; ++i)
    seat[-sights[i].second] = i;

  int ret = 0;
  for (int s : seat) {
    ret += fen.sum(s);
    fen.upd(s, 1);
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