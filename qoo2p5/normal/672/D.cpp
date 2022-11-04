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

const int N = 5e5 + 123;

int n, k;
int c[N];

int get_min() {
  int left = 0;
  int right = INF + 1;

  while (right - left > 1) {
    int m = (left + right) / 2;
    ll need = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] < m) {
        need += m - c[i];
      }
    }

    if (need <= k) {
      left = m;
    } else {
      right = m;
    }
  }

  return left;
}

int get_max() {
  int left = 0;
  int right = INF + 1;

  while (right - left > 1) {
    int m = (left + right) / 2;
    ll need = 0;
    for (int i = 0; i < n; i++) {
      if (c[i] > m) {
        need += c[i] - m;
      }
    }

    if (need <= k) {
      right = m;
    } else {
      left = m;
    }
  }

  return right;
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

  cin >> n >> k;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  int r = max(0, get_max() - get_min());

  if (r == 0) {
    ll sum = 0;
    for (int i = 0; i < n; i++) {
      sum += c[i];
    }

    if (sum % n != 0) {
      r = 1;
    }
  }

  cout << r << "\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}