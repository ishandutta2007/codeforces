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

const int MOD = 998244353;

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

const int MAXN = 4000;

int f[MAXN];
int invf[MAXN];

vector<int> get_cnt(const vector<bool> &used) {
  int n = used.size();
  vector<int> dp1(n);
  vector<int> dp2(n);
  dp2[0] = 1;
  for (int i = 0; i < n; i++) {
    vector<int> dp3 = dp2;
    if (i && !used[i] && !used[i - 1]) {
      for (int j = 1; j < n; j++) {
        add(dp3[j], dp1[j - 1]);
      }
    }
    dp1 = dp2;
    dp2 = dp3;
  }
  while (!dp2.empty() && !dp2.back()) dp2.pop_back();
  return dp2;
}

int main() {
#ifdef LOCAL
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#endif

  f[0] = invf[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    f[i] = mul(f[i - 1], i);
    invf[i] = minv(f[i]);
  }

  int h, w;
  while (scanf("%d%d", &h, &w) == 2) {
    vector<bool> usedh(h), usedw(w);
    int n;
    scanf("%d", &n);
    for (int i = 0; i < 2 * n; i++) {
      int x1, y1;
      scanf("%d%d", &x1, &y1);
      usedh[x1 - 1] = true;
      usedw[y1 - 1] = true;
    }

    vector<int> cnth = get_cnt(usedh);
    vector<int> cntw = get_cnt(usedw);
    int freeh = 0, freew = 0;
    for (int i = 0; i < h; i++) {
      freeh += !usedh[i];
    }
    for (int i = 0; i < w; i++) {
      freew += !usedw[i];
    }

    eprintf("%d %d\n", freeh, freew);

    int ans = 0;

    for (int ch = 0; ch < (int)cnth.size(); ch++) {
      for (int cw = 0; cw < (int)cntw.size() && 2 * ch + cw <= freeh && ch + 2 * cw <= freew; cw++) {
        int cur = mul(cnth[ch], cntw[cw]);
        int otherh = freeh - 2 * ch;
        int otherw = freew - 2 * cw;
        cur = mul(cur, mul(f[otherh], invf[otherh - cw]));
        cur = mul(cur, mul(f[otherw], invf[otherw - ch]));
        eprintf("%d %d %d\n", ch, cw, cur);
        add(ans, cur);
      }
    }

    printf("%d\n", ans);
  }

  return 0;
}