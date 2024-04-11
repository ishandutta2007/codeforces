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

const int N = 1e6;

int n;
int a[N];

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
  ll x, y;
  cin >> x >> y;

  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(a, a + n);

  int ans = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] % 2 == 1) {
      if (y > 0) {
        y--;
      } else if (x > 0) {
        x--;
      } else {
        break;
      }
      a[i]--;
    }

    int t = a[i] / 2;

    if (t <= x) {
      x -= t;
    } else {
      int rest = a[i] - 2 * x;
      x = 0;
      if (y < rest) {
        break;
      } else {
        y -= rest;
      }
    }

    ans++;
  }

  cout << ans << endl;

#ifdef DEBUG
  cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}