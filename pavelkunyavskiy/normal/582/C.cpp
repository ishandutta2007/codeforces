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

#define TASKNAME "C"

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

vector<int> divs;

vector<vector<int>> gcds;

vector<int> a;

int main() {
  #ifdef LOCAL
  assert(freopen (TASKNAME".in", "r", stdin));
  assert(freopen (TASKNAME".out", "w", stdout));
  #endif

  int n;
  scanf ("%d", &n);
  a.resize(n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  for (int i = 1; i < n; i++) {
    if (n % i == 0) {
      divs.push_back (i);
    }
  }

  gcds.resize (divs.size ());

  for (int i = 1; i < n; i++) {
    int g = __gcd (i, n);
    int id = lower_bound (divs.begin (), divs.end (), g) - divs.begin ();
    gcds[id].push_back (i);
  }

  long long ans = 0;

  for (int it = 0; it < (int)divs.size (); it++) {
    int d = divs[it];
    vector<int> ok(n);

    for (int i = 0; i < d; i++) {
      int mv = a[i];
      for (int j = i; j < n; j += d) {
        mv = max (mv, a[j]);
      }
      for (int j = i; j < n; j += d) {
        if (a[j] == mv) {
          ok[j] = 1;
        }
      }
    }

    int start = find(ok.begin(), ok.end(), 0) - ok.begin();
    if (start == n) {
      eprintf("any with gcd = %d is ok (+%lld)\n", d, gcds[it].size() * 1LL * n);
      ans += gcds[it].size() * 1LL * n;
      continue;
    }
    rotate(ok.begin(), ok.begin() + start + 1, ok.end());

    assert(ok.back() == 0);

    for (int i = 0; i < n; ) {
      int j = i;
      while (j < n && ok[j] == 1) j++;
      int len = j - i;
      i = j + 1;
      for (int g : gcds[it]) {
        if (g > len) {
          break;
        }
        eprintf("seg of len %d for g = %d (+%d)\n", len, g, len + g - 1);
        ans += len - g + 1;
      }
    }
  }

  printf("%lld\n", ans);
  return 0;
}