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

const int N = 2000;

int a[N][4];
int ord[4] = {1, 0, 2, 3};

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

  int n, m;
  cin >> n >> m;

  int cur = 1;
  for (int i = 0; i < n; i++) {
    a[i][0] = cur++;
    a[i][3] = cur++;
  }
  for (int i = 0; i < n; i++) {
    a[i][1] = cur++;
    a[i][2] = cur++;
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 4; j++) {
      if (a[i][ord[j]] <= m) {
        cout << a[i][ord[j]] << " ";
      }
    }
  }

  cout << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}