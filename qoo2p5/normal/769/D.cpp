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

const int N = (int) 1e4 + 5;

int n, k;
int a[N];
bool ok[2 * N];

void run() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		a[x]++;
	}
	
	for (int i = 0; i < 2 * N; i++) {
		int c = 0;
		for (int j = 0; j < 20; j++) {
			if (i & (1 << j)) {
				c++;
			}
		}
		ok[i] = (c == k);
	}
	
	ll ans = 0;
	
	for (int i = 0; i < N; i++) {
		if (ok[0]) {
			ans += a[i] * 1LL * (a[i] - 1) / 2;
		}
		for (int j = i + 1; j < N; j++) {
			if (ok[i ^ j]) {
				ans += a[i] * 1LL * a[j];
			}
		}
	}
	
	cout << ans << "\n";
}