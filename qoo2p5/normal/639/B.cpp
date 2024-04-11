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

const int N = 1e5 + 123;

int n, h, d;

vector<pair<int, int>> ans;

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

  cin >> n >> d >> h;

  if (d - h > h) {
    cout << "-1\n";
    return 0;
  }

  if (h == d) {
    if (h == 1 && n != 2) {
      cout << "-1\n";
      return 0;
    }

    for (int i = 1; i <= h; i++) {
      ans.pb(mp(i, i + 1));
    }
    for (int i = h + 2; i <= n; i++) {
      ans.pb(mp(2, i));
    }
    for (int i = 0; i < n - 1; i++) {
      cout << ans[i].first << " " << ans[i].second << "\n";
    }
    return 0;
  }

  for (int i = 1; i <= h; i++) {
    ans.pb(mp(i, i + 1));
  }

  if (h + 2 <= n) ans.pb(mp(1, h + 2));

  int cur = h + 3;
  int len = 1 + h;
  while (len < d) {
    ans.pb(mp(cur - 1, cur));
    cur++;
    len++;
  }

  while (cur <= n) {
    ans.pb(mp(1, cur));
    cur++;
  }

  for (int i = 0; i < n - 1; i++) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}