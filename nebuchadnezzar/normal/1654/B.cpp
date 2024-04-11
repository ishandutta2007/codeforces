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

vector<int> build_suffarr(string s) {
	int n = szof(s);
	auto norm = [&](int num) {
		if (num >= n) {
			return num - n;
		}
		return num;
	};
	vector<int> classes(s.begin(), s.end()), n_classes(n);
	vector<int> order(n), n_order(n);
	iota(order.begin(), order.end(), 0);
	vector<int> cnt(max(szof(s), 128));
	for (int num : classes) {
		cnt[num + 1]++;
	}
	for (int i = 1; i < szof(cnt); ++i) {
		cnt[i] += cnt[i - 1];
	}

	for (int i = 0; i < n; i = i == 0 ? 1 : i * 2) {
		for (int pos : order) {
			int pp = norm(pos - i + n);
			n_order[cnt[classes[pp]]++] = pp;
		}
		int q = -1;
		pii prev = {-1, -1};
		for (int j = 0; j < n; ++j) {
			pii cur = {classes[n_order[j]], classes[norm(n_order[j] + i)]};
			if (cur != prev) {
				prev = cur;
				++q;
				cnt[q] = j;
			}
			n_classes[n_order[j]] = q;
		}
		swap(n_classes, classes);
		swap(n_order, order);
	}
	return order;
}

void solve() {
	string s;
	cin >> s;
	s += "$";
	auto suffarr = build_suffarr(s);

	vector<int> where(szof(s));
	for (int i = 0; i < szof(s); ++i) {
		where[suffarr[i]] = i;
	}

	vector<int> lcp(szof(s));
	int cnt = 0;
	for (int i = 0; i < szof(s); ++i) {
		if (where[i] == szof(s) - 1) {
			cnt = 0;
			continue;
		}
		cnt = max(cnt - 1, 0);
		int next = suffarr[where[i] + 1];
		while (i + cnt < szof(s) && next + cnt < szof(s) && s[i + cnt] == s[next + cnt]) {
			++cnt;
		}
		lcp[where[i]] = cnt;
	}

	int bpv = 1;
	while (bpv < szof(s)) {
		bpv *= 2;
	}

	vector<int> segtree(bpv * 2);
	copy(lcp.begin(), lcp.end(), segtree.begin() + bpv);
	for (int i = bpv - 1; i; --i) {
		segtree[i] = min(segtree[i * 2], segtree[i * 2 + 1]);
	}

	auto get_min = [&](int l, int r) {
		l += bpv; r += bpv;
		int ret = INF;
		while (l < r) {
			if (l & 1) {
				ret = min(ret, segtree[l++]);
			}
			if (r & 1) {
				ret = min(ret, segtree[--r]);
			}
			l /= 2; r /= 2;
		}
		return ret;
	};

	set<int> left_pos;
	for (int i = 0; i < szof(s); ++i) {
		left_pos.insert(i);
	}
	int st = 0;
	while (true) {
		int pos = where[st];
		auto it = left_pos.find(pos);
		int len = 0;
		auto it2 = it;
		if (it2 != left_pos.begin()) {
			--it2;
			len = max(len, get_min(*it2, *it));
		}
		it2 = it;
		++it2;
		if (it2 != left_pos.end()) {
			len = max(len, get_min(*it, *it2));
		}
		if (len == 0) {
			break;
		}
		for (int i = 0; i < len; ++i) {
			left_pos.erase(where[st]);
			++st;
		}
	}

	cout << s.substr(st, szof(s) - st - 1) << "\n";
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