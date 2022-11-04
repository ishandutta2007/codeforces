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
const ll MOD = 1e9 + 9;

#define TASKNAME ""

int power(int a, int b) {
  if (b == 0) {
    return 1;
  }

  if (b & 1) {
    return (power(a, b - 1) * 1LL * a) % MOD;
  } else {
    int x = power(a, b / 2);
    return (x * 1LL * x) % MOD;
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

  int n, m, k;
  cin >> n >> m >> k;

  int x = max(0, n / k - n + m);
  int mult = power(2, x + 1) - 2;
  if (mult < 0) mult += MOD;
  int ans = (mult * 1LL * k + (m - k * x)) % MOD;
  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}