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
	int n, x, y;
	cin >> n >> x >> y;
	vector<int> arr;
	vector<vector<int>> where(n + 1);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		where[num].push_back(i);
		arr.push_back(num);
	}
	if (x > y) {
		cout << "NO\n";
		return;
	}
	int qq;
	for (int i = 0; i <= n; ++i) {
		if (!szof(where[i])) {
			qq = i;
			break;
		}
	}

	vector<int> outp(n, qq);
	set<pii> have;
	for (int i = 0; i <= n; ++i) {
		if (szof(where[i])) {
			have.insert({szof(where[i]), i});
		}
	}

	for (int i = 0; i < x; ++i) {
		pii tmp = *--have.end();
		have.erase(--have.end());
		int pos = where[tmp.ss].back();
		outp[pos] = arr[pos];
		where[tmp.ss].pop_back();
		if (szof(where[tmp.ss])) {
			have.insert({szof(where[tmp.ss]), tmp.ss});
		}
	}

	for (int i = x; i < y;) {
		if (szof(have) <= 1) {
			cout << "NO\n";
			#ifdef LOCAL
			assert(false);
			#endif
			return;
		}

		pii tmp1 = *--have.end();
		have.erase(--have.end());
		pii tmp2 = *--have.end();
		have.erase(--have.end());
		int pos1 = where[tmp1.ss].back();
		where[tmp1.ss].pop_back();
		int pos2 = where[tmp2.ss].back();
		where[tmp2.ss].pop_back();

		if (y - i == 3 && szof(have) >= 1) {
			pii tmp3 = *--have.end();
			have.erase(--have.end());
			int pos3 = where[tmp3.ss].back();
			where[tmp3.ss].pop_back();
			outp[pos1] = arr[pos2];
			outp[pos2] = arr[pos3];
			outp[pos3] = arr[pos1];
			break;
		}
		if (i + 2 <= y) {
			outp[pos1] = arr[pos2];
			outp[pos2] = arr[pos1];
			i += 2;
		} else {
			outp[pos1] = arr[pos2];
			i += 1;
		}
		if (szof(where[tmp1.ss])) {
			have.insert({szof(where[tmp1.ss]), tmp1.ss});
		}
		if (szof(where[tmp2.ss])) {
			have.insert({szof(where[tmp2.ss]), tmp2.ss});
		}
	}

	cout << "YES\n";
	for (int num : outp) {
		cout << num + 1 << " ";
	}
	cout << "\n";

	/*int cntx = 0;
	int cnty = 0;
	vector<pii> cnt_vals(n + 1);
	for (int i = 0; i < n; ++i) {
		cntx += arr[i] == outp[i];
		cnt_vals[arr[i]].ff++;
		cnt_vals[outp[i]].ss++;
	}
	for (pii p : cnt_vals) {
		cnty += min(p.ff, p.ss);
	}
	assert(x == cntx && y == cnty);*/
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