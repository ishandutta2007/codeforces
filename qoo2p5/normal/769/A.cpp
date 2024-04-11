#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int INF = (int) 1e9 + 123;
const ll LINF = (ll) 1e18 + 123;
const ld EPS = 1e-8;
const int MOD = (int) 1e9 + 7;

#define mp(x, y) make_pair(x, y)
#define pb(x) push_back((x))
#define all(x) (x).begin(), (x).end()
#define sz(x) (int) (x).size()
#ifndef LOCAL
	#define debug(x)
#else
	#define debug(x) cerr << x << endl
#endif

#define TASK ""
#define MULTITEST 0

void run();

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	if (strlen(TASK) > 0) {
		freopen(TASK ".in", "r", stdin);
		freopen(TASK ".out", "w", stdout);
	}
#endif
	int t = 1;
	if (MULTITEST) {
		cin >> t;
	}
	for (int i = 0; i < t; i++) {
		run();
	}
	return 0;
}

// == PROBLEM SOLUTION == //

const int N = 10;

int n;
int a[N];

void run() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	nth_element(a, a + (n / 2), a + n);
	cout << a[n / 2] << "\n";
}