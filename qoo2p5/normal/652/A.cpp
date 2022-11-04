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

	int h1, h2;
	cin >> h1 >> h2;
	int a, b;
	cin >> a >> b;

	int h = h1;
	int cur = 15;
	int day = 0;

	while (day < 1000000) {
		if (11 <= cur && cur <= 22) {
			h += a;
		} else {
			h -= b;
		}

		if (h >= h2) {
			cout << day << "\n";
			return 0;
		}

		if (a <= b && day > 1) {
			cout << "-1\n";
			return 0;
		}

		cur++;
		if (cur >= 24) {
			cur -= 24;
			day++;
		}
	}

	cout << "-1\n";

#ifdef DEBUG
	cerr << "TIME ELAPSED: " << (clock() - tbegin) / CLOCKS_PER_SEC << "\n";
#endif

	return 0;
}