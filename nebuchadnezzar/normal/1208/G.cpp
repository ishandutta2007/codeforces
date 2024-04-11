// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

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

const int MAXN = 1e6 + 5;

int sieve[MAXN];

int weight(int num) {
	if (num == 3) {
		return 3;
	}
	if (num == 4) {
		return 3;
	}
	set<int> primes;
	int mem = num;
	while (sieve[num] != 0) {
		primes.insert(sieve[num]);
		num /= sieve[num];
	}
	primes.insert(num);
	// cerr << "weight " << mem << endl;
	for (int p : primes) {
		// cerr << p << endl;
		mem = mem / p * (p - 1);
	}
	return mem;
}

void solve() {
	// for (int i = 2; i < MAXN; ++i) {
	// 	if (sieve[i] == 0) {
	// 		for (int j = i * 2; j < MAXN; j += i) {
	// 			sieve[j] = i;
	// 		}
	// 	}
	// }
	int n, k;
	cin >> n >> k;
	if (n == 3) {
		cout << "3\n";
		return;
	}
	set<pii> qu;
	vector<bool> used(n + 1);
	// vector<vector<int>> next(n + 1);
	vector<int> cnt_prev(n + 1);
	
	qu.insert({weight(4), 4});

	vector<int> prarr;

	for (int i = 2; i <= n; ++i) {
		if (sieve[i] == 0) {
			prarr.push_back(i);
			if (i > 2) {
				qu.insert({weight(i), i});
			}
			for (int j = i * 2; j <= n; j += i) {
				sieve[j] = i;
			}
		}
	}
	// cerr << clock() << endl;

	for (int i = 3; i <= n; ++i) {
		set<int> pr;
		int tmp = i;
		while (sieve[tmp]) {
			pr.insert(sieve[tmp]);
			tmp /= sieve[tmp];
		}
		pr.insert(tmp);
		cnt_prev[i] = szof(pr);
	}

	// for (int num : next[2]) {
	// 	next[4].push_back(num);
	// }

	// sort(next[4].begin(), next[4].end());
	// next[4].erase(unique(next[4].begin(), next[4].end()), next[4].end());

	ll ans = 0;

	fill(used.begin(), used.end(), 0);


	for (int i = 0; i < k; ++i) {
		// cerr << qu.begin()->ff << " " << qu.begin()->ss << endl;
		ans += qu.begin()->ff;
		int num = qu.begin()->ss;
		qu.erase(qu.begin());

		for (int p : prarr) {
			ll to = p * num;
			if (to > n) {
				break;
			}
			--cnt_prev[to];
			if (cnt_prev[to] == 0) {
				qu.insert({weight(to), to});
			}
		}

		if (num == 4) {
			for (int p : prarr) {
				ll to = p * 2;
				if (to == 4) {
					continue;
				}
				if (to > n) {
					break;
				}
				--cnt_prev[to];
				if (cnt_prev[to] == 0) {
					qu.insert({weight(to), to});
				}
			}
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