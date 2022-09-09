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

vector<vector<char>> gen_box(string s) {
	vector<vector<char>> ret(3, vector<char>(szof(s) + 4, ' '));
	fill(ret[0].begin(), ret[0].end(), '-');
	fill(ret[2].begin(), ret[2].end(), '-');
	for (int i = 0; i < 3; ++i) {
		ret[i].front() = ret[i].back() = '+';
	}
	copy(s.begin(), s.end(), ret[1].begin() + 2);
	return ret;
}

vector<vector<char>> add_plus(vector<vector<char>> q) {
	int n = szof(q), m = szof(q[0]);
	vector<vector<char>> ret(n + 2, vector<char>(m + 6, ' '));
	fill(ret[1].begin(), ret[1].end(), '-');
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ret[i][j + 3] = q[i][j];
		}
	}

	for (int i = 2; i < n + 1; ++i) {
		ret[i].front() = ret[i].back() = '|';
	}

	fill(ret.back().begin(), ret.back().end(), '-');
	ret[1][0] = ret[1].back() = ret.back()[0] = ret.back().back() = '+';
	ret[1][2] = ret[1][m + 4] = '>';
	ret.back()[1] = '<';
	return ret;
}

vector<vector<char>> add_question(vector<vector<char>> q) {
	int n = szof(q), m = szof(q[0]);
	vector<vector<char>> ret(n + 3, vector<char>(m + 6, ' '));
	for (int i = 1; i <= 4; ++i) {
		ret[i].front() = ret[i].back() = '|';
	}
	fill(ret[4].begin(), ret[4].end(), '-');
	fill(ret[1].begin(), ret[1].end(), '-');
	ret[4][2] = ret[4][m + 4] = ret[1][m + 4] = '>';
	ret[1][0] = ret[1].back() = ret[4][0] = ret[4].back() = '+';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ret[i + 3][j + 3] = q[i][j];
		}
	}

	

	return ret;
}

vector<vector<char>> add_asterisk(vector<vector<char>> q) {
	int n = szof(q), m = szof(q[0]);
	vector<vector<char>> ret(n + 5, vector<char>(m + 6, ' '));
	for (int i = 1; i < n + 5; ++i) {
		ret[i].front() = ret[i].back() = '|';
	}
	fill(ret[1].begin(), ret[1].end(), '-');
	fill(ret[4].begin(), ret[4].end(), '-');
	fill(ret[n + 4].begin(), ret[n + 4].end(), '-');
	ret[4][2] = ret[4][m + 4] = ret[1][m + 4] = '>';
	ret[1][0] = ret[1].back() = ret[4][0] = ret[4].back() = '+';
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			ret[i + 3][j + 3] = q[i][j];
		}
	}

	

	ret.back()[0] = ret.back().back() = '+';
	ret.back()[1] = '<';

	return ret;
}

vector<vector<char>> gen_or_comb(vector<vector<vector<char>>> const& arr) {
	int n = 0, m = 0;
	for (auto& q : arr) {
		n += szof(q) + 1;
		m = max(m, szof(q[0]));
	}

	n--;
	m += 6;

	vector<vector<char>> ret(n, vector<char>(m, ' '));
	int pos = 0;
	for (int i = 0; i < szof(arr); ++i) {
		int cn = szof(arr[i]);
		int cm = szof(arr[i][0]);
		fill(ret[pos + 1].begin(), ret[pos + 1].end(), '-');
		for (int x = 0; x < cn; ++x) {
			for (int y = 0; y < cm; ++y) {
				ret[pos + x][y + 3] = arr[i][x][y];
			}
		}
		ret[pos + 1][0] = ret[pos + 1].back() = '+';
		ret[pos + 1][2] = ret[pos + 1][m - 2] = '>';

		if (i == szof(arr) - 1) {
			for (int j = 1; j < pos + 1; ++j) {
				if (ret[j][0] == ' ') {
					ret[j][0] = '|';
				}
				if (ret[j].back() == ' ') {
					ret[j].back() = '|';
				}
			}
		}

		pos += cn + 1;
	}

	return ret;
}

vector<vector<char>> gen_concat_comb(vector<vector<vector<char>>> const& arr) {
	int n = 0, m = 0;
	for (auto& q : arr) {
		n = max(n, szof(q));
		m += szof(q[0]) + 2;
	}

	m -= 2;

	vector<vector<char>> ret(n, vector<char>(m, ' '));
	int pos = 0;
	for (int i = 0; i < szof(arr); ++i) {
		int cn = szof(arr[i]);
		int cm = szof(arr[i][0]);
		for (int x = 0; x < cn; ++x) {
			for (int y = 0; y < cm; ++y) {
				ret[x][pos + y] = arr[i][x][y];
			}
		}
		if (i < szof(arr) - 1) {
			ret[1][pos + cm] = '-';
			ret[1][pos + cm + 1] = '>';
		}

		pos += cm + 2;
	}

	return ret;
}

void solve() {
	string s;
	cin >> s;
	int pos = 0;

	function<vector<vector<char>>()> parse_unary;

	function<vector<vector<char>>(int)> parse_binary = [&](int lvl) {
		if (lvl == 2) {
			return parse_unary();
		}

		vector<vector<vector<char>>> res = {parse_binary(lvl + 1)};
		while (pos < szof(s)) {
			if (s[pos] == ')' || (lvl == 1 && s[pos] == '|')) {
				break;
			}

			if (lvl == 0) {
				++pos;
			}

			res.push_back(parse_binary(lvl + 1));
		}

		if (szof(res) == 1) {
			return res[0];
		}

		if (lvl == 0) {
			return gen_or_comb(res);
		}
		return gen_concat_comb(res);
	};

	parse_unary = [&]() {
		vector<vector<char>> res;
		if (s[pos] == '(') {
			++pos;
			res = parse_binary(0);
			assert(s[pos] == ')');
			++pos;
		} else {
			assert('A' <= s[pos] && s[pos] <= 'Z');
			string q = "";
			while (pos < szof(s) && ('A' <= s[pos] && s[pos] <= 'Z')) {
				q += s[pos++];
			}
			if (pos < szof(s) && (s[pos] == '+' || s[pos] == '*' || s[pos] == '?') && szof(q) > 1) {
				q.pop_back();
				--pos;
			}
			res =  gen_box(q);
		}

		while (pos < szof(s) && (s[pos] == '+' || s[pos] == '?' || s[pos] == '*')) {
			if (s[pos] == '+') {
				res = add_plus(res);
			} else if (s[pos] == '?') {
				res = add_question(res);
			} else if (s[pos] == '*') {
				res = add_asterisk(res);
			}
			++pos;
		}

		return res;
	};

	auto res = parse_binary(0);
	int n = szof(res), m = szof(res[0]) + 6;
	vector<vector<char>> ans(n, vector<char>(m, ' '));
	for (int i = 0; i < szof(res); ++i) {
		for (int j = 0; j < szof(res[i]); ++j) {
			ans[i][j + 3] = res[i][j];
		}
	}

	ans[1][0] = 'S';
	ans[1][1] = ans[1][m - 3] = '-';
	ans[1][2] = ans[1][m - 2] = '>';
	ans[1][m - 1] = 'F';

	cout << szof(ans) << " " << szof(ans[0]) << "\n";
	for (int i = 0; i < szof(ans); ++i) {
		for (int j = 0; j < szof(ans[i]); ++j) {
			cout << ans[i][j];
		}
		cout << "\n";
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}