//#include <iostream>
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
#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "D"

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
vector<vector<int>> id;
vector<int> used;
vector<int> ts;

void dfs(int v, int x) {
  if (used[v]) return;
  used[v] = 1;
  for (int i = 0; i < (int)g[v].size(); i++) {
    if (id[v][i] < x) {
      dfs(g[v][i], x);
    }
  }
  ts.push_back(v);
}

bool check(int x) {
  ts.clear();
  used = vector<int>(g.size());
  for (int i = 0; i < (int)g.size(); i++) {
    dfs(i, x);
  }
  reverse(ts.begin(), ts.end());
  for (int i = 0; i + 1 < (int)ts.size(); i++) {
    int v = ts[i];
    bool ok = false;
    for (int j = 0; j < (int)g[v].size(); j++)
      if (g[v][j] == ts[i + 1] && id[v][j] < x) {
        ok = true;
      }
    if (!ok) return false;
  }
  return true;
}

int main() {
#ifdef LOCAL
  assert(freopen(TASKNAME".in", "r", stdin));
  assert(freopen(TASKNAME".out", "w", stdout));
#endif

  int n, m;
  scanf("%d%d",&n,&m);
  g = vector<vector<int>>(n);
  id = vector<vector<int>>(n);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].pb(b);
    id[a].pb(i);
  }

  if (!check(m)) {
    printf("-1\n");
    return 0;
  }

  int l = 0;
  int r = m;
  while (r - l > 1) {
    int mid = (l + r) / 2;
    if (check(mid))
      r = mid;
    else
      l = mid;
  }

  printf("%d\n", r);
  return 0;
}