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

#define TASKNAME "D"

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

const int MAXK = 150;
const int INF = (int)1.1e9;
vector<int> dp[MAXK];
int a[MAXK];

int main() {
  #ifdef LOCAL
    assert(freopen (TASKNAME".in", "r", stdin));
    assert(freopen (TASKNAME".out", "w", stdout));
  #endif

  int n, k, s;
  scanf ("%d%d%d", &n, &k, &s);

  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  {
    vector<int> ord (n);
    for (int i = 0; i < n; i++)
      ord[i] = i;
    sort (ord.begin (), ord.end (), [](int x, int y) {
      return a[x] < a[y];
    });
    sort(ord.begin(), ord.begin() + k);
    int need = 0;
    for (int i = 0; i < k; i++) {
      need += ord[i] - i;
    }
    if (need <= s) {
      eprintf("%d is enough (need = %d)\n", s, need);
      int ans = 0;
      for (int i = 0; i < k; i++)
        ans += a[ord[i]];
      printf("%d\n", ans);
      return 0;
    }
  }


  for (int i = 0; i <= k; i++) {
    dp[i] = vector<int>(s + 1, INF);
  }
  dp[0][0] = 0;

  for (int i = 0; i < n; i++) {
    for (int j = min(i, k - 1); j >= 0; j--) {
      for (int c = 0; c + i - j <= s; c++) {
        dp[j + 1][c + i - j] = min(dp[j + 1][c + i - j], dp[j][c] + a[i]);
      }
    }
  }

  int ans = INF;
  for (int i = 0; i <= s; i++)
    ans = min(ans, dp[k][i]);

  printf("%d\n", ans);
  return 0;
}