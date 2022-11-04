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

#define TASKNAME ""

const int N = 5 * 1e4;
const int M = 5 * 1e3;
const int C = 1e6 + 1;

int n, m;
int a[N];
int precount[C];
int ans[M];
int dp[N + 1];
int ndp[N + 1];
int l[M], r[M];

inline int f(int u, int v) {
	return precount[v] ^ precount[u - 1];
}

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

	for (int i = 1; i < C; i++) {
		precount[i] = precount[i - 1] ^ i;
	}

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	for (int i = 0; i < m; i++) {
		cin >> l[i] >> r[i];
		l[i]--; r[i]--;
	}

	for (int i = 0; i < n; i++) {
		dp[i] = a[i];

		for (int j = i + 1; j < n; j++) {
			dp[j] = max(dp[j - 1], a[i] <= a[j] ? f(a[i], a[j]) : f(a[j], a[i]));
		}

		for (int j = 0; j < m; j++) {
			if (l[j] <= i && i <= r[j] && ans[j] < dp[r[j]]) {
				ans[j] = dp[r[j]];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		cout << ans[i] << "\n";
	}

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}