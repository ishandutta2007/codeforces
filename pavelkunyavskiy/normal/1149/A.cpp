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

const int MAXN = 410000;

int mind[MAXN];
int is_prime[MAXN];
vector<int> primes;

void gen_primes(int n) {
  mind[1] = 1;
  for (int i = 2; i <= n; i++) {
    if (mind[i] == 0) {
      mind[i] = i;
      primes.push_back(i);
      is_prime[i] = true;
    }
    for (int j : primes) {
      if (j > mind[i] || i * j > n) break;
      mind[i * j] = j;
    }
  }
}


int main() {
#ifdef LOCAL
  freopen("a.in", "r", stdin);
  freopen("a.out", "w", stdout);
#endif



  int n;
  while (scanf("%d", &n) == 1) {
    int cnt[2];
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      int x;
      scanf("%d", &x);
      cnt[x - 1]++;
    }

    int tot = cnt[0] + 2 * cnt[1];
    int skip = cnt[1];
    vector<bool> use(tot + 1, true);
    if (skip) {
      use[1] = false;
      skip--;
    }
    for (int i = 0; i < skip; i++) {
      use[(cnt[0] == 0 ? 3 : 4) + 2 * i] = false;
    }
    for (int i = 1; i <= tot; i++) {
      if (use[i]) {
        if (i == 1 || use[i-1]) {
          printf("1 ");
        } else {
          printf("2 ");
        }
      }
    }
    printf("\n");
  }

  return 0;
}