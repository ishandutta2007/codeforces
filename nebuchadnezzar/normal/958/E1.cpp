#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

int cross(pii p1, pii p2, pii p3) {
	return (p1.ff - p2.ff) * (p3.ss - p2.ss) - (p1.ss - p2.ss) * (p3.ff - p2.ff);
}

int sign(int num) {
	return num < 0 ? -1 : num > 0 ? 1 : 0;
}

bool intersects(pii p1, pii p2, pii p3, pii p4) {
	return sign(cross(p3, p2, p1)) * sign(cross(p1, p2, p4)) > 1 && sign(cross(p1, p3, p4)) * sign(cross(p4, p3, p2)) > 1;
}

void solve() {
	int r, b;
	cin >> r >> b;
	if (r != b) {
		cout << "No\n";
		return;
	}

	vector<pii> arr1, arr2;
	for (int i = 0; i < r; ++i) {
		int x, y;
		cin >> x >> y;
		arr1.push_back({x, y});
	}
	for (int i = 0; i < r; ++i) {
		int x, y;
		cin >> x >> y;
		arr2.push_back({x, y});
	}

	vector<int> order(r);
	iota(order.begin(), order.end(), 0);
	do {
		bool flag = true;
		for (int i = 0; i < r; ++i) {
			for (int j = 0; j < r; ++j) {
				if (intersects(arr1[i], arr2[order[i]], arr1[j], arr2[order[j]])) {
					flag = false;
					break;
				}
			}
			if (!flag) {
				break;
			}
		}
		if (flag) {
			cout << "Yes\n";
			return;
		}
	} while (next_permutation(order.begin(), order.end()));
	cout << "No\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}