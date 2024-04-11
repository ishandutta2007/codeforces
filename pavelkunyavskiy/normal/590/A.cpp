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

#define TASKNAME "A"

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

const int MAXN = 510000;
int a[MAXN];

int main() {
  #ifdef LOCAL
  assert(freopen (TASKNAME
           ".in", "r", stdin));
  assert(freopen (TASKNAME
           ".out", "w", stdout));
  #endif

  int n;
  scanf ("%d", &n);
  for (int i = 0; i < n; i++)
    scanf ("%d", &a[i]);
  vector<int> lens;
  for (int i = 0; i < n;) {
    int j = i;
    while (j < n && a[i] == a[j])
      j++;
    lens.push_back (j - i);
    i = j;
  }
  lens[0]++;
  lens.back ()++;

  int iters = 0;
  vector<int> nlens;

  for (int i = 0; i < (int)lens.size(); ) {
    if (lens[i] > 1) {
      nlens.push_back (lens[i]);
      i++;
      continue;
    }
    int j = i;
    while (j < (int)lens.size() && lens[j] == 1)
      j++;
    int cnt = j - i;
    if (cnt % 2 == 1) {
      assert(nlens.size());
      assert(j < (int)lens.size());
      nlens.back() += cnt;
      nlens.back() += lens[j];
      iters = max(iters, (cnt + 1) / 2);
      i = j + 1;
      continue;
    } else {
      assert(nlens.size());
      assert(j < (int)lens.size());
      nlens.back() += cnt / 2;
      iters = max(iters, cnt / 2);
      nlens.push_back(cnt / 2);
      nlens.back() += lens[j];
      i = j + 1;
      continue;
    }
  }

  lens = nlens;

  lens[0]--;
  lens.back ()--;

  printf("%d\n", iters);
  int cur = a[0];
  for (int l : lens) {
    for (int i = 0; i < l; i++)
      printf ("%d ", cur);
    cur ^= 1;
  }
  printf("\n");
  return 0;
}