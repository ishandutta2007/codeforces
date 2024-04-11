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


void solve() {
	//int n;
	//cin >> n;
	vector<vector<int>> ans;
	string s;
	cin >> s;
	int n = szof(s);
	set<int> ones, zeroes;
	for (int i = 0; i < n; ++i) {
		if (s[i] == '1') {
			ones.insert(i);
		} else {
			zeroes.insert(i);
		}
	}

	while (szof(ones) || szof(zeroes)) {
		if (!szof(zeroes)) {
			cout << "-1\n";
			return;
		}
		int pos = *zeroes.begin();
		zeroes.erase(pos);
		ans.push_back({pos});
		while (ones.lower_bound(pos) != ones.end()) {
			pos = *ones.lower_bound(pos);
			ones.erase(pos);
			ans.back().push_back(pos);
			if (zeroes.lower_bound(pos) == zeroes.end()) {
				cout << "-1\n";
				return;
			}
			pos = *zeroes.lower_bound(pos);
			zeroes.erase(pos);
			ans.back().push_back(pos);
		}
	}

	cout << szof(ans) << "\n";
	for (auto& v : ans) {
		cout << szof(v) << " ";
		for (int num : v) {
			cout << num + 1 << " ";
		}
		cout << "\n";
	}
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