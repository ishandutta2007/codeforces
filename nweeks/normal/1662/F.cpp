#include <bits/stdc++.h>
#define int long long
using namespace std;

const int INF = 1e18;

vector<int> iDeb, iFin;
vector<pair<int, int>> valG, valD;

void init(int node, int l, int r) {
  iDeb[node] = l;
  iFin[node] = r;
  valG[node] = pair(-INF, -1);
  valD[node] = pair(-INF, -1);
  if (l == r)
    return;
  int mid = (l + r) / 2;
  init(2 * node, l, mid);
  init(2 * node + 1, mid + 1, r);
}

void pull(int node) {
  valG[node] = max(valG[2 * node], valG[2 * node + 1]);
  valD[node] = max(valD[2 * node], valD[2 * node + 1]);
}

void setVal(int node, int pos, pair<int, int> x) {
  if (iDeb[node] > pos or iFin[node] < pos)
    return;
  if (iDeb[node] == iFin[node]) {
    valG[node] = pair(x.first, pos);
    valD[node] = pair(x.second, pos);
    return;
  }
  setVal(2 * node, pos, x);
  setVal(2 * node + 1, pos, x);
  pull(node);
}

pair<int, int> getMax(int node, int deb, int fin, bool side) {
  if (iFin[node] < deb or iDeb[node] > fin)
    return pair(-INF, -1);
  if (iDeb[node] >= deb and iFin[node] <= fin)
    return (side ? valD[node] : valG[node]);
  return max(getMax(2 * node, deb, fin, side),
             getMax(2 * node + 1, deb, fin, side));
}

void solve() {
  int n, deb, fin;
  cin >> n >> deb >> fin;
  --deb, --fin;
  vector<int> puissance(n);
  for (int &x : puissance)
    cin >> x;
  iDeb.resize(4 * n);
  iFin.resize(4 * n);
  valG.resize(4 * n);
  valD.resize(4 * n);
  init(1, 0, n - 1);
  for (int i = 0; i < n; ++i)
    setVal(1, i, pair(i + puissance[i], puissance[i] - i));

  queue<int> q;
  q.push(deb);
  vector<int> dis(n, -1);
  dis[deb] = 0;
  setVal(1, deb, pair(-INF, -INF));
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    // cout << u + 1 << endl;

    while (true) {
      auto [val, nxt] = getMax(1, u - puissance[u], u - 1, 0);
      // cout << "PotentialL " << 1 + u << ' ' << 1 + nxt << endl;
      if (val == -INF or puissance[nxt] + nxt < u)
        break;
      assert(dis[nxt] == -1);
      dis[nxt] = dis[u] + 1;
      q.push(nxt);
      // cout << u + 1 << ' ' << nxt + 1 << endl;
      setVal(1, nxt, pair(-INF, -INF));
    }
    while (true) {
      auto [val, nxt] = getMax(1, u + 1, u + puissance[u], 1);
      // cout << "PotentialR " << 1 + u << ' ' << 1 + nxt << endl;
      if (val == -INF or nxt - puissance[nxt] > u)
        break;
      assert(dis[nxt] == -1);
      dis[nxt] = dis[u] + 1;
      q.push(nxt);
      // cout << u + 1 << ' ' << nxt + 1 << endl;
      setVal(1, nxt, pair(-INF, -INF));
    }
  }
  assert(dis[fin] != -1);
  cout << dis[fin] << '\n';
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nbTests;
  cin >> nbTests;
  for (int iTest(0); iTest < nbTests; ++iTest)
    solve();
}