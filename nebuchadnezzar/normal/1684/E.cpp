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

pii sum(pii a, pii b) {
	return {a.ff + b.ff, a.ss + b.ss};
}

void solve() {
	int n, k;
	cin >> n >> k;
	map<int, int> cnt;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		cnt[num]++;
	}

	vector<pii> have;
	for (auto p : cnt) {
		have.push_back({p.ss, p.ff});
	}

	sort(have.begin(), have.end());

	int bpv = 1;
	while (bpv < szof(have)) {
		bpv *= 2;
	}

	vector<pii> segtree(bpv * 2);

	auto segtree_set = [&](int pos, pii val) {
		pos += bpv;
		segtree[pos] = val;
		pos /= 2;
		while (pos) {
			segtree[pos] = sum(segtree[pos * 2], segtree[pos * 2 + 1]);
			pos /= 2;
		}
	};

	function<int(int, int, int, int)> segtree_find = [&](int v, int vl, int vr, int s) {
		if (segtree[v].ff <= s) {
			return segtree[v].ss;
		}
		if (vl + 1 == vr) {
			return 0;
		}
		int vm = (vl + vr) / 2;
		if (segtree[v * 2].ff <= s) {
			return segtree[v * 2].ss + segtree_find(v * 2 + 1, vm, vr, s - segtree[v * 2].ff);
		}
		return segtree_find(v * 2, vl, vm, s);
	};

	for (int i = 0; i < szof(have); ++i) {
		segtree_set(i, {have[i].ff, 1});
	}

	int need_add = 0;
	int ans = INF;
	int larger = szof(have);

	for (int mex = 0; mex <= n; ++mex) {
		int cur_cnt = 0;
		if (cnt.count(mex)) {
			cur_cnt = cnt[mex];
			int pos = lower_bound(have.begin(), have.end(), pii(cur_cnt, mex)) - have.begin();
			segtree_set(pos, {0, 0});
			--larger;
		}
		int cur_changes = max(need_add, cur_cnt);
		// cerr << mex << " " << cur_changes << endl;
		if (cur_changes <= k) {
			int diff = mex;
			diff += larger - segtree_find(1, 0, bpv, (k - cur_changes) + max(0, need_add - cur_cnt));
			diff = max(diff, 1);
			// cerr << mex << " " << diff << endl;
			ans = min(ans, diff - mex);
		}
		if (cur_cnt == 0) {
			++need_add;
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
	cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}