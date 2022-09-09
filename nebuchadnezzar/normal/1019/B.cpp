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

int n;
map<int, int> mem;

int ask(int pos) {
	pos %= n;
	if (mem.count(pos)) {
		return mem[pos];
	}
	cout << "? " << pos + 1 << endl;
	cin >> mem[pos];
	return mem[pos];
}

int sign(int num) {
	return num < 0 ? -1 : (num > 0 ? 1 : 0);
}

void solve() {
	cin >> n;
	if (n / 2 % 2 == 1) {
		cout << "! -1\n";
		return;
	}
	int l = 0, r = n / 2;
	if (ask(l) == ask(r)) {
		cout << "! 1\n";
		return;
	}
	while (r - l > 1) {
		int mid = (l + r) / 2;
		int vall = ask(l) - ask(l + n / 2);
		//int valr = ask(r) - ask(r + n / 2);
		int valm = ask(mid) - ask(mid + n / 2);
		if (valm == 0) {
			cout << "! " << mid + 1 << "\n";
			return;
		}
		if (sign(valm) == sign(vall)) {
			l = mid;
		} else {
			r = mid;
		}
	}
	assert(false);
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