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

const int N = 2e5 + 123;

int n;
int a[N];
int pref[N];
int suff[N];
int pos[N];
vector<int> dividers[N];

void factorize(int x, vector<int> &divs) {
  for (int d = 1; d * d <= x; d++) {
    int subd = x / d;

    if (d * subd == x) {
      if (d != subd) {
        divs.pb(d);
        divs.pb(subd);
      } else {
        divs.pb(d);
      }
    }
  }
}

void calc_pref() {
  fill(pos, pos + N, -1);

  for (int i = 0; i < n; i++) {
    if (i != 0) {
      pref[i] = pref[i - 1];
    }

    for (int d : dividers[i]) {
      if (pos[d] != -1) {
        pref[i] = max(pref[i], d);
      } else {
        pos[d] = i;
      }
    }
  }
}

void calc_suff() {
  fill(pos, pos + N, -1);

  for (int i = n - 1; i >= 0; i--) {
    if (i != n - 1) {
      suff[i] = suff[i + 1];
    }

    for (int d : dividers[i]) {
      if (pos[d] != -1) {
        suff[i] = max(suff[i], d);
      } else {
        pos[d] = i;
      }
    }
  }
}

struct SegmentTree {
  int n;
  int *p, *mi, *ma;
  ll *tree;
  
  SegmentTree(int nn) {
    n = 1;
    while (n < nn) {
      n *= 2;
    }
    p = new int[2 * n];
    mi = new int[2 * n];
    ma = new int[2 * n];
    tree = new ll[2 * n];
    fill(p, p + 2 * n, -1);
    fill(tree, tree + 2 * n, 0);
    fill(mi, mi + 2 * n, 0);
    fill(ma, ma + 2 * n, 0);
  }
  
  inline void push(int i, int tl, int tr) {
    if (p[i] == -1) {
      return;
    }
    
    mi[i] = p[i];
    ma[i] = p[i];
    tree[i] = p[i] * 1LL * (tr - tl);
    
    if (tl != tr - 1) {
      p[2 * i + 1] = p[i];
      p[2 * i + 2] = p[i];
    }
    
    p[i] = -1;
  }
  
  void update(int i, int tl, int tr, int l, int r, int val) {
    push(i, tl, tr);
    
    if (tl >= r || tr <= l || mi[i] >= val) {
      return;
    }
    
    if (l <= tl && tr <= r && ma[i] <= val) {
      p[i] = val;
      push(i, tl, tr);
      return;
    }
    
    int tm = (tl + tr) / 2;
    update(2 * i + 1, tl, tm, l, r, val);
    update(2 * i + 2, tm, tr, l, r, val);
    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
    mi[i] = min(mi[2 * i + 1], mi[2 * i + 2]);
    ma[i] = max(ma[2 * i + 1], ma[2 * i + 2]);
  }
  
  void update(int l, int r, int val) {
    update(0, 0, n, l, r + 1, val);
  }
  
  ll get_sum(int i, int tl, int tr, int l, int r) {
    push(i, tl, tr);
    
    if (tl >= r || tr <= l) {
      return 0;
    }
    
    if (l <= tl && tr <= r) {
      return tree[i];
    }
    
    int tm = (tl + tr) / 2;
    return get_sum(2 * i + 1, tl, tm, l, r) + get_sum(2 * i + 2, tm, tr, l, r);
  }
  
  ll get_sum(int l, int r) {
    return get_sum(0, 0, n, l, r + 1);
  }
};

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
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    factorize(a[i], dividers[i]);
  }

  calc_pref();
  calc_suff();
  
  SegmentTree t(n + 1);
  
  for (int i = 0; i < n; i++) {
    t.update(i, i, suff[i]);
  }
  t.update(n, n, 1);
  
  ll ans = 0;
  
  for (int i = 0; i < n; i++) {
    ans += t.get_sum(i + 1, n);
    t.update(0, n, pref[i]);
    
    for (int d : dividers[i]) {
      t.update(0, pos[d], d);
    }
  }
  
  ans -= 2;
  
  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}