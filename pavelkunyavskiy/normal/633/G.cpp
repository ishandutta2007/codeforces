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

#define TASKNAME "G"

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

const int M = 1000;

typedef bitset<M> mask_t;

int n;

mask_t all;
mask_t primes;

const int MAXN = 1 << 18;

mask_t tree[MAXN];
int shift[MAXN];
int lst;

vector<int> g[MAXN];
int tin[MAXN];
int tout[MAXN];
int m;

void dfs(int v, int p) {
  static int timer = 0;
  tin[v] = timer++;
  for (int u : g[v])
    if (u != p)
      dfs(u, v);
  tout[v] = timer - 1;
}

void rotate_one(int v, int rot) {
  rot %= m;
  shift[v] += rot;
  shift[v] %= m;
  tree[v] = ((tree[v] >> (m - rot)) | (tree[v] << rot)) & all;
}

void push(int v) {
  if (shift[v]) {
    rotate_one(2*v, shift[v]);
    rotate_one(2*v + 1, shift[v]);
    shift[v] = 0;
  }
}

void rotate(int v, int l, int r, int L, int R, int x) {
  if (r < L || R < l) return;
  if (L <= l && r <= R) {
    rotate_one(v, x);
    return;
  }
  push(v);
  rotate(2*v, l, (l+r)/2, L, R, x);
  rotate(2*v + 1, (l+r)/2+1, r, L, R, x);
  tree[v] = tree[2*v] | tree[2*v+1];
}

mask_t get(int v, int l, int r, int L, int R) {
  if (r < L || R < l) return mask_t();
  if (L <= l && r <= R) {
    return tree[v];
  }
  push(v);
  return get(2*v, l, (l+r)/2, L, R) | get(2*v + 1, (l+r)/2+1, r, L, R);
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n;
  scanf("%d%d",&n,&m);

  for (int i = 0; i < m; i++) {
    all[i] = 1;
    bool ok = i >= 2;
    for (int j = 2; j * j  <= i; j++)
      ok &= i % j != 0;
    if (ok) {
      primes[i] = 1;
    }
  }

  vector<int> start(n);

  for (int i = 0; i < n; i++)
    scanf("%d", &start[i]);

  for (int i = 1; i < n; i++) {
    int a, b;
    scanf("%d%d",&a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0, -1);

  lst = 2;
  while (lst < n) lst *= 2;

  for (int i = 0; i < n; i++) {
    tree[lst + tin[i]][start[i] % m] = 1;
  }

  for (int i = lst - 1; i > 0; i--)
    tree[i] = tree[2*i] | tree[2*i+1];



  int q;
  scanf("%d", &q);
  for (int i = 0; i < q; i++) {
    int t, v;
    scanf("%d%d", &t, &v);
    v--;
    if (t == 1) {
      int x;
      scanf("%d", &x);
      x %= m;
      rotate(1, 0, lst - 1, tin[v], tout[v], x);
    } else {
      mask_t res = get(1, 0, lst - 1, tin[v], tout[v]);
      /*for (int x = 0; x < m; x++)
        eprintf("%d", (int)res[x]);
      eprintf("\n");*/
      printf("%d\n", (int) (res & primes).count());
    }
  }

      
  return 0;
}