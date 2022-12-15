#include <bits/stdc++.h>
#define int long long
using namespace std;

struct Fenwick {
  int N;
  vector<int> bit;

  Fenwick(int n) : N(n + 1), bit(N) {}

  void upd(int i, int v) {
    for (i++; i < N; i += i & -i)
      bit[i] += v;
  }

  int sum(int r) {
    int v = 0;
    for (; r; r -= r & -r)
      v += bit[r];
    return v;
  }

  int sum(int l, int r) { return sum(r) - sum(l); }
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);

  auto getNxt = [](const set<int> &pos, int cur) {
    auto it = pos.lower_bound(cur);
    if (it == pos.end())
      return *pos.begin();
    return *it;
  };

  int nbCartes;
  cin >> nbCartes;
  const int MAXN = 1e5;
  vector<int> pos[MAXN];
  for (int iCarte = 0; iCarte < nbCartes; ++iCarte) {
    int v;
    cin >> v;
    pos[v - 1].push_back(iCarte);
  }
  Fenwick fen(nbCartes);
  for (int i = 0; i < nbCartes; ++i) {
    fen.upd(i, 1);
  }
  int curPos = 0;
  set<int> alive;
  int sol = 0;
  for (int curVal(0); curVal < MAXN; ++curVal) {
    for (auto v : pos[curVal])
      alive.insert(v);

    while (!alive.empty()) {
      int nxtPos = getNxt(alive, curPos);
      if (nxtPos >= curPos)
        sol += fen.sum(curPos, nxtPos + 1);
      else
        sol += fen.sum(curPos, nbCartes) + fen.sum(0, nxtPos + 1);
      curPos = nxtPos;
      fen.upd(curPos, -1);
      alive.erase(nxtPos);
    }
  }
  cout << sol << endl;
}