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

const ll INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-9;
const ld PI = 3.141592653589;
const ll MOD = 1e9 + 7;

#define TASKNAME ""

const int N = 3e5 + 123;

struct SegmentTree {
  int n;
  ll *p, *tree;
  
  SegmentTree() {}
  
  SegmentTree(int nn) {
    n = 1;
    while (n < nn) {
      n *= 2;
    }
    
    p = new ll[2 * n];
    tree = new ll[2 * n];
    fill(p, p + 2 * n, 0);
    fill(tree, tree + 2 * n, LINF);
  }
  
  void push(int i, int tl, int tr) {
    if (p[i] == 0) {
      return;
    }
    
    if (tl != tr - 1) {
      p[2 * i + 1] += p[i];
      p[2 * i + 2] += p[i];
    }
    
    tree[i] = min(LINF, tree[i] + p[i]);
    p[i] = 0;
  }
  
  void add(int i, int tl, int tr, int l, int r, ll val) {
    push(i, tl, tr);
    
    if (tl >= r || tr <= l) {
      return;
    }
    
    if (l <= tl && tr <= r) {
      p[i] = val;
      push(i, tl, tr);
      return;
    }
    
    int tm = (tl + tr) / 2;
    add(2 * i + 1, tl, tm, l, r, val);
    add(2 * i + 2, tm, tr, l, r, val);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
  }
  
  void add(int l, int r, ll val) {
    add(0, 0, n, l, r + 1, val);
  }
  
  void set(int i, int tl, int tr, int ind, ll val) {
    push(i, tl, tr);
    
    if (tl == tr - 1) {
      tree[i] = val;
      return;
    }
    
    int tm = (tl + tr) / 2;
    if (ind < tm) {
      set(2 * i + 1, tl, tm, ind, val);
    } else {
      set(2 * i + 2, tm, tr, ind, val);
    }
    
    tree[i] = min(tree[2 * i + 1] + p[2 * i + 1], tree[2 * i + 2] + p[2 * i + 2]);
  }
  
  void set(int ind, ll val) {
    set(0, 0, n, ind, val);
  }
  
  ll get_min(int i, int tl, int tr, int l, int r) {
    push(i, tl, tr);
    
    if (tl >= r || tr <= l) {
      return LINF;
    }
    
    if (l <= tl && tr <= r) {
      return tree[i];
    }
    
    int tm = (tl + tr) / 2;
    return min(get_min(2 * i + 1, tl, tm, l, r), get_min(2 * i + 2, tm, tr, l, r));
  }
  
  ll get_min(int l, int r) {
    return get_min(0, 0, n, l, r + 1);
  }
};

int n, m;
vector<int> g[N];
int c[N];
vector<int> s[N];
vector<int> f[N];
ll dp[N];
int l[N], r[N];
int num[N];
SegmentTree t;

int tmr;

void numerate(int v, int from = -1) {
  l[v] = tmr;
  for (int u : g[v]) {
    if (u != from) {
      numerate(u, v);
    }
  }
  for (int i : f[v]) {
    num[i] = tmr++;
  }
  r[v] = tmr - 1;
}

void dfs(int v, int from = -1) {
  ll sum = 0;
  
  for (int u : g[v]) {
    if (u != from) {
      dfs(u, v);
      sum = min(LINF, sum + dp[u]);
    }
  }
  
  if (sum == LINF) {
    dp[v] = LINF;
    return;
  }

  for (int u : g[v]) {
    if (u != from) {
      t.add(l[u], r[u], sum - dp[u]);
    }
  }
  
  for (int i : f[v]) {
    t.set(num[i], sum + c[i]);
  }
  
  for (int i : s[v]) {
    t.set(num[i], LINF);
  }
  
  if (v == 0) {
    dp[v] = sum;
  } else {
    dp[v] = t.get_min(l[v], r[v]);
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

  cin >> n >> m;
  for (int i = 0; i < n - 1; i++) {
    int u, v;
    cin >> u >> v;
    u--;
    v--;
    g[u].pb(v);
    g[v].pb(u);
  }
  
  for (int i = 0; i < m; i++) {
    int u, v;
    cin >> u >> v >> c[i];
    u--;
    v--;
    
    s[v].pb(i);
    f[u].pb(i);
  }
  
  t = SegmentTree(m);
  numerate(0);
  dfs(0);
  
  cout << (dp[0] == LINF ? -1 : dp[0]) << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}