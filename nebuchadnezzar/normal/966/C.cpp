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
	int n;
	cin >> n;
	vector<ll> inp;
	for (int i = 0; i < n; ++i) {
		ll num;
		cin >> num;
		inp.push_back(num);
	}

	vector<int> order;
	for (int i = 59; i >= 0; --i) {
		vector<int> next;
		vector<int> add;
		for (int j = 0; j < n; ++j) {
			if ((inp[j] >> i) == 1) {
				add.push_back(j);
			}
		}
		/*
		cerr << i << endl;
		for (int ind : add) {
			cerr << inp[ind] << " ";
		}
		cerr << endl;
		*/
		int cur = 0;
		if (szof(add)) {
			next.push_back(add.back());
			add.pop_back();
			cur = 1;
		}

		for (int num : order) {
			next.push_back(num);
			if (inp[num] & (1ll << i)) {
				cur ^= 1;
			}
			//cerr << inp[num] << " " << cur << endl;
			if (!cur && szof(add)) {
				next.push_back(add.back());
				add.pop_back();
				cur ^= 1;
			}
		}

		if (szof(add)) {
			cout << "No\n";
			return;
		}

		order = next;
	}

	assert(szof(order) == n);

	cout << "Yes\n";
	ll cur = 0;
	for (int ind : order) {
		cout << inp[ind] << " ";
		ll next = cur ^ inp[ind];
		//cerr << next << endl;
		assert(next > cur);
		/*
		string s;
		ll tmp = inp[ind];
		while (tmp) {
			s += '0' + tmp % 2;
			tmp >>= 1;
		}
		reverse(s.begin(), s.end());
		cerr << s << endl;
		*/
		cur = next;
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