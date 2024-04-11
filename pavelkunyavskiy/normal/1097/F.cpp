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

const int MAXK = 7000;
const int MAXN = 100010;

bitset<MAXK> a[MAXN];

bitset<MAXK> divs[MAXK + 1];
bitset<MAXK> rdivs[MAXK + 1];
bool sqfree[MAXK + 1];

int main() {
#ifdef LOCAL
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#endif

  int n, q;
  scanf("%d%d", &n, &q);

  for (int i = 0; i <= MAXK; i++) {
    sqfree[i] = true;
    for (int j = 2; j * j <= i; j++) {
      if (i % (j * j) == 0) {
        sqfree[i] = false;
      }
    }
  }



  for (int i = 1; i <= MAXK; i++) {
    for (int j = i; j <= MAXK; j += i) {
      divs[j].set(i - 1);
      if (sqfree[j / i]) {
        rdivs[i].set(j - 1);
      }
    }
  }

  string ans = "";

  for (int i = 0; i < q; i++) {
    int ty;
    scanf("%d", &ty);
    if (ty == 1) {
      int x, v;
      scanf("%d%d", &x, &v);
      a[x - 1] = divs[v];
    } else if (ty == 2) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      a[x - 1] = a[y - 1] ^ a[z - 1];
    } else if (ty == 3) {
      int x, y, z;
      scanf("%d%d%d", &x, &y, &z);
      a[x - 1] = a[y - 1] & a[z - 1];
    } else if (ty == 4) {
      int x, v;
      scanf("%d%d", &x, &v);
      ans += '0' + ((a[x - 1] & rdivs[v]).count() % 2);
    }
  }

  printf("%s\n", ans.c_str());

  return 0;
}