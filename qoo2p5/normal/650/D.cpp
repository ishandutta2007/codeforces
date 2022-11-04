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

void cut(int &x) {
  if (x >= MOD) x -= MOD;
  if (x < 0) x += MOD;
}

struct Node {
  int x, sum;

  Node() : x(0), sum(0) {}

  Node(int x, int sum) : x(x), sum(sum) {}

  Node operator+(const Node &other) {
    if (x > other.x) {
      return *this;
    } else if (x < other.x) {
      return other;
    } else {
      int s = sum + other.sum;
      cut(s);
      return Node(x, s);
    }
  }
};

class SegmentTree {
private:
  int n;
  Node *tree;

  int up_p2(int x) {
    int y = 1;
    while (y < x) y *= 2;
    return y;
  }

  Node get(int i, int tl, int tr, int l, int r) {
    if (l >= tr || r <= tl) {
      return Node();
    }

    if (l <= tl && tr <= r) {
      return tree[i];
    }

    int tm = (tl + tr) / 2;
    return get(2 * i + 1, tl, tm, l, r) + get(2 * i + 2, tm, tr, l, r);
  }

  void set(int i, int tl, int tr, int index, Node val) {
    if (tl == tr - 1) {
      tree[i] = tree[i] + val;
      return;
    }

    int tm = (tl + tr) / 2;
    if (index < tm) {
      set(2 * i + 1, tl, tm, index, val);
    } else {
      set(2 * i + 2, tm, tr, index, val);
    }

    tree[i] = tree[2 * i + 1] + tree[2 * i + 2];
  }

public:
  SegmentTree(int size) {
    n = up_p2(size);
    tree = new Node[2 * n];
    fill(tree, tree + 2 * n, Node());
  }

  Node get(int l, int r) {
    return get(0, 0, n, l, r + 1);
  }

  void set(int index, Node val) {
    set(0, 0, n, index, val);
  }
};

const int N = 4e5 + 123;

int n, m;
int h[N];
vector<pair<int, int>> q[N];
Node lft[N];
Node rht[N];
Node lft1[N];
Node rht1[N];
int ans[N];

void input() {
  cin >> n >> m;
  vector<pair<int, pair<int, int>>> arr;
  arr.reserve(n + m);

  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    arr.pb(mp(x, mp(i, -INF)));
  }

  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr.pb(mp(b, mp(i, a - 1)));
  }

  sort(arr.begin(), arr.end());

  int tmp = 1;

  for (int i = 0; i < n + m; i++) {
    int j = i;
    while (j + 1 < n + m && arr[j + 1].first == arr[j].first) j++;

    for (int k = i; k <= j; k++) {
      auto &it = arr[k];
      if (it.second.second == -INF) {
        h[it.second.first] = tmp;
      } else {
        q[it.second.second].pb(mp(tmp, it.second.first));
      }
    }

    tmp++;
    i = j;
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

  input();

  SegmentTree tree1(n + m + 1);
  tree1.set(0, Node(0, 1));

  for (int i = 0; i < n; i++) {
    for (auto &it : q[i]) {
      Node t = tree1.get(0, it.first - 1);
      lft[it.second] = Node(t.x + 1, t.sum);
    }

    Node t = tree1.get(0, h[i] - 1);
    tree1.set(h[i], Node(t.x + 1, t.sum));
    lft1[i] = Node(t.x + 1, t.sum);
  }

  int A = 0;
  int SUM = 0;

  for (int i = 0; i <= n + m; i++) {
    Node t = tree1.get(i, i);
    if (t.x == A) {
      SUM += t.sum;
      cut(SUM);
    } else if (t.x > A) {
      A = t.x;
      SUM = t.sum;
    }
  }

  SegmentTree tree2(n + m + 2);
  tree2.set(n + m + 1, Node(0, 1));

  for (int i = n - 1; i >= 0; i--) {
    for (auto &it : q[i]) {
      Node t = tree2.get(it.first + 1, n + m + 1);
      rht[it.second] = Node(t.x + 1, t.sum);
    }

    Node t = tree2.get(h[i] + 1, n + m + 1);
    tree2.set(h[i], Node(t.x + 1, t.sum));
    rht1[i] = Node(t.x + 1, t.sum);
  }

  for (int i = 0; i < n; i++) {
    int cnt = (lft1[i].sum * 1LL * rht1[i].sum) % MOD;
    int len = lft1[i].x + rht1[i].x - 1;

    for (auto &it : q[i]) {
      int j = it.second;
      ans[j] = lft[j].x + rht[j].x - 1;

      if (len == A && cnt == SUM) {
        ans[j] = max(ans[j], A - 1);
      } else {
        ans[j] = max(ans[j], A);
      }
    }
  }

  for (int i = 0; i < m; i++) {
    cout << ans[i] << "\n";
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}