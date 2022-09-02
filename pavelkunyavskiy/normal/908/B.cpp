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

const int dx[4] = {0, 1, 0, -1};
const int dy[4] = {1, 0, -1, 0};

char s[200][200];
char c[200];

int main() {
#ifdef LOCAL
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n, m;
  while (scanf("%d%d", &n, &m) == 2) {
    for (int i = 0; i < n; i++) {
      scanf("%s", s[i]);
    }
    scanf("%s", c);

    vector<int> order(4);
    for (int i = 0; i < 4; i++) {
      order[i] = i;
    }
    int ans = 0;
    do {
      int x, y;
      x = y = -1;
      for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
          if (s[i][j] == 'S') {
            x = i;
            y = j;
            break;
          }
        }
      }

      bool bad = true;

      for (int i = 0; c[i]; i++) {
        x += dx[order[c[i] - '0']];
        y += dy[order[c[i] - '0']];
        if (!(0 <= x && x < n)) {
          break;
        }
        if (!(0 <= y && y < m)) {
          break;
        }
        if (s[x][y] == '#') {
          break;
        }
        if (s[x][y] == 'E') {
          bad = false;
          break;
        }
      }
      if (!bad) {
        ans += 1;
//        for (int i = 0; i < 4; i++) {
//          printf("(%d, %d) ", dx[order[i]], dy[order[i]]);
//        }
//        printf("\n");
      }
    } while (next_permutation(order.begin(), order.end()));
    printf("%d\n", ans);
  }

  return 0;
}