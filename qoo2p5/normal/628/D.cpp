#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

#ifdef DEBUG
  #define debug(x) cerr << "\033[31m" << x << "\033[39m" << endl;
#else
  #define debug(x)
#endif

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;
const int MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 2016;

void cut(int &x) {
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}

int m, d;
int dp[N][N][2][2];

int solve(int *s) {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      for (int a = 0; a < 2; a++) {
        for (int b = 0; b < 2; b++) {
          dp[i][j][a][b] = 0;
        }
      }
    }
  }

  int pos = N;
  for (int i = 0; i < N; i++) {
    if (s[i] != 0) {
      pos = i;
      break;
    }
  }

  for (int i = 0; i < N - 1; i++) {
    for (int c = 0; c < 2; c++) {
      if (i % 2 == c && i >= pos) { // starting
        for (int t = 1; t <= 9; t++) {
          if (t == d) {
            continue;
          }

          int r = t % m;

          if (t == s[i] && i == pos) {
            dp[i][r][1][c] += 1;
            cut(dp[i][r][1][c]);
          } else if (t < s[i] || i > pos) {
            dp[i][r][0][c] += 1;
            cut(dp[i][r][0][c]);
          }
        }
      }

      for (int j = 0; j < m; j++) {
        if (i % 2 != c) {
          for (int t = 0; t <= 9; t++) {
            if (t == d) {
              continue;
            }

            int r = (j * 10 + t) % m;

            dp[i + 1][r][0][c] += dp[i][j][0][c];
            cut(dp[i + 1][r][0][c]);
            if (t == s[i + 1]) {
              dp[i + 1][r][1][c] += dp[i][j][1][c];
              cut(dp[i + 1][r][1][c]);
            } else if (t < s[i + 1]) {
              dp[i + 1][r][0][c] += dp[i][j][1][c];
              cut(dp[i + 1][r][0][c]);
            }
          }
        } else {
          int r = (j * 10 + d) % m;
          dp[i + 1][r][0][c] += dp[i][j][0][c];
          cut(dp[i + 1][r][0][c]);

          if (d == s[i + 1]) {
            dp[i + 1][r][1][c] += dp[i][j][1][c];
            cut(dp[i + 1][r][1][c]);
          } else if (d < s[i + 1]) {
            dp[i + 1][r][0][c] += dp[i][j][1][c];
            cut(dp[i + 1][r][1][c]);
          }
        }
      }
    }
  }

  for (int c = 0; c < 2; c++) {
    int i = N - 1;
    if (i % 2 == c && i >= pos) { // starting
      for (int t = 1; t <= 9; t++) {
        if (t == d) {
          continue;
        }

        int r = t % m;

        if (t == s[i] && i == pos) {
          dp[i][r][1][c] += 1;
          cut(dp[i][r][1][c]);
        } else if (t < s[i] || i > pos) {
          dp[i][r][0][c] += 1;
          cut(dp[i][r][0][c]);
        }
      }
    }
  }

  int res = 0;
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      res += dp[N - 1][0][i][j];
      cut(res);
    }
  }

  return res;
}

bool check(int *s) {
  int pos = N;
  int c = 0;
  for (int i = 0; i < N; i++) {
    if (s[i] != 0) {
      c = i % 2;
      pos = i;
      break;
    }
  }

  for (int i = pos; i < N; i++) {
    if (i % 2 == c && s[i] == d) {
      return false;
    }
    if (i % 2 != c && s[i] != d) {
      return false;
    }
  }

  int r = 0;
  for (int i = 0; i < N; i++) {
    r = (10 * r + s[i]) % m;
  }

  return r == 0;
}

int* get(string s) {
  int* a = new int[N];
  fill(a, a + N, 0);
  for (int i = 0; i < sz(s); i++) {
    a[N - sz(s) + i] = s[i] - '0';
  }

  return a;
}

int main() {
  ios::sync_with_stdio(false);
  cout.tie(nullptr);
  cin.tie(nullptr);
  float tbegin = clock();
  srand(42);

#ifdef DEBUG
  freopen("input.txt", "r", stdin);
#else
  if (TASKNAME != "") {
    freopen(TASKNAME ".in", "r", stdin);
    freopen(TASKNAME ".out", "w", stdout);
  }
#endif

  cin >> m >> d;

  string as, bs;
  cin >> as >> bs;
  int* a = get(as);
  int* b = get(bs);

  int ans = solve(b) - solve(a);
  cut(ans);
  if (check(a)) {
    ans++;
    cut(ans);
  }

  cout << ans << "\n";

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}