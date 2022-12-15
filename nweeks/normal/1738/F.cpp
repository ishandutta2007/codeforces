#include <bits/stdc++.h>
#define int long long
using namespace std;

int query(int u) {
  cout << "? " << u + 1 << endl;
  int v;
  cin >> v;
  assert(v != -1);
  return v - 1;
}

void solve() {
  int nbSommets;
  cin >> nbSommets;

  vector<int> color(nbSommets, -1);
  vector<int> deg(nbSommets);
  for (int &d : deg)
    cin >> d;
  vector<int> order(nbSommets);
  iota(order.begin(), order.end(), 0LL);
  sort(order.begin(), order.end(),
       [&](int u, int v) { return pair(deg[u], u) > pair(deg[v], v); });
  int cntCol = 0;
  for (int u : order) {
    if (color[u] != -1)
      continue;
    vector<int> seen;
    seen.push_back(u);
    int col = cntCol;
    for (int i = 0; i < deg[u]; ++i) {
      int v = query(u);
      if (color[v] != -1) {
        col = color[v];
        break;
      }
      seen.push_back(v);
    }
    for (int x : seen)
      color[x] = col;
    if (col == cntCol)
      ++cntCol;
  }
  cout << "!";
  for (int x : color)
    cout << ' ' << x + 1;
  cout << endl;
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}