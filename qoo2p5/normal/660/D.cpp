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

const int N = 2016;

int n;
pair<int, int> points[N];
vector<pair<int, int>> cnt;

int get(pair<int, int> t) {
  return upper_bound(cnt.begin(), cnt.end(), t) - lower_bound(cnt.begin(), cnt.end(), t);
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
  for (int i = 0; i < n; i++) {
    cin >> points[i].first >> points[i].second;
  }

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      cnt.pb(mp(points[i].first - points[j].first, points[i].second - points[j].second));
    }
  }

  sort(cnt.begin(), cnt.end());

  ll ans = 0;

  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      pair<int, int> t = mp(points[i].first - points[j].first, points[i].second - points[j].second);
      ans += get(t) + get(mp(-t.first, -t.second)) - 1;
    }
  }

  cout << ans / 4 << endl;

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}