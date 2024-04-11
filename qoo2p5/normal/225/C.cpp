#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (ll) x.size()
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
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 1005;

int n, m, x, y;
int a[N][N];
int prefix[N];

int calc(int j) {
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i][j];
  }
  return ans;
}

int cost(int f, int t, int color) {
  int ans = prefix[t];
  if (f > 0) ans -= prefix[f - 1];
  if (color) ans = (t - f + 1) * n - ans;
  return ans;
}

int dp[N][2];

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

  cin >> n >> m >> x >> y;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      char c;
      cin >> c;
      a[i][j] = c == '#';
    }
  }

  prefix[0] = calc(0);
  for (int j = 1; j < m; j++) {
    prefix[j] = prefix[j - 1] + calc(j);
  }

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= 1; j++) {
      dp[i][j] = INF;
    }
  }
  dp[0][0] = 0;
  dp[0][1] = 0;

  for (int i = 1; i <= m; i++) {
    for (int c = 0; c <= 1; c++) {
      for (int w = x; w <= y; w++) {
        if (i - w < 0) continue;
        dp[i][c] = min(dp[i][c], dp[i - w][!c] + cost(i - w, i - 1, c));
      }
    }
  }

  cout << min(dp[m][0], dp[m][1]) << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}