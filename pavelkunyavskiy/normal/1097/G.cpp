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

int minv(int x) {
  return mpow(x, MOD - 2);
}

const int MAXN = 110000;
const int MAXK = 200;

vector<int> g[MAXN];
int sz[MAXN];

void dfs_size(int v) {
  sz[v] = 1;
  for (int u : g[v]) {
    g[u].erase(find(g[u].begin(), g[u].end(), v));
    dfs_size(u);
    sz[v] += sz[u];
  }
}

int dp1[MAXN][MAXK + 1];
int dp2[MAXN][MAXK + 1];
int p2[MAXN];
int p2c[MAXN];
int k;

void dfs_dp(int v) {
  dp2[v][0] = 1;
  int csz = 1;
  for (int u : g[v]) {
    dfs_dp(u);
    for (int i = k; i > 0; i--) {
      add(dp2[u][i], mul(dp2[u][i - 1], (i == 1) ? p2c[sz[u]] : 1));
    }
    for (int i = min(csz - 1, k); i >= 0; i--) {
      for (int j = min(sz[u], k - i); j > 0; j--) {
        add(dp2[v][i + j], mul(dp2[v][i], dp2[u][j]));
      }
    }
    csz += sz[u];
  }

  for (int i = 1; i <= k; i++) {
    dp1[v][i] = dp2[v][i];
  }

  for (int u : g[v]) {
    for (int i = 1; i <= k; i++) {
      sub(dp1[v][i], dp2[u][i]);
    }
    for (int i = 1; i <= k; i++) {
      sub(dp2[u][i], mul(dp2[u][i - 1], (i == 1) ? p2c[sz[u]] : 1));
    }
  }

}

int cnk[MAXK + 1][MAXK + 1];
int choose[MAXK + 1][MAXK + 1];

int main() {
#ifdef LOCAL
  freopen("g.in", "r", stdin);
  freopen("g.out", "w", stdout);
#endif

  int n;
  scanf("%d%d", &n, &k);

  p2[0] = 1;
  for (int i = 1; i <= n; i++) {
    p2[i] = mul(p2[i - 1], 2);
  }
  for (int i = 0; i <= n; i++) {
    p2c[i] = mul(p2[i] - 1, minv(p2[i]));
  }
  for (int i = 0; i < n - 1; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs_size(0);
  dfs_dp(0);

//  for (int i = 0; i < n; i++) {
//    for (int j = 0; j <= k; j++) {
//      eprintf("%d ", dp1[i][j]);
//    }
//    eprintf("\n");
//  }

//  eprintf("===\n");
//  for (int i = 0; i < n; i++) {
//    for (int j = 0; j <= k; j++) {
//      eprintf("%d ", dp2[i][j]);
//    }
//    eprintf("\n");
//  }
//  eprintf("===\n");

  cnk[0][0] = 1;
  for (int i = 0; i <= MAXK; i++) {
    for (int j = 0; j <= MAXK; j++) {
      if (i) add(cnk[i][j], cnk[i - 1][j]);
      if (i && j) add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }

  choose[0][0] = 1;
  for (int i = 1; i <= MAXK; i++) {
    for (int j = 1; j <= MAXK; j++) {
      for (int t = 1; t <= i; t++) {
        add(choose[i][j], mul(choose[i - t][j - 1], cnk[i][t]));
      }
    }
  }


  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j <= k; j++) {
      if (i != 0 && j != k) {
        int cnt = dp2[i][j];
        cnt = mul(p2c[n - sz[i]], cnt);
        int es = j + 1;
        if (es == 1) {
          cnt = mul(cnt, p2c[sz[i]]);
        }
        cnt = mul(cnt, p2[n]);
//        if (cnt) eprintf("1. i = %d, j = %d, cnt = %d, c = %d\n", i, j, cnt, choose[k][es]);
        add(ans, mul(choose[k][es], cnt));
      }
      int cnt = dp1[i][j];
      int es = j;
      cnt = mul(cnt, p2[n]);
//      if (cnt) eprintf("2. i = %d, j = %d, cnt = %d\n", i, j, cnt);
      add(ans, mul(choose[k][es], cnt));
    }
  }

  printf("%d\n", ans);


  return 0;
}