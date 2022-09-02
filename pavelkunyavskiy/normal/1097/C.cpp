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

const int MAXL = 510000;

char buf[MAXL];

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<int> pos(MAXL);
    vector<int> neg(MAXL);
    for (int i = 0; i < n; i++) {
      scanf("%s", buf);
      int bal = 0;
      int min_bal = 0;
      for (int j = 0; buf[j]; j++) {
        char c = buf[j];
        if (c == '(') {
          bal++;
        } else {
          bal--;
        }
        min_bal = min(bal, min_bal);
      }
      if (bal >= 0) {
        if (min_bal >= 0) {
          pos[bal]++;
        }
      } else {
        if (min_bal >= bal) {
          neg[-bal]++;
        }
      }
    }

    int ans = pos[0] / 2;
    for (int i = 1; i < MAXL; i++) {
      ans += min(pos[i], neg[i]);
    }
    printf("%d\n", ans);
  }

  return 0;
}