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

const int N = 333;

int n, t;
int a[N];
int cnt[N];
int dp1[N];
int dp2[N];

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

  cin >> n >> t;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }

  if (t <= 2 * n) {
    for (int i = 0; i < t; i++) {
      for (int j = 0; j < n; j++) {
        int best = max(1, dp1[a[j]]);
        for (int prev = 0; prev < (i == 0 ? j : n); prev++) {
          if (a[prev] <= a[j]) {
            best = max(best, dp1[a[prev]] + 1);
          }
        }
        dp1[a[j]] = best;
      }
    }

    cout << *max_element(dp1, dp1 + N) << "\n";
    return 0;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      int best = max(1, dp1[a[j]]);
      for (int prev = 0; prev < (i == 0 ? j : n); prev++) {
        if (a[prev] <= a[j]) {
          best = max(best, dp1[a[prev]] + 1);
        }
      }
      dp1[a[j]] = best;
    }
  }


  for (int i = 0; i < n; i++) {
    for (int j = n - 1; j >= 0; j--) {
      int best = max(1, dp2[a[j]]);
      for (int prev = (i == 0 ? j + 1 : 0); prev < n; prev++) {
        if (a[prev] >= a[j]) {
          best = max(best, dp2[a[prev]] + 1);
        }
      }
      dp2[a[j]] = best;
    }
  }

  int ans = 0;

  for (int i = 0; i < n; i++) {
    int mid = a[i];
    ans = max(ans, cnt[mid] * (t - 2 * n) + dp1[mid] + dp2[mid]);
  }

  cout << ans << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}