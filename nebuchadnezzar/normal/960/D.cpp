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

int get_level(ll x) {
	ll cur = 1;
	int ret = 0;
	while (cur < x) {
		cur = cur * 2 + 1;
		++ret;
	}
	return ret;
}

void solve() {
	int q;
	cin >> q;
	vector<ll> shift1(100), shift2(100);
	for (int i = 0; i < q; ++i) {
		int t;
		ll x;
		cin >> t >> x;
		int lvl = get_level(x);
		if (t == 1) {
			ll k;
			cin >> k;

			shift1[lvl] = (shift1[lvl] + k) % (1ll << lvl);
			if (shift1[lvl] < 0) {
				shift1[lvl] += 1ll << lvl;
			}
		} else if (t == 2) {
			ll k;
			cin >> k;

			shift2[lvl] = (shift2[lvl] + k) % (1ll << lvl);
			if (shift2[lvl] < 0) {
				shift2[lvl] += 1ll << lvl;
			}
		} else {
			ll cur = 1;
			ll first = 1, last = 1;
			vector<ll> ans;
			int l = 0;
			ll shift = 0;
			while (last < x) {
				shift = (shift + shift2[l] * (1ll << (lvl - l))) % (1ll << lvl);
				first = first * 2;
				last = last * 2 + 1;
				++l;
			}
			//cerr << shift << endl;

			shift = (shift + shift1[lvl] + shift2[lvl]) % (1ll << lvl);
			cur = (x - first + shift) % (1ll << lvl) + first;
			shift = ((shift - shift1[lvl]) % (1ll << lvl) + (1ll << lvl)) % (1ll << lvl);

			l = lvl;
			while (cur) {
				//cerr << shift << endl;
				ll cur_shift = (shift + shift1[l]) % (1ll << l);
				ll val = ((cur - first - cur_shift) % (1ll << l) + (1ll << l)) % (1ll << l) + first;
				ans.push_back(val);

				assert((((shift - shift2[l]) % (1ll << l)) + (1ll << l)) % (1ll << l) % 2 == 0);
				shift = (((shift - shift2[l]) % (1ll << l)) + (1ll << l)) % (1ll << l) / 2;
				first /= 2;
				last /= 2;
				--l;
				cur /= 2;
			}

			for (auto num : ans) {
				cout << num << " ";
			}
			cout << "\n";
		}
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