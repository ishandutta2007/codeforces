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

#define TASKNAME "E"

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

struct object {
  int v;
  int w;
  int in;
  int out;
};

const int MAXN = 31000;

vector<int> tree[MAXN * 4];
int k;
int lst;

vector<object> objects;
vector<int> queries;

void add(int v, int l, int r, int L, int R, int id) {
  if (r < L || R < l) return;
  if (L <= l && r <= R) {
    tree[v].push_back(id);
    return;
  }
  add(2*v, l, (l+r)/2, L, R, id);
  add(2*v + 1, (l+r)/2 + 1, r, L, R, id);
}

void solve(int v, int L, int R, vector<int> cur) {
  for (int id : tree[v]) {
    int w = objects[id].w;
    int v = objects[id].v;
    for (int i = (int)cur.size() - 1; i >= w; i--) {
      cur[i] = max(cur[i], cur[i-w]+v);
    }
  }
  if (L == R) {
    int ans = 0;
    for (int i = (int) cur.size() - 1; i > 0; i--) {
      ans = (int) ((ans * 10000019LL + cur[i]) % 1000000007);
    }
    printf("%d\n", ans);
    return;
  }
  solve(2*v, L, (L+R)/2, cur);
  solve(2*v + 1, (L+R)/2 + 1, R, cur);
}

int main() {
#ifdef LOCAL
  assert(freopen(TASKNAME".in", "r", stdin));
  assert(freopen(TASKNAME".out", "w", stdout));
#endif

  int n;
  scanf("%d%d", &n, &k);

  objects.resize(n);

  for (int i = 0; i < n; i++) {
    scanf("%d%d", &objects[i].v, &objects[i].w);
    objects[i].in = -1;
    objects[i].out = (int) 1e9;
  }

  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int type;
    scanf("%d", &type);
    if (type == 1) {
      objects.push_back(object());
      scanf("%d%d", &objects.back().v, &objects.back().w);
      objects.back().in = i;
      objects.back().out = (int) 1e9;
    } else if (type == 2) {
      int id;
      scanf("%d", &id);
      --id;
      assert(0 <= id && id < (int)objects.size());
      objects[id].out = i;
    } else {
      assert(type == 3);
      queries.push_back(i);
    }
  }

  for (int i = 0; i < (int)objects.size(); i++) {
    const object& o = objects[i];
    int l = lower_bound(queries.begin(), queries.end(), o.in) - queries.begin();
    int r = upper_bound(queries.begin(), queries.end(), o.out) - queries.begin();
    if (l != r) {
      add(1, 0, (int) queries.size() - 1, l, r - 1, i);
    }
  }

  solve(1, 0, (int) (queries.size() - 1), vector<int>(k + 1, 0));


  return 0;
}