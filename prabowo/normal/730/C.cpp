#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i <= (b); i++)
#define FORN(i, a, b) for (int i = (a); i < (b); i++)
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FORD(i, a, b) for (int i = (a); i >= (b); i--)
#define BUG(x) cerr << #x << " = " << x << endl
#define SIZE(a) ((int) a.size())

#define PI acos(-1)

#define maxn 5111

#define oo 1000000000

typedef pair<int, int> pii;

struct Store {
  int city, items, price;
};

int n, m, d[maxn], storeCount;
vector<int> ds[maxn];
Store store[maxn];

bool operator < (const Store& lhs, const Store& rhs)
{
  return lhs.price < rhs.price;
}


void bfs(int u) {
  FOR (i, 1, n) {
    d[i] = oo;
  }

  queue<int> q;
  d[u] = 0;
  q.push(u);

  while (!q.empty()) {
    int u = q.front();
    q.pop();

    REP(i, SIZE(ds[u])) {
      int v = ds[u][i];

      if (d[v] == oo) {
        d[v] = d[u] + 1;
        q.push(v);
      }
    }
  }
}

bool check(int time, int city, int items, int budget) {
  vector<pii> available;

  FOR (i, 1, storeCount)
    if (d[store[i].city] <= time) {
      available.push_back(make_pair(store[i].price, store[i].items));
    }

  // sort(available.begin(), available.end());

  int need = items;
  long long money = budget;

  REP(i, SIZE(available)) {
    pii item = available[i];

    long long buy = min(need, item.second);

    money -= buy * item.first; 

    if (money < 0) return false;
    need -= buy;
  }

  return (need <= 0);
}

bool cmpStore(Store const& a, Store const& b) {
  return d[a.city] < d[b.city];
}

int solve(int city, int items, int budget) {
  bfs(city);

  int res = -1, l = 0, r = n;

  while (l <= r) {
    int m = (l + r) / 2;

    if (check(m, city, items, budget)) {
      res = m;
      r = m - 1;
    }
    else l = m + 1;
  }

  return res;
}

int main() {
  cin >> n >> m;
  FOR (i, 1, m) {
    int u, v;

    cin >> u >> v;
    ds[u].push_back(v);
    ds[v].push_back(u);
  }

  cin >> storeCount;
  FOR (i, 1, storeCount) {
    cin >> store[i].city >> store[i].items >> store[i].price;
  }

  sort(store + 1, store + 1 + storeCount);

  int q;
  cin >> q;
  int city, items, budget;

  while (q--) {
    cin >> city >> items >> budget;
    cout << solve(city, items, budget) << endl;
  }
  return 0;
}