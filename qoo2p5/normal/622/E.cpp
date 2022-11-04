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

const int N = 5e5 + 123;

int n;
vector<int> g[N];

void dfs(int v, int root, vector<int> &a, int h = 0) {
  if (sz(g[v]) == 1) {
    a.pb(h);
  }

  for (int to : g[v]) {
    if (to != root) {
      dfs(to, v, a, h + 1);
    }
  }
}

int solve() {
  int ans = 0;

  for (int u : g[1]) {
    vector<int> a;
    dfs(u, 1, a);

    int cur = -INF;
    sort(a.begin(), a.end());

    for (int h : a) {
      cur = max(h, cur + 1);
    }

    ans = max(ans, cur + 1);
  }

  return ans;
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

  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    g[a].pb(b);
    g[b].pb(a);
  }
  cout << solve() << "\n";

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}