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
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

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

const int MAXC = 10000001;
const int MAXN = 100001;
const int MAXLOG = 18;

int mind[MAXC + 1];
vector<int> primes;

void gen_primes(int n) {
  mind[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (mind[i] == 0) {
      mind[i] = i;
      primes.push_back(i);
    }
    for (int j : primes) {
      if (j > mind[i] || i * j > n) break;
      mind[i * j] = j;
    }
  }
}

vector<int> divisors(int x) {
  int lp, lp2;
  lp = 1, lp2 = 1;
  vector<int> ans;
  while (x != 1) {
    if (mind[x] != lp) {
      lp = mind[x];
      lp2 = 1;
    }
    lp2 *= lp;
    ans.push_back(lp2);
    x /= lp;
  }
  return ans;
}

struct query {
  int d;
  int qid;
  int ty;
};


int up[MAXLOG][MAXN];
int h[MAXN];
vector<vector<int>> g;
vector<vector<query>> qs;
vector<int> a;

void dfs(int v, int p) {
  up[0][v] = p;
  h[v] = h[p] + 1;
  for (int u : g[v]) {
    if (u != p) {
      dfs(u, v);
    }
  }
}

int lca(int u, int v) {
  if (h[u] < h[v]) swap(u, v);
  for (int i = MAXLOG - 1; i >= 0; i--) {
    if (h[up[i][u]] >= h[v]) {
      u = up[i][u];
    }
  }
  if (u == v) return u;
  for (int i = MAXLOG - 1; i >= 0; i--) {
    if (up[i][u] != up[i][v]) {
      u = up[i][u];
      v = up[i][v];
    }
  }
  return up[0][v];
}

const int MOD = 1000000007;

void add(int &a, int b) {
  if ((a += b) >= MOD) a -= MOD;
}

void sub(int &a, int b) {
  if ((a -= b) < 0) a += MOD;
}

int mul(int a, int b) {
  return (int) ((a * 1LL * b) % MOD);
}

int mpow(int a, int b) {
  int res = 1;
  while (b) {
    if (b & 1) res = mul(res, a);
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}


int invv[MAXC];

int cur[MAXC];
int icur[MAXC];
vector<int> ans;

void dfs_solve(int v, int p) {
  for (auto q : qs[v]) {
    if (q.ty == -1) {
      ans[q.qid] = mul(ans[q.qid], icur[q.d]);
    }
  }
  vector<int> d = divisors(a[v]);
  for (int x : d) {
    cur[x] = mul(cur[x], mind[x]);
    icur[x] = mul(icur[x], invv[mind[x]]);
  }
  for (auto q : qs[v]) {
    if (q.ty == 1) {
      ans[q.qid] = mul(ans[q.qid], cur[q.d]);
    } else if (q.ty == -1) {
      ans[q.qid] = mul(ans[q.qid], icur[q.d]);
    }
  }

  for (int u : g[v]) {
    if (u != p) {
      dfs_solve(u, v);
    }
  }
  for (int x : d) {
    cur[x] = mul(cur[x], invv[mind[x]]);
    icur[x] = mul(icur[x], mind[x]);
  }
}

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  gen_primes(MAXC);
  invv[1] = 1;
  for (int i = 2; i < MAXC; i++) {
    invv[i] = mul(MOD - invv[MOD % i], MOD / i);
    assert(mul(i, invv[i]) == 1);
  }


  int n;
  while (scanf("%d", &n) == 1) {
    g = vector<vector<int>>(n);
    for (int i = 0; i < n - 1; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      --u, --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    dfs(0, 0);

    for (int i = 1; i < MAXLOG; i++) {
      for (int j = 0; j < n; j++) {
        up[i][j] = up[i - 1][up[i - 1][j]];
      }
    }

    qs = vector<vector<query>>(n);
    a = vector<int>(n);
    for (int i = 0; i < n; i++) {
      scanf("%d", &a[i]);
    }


    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
      int u, v, x;
      scanf("%d%d%d", &u, &v, &x);
      --u, --v;
      int c = lca(u, v);
      vector<int> divs = divisors(x);
      for (int d : divs) {
        qs[u].push_back({d, i, 1});
        qs[v].push_back({d, i, 1});
        qs[c].push_back({d, i, -1});
      }
    }

    ans = vector<int>(q, 1);
    for (int i = 0; i < MAXC; i++) {
      cur[i] = icur[i] = 1;
    }

    dfs_solve(0, 0);

    for (int i = 0; i < q; i++) {
      printf("%d\n", ans[i]);
    }
  }

  return 0;
}