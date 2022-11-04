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

const int N = 3e5 + 123;

int n, k;
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

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }

  int best = 0;
  int best_i = 0;
  int best_j = 1;

  int j = 0;
  int cur = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) {
      cur++;
    }

    while (cur > k && j <= i) {
      if (a[j] == 0) {
        cur--;
      }
      j++;
    }

    if (j <= i) {
      int len = i - j + 1;
      if (len > best) {
        best = len;
        best_i = i;
        best_j = j;
      }
    }
  }

  cout << best << "\n";
  for (int i = 0; i < n; i++) {
    cout << (i >= best_j && i <= best_i ? 1 : a[i]) << " ";
  }
  cout << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}