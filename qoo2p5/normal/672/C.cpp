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

struct point {
  ld x, y;
  point() {}
};

ld dist(point &a, point &b) {
  return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

const int N = 1e5 + 123;

int n;
point a, b, t;
point p[N];

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

  cin >> a.x >> a.y >> b.x >> b.y >> t.x >> t.y;
  cin >> n;

  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }

  ld sum = 0;
  for (int i = 0; i < n; i++) {
    sum += 2 * dist(t, p[i]);
  }

  ld only_a = 1e20;
  ld only_b = 1e20;

  for (int i = 0; i < n; i++) {
    only_a = min(only_a, sum - dist(t, p[i]) + dist(a, p[i]));
    only_b = min(only_b, sum - dist(t, p[i]) + dist(b, p[i]));
  }

  vector<pair<ld, int>> good_a;
  vector<pair<ld, int>> good_b;

  for (int i = 0; i < n; i++) {
    good_a.pb(mp(-dist(t, p[i]) + dist(a, p[i]), i));
    good_b.pb(mp(-dist(t, p[i]) + dist(b, p[i]), i));
  }

  ld ans = min(only_a, only_b);

  sort(good_a.begin(), good_a.end());
  sort(good_b.begin(), good_b.end());

  if (n >= 2) {
    for (int i = 0; i < min(3, n); i++) {
      for (int j = 0; j < min(3, n); j++) {
        if (good_a[i].second == good_b[j].second) continue;

        ans = min(ans, sum + good_a[i].first + good_b[j].first);
      }
    }
  }

  cout << fixed << setprecision(20) << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}