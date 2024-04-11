#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#  define _GLIBCXX_DEBUG_PEDANTIC
#endif

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
	string s;
	cin >> s;
	pair<string, int> a = {"", -1}, b = {"", -1};
	int cnt = 0;
	map<int, pii> from;
	for (char c : s) {
		a.ff += c;
		reverse(b.ff.begin(), b.ff.end());
		b.ff += c;
		pair<string, int> na, nb;
		if (a.ff < b.ff) {
			from[cnt] = {a.ss, 0};
			na = {a.ff, cnt};
			++cnt;
		} else {
			from[cnt] = {b.ss, 1};
			na = {b.ff, cnt};
			++cnt;
		}
		a.ff.pop_back();
		reverse(a.ff.begin(), a.ff.end());
		a.ff.push_back(c);;
		reverse(a.ff.begin(), a.ff.end());
		b.ff.pop_back();
		reverse(b.ff.begin(), b.ff.end());
		b.ff.push_back(c);
		reverse(b.ff.begin(), b.ff.end());
		if (a.ff < b.ff) {
			from[cnt] = {a.ss, 1};
			nb = {a.ff, cnt};
			++cnt;
		} else {
			from[cnt] = {b.ss, 0};
			nb = {b.ff, cnt};
			++cnt;
		}
		reverse(nb.ff.begin(), nb.ff.end());
		swap(a, na);
		swap(b, nb);
	}

	reverse(b.ff.begin(), b.ff.end());

	int cur = -1;
	vector<int> ans;
	if (a.ff < b.ff) {
		ans = {0};
		cur = a.ss;
		
	} else {
		ans = {1};
		cur = b.ss;
	}

	while (cur != -1) {
		ans.push_back(from[cur].ss);
		cur = from[cur].ff;
	}

	ans.pop_back();

	reverse(ans.begin(), ans.end());
	for (int num : ans) {
		cout << num << " ";
	}
	cout << "\n";

	// cout << min(a, b) << "\n";
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