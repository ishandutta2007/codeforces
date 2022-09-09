// Created by Nikolay Budin

#ifdef LOCAL
#  define _GLIBCXX_DEBUG
#else
#  define cerr __get_ce
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

bool is_prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int MOD;
const int P = 239;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

void solve() {
	MOD = rnd(INF / 2, INF);
	while (!is_prime(MOD)) {
		++MOD;
	}
	string s;
	cin >> s;

	vector<int> pref_h = {0}, pref_rh = {0};
	for (char c : s) {
		pref_h.push_back(sum(mult(pref_h.back(), P), c));
	}
	for (int i = szof(s) - 1; i >= 0; --i) {
		char c = s[i];
		pref_rh.push_back(sum(mult(pref_rh.back(), P), '0' + 1 - (c - '0')));
	}

	vector<int> arrp = {1};
	for (int i = 0; i < szof(s) + 5; ++i) {
		arrp.push_back(mult(arrp.back(), P));
	}

	auto get_hash = [&](vector<int> const& arrh, int l, int r) {
		return sum(arrh[r], MOD - mult(arrh[l], arrp[r - l]));
	};

	vector<pii> segs;

	for (int i = 0; i < szof(s); ++i) {
		for (int j = 1; j < 20 && 0 <= i - j && i + j < szof(s); ++j) {
			if (s[i - j] == s[i] && s[i] == s[i + j]) {
				segs.push_back({i - j, i + j + 1});
				break;
			}
		}
	}

	sort(segs.begin(), segs.end());

	multiset<int> ends;
	for (auto p : segs) {
		ends.insert(p.ss);
	}

	ll ans = 0;
	int cnt = 0;

	for (int i = 0; i < szof(s); ++i) {
		if (!szof(ends)) {
			break;
		}
		ans += szof(s) - *ends.begin() + 1;

		while (cnt < szof(segs) && segs[cnt].ff == i) {
			ends.erase(ends.find(segs[cnt].ss));
			++cnt;
		}
	}

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}