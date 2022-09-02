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

bool check(vector<int> a, vector<int> b, int m, int L) {
  int n = a.size();
  for (int & x : a) {
    x -= m;
    if (x < 0) x += L;
  }
  rotate(a.begin(), min_element(a.begin(), a.end()), a.end());
  for (int i = 0; i < n; i++) {
    b.push_back(b[i] + L);
  }

  int max_from, min_to;
  max_from = 0;
  min_to = b.size();

  for (int i = 0; i < (int)a.size(); i++) {
    int from = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
    int to = upper_bound(b.begin(), b.end(), a[i] + 2 * m) - b.begin();
    from -= i;
    to -= i;
    from = max(from, 0);
    to = max(to, 0);
    max_from = max(from, max_from);
    min_to = min(to, min_to);
  }
  return max_from < min_to;
}

int main() {
#ifdef LOCAL
  freopen("f.in", "r", stdin);
  freopen("f.out", "w", stdout);
#endif

  int n, L;
  while (scanf("%d%d", &n, &L) == 2) {
    vector<int> a(n);
    vector<int> b(n);
    for (int &x : a) scanf("%d", &x);
    for (int &x : b) scanf("%d", &x);

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int lf = -1;
    int rg = L / 2;

    while (rg - lf > 1) {
      int m = (lf + rg) / 2;
      if (check(a, b, m, L)) {
        rg = m;
      } else {
        lf = m;
      }
    }
    printf("%d\n", rg);
  }

  return 0;
}