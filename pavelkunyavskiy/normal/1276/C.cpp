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

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n;
  scanf("%d", &n);
  map<int, int> cnts_map;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    cnts_map[a]++;
  }
  vector<pair<int, int>> cnts;
  for (auto [val, cnt] : cnts_map) {
    cnts.emplace_back(cnt, val);
  }
  sort(cnts.begin(), cnts.end());

  int p = 0, q = 0;
  int ptr = 0;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    while (ptr < (int)cnts.size() && cnts[ptr].first <= i) {
      sum += cnts[ptr].first;
      ptr++;
    }
    int pp = i;
    int qq = (sum + (cnts.size() - ptr) * i) / i;
    if (qq >= pp && pp * 1LL * qq > p * 1LL * q) {
      p = pp;
      q = qq;
    }
  }

  eprintf("%d %d\n", p, q);
  vector<vector<int>> ans(p, vector<int>(q, -1));
  vector<int> vals;
  for (auto [cnt, val] : cnts) {
    for (int i = 0; i < min(cnt, p); i++) {
      vals.push_back(val);
    }
  }
  assert(p <= q);
  assert((int)vals.size() >= p * q);
  reverse(vals.begin(), vals.end());
  ptr = 0;
  for (int i = 0; i < q; i++) {
    for (int j = 0; j < p; j++) {
      ans[j][(i + j) % q] = vals[ptr++];
    }
  }

  printf("%d\n%d %d\n", p * q, p, q);
  for (int i = 0; i < p; i++) {
    for (int j = 0; j < q; j++) {
      printf("%d%c", ans[i][j], " \n"[j == q - 1]);
    }
  }


  fflush(stdout);
  for (int i = 0; i < p; i++) {
    vector<int> v = ans[i];
    sort(v.begin(), v.end());
    assert(unique(v.begin(), v.end()) == v.end());
  }
  for (int i = 0; i < q; i++) {
    vector<int> v(p);
    for (int j = 0; j < p; j++) {
      v[j] = ans[j][i];
    }
    sort(v.begin(), v.end());
    assert(unique(v.begin(), v.end()) == v.end());
  }

  return 0;
}