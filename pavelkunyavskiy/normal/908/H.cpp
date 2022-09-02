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


char s[100][100];

vector<int> comp;
int n;

int dfs(int v, int c) {
  comp[v] = c;
  int r = 1;
  for (int i = 0; i < n; i++) {
    if (s[v][i] == 'A' && comp[i] == -1) {
      r += dfs(i, c);
    }
  }
  return r;
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


void t1(vector<int> &a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) {
        add(a[j], a[j ^ (1 << i)]);
      }
    }
  }
}

void t2(vector<int> &a, int n) {
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (1 << n); j++) {
      if (j & (1 << i)) {
        sub(a[j], a[j ^ (1 << i)]);
      }
    }
  }
}


int solve(vector<int> g) {
  int n = (int)g.size();
  vector<int> indep(1 << n);
  for (int i = 0; i < (1 << n); i++) {
    indep[i] = 1;
    for (int j = 0; j < n; j++) {
      if ((i & (1 << j)) && (g[j] & i)) {
        indep[i] = 0;
      }
    }
  }
  vector<int> cur(1 << n);
  cur[0] = 1;
  t1(indep, n);
  t1(cur, n);

  vector<int> mu(1 << n);
  mu[0] = 1;
  for (int i = 1; i < (1 << n); i++) {
    mu[i] = MOD - mu[i & (i - 1)];
  }

  for (int i = 0; ; i++) {
    int val = 0;
    for (int j = 0; j < (1 << n); j++) {
      add(val, mul(mu[j], cur[j]));
    }
    if (val) {
      return i;
    }
    for (int j = 0; j < (1 << n); j++) {
      cur[j] = mul(cur[j], indep[j]);
    }
  }
}

int main() {
#ifdef LOCAL
  freopen("h.in", "r", stdin);
  freopen("h.out", "w", stdout);
#endif

  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%s", s[i]);
  }

  comp.resize(n, -1);
  int cc = 0;

  for (int i = 0; i < n; i++) {
    if (comp[i] == -1) {
      int r = dfs(i, cc++);
      if (r == 1) {
        cc--;
        comp[i] = -2;
      }
    }
  }

  vector<int> g(cc);
  for (int i = 0; i < n; i++) if (comp[i] != -2) {
    for (int j = 0; j < n; j++) if (comp[j] != -2) {
      if (s[i][j] == 'X') {
        if (comp[i] == comp[j]) {
          printf("-1\n");
          return 0;
        }
        g[comp[i]] |= (1 << comp[j]);
        g[comp[j]] |= (1 << comp[i]);
      }
    }
  }

  printf("%d\n", n - 1 + solve(g));

  return 0;
}