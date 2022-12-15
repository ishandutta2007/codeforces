#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6 + 2;
vector<pair<int, int>> adj[MAXN];

struct UnionFind {
  vector<int> id;

  UnionFind() {}
  UnionFind(int N) { id.assign(N, -1); }

  int find(int u) {
    if (id[u] < 0)
      return u;
    return id[u] = find(id[u]);
  }

  bool merge(int u, int v) {
    u = find(u), v = find(v);
    if (u == v)
      return false;
    if (id[u] > id[v])
      swap(u, v);
    id[u] += id[v];
    id[v] = u;
    return true;
  }
};

bitset<MAXN> isPrime;
int factor[MAXN];

void sieve() {
  isPrime.flip();
  isPrime[0] = isPrime[1] = false;
  for (int p = 2; p * p < MAXN; ++p)
    if (isPrime[p])
      for (int q = 2 * p; q < MAXN; q += p) {
        isPrime[q] = false;
        factor[q] = p;
      }
}

signed main(void) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sieve();

  int n, nbRequetes;
  cin >> n >> nbRequetes;
  vector<int> arr(n);
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
  }

  vector<pair<int, int>> edges;

  auto factorize = [&](int x) {
    vector<int> ret;
    while (!isPrime[x]) {
      ret.push_back(factor[x]);
      x /= factor[x];
    }
    ret.push_back(x);
    sort(ret.begin(), ret.end());
    ret.resize(unique(ret.begin(), ret.end()) - ret.begin());
    return ret;
  };

  vector<vector<int>> fact0(n), fact1(n);
  for (int i = 0; i < n; ++i) {
    fact0[i] = factorize(arr[i]);
    fact1[i] = factorize(arr[i] + 1);
  }

  UnionFind uf(MAXN);
  for (int i = 0; i < n; ++i)
    for (int j = 1; j < (int)fact0[i].size(); ++j)
      uf.merge(fact0[i][0], fact0[i][j]);

  vector<int> cc(n);
  for (int i = 0; i < n; ++i)
    cc[i] = uf.find(fact0[i][0]);

  set<pair<int, int>> inOne;
  for (int i = 0; i < n; ++i) {
    for (int p : fact0[i])
      for (int q : fact1[i]) {
        inOne.emplace(uf.find(p), uf.find(q));
        inOne.emplace(uf.find(q), uf.find(p));
      }
    for (int p : fact1[i])
      for (int q : fact1[i])
        inOne.emplace(uf.find(p), uf.find(q));
  }

  vector<set<int>> reach(MAXN);
  for (int i = 0; i < n; ++i)
    for (int q : fact1[i])
      reach[cc[i]].insert(uf.find(q));

  for (int i = 0; i < nbRequetes; ++i) {
    int x, y;
    cin >> x >> y;
    --x, --y;
    int ret = 2;
    if (cc[x] == cc[y]) {
      ret = 0;
    } else if (inOne.count({cc[x], cc[y]}) or reach[cc[x]].count(cc[y]) or
               reach[cc[y]].count(cc[x]))
      ret = 1;
    cout << ret << '\n';
  }
}