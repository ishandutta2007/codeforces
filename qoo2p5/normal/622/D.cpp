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

const int N = 1e6;

int n;
int ans[N];

void solve1(int n) {
	for (int i = 1; i < n; i += 2) {
		ans[(i + 1) / 2 - 1] = i;
		ans[n - (i + 1) / 2] = i;
	}

	for (int i = 2; i < n; i += 2) {
		ans[n + i / 2 - 1] = i;
		ans[2 * n - i / 2 - 1] = i;
	}

	for (int i = 0; i < 2 * n; i++) {
		if (ans[i] == 0) {
			ans[i] = n;
		}
	}
}

void solve2(int n) {
	for (int i = 1; i < n; i += 2) {
		ans[(i + 1) / 2] = i;
		ans[n - (i + 1) / 2 + 1] = i;
	}

	for (int i = 2; i < n; i += 2) {
		ans[n + i / 2] = i;
		ans[2 * n - i / 2] = i;
	}

	for (int i = 0; i < 2 * n; i++) {
		if (ans[i] == 0) {
			ans[i] = n;
		}
	}
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

	scanf("%d", &n);

	if (n % 2 == 1) {
		solve2(n);
	} else {
		solve1(n);
	}

	for (int i = 0; i < 2 * n; i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}