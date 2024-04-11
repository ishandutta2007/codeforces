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

int n, m;
int a[N];
int nxt[N];

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

	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}

	for (int i = 0; i < n; i++) {
		int j = i;
		while (j + 1 < n && a[j + 1] == a[i]) {
			j++;
		}

		for (int k = i; k <= j; k++) {
			nxt[k] = j + 1;
		}

		i = j;
	}

	for (int i = 0; i < m; i++) {
		int l, r, x;
		scanf("%d%d%d", &l, &r, &x);
		l--; r--;

		int ans = -1;
		if (a[l] != x) {
			ans = l + 1;
		} else if (nxt[l] <= r) {
			ans = nxt[l] + 1;
		}

		printf("%d\n", ans);
	}

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}