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

const int N = 1e6 + 123;

int n, k;
int f[2 * N];
int last[1000];
int dp[2 * N];
int s[2 * N];
int m;
int tmp[2 * N];

inline void cut(int &x) {
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}

int count() {
  fill(last, last + 1000, -1);
  fill(f, f + 1000, 0);
  fill(dp, dp + 1000, 0);

  dp[0] = 2;
  last[s[0]] = 0;
  f[0] = 1;

  for (int i = 1; i < m + n; i++) {
    int prev = last[s[i]];
    dp[i] = 2 * dp[i - 1];
    cut(dp[i]);

    if (prev != -1) {
      dp[i] -= dp[prev];
      cut(dp[i]);
      dp[i] += f[prev];
      cut(dp[i]);
    }

    f[i] = dp[i - 1];
    if (prev != -1) {
      f[i] += f[prev];
      cut(f[i]);
      f[i] -= dp[prev];
      cut(f[i]);
    }

    last[s[i]] = i;
  }

  // for (int i = 0; i < m + n; i++) debug(dp[i]);

  return dp[m + n - 1];
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

  cin >> n >> k;
  string t;
  cin >> t;
  for (int i = 0; i < sz(t); i++) {
    s[i] = t[i] - 'a';
  }
  m = sz(t);

  for (int i = 0; i < k; i++) tmp[i] = -1;
  for (int i = 0; i < m; i++) tmp[s[i]] = i;

  for (int i = m; i < n + m; i++) {
    int best = 0;
    int dist = -INF;

    for (int j = 0; j < k; j++) {
      int val = i - tmp[j];
      if (val > dist) {
        dist = val;
        best = j;
      }
    }

    s[i] = best;
    tmp[best] = i;
  }

  /*for (int i = 0; i < n + m; i++) {
    cerr << (char) (s[i] + 'a');
  }
  cerr << endl;*/

  cout << count() << endl;

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}