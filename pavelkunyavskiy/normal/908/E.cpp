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
#include <numeric>

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


const int MAXN = 1010;

int dp[MAXN][MAXN];
int dp2[MAXN];
char buf[MAXN];

int main() {
#ifdef LOCAL
  freopen("e.in", "r", stdin);
  freopen("e.out", "w", stdout);
#endif

  int m, n;
  scanf("%d%d", &m, &n);

  dp[0][0] = dp2[0] = 1;
  for (int i = 1; i <= m; i++) {
    for (int j = 0; j <= i; j++) {
      if (j) {
        add(dp[i][j], dp[i - 1][j - 1]);
      }
      add(dp[i][j], mul(dp[i - 1][j], j));
      add(dp2[i], dp[i][j]);
    }
  }

  vector<vector<int>> s(2 * n);
  for (int i = 0; i < n; i++) {
    scanf("%s", buf);
    for (int j = 0; j < m; j++) {
      s[i].push_back(buf[j] - '0');
      s[i + n].push_back((buf[j] - '0') ^ 1);
    }
  }

  vector<vector<int>> v;
  for (int j = 0; j < m; j++) {
    vector<int> res(m, 1);
    for (const vector<int> &x : s) {
      if (x[j] != 1) continue;
      for (int k = 0; k < m; k++) {
        res[k] &= x[k];
      }
    }
    v.push_back(res);
  }
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());

  int ans = 1;
  for (const vector<int> &x : v) {
    int cnt = accumulate(x.begin(), x.end(), 0);
    eprintf("cnt = %d, dp2 = %d\n", cnt, dp2[cnt]);
    ans = mul(ans, dp2[cnt]);
  }
  printf("%d\n", ans);
  return 0;
}