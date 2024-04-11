#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }


void solve() {
	int n;
	cin >> n;
	vector<pll> inp;
	map<pll, int> have;
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		ll a = 0, b = 0, c = 0;
		int j;
		for (j = 1; s[j] != '+'; ++j) {
			a = a * 10 + s[j] - '0';
		}
		++j;
		for (; s[j] != ')'; ++j) {
			b = b * 10 + s[j] - '0';
		}
		j += 2;
		for (; j < szof(s); ++j) {
			c = c * 10 + s[j] - '0';
		}

		ll p = a + b;
		ll q = c;
		ll tmp = __gcd(p, q);
		p /= tmp;
		q /= tmp;
		have[{p, q}]++;
		inp.push_back({p, q});
	}

	for (int i = 0; i < n; ++i) {
		cout << have[inp[i]] << " ";
	}
	cout << "\n";
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