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

#define GG do{puts("0"); exit(0);}while (false);
#define ASRT(S) if (!(S)) GG;

const int N = 17, V = (1 << N) + 5;

int ver;
vector<int> g[V];
int cnt[5];
bool vis[V];

void chk(int u, int d) {
  vis[u] = true;
  int cnt = 0;
  for (int v : g[u])
    if (!vis[v]) {
      chk(v, d - 1);
      ++cnt;
    }
  if (cnt == 0) {
    ASRT(d == 1);
  } else
    ASRT(cnt == 2);
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int n;
  scanf("%d", &n);
  if (n == 2) {
    puts("2\n1 2");
    return 0;
  }

  // 2 -- 3 -- 1
  ver = (1 << n) - 2;
  for (int rep = 1; rep < ver; ++rep) {
    int u, v;
    scanf("%d%d", &u, &v);
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= ver; ++i) {
    ASRT(g[i].size() <= 4 && g[i].size() > 0);
    ++cnt[g[i].size()];
  }

  if (0 == cnt[2]) { // p = root
    ASRT(cnt[1] == 1 << (n - 1));
    ASRT(cnt[4] == 0);

    static int dis[V];
    queue<int> q;
    for (int i = 1; i <= ver; ++i)
      if (g[i].size() == 1) {
        q.push(i);
        dis[i] = 1;
      }
    vector<int> ans;
    while (!q.empty()) {
      int u = q.front(); q.pop();
      if (dis[u] == n - 1)
        ans.push_back(u);
      if (dis[u] > n - 1)
        GG;
      for (int v : g[u])
        if (!dis[v]) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
    }
    ASRT(ans.size() == 2);
    int rt1 = ans[0], rt2 = ans[1];
    bool fl = false;
    for (int v : g[rt1])
      if (v == rt2) {
        fl = true;
        break;
      }
    ASRT(fl);
    vis[rt1] = true;
    vis[rt2] = true;
    chk(rt1, n - 1);
    chk(rt2, n - 1);
    if (rt1 > rt2)
      swap(rt1, rt2);
    printf("2\n%d %d\n", rt1, rt2);
  } else if (cnt[2] == 2) { // v = leaf
    ASRT(cnt[4] == 0);
    ASRT(cnt[1] == ((1 << (n - 1)) - 1));
    int ans = -1, rt = -1;
    for (int i = 1; i <= ver; ++i) {
      if (g[i].size() != 2)
        continue;
      bool f = false;
      for (int v : g[i])
        if (g[v].size() == 1) {
          f = true;
        }
      if (!f) {
        rt = i;
      } else {
        g[i].push_back(ver + 1);
        ans = i;
      }
    }
    if (ans == -1 || rt == -1)
      GG;
    chk(rt, n);
    printf("1\n%d\n", ans);
  } else {
    ASRT(cnt[4] == 1);
    ASRT(cnt[2] == 1);
    ASRT(cnt[1] == 1 << (n - 1));
    int rt = -1, ans = -1;
    for (int i = 1; i <= ver; ++i)
      if (g[i].size() == 2)
        rt = i;
      else if (g[i].size() == 4)
        ans = i;

    static int dis[V];
    queue<int> q;
    for (int i = 1; i <= ver; ++i)
      if (g[i].size() == 1) {
        q.push(i);
        dis[i] = 1;
      }
    while (!q.empty()) {
      int u = q.front(); q.pop();
      for (int v : g[u])
        if (!dis[v]) {
          dis[v] = dis[u] + 1;
          q.push(v);
        }
    }
    vector<pair<int, int>> vv;
    for (int v : g[ans])
      vv.emplace_back(dis[v], v);
    sort(vv.begin(), vv.end());
    vector<int> ng;
    for (int v : g[ans])
      if (vv[0].second != v && vv[1].second != v)
        ng.push_back(v);
    ng.push_back(ver + 1);
    g[ver + 1].push_back(vv[0].second);
    g[ver + 1].push_back(vv[1].second);
    g[ans] = ng;
    for (int& v : g[vv[0].second])
      if (v == ans) {
        v = ver + 1;
        break;
      }
    for (int& v : g[vv[1].second])
      if (v == ans) {
        v = ver + 1;
        break;
      }
    chk(rt, n);
    printf("1\n%d\n", ans);
  }

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}