#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

#define pb push_back
#define f first
#define s second
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 2 * (int) 1e5 + 10;

using namespace std;

struct edge {
  int a, b, c, id;
  bool norm;

  edge(int a = 0, int b = 0, int c = 0, int id = 0, bool norm = false) : a(a), b(b), c(c), id(id), norm(norm) {};
};

int n, m;
vector <int> g[MAXN];
edge e[2 * MAXN];
int sum[MAXN];
int ans[MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &m);
  int es = 0; memset(sum, 0, sizeof sum);
  for (int i = 0; i < m; i++) {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    a--; b--;
    g[a].pb(es);
    e[es++] = edge(a, b, c, i, true);
    g[b].pb(es);
    e[es++] = edge(b, a, c, i, false);
    sum[a] += c;
    sum[b] += c;
  }

  set <pii> s; memset(ans, -1, sizeof ans);
  sum[0] = 0; sum[n - 1] = 2 * (int) 1e9;
  s.insert(mp(sum[0], 0));

  while (!s.empty()) {
    int v = s.begin() -> second;
    s.erase(mp(sum[v], v));
    if  (sum[v] > 0) break;

    for (int i = 0; i < sz(g[v]); i++) {
      int id = g[v][i];
      int b = e[id].b;
      int c = e[id].c;

      if  (ans[e[id].id] != -1) continue;

      s.erase(mp(sum[b], b));
      sum[b] -= 2 * c;
      if  (e[id].norm)
        ans[e[id].id] = 0;
      else
        ans[e[id].id] = 1;
      s.insert(mp(sum[b], b));
    }
  }

  for (int i = 0; i < m; i++)
    printf("%d\n", ans[i]);
  return 0;
}