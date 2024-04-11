#include <bits/stdc++.h>
#define int long long
using namespace std;

struct unionFind {

  vector<int> id;
  vector<set<int>> inCC;
  set<int> ccs;

  unionFind(int n) : id(n, -1), inCC(n) {
    for (int i = 0; i < n; ++i) {
      inCC[i].insert(i);
      ccs.insert(i);
    }
  }

  int find(int u) {
    if (id[u] < 0)
      return u;
    return id[u] = find(id[u]);
  }

  void merge(int a, int b) {
    a = find(a), b = find(b);
    if (a > b)
      swap(a, b);
    if (id[a] > id[b])
      swap(a, b);
    id[a] += id[b];
    id[b] = a;
    if (inCC[a].size() < inCC[b].size())
      inCC[a].swap(inCC[b]);
    for (int x : inCC[b])
      inCC[a].insert(x);
    inCC[b].clear();
    ccs.erase(b);
  }
};

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int nbSommets, aretesGauche, aretesDroite;

  cin >> nbSommets >> aretesGauche >> aretesDroite;

  unionFind ufLft(nbSommets), ufRgt(nbSommets);

  for (int i = 0; i < aretesGauche; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ufLft.merge(u, v);
  }
  for (int i = 0; i < aretesDroite; ++i) {
    int u, v;
    cin >> u >> v;
    --u, --v;
    ufRgt.merge(u, v);
  }

  cout << nbSommets - 1 - max(aretesGauche, aretesDroite) << endl;

  while (ufLft.ccs.size() > 1 and ufRgt.ccs.size() > 1) {
    auto it1 = ufLft.ccs.begin();
    auto it2 = next(it1);
    int u = *it1;
    int v = *it2;

    if (ufRgt.find(u) != ufRgt.find(v)) {
      cout << u + 1 << ' ' << v + 1 << '\n';
      ufLft.merge(u, v);
      ufRgt.merge(u, v);
    } else {
      auto it3 = ufRgt.ccs.begin();
      if (*it3 == ufRgt.find(u))
        ++it3;
      int w = *it3;
      if (ufLft.find(w) == ufLft.find(u))
        swap(u, v);
      assert(ufLft.find(u) != ufLft.find(w));
      assert(ufRgt.find(u) != ufRgt.find(w));
      cout << u + 1 << ' ' << w + 1 << '\n';
      ufLft.merge(u, w);
      ufRgt.merge(u, w);
    }
  }
}