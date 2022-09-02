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

int solve_one(vector<pair<int, int>> a, int c) {
  int ans = 0;
  for (auto x : a) {
    if (x.first <= c) {
      ans = max(ans, x.second);
    }
  }
  return ans;
}

int solve_two(vector<pair<int, int>> a, int c) {
  int max1 = -1, max2 = -1;
  int ptr = 0;
  int ans = -1;
  for (int i = (int)a.size() - 1; i >= 0; i--) {
    while (ptr < (int)a.size() && a[ptr].first + a[i].first <= c) {
      int t = a[ptr].second;
      if (max1 < t || max1 == -1) {
        swap(max1, t);
      }
      if (max2 < t || max2 == -1) {
        swap(max2, t);
      }
      ptr++;
    }
    int other;
    if (i < ptr && max1 == a[i].second) {
      other = max2;
    } else {
      other = max1;
    }

    if (other != -1) {
      ans = max(ans, a[i].second + other);
    }
  }
  return ans;
}


int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n, c, d;
  while (scanf("%d%d%d", &n, &c, &d) == 3) {
    vector<pair<int, int>> a, b;

    for (int i = 0; i < n; i++) {
      int x, y;
      char t;
      scanf("%d%d %c", &x, &y, &t);
      if (t == 'C') {
        a.push_back({y, x});
      } else {
        b.push_back({y, x});
      }
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 0;
    ans = max(ans, solve_two(a, c));
    ans = max(ans, solve_two(b, d));
    if (!a.empty() && a[0].first <= c && !b.empty() && b[0].first <= d) {
      ans = max(ans, solve_one(a, c) + solve_one(b, d));
    }

    printf("%d\n", ans);
  }

  return 0;
}