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

#define TASKNAME "B"

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

const int INF = 1e9;

typedef long long ll;
typedef long double ld;

const int MAXN = 100000;

vector<int> g[MAXN];
vector<int> col[MAXN];

vector<int> used;
vector<int> inv;
int usedptr;

vector<int> best;
vector<int> result;
vector<int> cur;


bool dfs(int v, int inv_me, int color) {
  inv[v] = inv_me;
  used[v] = usedptr;
  if (inv_me) {
    cur.push_back(v);
  }
  for (int i = 0; i < (int)g[v].size(); i++) {
    int to = g[v][i];
    int c = col[v][i];

    int change = (c ^ inv_me) != color;

    if (used[to] == usedptr) {
      if (inv[to] == change) {
        continue;
      }
      return false;
    } else {
      if (!dfs(to, change, color)) {
        return false;
      }
    }
  }
  return true;
}

bool solve_color(int n, int color, vector<int>& ans) {
  used = vector<int>(n, 0);
  inv = vector<int>(n, 0);
  usedptr = 0;

  for (int i = 0; i < n; i++) {
    if (used[i] == 0) {
      best.clear();
      bool found = false;
      for (int a = 0; a <= 1; a++) {
        cur.clear();
        usedptr++;
        if (dfs(i, a, color)) {
          if (!found || best.size() > cur.size()) {
            best = cur;
          }
          found = true;
        }

        if (!found) {
          return false;
        }
      }
      ans.insert(ans.end(), best.begin(), best.end());
    }
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
  for (int i = 0; i < m; i++) {
    int a, b;
    char c;
    scanf("%d %d %c",&a,&b,&c);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
    col[a].push_back(c == 'R');
    col[b].push_back(c == 'R');
  }

  vector<int> ans0;
  vector<int> ans1;

  bool ok0 = solve_color(n, 0, ans0);
  bool ok1 = solve_color(n, 1, ans1);

  if (!ok0 && !ok1) {
    printf("-1\n");
    return 0;
  }

  if (ok0) result = ans0;
  if (ok1) result = ans1;
  if (ok0 && ok1) {
    if (ans0.size() < ans1.size())
      result = ans0;
    else
      result = ans1;
  }

  printf("%d\n", (int)result.size());

  for (int x : result)
    printf("%d ", x + 1);
  printf("\n");

  return 0;
}