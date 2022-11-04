#include <iostream>
#include <stdio.h>
#include <set>
#include <vector>

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

set<int> cnt;

int main() {
	ios::sync_with_stdio(false);
	// float tbegin = clock();
	srand(42);

#ifdef DEBUG
	freopen("input.txt", "r", stdin);
#else
	if (TASKNAME != "") {
		freopen(TASKNAME ".in", "r", stdin);
		freopen(TASKNAME ".out", "w", stdout);
	}
#endif

	int n;
	scanf("%d\n", &n);

	int last = -1;
	vector<pair<int, int> > ans;

	for (int i = 0; i < n; i++) {
		int a;
		scanf("%d", &a);

		if (cnt.find(a) != cnt.end()) {
			ans.pb(mp(last + 1, i));
			last = i;
			cnt.clear();
		} else {
			cnt.insert(a);
		}
	}

	if (last == -1) {
		printf("-1\n");
	} else {
		printf("%d\n", sz(ans));

		if (last != n - 1) {
			ans.rbegin()->second = n - 1;
		}

		for (int i = 0; i < sz(ans); i++) {
			pair<int, int> it = ans[i];
			printf("%d %d\n", it.first + 1, it.second + 1);
		}
	}

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}