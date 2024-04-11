// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
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

using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
template <typename K, typename V> using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

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
	string s;
	cin >> s;
	if (*min_element(s.begin(), s.end()) == *max_element(s.begin(), s.end())) {
		cout << s << "\n";
		return;
	}

	vector<int> cnt(26);
	for (char c : s) {
		cnt[c - 'a']++;
	}

	for (int i = 0; i < 26; ++i) {
		if (cnt[i] == 1) {
			string ans;
			ans += 'a' + i;
			cnt[i]--;
			for (int j = 0; j < 26; ++j) {
				while (cnt[j]) {
					ans += 'a' + j;
					--cnt[j];
				}
			}

			cout << ans << "\n";
			return;
		}
	}

	char a1 = *min_element(s.begin(), s.end());
	cnt[a1 - 'a']--;
	char a2;
	for (a2 = 'a'; a2 <= 'z'; ++a2) {
		if (!cnt[a2 - 'a']) {
			continue;
		}
		--cnt[a2 - 'a'];

		if (a1 == a2) {
			if (cnt[a2 - 'a'] <= (szof(s) - 2) / 2) {
				break;
			}
		} else {
			break;
		}

		++cnt[a2 - 'a'];
	}

	string ans;
	ans += a1;
	ans += a2;

	for (int i = 2; i < szof(s); ++i) {
		// for (int num : cnt) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
		// cerr << ans << endl;
		char c;
		for (c = 'a'; c <= 'z'; ++c) {
			if (!cnt[c - 'a']) {
				continue;
			}

			if (ans.back() == a1 && c == a2) {
				continue;
			}

			--cnt[c - 'a'];

			if (a1 == a2) {
				if (c == a1) {
					if (cnt[a1 - 'a'] <= (szof(s) - i - 1) / 2) {
						break;
					}
				} else {
					// cerr << "here" << endl;
					if (cnt[a1 - 'a'] <= (szof(s) - i) / 2) {
						break;
					}
				}
			} else {
				if (c == a1) {
					if (cnt[a2 - 'a'] == 0 || cnt[a1 - 'a'] + cnt[a2 - 'a'] < szof(s) - i - 1) {
						break;
					}
				} else if (c == a2) {
					break;
				} else {
					break;
				}
			}

			++cnt[c - 'a'];
		}

		ans += c;
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}