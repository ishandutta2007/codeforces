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

const int N = 15;
const int W = 1 << 20;

int w[N][N];

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

  int n, t;
  cin >> n >> t;
  
  for (int i = 0; i < t; i++) {
    w[0][0] += W;
    
    for (int j = 0; j < n; j++) {
      for (int k = 0; k < j + 1; k++) {
        if (w[j][k] > W) {
          int r = w[j][k] - W;
          r /= 2;
          w[j + 1][k] += r;
          w[j + 1][k + 1] += r;
          w[j][k] = W;
        }
      }
    }
  }
  
  int ans = 0;
  
  for (int j = 0; j < n; j++) {
    for (int k = 0; k < j + 1; k++) {
      if (w[j][k] >= W) ans++;
    }
  }
  
  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}