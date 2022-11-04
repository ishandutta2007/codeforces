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
vector<int> g[2][N];
int p[2][N];
int f[N];
int cnt;
int ans[N][4];

int get_f(int v) {
  if (f[v] == v) {
    return v;
  }

  return f[v] = get_f(f[v]);
}

void dfs(int t, int v, int root = -1) {
  p[t][v] = root;

  for (int to : g[t][v]) {
    if (to == root) {
      continue;
    }

    dfs(t, to, v);
  }
}

void solve(int v) {
  for (int to : g[0][v]) {
    if (to == p[0][v]) {
      continue;
    }

    solve(to);

    if (p[1][to] != v && p[1][v] != to) {
      int u = get_f(to);
      ans[cnt][0] = v + 1;
      ans[cnt][1] = to + 1;
      ans[cnt][2] = u + 1;
      ans[cnt][3] = p[1][u] + 1;
      cnt++;
    }
  }
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
    a--; b--;
    g[0][a].pb(b);
    g[0][b].pb(a);
  }
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--; b--;
    g[1][a].pb(b);
    g[1][b].pb(a);
  }

  dfs(0, 0);
  dfs(1, 0);

  for (int v = 0; v < n; v++) {
    int u = p[1][v];
    if (u != -1 && (p[0][u] == v || p[0][v] == u)) {
      f[v] = u;
    } else {
      f[v] = v;
    }
  }

  solve(0);

  cout << cnt << "\n";
  for (int i = 0; i < cnt; i++) {
    for (int j = 0; j < 4; j++) {
      cout << ans[i][j] << " ";
    }
    cout << "\n";
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}