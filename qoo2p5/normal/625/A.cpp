#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ull unsigned ll
#define ld long double
#define sz(x) (int) x.size()
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eq(a, b) abs(a - b) < EPS

const int INF = 1e9;
const ll LINF = 1e18;
const ld EPS = 1e-10;
const ld PI = 3.141592653589;

#define TASKNAME ""

int main() {
  ios::sync_with_stdio(false);
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

  ll n, a, b, c;
  cin >> n >> a >> b >> c;

  ll t = b - c;
  if (a <= t) {
    cout << n / a << endl;
  } else {
    if (n >= b) {
      ll left = 0;
      ll right = n;

      while (right - left > 1) {
        ll m = (left + right) / 2;
        ld nn = n - (b - c) * ((ld) m);
        if (nn >= b - EPS) {
          left = m;
        } else {
          right = m;
        }
      }

      ll ans = left + 1;
      ll rest = n - (b - c) * (left + 1);
      ans += rest / a;
      cout << ans << endl;
    } else {
      cout << n / a << endl;
    }
  }

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

  return 0;
}