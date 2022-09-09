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

const int MOD = 998'244'353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b /= 2;
	}
	return ret;
}


void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for (int& num : a) {
		cin >> num;
		--num;
	}
	vector<int> b(k);
	vector<bool> ask(n);
	for (int& num : b) {
		cin >> num;
		--num;
		ask[num] = true;
	}

	vector<int> where(n);
	for (int i = 0; i < n; ++i) {
		where[a[i]] = i;
	}

	set<int> left;
	for (int i = 0; i < n; ++i) {
		left.insert(i);
	}

	int ans = 1;

	for (int i = 0; i < k; ++i) {
		int pos = where[b[i]];
		auto it = left.find(pos);
		vector<int> cands;
		if (it != left.begin()) {
			auto it2 = it;
			--it2;
			int tmp = *it2;
			if (!ask[a[tmp]]) {
				cands.push_back(tmp);
			}
		}

		++it;
		if (it != left.end()) {
			int tmp = *it;
			if (!ask[a[tmp]]) {
				cands.push_back(tmp);
			}
		}

		if (!szof(cands)) {
			cout << "0\n";
			return;
		}

		ans = mult(ans, szof(cands));
		left.erase(cands[0]);
		ask[b[i]] = false;
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