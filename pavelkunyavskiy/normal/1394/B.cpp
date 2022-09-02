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
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n, m, k;
  while (scanf("%d%d%d", &n, &m, &k) == 3) {
    vector<vector<pair<int, int>>> g(n);
    vector<vector<pair<int, int>>> rg(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      scanf("%d%d%d", &a, &b, &c);
      g[a - 1].emplace_back(c, b - 1);
    }
    for (auto &l : g) {
      sort(l.begin(), l.end());
      for (int i = 0; i < (int)l.size(); i++) {
        rg[l[i].second].emplace_back(l.size() - 1, i);
      }
    }

    vector<vector<vector<vector<bool>>>> bad(k, vector<vector<vector<bool>>>(k, vector<vector<bool>>(k, vector<bool>(k, false))));

    for (auto &l : rg) {
      sort(l.begin(), l.end());
      int pt = 0;
      for (int i = 0; i < (int)l.size(); i++) {
        if (pt < 2 || l[i] != l[pt - 2]) {
          l[pt++] = l[i];
        }
      }
      l.resize(pt);
      for (int i = 0; i < (int)l.size(); i++) {
        for (int j = i + 1; j < (int)l.size(); j++) {
          bad[l[i].first][l[i].second][l[j].first][l[j].second] = true;
          bad[l[j].first][l[j].second][l[i].first][l[i].second] = true;
        }
      }
    }

    vector<int> p(k);
    ll ans = 0;
    std::function<void(int)> go = [&](int pos) {
      if (pos == k) {
//        for (int x : p) eprintf("%d ", x);
//        eprintf("\n");
        ans++;
        return;
      }
      for (int i = 0; i <= pos; i++) {
        p[pos] = i;
        bool ok = true;
        for (int j = 0; j <= pos; j++) {
          if (bad[j][p[j]][pos][i]) {
            ok = false;
            break;
          }
        }
        if (!ok) continue;
        go(pos + 1);
      }
    };

    go(0);
    printf("%lld\n", ans);

  }

  return 0;
}