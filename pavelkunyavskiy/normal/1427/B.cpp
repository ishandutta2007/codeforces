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

char s[200'000];

void solve() {
  int n, k;
  scanf("%d%d%s", &n, &k, s);
  int len = numeric_limits<int>::min();
  int score = 0;
  vector<int> adds;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'W') {
      score++;
      if (i && s[i - 1] == 'W') {
        score++;
      }
      if (len > 0) {
        adds.push_back(len);
      }
      len = 0;
    } else {
      len++;
    }
  }
  if (score == 0) {
    score = max(0, 2 * k - 1);
  } else {
    score += 2 * k;
    sort(adds.begin(), adds.end());
    for (int i = 0; i < (int) adds.size() && adds[i] <= k; i++) {
      k -= adds[i];
      score++;
    }

    score = min(score, 2 * n - 1);
  }
  printf("%d\n", score);
}

int main() {
#ifdef LOCAL
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int t;
  scanf("%d", &t);
  while (t-->0) {
    solve();
  }

  return 0;
}