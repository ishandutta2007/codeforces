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

const int P = 239, MOD = 1e9 + 7;

int get_h(string s) {
	int h = 0;
	//reverse(s.begin(), s.end());
	for (char c : s) {
		h = ((ll) h * P + c) % MOD;
	}
	return h;
}

vector<int> arrh, arrp;

int get_h(int l, int r) {
	int tmp = (arrh[r] - (ll) arrh[l] * arrp[r - l]) % MOD;
	if (tmp < 0) {
		tmp += MOD;
	}
	return tmp;
}

void solve() {
	string s;
	cin >> s;
	int n = szof(s);

	arrh = {0};
	arrp = {1};
	for (char c : s) {
		arrp.push_back((ll) arrp.back() * P % MOD);
		arrh.push_back(((ll) arrh.back() * P + c) % MOD);
	}

	int q;
	cin >> q;
	const int S = 300;
	vector<int> ans(q);
	vector<int> lens;
	vector<vector<pii>> ask(S);
	for (int i = 0; i < q; ++i) {
		//cerr << i << endl;
		int k;
		cin >> k;
		lens.push_back(k);
		string m;
		cin >> m;
		if (szof(m) < S) {
			ask[szof(m)].push_back({get_h(m), i});
		} else {
			int h = get_h(m);
			vector<int> posses;
			for (int j = 0; j + szof(m) <= szof(s); ++j) {
				if (get_h(j, j + szof(m)) == h) {
					posses.push_back(j);
				}	
			}
			if (szof(posses) < k) {
				ans[i] = -1;
			} else {
				ans[i] = INF;
				for (int j = 0; j + k <= szof(posses); ++j) {
					ans[i] = min(ans[i], posses[j + k - 1] - posses[j] + szof(m));
				}
			}
		}
	}

	for (int i = 1; i < S; ++i) {
		//cerr << "i: " << i << endl;
		map<int, vector<int>> intr;
		for (auto p : ask[i]) {
			//cerr << "intr " << p.ff << endl;
			intr[p.ff] = {};
		}
		for (int j = 0; j + i <= szof(s); ++j) {
			int tmp = get_h(j, j + i);
			//cerr << tmp << endl;
			if (intr.count(tmp)) {
				intr[tmp].push_back(j);
			}
		}

		for (auto p : ask[i]) {
			//cerr << p.ss << endl;
			auto& posses = intr[p.ff];
			int k = lens[p.ss];
			if (szof(posses) < k) {
				ans[p.ss] = -1;
			} else {
				ans[p.ss] = INF;
				for (int j = 0; j + k <= szof(posses); ++j) {
					ans[p.ss] = min(ans[p.ss], posses[j + k - 1] - posses[j] + i);
				}
			}
		}
	}

	for (auto num : ans) {
		cout << num << "\n";
	}
}


int main() {
	//freopen("in", "r", stdin);
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