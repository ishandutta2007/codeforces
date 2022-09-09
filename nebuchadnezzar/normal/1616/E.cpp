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
	int n;
	cin >> n;
	string s, t;
	cin >> s >> t;
	vector<int> cnt(26);
	vector<vector<int>> where(26);
	for (int i = 0; i < n; ++i) {
		cnt[s[i] - 'a']++;
		where[s[i] - 'a'].push_back(i);
	}

	for (int i = 0; i < 26; ++i) {
		reverse(where[i].begin(), where[i].end());
	}

	int bpv = 1;
	while (bpv < n) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);

	auto segtree_set = [&](int pos, int val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = segtree[pos * 2] + segtree[pos * 2 + 1];
			pos /= 2;
		}
	};

	auto segtree_get = [&](int l, int r) {
		l += bpv; r += bpv;
		int ret = 0;
		while (l < r) {
			if (l & 1) {
				ret += segtree[l++];
			}
			if (r & 1) {
				ret += segtree[--r];
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	for (int i = 0; i < n; ++i) {
		segtree_set(i, 1);
	}

	ll ans = INFL;

	ll invs = 0;

	for (char c : t) {
		for (char nc = 'a'; nc < c; ++nc) {
			if (!cnt[nc - 'a']) {
				continue;
			}
			int pos = where[nc - 'a'].back();
			ans = min(ans, invs + segtree_get(0, pos));
		}
		if (!cnt[c - 'a']) {
			break;
		}
		--cnt[c - 'a'];
		int pos = where[c - 'a'].back();
		where[c - 'a'].pop_back();
		invs += segtree_get(0, pos);
		segtree_set(pos, 0);
	}

	if (ans == INFL) {
		cout << "-1\n";
	} else {
		cout << ans << "\n";
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