#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
clock_t __my_start_clock = clock();
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, (clock() - __my_start_clock)*1.0/CLOCKS_PER_SEC)

using namespace std;

#ifdef LOCAL
static struct __timestamper {
  string what;
  __timestamper(const char* what) : what(what){};
  __timestamper(const string& what) : what(what){};
  ~__timestamper(){
    TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

vector<vector<int>> g;
int lst;

void add_edges(int v, int l, int r, int L, int R, int vs) {
  if (R <= l || r <= L) return;
  if (L <= l && r <= R) {
    g[vs].push_back(v);
    return;
  }
  add_edges(2 * v    , l, (l + r) / 2, L, R, vs);
  add_edges(2 * v + 1, (l + r) / 2, r, L, R, vs);
}

vector<int> used;
vector<int> ts;

bool dfs(int v, int l, int r) {
  if (used[v] == 1) return false;
  if (used[v] == 2) return true;
  used[v] = 1;
  for (int u : g[v]) {
    if (!dfs(u, l, r)) return false;
  }
  used[v] = 2;
  if (v >= l && v < r) {
    ts.push_back(v - l);
  }
  return true;
}

void solve(int n) {
  lst = 1;
  while (lst < n) lst *= 2;
  g = vector<vector<int>>(2 * lst);
  for (int i = 1; i < lst; i++) {
    g[i].push_back(2 * i);
    g[i].push_back(2 * i + 1);
  }

  for (int i = 0; i < n; i++) {
    int x;
    scanf("%d", &x);
    --x;
    if (x < 0) continue;
    if (x != i) {
      add_edges(1, 0, lst, i + 1, x, i + lst);
    }
    if (x != n) {
      assert(x + lst < (int)g.size());
      g[x + lst].push_back(i + lst);
    }
  }
  used = vector<int>(2 * lst);
  ts.clear();
  for (int i = 0; i < 2 * lst; i++) {
    if (!dfs(i, lst, lst + n)) {
      printf("-1\n");
      return;
    }
  }

  vector<int> answer(n);
  for (int i = 0; i < n; i++) {
    answer[ts[i]] = i + 1;
  }
  for (int x : answer) {
    printf("%d ", x);
  }
  printf("\n");
}

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int t;
  scanf("%d", &t);
  while (t-->0) {
    int n;
    scanf("%d", &n);
    solve(n);
  }

#ifdef LOCAL
  int n;
  while (scanf("%d", &n) == 1) solve(n);
#endif
  return 0;
}