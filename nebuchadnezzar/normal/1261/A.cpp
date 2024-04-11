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


void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	string t = "";
	for (int i = 0; i < k - 1; ++i) {
		t += "()";
	}
	t += string(n / 2 - k + 1, '(') + string(n / 2 - k + 1, ')');
	assert(szof(s) == szof(t));

	vector<pii> ans;
	for (int i = 0; i < n; ++i) {
		if (s[i] == t[i]) {
			continue;
		}
		for (int j = i + 1; j < n; ++j) {
			if (s[j] == t[i]) {
				ans.push_back({i, j});
				reverse(s.begin() + i, s.begin() + j + 1);
				break;
			}
		}
	}
	cout << szof(ans) << "\n";
	for (auto p : ans) {
		cout << p.ff + 1 << " " << p.ss + 1 << "\n";
	}
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}