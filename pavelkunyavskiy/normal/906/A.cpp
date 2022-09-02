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

static const int ALPH = 26;
char buf[200000];

int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    vector<bool> can(ALPH, true);
    bool known = false;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      char c;
      scanf(" %c", &c);
      if (c == '.') {
        scanf("%s", buf);
        for (int j = 0; buf[j]; j++) {
          can[buf[j] - 'a'] = false;
        }
      } else if (c == '!') {
        if (known) ans++;
        scanf("%s", buf);
        vector<bool> ncan(ALPH, false);
        for (int j = 0; buf[j]; j++) {
          ncan[buf[j] - 'a'] = true;
        }
        for (int j = 0; j < ALPH; j++) {
          can[j] = can[j] && ncan[j];
        }
      } else if (c == '?') {
        if (known && i != n - 1) ans++;
        char cc;
        scanf(" %c", &cc);
        can[cc - 'a'] = false;
      }
      int cnt = 0;
      for (int j = 0; j < ALPH; j++) {
        cnt += can[j];
      }
      known = cnt == 1;
    }

    printf("%d\n", ans);
  }

  return 0;
}