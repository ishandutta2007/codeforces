#include <bits/stdc++.h>
using namespace std;

const int MAXBIT = 20;
int nbElem, nbBits;
vector<int> arr;
vector<int> sol[MAXBIT];

vector<int> solve(int deb, int fin, int bit, vector<int> restants) {
  if (bit == -1) {
    assert(restants.size() <= 1);
    return restants;
  }

  int mid = (deb + fin) / 2;
  vector<int> lft, rgt;
  for (int &x : restants) {
    if (x & (1 << bit))
      rgt.push_back(x);
    else
      lft.push_back(x);
  }
  if (lft.empty()) {
    auto ret = solve(mid, fin, bit - 1, rgt);
    assert(ret.size() == (1 << bit));
    for (int i = 0; i < (1 << bit); ++i)
      ret.push_back(ret[i]);
    return ret;
  } else if (rgt.empty()) {
    auto ret = solve(deb, mid, bit - 1, lft);
    assert(ret.size() == (1 << bit));
    for (int i = 0; i < (1 << bit); ++i)
      ret.push_back(ret[i]);
    return ret;
  }

  auto retLft = solve(deb, mid, bit - 1, lft);
  auto retRgt = solve(mid, fin, bit - 1, rgt);
  assert(retLft.size() == (1 << bit));
  assert(retRgt.size() == (1 << bit));

  vector<int> ret(1 << (bit + 1));
  for (int a = 0; a < (1 << (bit + 1)); ++a) {
    int y = 1e9;
    int flipA = (1 << (bit + 1)) - 1 - a;
    assert(flipA < (1 << (bit + 1)));
    if (!(a & (1 << bit))) {
      y = (a ^ retRgt[a]) - (a ^ retLft[(1 << bit) - 1 - a]);
      ret[a] = retLft[a];
    } else {
      y = (a ^ retLft[a ^ (1 << bit)]) - (a ^ retRgt[flipA]);
      ret[a] = retRgt[a ^ (1 << bit)];
    }
    sol[bit][a] = min(sol[bit][a], y);
  }
  return ret;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> nbElem >> nbBits;
  arr.resize(nbElem);
  for (int i = 0; i < MAXBIT; ++i)
    sol[i].assign(1 << nbBits, 1e9);

  for (int &v : arr)
    cin >> v;

  sort(arr.begin(), arr.end());

  solve(0, (1 << nbBits), nbBits - 1, arr);

  for (int x = 0; x < (1 << nbBits); ++x) {
    int ret = 1e9;
    int y = x;
    for (int bit = nbBits - 1; bit >= 0; --bit) {
      ret = min(ret, sol[bit][y]);
      if ((1 << bit) & y)
        y ^= 1 << bit;
    }
    cout << ret << '\n';
    // cout << ret << ' ';
  }
  cout << endl;
}