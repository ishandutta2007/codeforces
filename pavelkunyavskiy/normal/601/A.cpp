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

#define TASKNAME "A"

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

int g[410][410];
int d[410];

int main() {
  #ifdef LOCAL
  assert(freopen (TASKNAME".in", "r", stdin));
  assert(freopen (TASKNAME".out", "w", stdout));
  #endif

  int n, m;
  scanf ("%d%d", &n, &m);
  for (int i = 0; i < m; i++) {
    int a, b;
    scanf ("%d%d", &a, &b);
    --a, --b;
    g[a][b] = g[b][a] = 1;
  }
  queue<int> q;
  q.push (0);
  memset (d, -1, sizeof (d));
  d[0] = 0;
  while (!q.empty ()) {
    int v = q.front ();
    q.pop ();
    if (v == n - 1) {
      printf ("%d\n", d[v]);
      return 0;
    }
    for (int i = 0; i < n; i++)
      if (g[v][i] ^ g[0][n - 1]) {
        if (d[i] == -1) {
          q.push (i);
          d[i] = d[v] + 1;
        }
      }
  }
  printf ("-1\n");
  return 0;
}