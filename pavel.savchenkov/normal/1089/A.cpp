#ifdef DEBUG
#define _GLIBCXX_DEBUG
#endif

#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

#ifdef DEBUG
#define eprintf(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define sz(x) ((int) (x).size())
#define TASK "text"

const int inf = (int) 1.01e9;
const long long infll = (long long) 1.01e18;
const ld eps = 1e-9;
const ld pi = acos((ld) -1);

#ifdef DEBUG
mt19937 mrand(300); 
#else
mt19937 mrand(chrono::steady_clock::now().time_since_epoch().count()); 
#endif

int rnd(int x) {
  return mrand() % x;
}

const int maxn = 205;
int dp[4][4][maxn][maxn][2];
const vector<pair<int, int>> scores = {{3, 0}, {3, 1}, {3, 2}, {2, 3}, {1, 3}, {0, 3}};

void precalc() {
  memset(dp, -1, sizeof(dp));
  dp[0][0][0][0][0] = 0;
  dp[0][0][0][0][1] = 0;
  for (int w0 = 0; w0 < 4; w0++) {
    for (int w1 = 0; w1 < 4; w1++) {
      for (int a = 0; a < maxn; a++) {
        for (int b = 0; b < maxn; b++) {
          if (dp[w0][w1][a][b][0] == -1) {
            continue;
          }
          if (w0 >= 3 || w1 >= 3) {
            continue;
          }
          int x = (w0 + w1 == 4 ? 15 : 25);
          if (a + x < maxn) {
            for (int i = 0; i + 1 < x && b + i < maxn; i++) {
              dp[w0 + 1][w1][a + x][b + i][0] = x;
              dp[w0 + 1][w1][a + x][b + i][1] = i;
            }
          }
          if (b + x < maxn) {
            for (int i = 0; i + 1 < x && a + i < maxn; i++) {
              dp[w0][w1 + 1][a + i][b + x][0] = i;
              dp[w0][w1 + 1][a + i][b + x][1] = x;
            }
          }
          for (int i = x + 1; a + i < maxn && b + i - 2 < maxn; i++) {
            dp[w0 + 1][w1][a + i][b + i - 2][0] = i;
            dp[w0 + 1][w1][a + i][b + i - 2][1] = i - 2;
          }
          for (int i = x + 1; b + i < maxn && a + i - 2 < maxn; i++) {
            dp[w0][w1 + 1][a + i - 2][b + i][0] = i - 2;
            dp[w0][w1 + 1][a + i - 2][b + i][1] = i;
          }
        }
      }
    }
  }
}

int a, b;

bool read() {
  if (scanf("%d%d", &a, &b) < 2) {
    return false;
  }
  return true;
}

void solve() {
  int w0 = -1, w1 = -1;
  for (int i = 0; i < sz(scores); i++) {
    if (dp[scores[i].first][scores[i].second][a][b][0] != -1) {
      w0 = scores[i].first;
      w1 = scores[i].second;
      break;
    }
  }
  if (w0 == -1) {
    printf("Impossible\n");
    return;
  }
  printf("%d:%d\n", w0, w1);
  vector<pair<int, int>> ans;
  while (w0 || w1) {
    int x = dp[w0][w1][a][b][0];
    int y = dp[w0][w1][a][b][1];
    if (x > y) {
      w0--;
    } else {
      w1--;
    }
    a -= x;
    b -= y;
    ans.push_back(make_pair(x, y));
  }
  reverse(ans.begin(), ans.end());
  for (int i = 0; i < sz(ans); i++) {
    printf("%d:%d ", ans[i].first, ans[i].second);
  }
  printf("\n");
}

int main() {
  precalc();
#ifdef DEBUG
  assert(freopen(TASK ".in", "r", stdin));
  assert(freopen(TASK ".out", "w", stdout));
#endif
  int t;
  scanf("%d", &t);
  while (read()) {
    solve();
#ifdef DEBUG
    eprintf("Time %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
  }
  return 0;
}