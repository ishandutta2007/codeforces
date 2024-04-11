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

#define TASKNAME "C"

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

vector<bool> ok;
vector<bool> in;
vector<vector<int>> g;
vector<int> ans;

vector<int> first, second;

void use_var(int v, int x){
  ok[v] = true;
  if (first[x] == v || second[x] == v)
    ans[x] = 1;
  else {
    assert(first[x] == -v || second[x] == -v);
    ans[x] = 0;
  }
}

void dfs(int v, int come) {
  in[v] = true;
  for (int x : g[v]) {
    if (x == come) continue;
    int to = abs(first[x]) + abs(second[x]) - v;
    if (in[to]) {
      if (!ok[v]) use_var(v, x);
    } else {
      if (!ok[to]) dfs(to, x);
      if (ok[to]) {
        if (!ok[v]) use_var(v, x);
      } else {
        use_var(to, x);
      }
    }
  }
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, m;
  scanf("%d%d",&n, &m);
  first.resize(m + 1);
  second.resize(m + 1);
  ans.resize(m + 1);
  ok.resize(n + 1);
  in.resize(n + 1);
  g.resize(n + 1);
  for (int i = 1; i <= n; i++) {
    int k;
    scanf("%d", &k);
    for (int j = 0; j < k; j++){
      int x;
      scanf("%d", &x);
      int y = abs(x);
      if (first[y] == 0)
        first[y] = (x < 0 ? -i : i);
      else
        second[y] = (x < 0 ? -i : i);
    }
  }
  for (int i = 1; i <= m; i++) {
    if (first[i] == 0) {
      ans[i] = 1;
    } else if (second[i] == 0 || (first[i] * 1LL * second[i] > 0)) {
      ans[i] = first[i] > 0;
      ok[abs(first[i])] = 1;
      ok[abs(second[i])] = 1;
    } else {
      g[abs(first[i])].push_back(i);
      g[abs(second[i])].push_back(i);
    }
  }

  for (int i = 1; i <= n; i++){
    if (!ok[i]) dfs(i, -1);
    if (!ok[i]) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 1; i <= m; i++)
    printf("%d", ans[i]);
  printf("\n");
  return 0;
}