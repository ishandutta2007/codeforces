#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}

template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

const int N = 200010;

int n, m, a, b, cnt;
bool va, vb;
vector<int> g[N];
bool vis[N];

void dfs(int u) {
  ++cnt;
  vis[u] = true;
  for (int v : g[u])
    if (!vis[v]) {
      if (v == a)
        va = true;
      else if (v == b)
        vb = true;
      else {
        dfs(v);
      }
    }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &n, &m, &a, &b);
    while (m--) {
      int u, v;
      scanf("%d%d", &u, &v);
      g[u].push_back(v);
      g[v].push_back(u);
    }
    int xa = 0, xb = 0;
    for (int i = 1; i <= n; ++i)
      if (!vis[i] && i != a && i != b) {
        va = vb = cnt = 0;
        dfs(i);
        if (va && !vb)
          xa += cnt;
        else if (vb && !va)
          xb += cnt;
      }
    printf("%lld\n", xa * (ll)xb);

    for (int i = 1; i <= n; ++i)
      g[i].clear();
    fill(vis + 1, vis + n + 1, false);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}