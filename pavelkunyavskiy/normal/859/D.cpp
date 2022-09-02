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

double p[100][100];

vector<pair<double, double>> solve(int l, int r) {
  if (l == r - 1) return {{0.0, 1.0}};

  int m = (l + r) / 2;
  auto lf = solve(l, m);
  auto rg = solve(m, r);

  vector<pair<double, double>> v (r - l);

  for (int i = l; i < m; i++) {
    for (int j = m; j < r; j++) {
      v[i - l].second += lf[i - l].second * rg[j - m].second * p[i][j];
      v[j - l].second += lf[i - l].second * rg[j - m].second * p[j][i];
    }
  }

  for (int i = l; i < m; i++) {
    v[i - l].first = lf[i - l].first + v[i - l].second * (r - l) / 2.0 + max_element(rg.begin(), rg.end())->first;
  }
  for (int i = m; i < r; i++) {
    v[i - l].first = rg[i - m].first + v[i - l].second * (r - l) / 2.0 + max_element(lf.begin(), lf.end())->first;
  }
  return v;
}

int main() {
#ifdef LOCAL
  freopen("d.in", "r", stdin);
  freopen("d.out", "w", stdout);
#endif

  int n;
  while (scanf("%d", &n) == 1) {
    n = 1 << n;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int x;
        scanf("%d", &x);
        p[i][j] = x / 100.0;
      }
    }
    auto res = solve(0, n);
    printf("%.18lf\n", max_element(res.begin(), res.end())->first);
  }


  return 0;
}