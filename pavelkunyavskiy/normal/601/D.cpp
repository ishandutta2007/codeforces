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

const int MAXN = 300000;

long long best;
int bestcnt;
vector<int> g[MAXN];
char c[MAXN];
int cost[MAXN];
long long ans[MAXN];

void merge_sons(int v) {
  sort(g[v].begin(), g[v].end(), [](int a, int b) { return c[a] < c[b];});
  vector<int> ng;
  for (int i = 0; i < (int)g[v].size(); ) {
    int j = i;
    while (j < (int)g[v].size() && c[g[v][i]] == c[g[v][j]]) j++;
    if (j - i > 1) {
      for (int k = i + 1; k < j; k++) {
        g[g[v][i]].insert(g[g[v][i]].end(), g[g[v][k]].begin(), g[g[v][k]].end());
        g[g[v][k]].clear();
        g[g[v][k]].shrink_to_fit ();
      }
      merge_sons(g[v][i]);
    }
    ng.push_back (g[v][i]);
    i = j;
  }
  g[v] = ng;
  ans[v] = 1;
  for (int u : g[v])
    ans[v] += ans[u];
  eprintf("merge_sons(%d) -> %lld\n", v, ans[v]);
}

void dfs(int v) {
  for (int u : g[v]) {
    g[u].erase(find(g[u].begin(), g[u].end(), v));
    dfs(u);
  }
  merge_sons(v);
  eprintf("ans[%d] = %lld\n", v, ans[v]);
  if (ans[v] + cost[v] > best) {
    best = ans[v] + cost[v];
    bestcnt = 0;
  }
  if (ans[v] + cost[v] == best) {
    bestcnt++;
  }
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++) {
    scanf("%d",&cost[i]);
  }
  scanf("%s", c);
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d",&a,&b);
    --a, --b;
    g[a].push_back (b);
    g[b].push_back (a);
  }

  dfs(0);

  printf("%lld\n%d\n", best, bestcnt);
      
  return 0;
}