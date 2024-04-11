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

const int N = 1e5 + 123;

int n, m;

vector<int> g[N];
int dp[N];
vector<pair<int, int>> a;

void dfs(int v) {
  dp[v] = 0;

  for (int to : g[v]) {
    if (dp[to] == -1) {
      dfs(to);
    }

    dp[v] = max(dp[v], dp[to] + 1);
  }
}

bool check(int k) {
  for (int i = 0; i < n; i++) g[i].clear(), dp[i] = -1;
  for (int i = 0; i < k; i++) {
    g[a[i].first - 1].pb(a[i].second - 1);
  }

  for (int v = 0; v < n; v++) {
    if (dp[v] == -1) dfs(v);
  }

  return *max_element(dp, dp + n) == (n - 1);
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

  cin >> n >> m;
  a.resize(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first >> a[i].second;
  }

  if (!check(m)) {
    cout << "-1\n";
    return 0;
  }

  int left = 0;
  int right = m;

  while (right - left > 1) {
    int mid = (left + right) / 2;

    if (check(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }

  cout << right << "\n";

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}