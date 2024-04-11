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

const int MAXN = 710;

int deg[11][MAXN];
int ones[MAXN];

int cnt[MAXN];
char s[MAXN];

int cnk[MAXN][MAXN];
int innerval[MAXN][10];

int inner(int maxk2, int d) {
  int s = 0;
  for (int k2 = 0; k2 <= maxk2; k2++) {
    int val = cnk[maxk2][k2];
    val = mul(val, deg[10][k2]);
    val = mul(val, deg[9 - d][k2]);
    val = mul(val, deg[d][maxk2 - k2]);
    add(s, val);
  }
  return s;
}

int solve(int p) {
  int ans = 0;
  int c2 = 0;
  for (int d = 9; d >= 0; d--) {
    int c1 = cnt[d];
    for (int k1 = 0; k1 <= p; k1++) {
      int coef = mul(mul(d, cnk[p][k1]), ones[k1 + c1]);

      int maxk2 = p - k1;
      int s = innerval[maxk2][d];
      s = mul(s, deg[10][c2]);
      add(ans, mul(coef, s));
    }
    c2 += c1;
  }
  return ans;
}

int main() {
#ifdef LOCAL
  freopen("g.in", "r", stdin);
  freopen("g.out", "w", stdout);
#endif

  cnk[0][0] = 1;
  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < MAXN; j++) {
      if (i) add(cnk[i][j], cnk[i - 1][j]);
      if (i && j) add(cnk[i][j], cnk[i - 1][j - 1]);
    }
  }


  for (int i = 0; i <= 10; i++) {
    deg[i][0] = 1;
    for (int j = 1; j < MAXN; j++) {
      deg[i][j] = mul(deg[i][j - 1], i);
    }
  }

  ones[0] = 0;
  for (int i = 1; i < MAXN; i++) {
    ones[i] = mul(ones[i - 1], 10);
    add(ones[i], 1);
  }

  for (int i = 0; i < MAXN; i++) {
    for (int j = 0; j < 10; j++) {
      innerval[i][j] = inner(i, j);
    }
  }

  scanf("%s", s);
  int l = strlen(s);

  int ans = 0;

  for (int i = 0; s[i]; i++) {
    cnt[0]++;
    for (int j = 0; j < s[i] - '0'; j++) {
      add(ans, solve(l - i - 1));
      cnt[j]--;
      cnt[j + 1]++;
    }
  }
  add(ans, solve(0));
  printf("%d\n", ans);
  return 0;
}