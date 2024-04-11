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

const int N = 2e5 + 123;

int n, m, s, d;
int a[N];
int from[N];
pair<int, int> how[N];

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

  cin >> n >> m >> s >> d;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }

  fill(from, from + (n + 1), -1);
  a[0] = -1;
  sort(a, a + (n + 1));
  vector<pair<int, int>> cur;
  if (a[1] - 1 >= s) {
    cur.pb(mp(a[1] - 1, 0));
  }

  for (int i = 1; i <= n; i++) {
    int pos = a[i] + 1;
    auto it = lower_bound(cur.begin(), cur.end(), mp(pos - d, -1));

    if (it == cur.end()) {
      continue;
    }

    from[i] = it->second;
    int run = (a[from[i] + 1] - 1) - (a[from[i]] + 1);
    int jump = (a[i] + 1) - (a[from[i] + 1] - 1);
    how[i] = mp(run, jump);

    if (i != n && (a[i + 1] - 1) - (a[i] + 1) >= s) {
      cur.pb(mp(a[i + 1] - 1, i));
    }
  }

  if (from[n] == -1) {
    cout << "IMPOSSIBLE\n";
    return 0;
  }

  vector<pair<int, int>> ans;
  int i = n;
  while (i != 0) {
    ans.pb(how[i]);
    i = from[i];
  }
  reverse(ans.begin(), ans.end());

  for (auto it : ans) {
    cout << "RUN " << it.first << "\nJUMP " << it.second << "\n";
  }

  if (a[n] + 1 != m) {
    cout << "RUN " << m - (a[n] + 1) << "\n";
  }

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}