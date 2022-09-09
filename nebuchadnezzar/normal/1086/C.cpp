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
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

string get_ans(vector<int> const& ans) {
	vector<bool> used(szof(ans));
	for (int i = 0; i < szof(ans); ++i) {
		if (ans[i] != -1) {
			used[ans[i]] = true;
		}
	}

	string ret = "";
	int cnt = 0;
	for (int i = 0; i < szof(ans); ++i) {
		if (ans[i] != -1) {
			ret += ans[i] + 'a';
		} else {
			while (used[cnt]) {
				++cnt;
			}
			ret += cnt + 'a';
			used[cnt] = true;
		}
	}

	return ret;
}

void solve() {
	int k;
	cin >> k;
	string s, a, b;
	cin >> s >> a >> b;
	vector<int> ans(k, -1);
	vector<bool> used(k);
	int i;
	for (i = 0; i < szof(s); ++i) {
		if (a[i] < b[i]) {
			break;
		}
		int was = s[i] - 'a';
		if (ans[was] == -1) {
			int any = -1;
			int cnt = 0;
			for (char c = a[i]; c <= b[i]; ++c) {
				if (!used[c - 'a']) {
					++cnt;
					any = c - 'a';
					if (a[i] < c && c < b[i]) {
						ans[was] = c - 'a';
						cout << "YES\n";
						cout << get_ans(ans) << "\n";
						return;
					}
				}
			}

			if (cnt == 0) {
				cout << "NO\n";
				return;
			}

			if (cnt > 1) {
				break;
			}

			used[any] = true;
			ans[was] = any;
		} else {
			char c = ans[was] + 'a';
			if (c < a[i] || b[i] < c) {
				cout << "NO\n";
				return;
			}
		}
	}

	if (i == szof(s)) {
		cout << "YES\n";
		cout << get_ans(ans) << "\n";
		return;
	}

	set<int> vars;

	if (ans[s[i] - 'a'] == -1) {
		for (char c = a[i]; c <= b[i]; ++c) {
			if (!used[c - 'a']) {
				vars.insert(c - 'a');
				if (a[i] < c && c < b[i]) {
					ans[s[i] - 'a'] = c - 'a';
					cout << "YES\n";
					cout << get_ans(ans) << "\n";
					return;
				}
			}
		}
	} else {
		int to = ans[s[i] - 'a'];
		if (to + 'a' < a[i] || b[i] < to + 'a') {
			cout << "NO\n";
			return;
		}
		vars.insert(to);
		if (a[i] < to + 'a' && to + 'a' < b[i]) {
			cout << "YES\n";
			cout << get_ans(ans) << "\n";
			return;
		}
	}

	auto mem = ans;
	auto mem_used = used;
	auto mem_i = i;
	if (vars.count(a[i] - 'a')) {
		ans[s[i] - 'a'] = a[i] - 'a';
		used[a[i] - 'a'] = true;
		++i;
		bool ok = true;
		for (; i < szof(s); ++i) {
			int was = s[i] - 'a';
			if (ans[was] == -1) {
				int any = -1;
				int cnt = 0;
				for (char c = a[i]; c < 'a' + k; ++c) {
					if (!used[c - 'a']) {
						++cnt;
						any = c - 'a';
						if (a[i] < c) {
							ans[was] = c - 'a';
							cout << "YES\n";
							cout << get_ans(ans) << "\n";
							return;
						}
					}
				}

				if (cnt == 0) {
					ok = false;
					break;
				}

				assert(any == a[i] - 'a');
				used[any] = true;
				ans[was] = any;
			} else {
				char c = ans[was] + 'a';
				if (c > a[i]) {
					cout << "YES\n";
					cout << get_ans(ans) << "\n";
					return;
				}
				if (c < a[i]) {
					ok = false;
					break;
				}
			}
		}

		if (ok) {
			cout << "YES\n";
			cout << get_ans(ans) << "\n";
			return;
		}
		ans = mem;
		used = mem_used;
		i = mem_i;
	}

	if (vars.count(b[i] - 'a')) {
		ans[s[i] - 'a'] = b[i] - 'a';
		used[b[i] - 'a'] = true;
		++i;
		bool ok = true;
		for (; i < szof(s); ++i) {
			int was = s[i] - 'a';
			if (ans[was] == -1) {
				int any = -1;
				int cnt = 0;
				for (char c = 'a'; c <= b[i]; ++c) {
					// cerr << c << " " << szof(used) << endl;
					if (!used[c - 'a']) {
						++cnt;
						any = c - 'a';
						if (c < b[i]) {
							ans[was] = c - 'a';
							cout << "YES\n";
							cout << get_ans(ans) << "\n";
							return;
						}
					}
				}

				if (cnt == 0) {
					ok = false;
					break;
				}

				assert(any == b[i] - 'a');
				used[any] = true;
				ans[was] = any;
			} else {
				char c = ans[was] + 'a';
				if (c < b[i]) {
					cout << "YES\n";
					cout << get_ans(ans) << "\n";
					return;
				}
				if (c > b[i]) {
					ok = false;
					break;
				}
			}
		}

		if (ok) {
			cout << "YES\n";
			cout << get_ans(ans) << "\n";
			return;
		}
	}

	cout << "NO\n";
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