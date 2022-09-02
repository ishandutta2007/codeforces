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

const int MAXN = 110000;

char s[MAXN];
int nxt[MAXN][26];

int main() {
#ifdef LOCAL
  freopen("b.in", "r", stdin);
  freopen("b.out", "w", stdout);
#endif

  int n, q;

  while (scanf("%d%d", &n, &q) == 2) {
    scanf("%s", s);
    fill(begin(nxt[n]), end(nxt[n]), n + 1);
    for (int i = n - 1; i >= 0; i--) {
      memcpy(nxt[i], nxt[i + 1], sizeof(nxt[i]));
      nxt[i][s[i]-'a'] = i + 1;
    }

    vector<pair<int, char>> p[3];
    p[0].emplace_back(-1, 'a');
    p[1].emplace_back(-1, 'a');
    p[2].emplace_back(-1, 'a');

    vector<vector<int>> cur;
    cur.push_back({0, 0, 0});

    for (int i = 0; i < q; i++) {
      char ty;
      int id;
      scanf(" %c%d", &ty, &id);
      --id;
      if (ty == '+') {
        char c;
        scanf(" %c", &c);
        int nid = p[id].size();
        p[id].emplace_back(cur.back()[id], c);
        cur.push_back(cur.back());
        cur.back()[id] = nid;
      } else {
        cur.push_back(cur.back());
        cur.back()[id] = p[id][cur.back()[id]].first;
      }
    }

    vector<vector<vector<int>>> dp(p[0].size(), vector<vector<int>>(p[1].size(), vector<int>(p[2].size(), -1)));

    function<int(int, int, int)> solve = [&](int x, int y, int z) {
      if (x < 0 || y < 0 || z < 0) return n + 1;
      if (!x && !y && !z) return 0;
      int &ans = dp[x][y][z];
      if (ans != -1) return ans;
      ans = n + 1;
      {
        int prevx = solve(p[0][x].first, y, z);
        if (prevx != n + 1) {
          ans = min(ans, nxt[prevx][p[0][x].second - 'a']);
        }
      }
      {
        int prevy = solve(x, p[1][y].first, z);
        if (prevy != n + 1) {
          ans = min(ans, nxt[prevy][p[1][y].second - 'a']);
        }
      }
      {
        int prevz = solve(x, y, p[2][z].first);
        if (prevz != n + 1) {
          ans = min(ans, nxt[prevz][p[2][z].second - 'a']);
        }
      }
      return ans;
    };

    for (int i = 1; i <= q; i++) {
      if (solve(cur[i][0], cur[i][1], cur[i][2]) != n + 1) {
        printf("YES\n");
      } else {
        printf("NO\n");
      }
    }
#ifdef LOCAL
    printf("====\n");
#endif
  }

  return 0;
}