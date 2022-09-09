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
// #  define cerr __get_ce
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

int N;
int cnt;
vector<int> arr;

int ask(vector<int> const& left, vector<int> const& right) {
#ifdef TEST
	int a = 0;
	for (int ind : left) {
		assert(count(left.begin(), left.end(), ind) == 1);
		a += arr[ind];
	}
	int b = 0;
	for (int ind : right) {
		assert(find(left.begin(), left.end(), ind) == left.end());
		assert(count(right.begin(), right.end(), ind) == 1);
		b += arr[ind];
	}
	assert(abs(a * b) <= N);
	++cnt;
	return a * b;
#else
	cout << "? " << szof(left) << " " << szof(right) << "\n";
	for (int ind : left) {
		cout << ind + 1 << " ";
	}
	cout << "\n";
	for (int ind : right) {
		cout << ind + 1 << " ";
	}
	cout << endl;
	int res;
	cin >> res;
	return res;
#endif
}

void answer(vector<int> ans) {
#ifdef TEST
	sort(ans.begin(), ans.end());
	vector<int> correct;
	for (int i = 0; i < N; ++i) {
		if (!arr[i]) {
			correct.push_back(i);
		}
	}
	if (ans != correct) {
		cerr << "ans:" << endl;
		for (int ind : ans) {
			cerr << ind << " ";
		}
		cerr << endl;
		cerr << "correct:" << endl;
		for (int ind : correct) {
			cerr << ind << " ";
		}
		cerr << endl;
	}
	assert(ans == correct);
#else
	cout << "! " << szof(ans) << " ";
	for (int ind : ans) {
		cout << ind + 1 << " ";
	}
	cout << endl;
#endif
}

void solve(int n) {
	vector<int> ans;
	for (int i = 0; i < n; ++i) {
		vector<int> left = {i};
		vector<int> right;
		for (int j = i + 1; j < n; ++j) {
			right.push_back(j);
		}
		int res = ask(left, right);
		if (res) {
			int sum = 0;
			for (int j = i + 1; j < n - 1; ++j) {
				int val = ask({i}, {j});
				if (val == 0) {
					ans.push_back(j);
				}
				sum += val;
			}

			if (abs(sum) == abs(res)) {
				ans.push_back(n - 1);
			}

			int l = 0, r = i + 1;
			while (r - l > 1) {
				int mid = (l + r) / 2;
				left.clear();
				for (int j = 0; j < mid; ++j) {
					left.push_back(j);
				}
				if (ask(left, {i})) {
					r = mid;
				} else {
					l = mid;
				}
			}

			for (int j = 0; j < i; ++j) {
				if (j != l) {
					ans.push_back(j);
				}
			}

			break;
		}
	}

	answer(ans);
}

void stress() {
	for (int test = 1; test <= 100000; ++test) {
		cerr << "test #" << test << endl;
		N = rnd(3, 2000);
		arr = vector<int>(N);
		while (true) {
			for (int i = 0; i < N; ++i) {
				arr[i] = rnd(-1, 1);
			}
			if (count(arr.begin(), arr.end(), 0) >= 1 && count(arr.begin(), arr.end(), 0) <= N - 2) {
				break;
			}
		}
		cnt = 0;
		// cerr << "n: " << N << endl;
		// for (int num : arr) {
		// 	cerr << num << " ";
		// }
		// cerr << endl;
		solve(N);
		// cerr << "reqs: " << cnt << endl;
		assert(cnt <= N + log2(N));
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

#ifdef TEST
	stress();
#endif

	int test_count = 1;
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		int n;
		cin >> n;
		solve(n);
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}