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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

int P, MOD;

bool is_prime(int num) {
	for (int j = 2; j * j <= num; ++j) {
		if (num % j == 0) {
			return false;
		}
	}
	return true;
}

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
	MOD = rnd(INF, INF + 500);
	while (!is_prime(MOD)) {
		++MOD;
	}
	P = rnd(300, 600);
	while (!is_prime(P)) {
		++P;
	}
	// cerr << P << " " << MOD << endl;
	string s, t;
	cin >> s >> t;
	vector<int> phash = {0};
	for (char c : t) {
		phash.push_back(sum(mult(phash.back(), P), c));
	}

	vector<int> powsp = {1};
	for (int i = 0; i < szof(t); ++i) {
		powsp.push_back(mult(powsp.back(), P));
	}

	function<int(int, int)> get_hash = [&](int l, int r) {
		return sum(phash[r], MOD - mult(phash[l], powsp[r - l]));
	};

	int n0 = 0, n1 = 0;
	for (char c : s) {
		if (c == '0') {
			++n0;
		} else {
			++n1;
		}
	}
	if (n0 < n1) {
		swap(n0, n1);
		for (char& c : s) {
			if (c == '0') {
				c = '1';
			} else {
				c = '0';
			}
		}
	}

	int ans = 0;
	for (int l0 = 1; l0 * n0 < szof(t); ++l0) {
		if ((szof(t) - l0 * n0) % n1) {
			continue;
		}
		int l1 = (szof(t) - l0 * n0) / n1;
		int pos = 0;
		int h0 = 0, h1 = 0;
		bool fl0 = false, fl1 = false;
		bool flag = true;
		for (int i = 0; i < szof(s); ++i) {
			if (s[i] == '0') {
				int h = get_hash(pos, pos + l0);
				if (!fl0) {
					fl0 = true;
					h0 = h;
				} else {
					if (h0 != h) {
						flag = false;
						break;
					}
				}
				pos += l0;
			} else {
				int h = get_hash(pos, pos + l1);
				if (!fl1) {
					fl1 = true;
					h1 = h;
				} else {
					if (h1 != h) {
						flag = false;
						break;
					}
				}
				pos += l1;
			}
		}

		if (flag && h0 != h1) {
			++ans;
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