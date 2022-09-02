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

#define TASKNAME "E"

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

const int MAXN = 5100;
const int MAXH = 100;

int solved[3];
int hackable[3];

int can[5100];
int subm_time[5100][3];

int get_cost(int k, int n) {
  if (n < 2 * k && 2 * k <= 2 * n) return 2;
  if (n < 4 * k && 4 * k <= 2 * n) return 4;
  if (n < 8 * k && 8 * k <= 2 * n) return 6;
  if (n < 16 * k && 16 * k <= 2 * n) return 8;
  if (n < 32 * k && 32 * k <= 2 * n) return 10;
  return 12;
}

vector<int> get_possible(int solved, int hackable, int n) {
  vector<int> possible;
  for (int i = 0; i <= hackable; i++) {
    if (i == hackable || get_cost(solved - i, n) != get_cost(solved - i - 1, n)) {
      possible.push_back(i);
    }
  }
  return possible;
}

int get_score(int* s, int id, int mask) {
  return (s[0] * (250 - subm_time[id][0]) * ((mask & 1) == 1)) +
         (s[1] * (250 - subm_time[id][1]) * ((mask & 2) == 2)) +
         (s[2] * (250 - subm_time[id][2]) * ((mask & 4) == 4));
}

int dp[MAXH + 2][MAXH + 2][MAXH + 2];

int main() {
#ifdef LOCAL
  assert(freopen(TASKNAME".in", "r", stdin));
  assert(freopen(TASKNAME".out", "w", stdout));
#endif

  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 3; j++) {
      int a;
      scanf("%d", &a);
      if (a < 0) {
        can[i] |= (1 << j);
        hackable[j] ++;
      }
      if (a == 0) {
        subm_time[i][j] = 250;
      } else {
        subm_time[i][j] = abs(a);
        solved[j]++;
      }
    }
  }

  if (hackable[0] + hackable[1] + hackable[2] > MAXH) {
    printf("1\n");
    return 0;
  }

  vector<int> possible[3];
  for (int i = 0; i < 3; i++) {
    possible[i] = get_possible(solved[i], hackable[i], n);
  }

  int ans = n;

  for (int h0 : possible[0])
    for (int h1 : possible[1])
      for (int h2 : possible[2]) {
        int s[3] = {get_cost(solved[0] - h0, n), get_cost(solved[1] - h1, n), get_cost(solved[2] - h2, n)};
        int my_score = get_score(s, 0, 7) + 100 * (h0 + h1 + h2);
        memset(dp, 1, sizeof(dp));
        dp[0][0][0] = 0;

        int global_add = 1;

        for (int i = 1; i < n; i++) {
          if (can[i] == 0) {
            int his_score = get_score(s, i, 7);
            if (his_score > my_score) global_add++;
            continue;
          }
          for (int d0 = h0; d0 >= 0; d0--)
            for (int d1 = h1; d1 >= 0; d1--)
              for (int d2 = h2; d2 >= 0; d2--) {
                for (int j = can[i]; ; j = (j - 1) & can[i]) {
                  int his_score = get_score(s, i, 7 ^ j);
                  int add = 0;
                  if (his_score > my_score) add = 1;
                  if (j) {
                    int nd0 = d0 + ((j & 1) == 1);
                    int nd1 = d1 + ((j & 2) == 2);
                    int nd2 = d2 + ((j & 4) == 4);
                    dp[nd0][nd1][nd2] = min(dp[nd0][nd1][nd2], dp[d0][d1][d2] + add);
                  } else {
                    dp[d0][d1][d2] += add;
                    break;
                  }
                }
              }
        }
        ans = min(ans, dp[h0][h1][h2] + global_add);
      }

  printf("%d\n", ans);

  return 0;
}