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

const int MOD = 1'000'000'007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int inv2 = (MOD + 1) / 2;

int prog(int from, int to) {
	if (from > to) {
		swap(from, to);
	}
	return mult(mult(sum(from, to), to - from + 1), inv2);
}

void solve() {
	int n, k, l;
	cin >> n >> k >> l;
	vector<pair<pii, int>> all;
	for (int i = 0; i < n; ++i) {
		int x, y, c;
		cin >> x >> y >> c;
		--c;
		all.push_back({{x, y}, c});
	}

	sort(all.begin(), all.end());

	int fromx = 0;
	vector<multiset<int>> by_color(k);
	vector<pii> segs;
	int ans = 0;
	for (int i = 0; i < n; ++i) {
		if (i == 0 || all[i].ff.ff != all[i - 1].ff.ff) {
			for (int j = 0; j < k; ++j) {
				by_color[j].clear();
			}
			for (int j = i; j < n; ++j) {
				by_color[all[j].ss].insert(all[j].ff.ss);
			}

			segs.clear();
			for (int j = 0; j < k; ++j) {
				int fromy = 0;
				for (int y : by_color[j]) {
					if (fromy < y) {
						segs.push_back({fromy, y});
					}
					fromy = y + 1;
				}
				if (fromy < l) {
					segs.push_back({fromy, l});
				}
			}

			sort(segs.begin(), segs.end(), [&](auto& a, auto& b) {
				if (a.ff != b.ff) {
					return a.ff < b.ff;
				}
				return a.ss > b.ss;
			});
			set<pii> have_segs;
			int cur_maxy = 0;
			for (auto seg : segs) {
				if (cur_maxy < seg.ss) {
					cur_maxy = seg.ss;
					have_segs.insert(seg);
					// cerr << "add set " << seg.ff << " " << seg.ss << endl;
				}
			}

			int sum_area = 0;
			{
				int fromy = 0;
				int toy = 0;
				for (auto seg : have_segs) {
					if (fromy != toy) {
						add(sum_area, prog(toy - fromy, toy - min(toy - 1, seg.ff - 1)));
					}
					tie(fromy, toy) = seg;
				}
				if (fromy != toy) {
					add(sum_area, prog(toy - fromy, 1));
				}
				// cerr << sum_area << endl;
			}

			for (int j = n - 1; j >= i; --j) {
				if (j == n - 1 || all[j].ff.ff != all[j + 1].ff.ff) {
					int x_mult = all[i].ff.ff - fromx + 1;
					if (j == n - 1) {
						x_mult = mult(x_mult, l - all[j].ff.ff);
					} else {
						x_mult = mult(x_mult, all[j + 1].ff.ff - all[j].ff.ff);
					}

					// cerr << i << " " << j << " " << x_mult << " " << sum(prog(1, l), MOD - sum_area) << endl;

					add(ans, mult(x_mult, sum(prog(1, l), MOD - sum_area)));
				}

				auto& cur_set = by_color[all[j].ss];
				cur_set.erase(cur_set.find(all[j].ff.ss));
				if (cur_set.find(all[j].ff.ss) == cur_set.end()) {
					auto it = cur_set.lower_bound(all[j].ff.ss);
					int lg, rg;
					if (it == cur_set.end()) {
						rg = l;
					} else {
						rg = *it;
					}
					if (it == cur_set.begin()) {
						lg = 0;
					} else {
						--it;
						lg = *it + 1;
					}

					// cerr << "try add " << lg << " " << rg << endl;

					auto it2 = have_segs.lower_bound({lg, INF});
					bool skip = false;
					if (it2 != have_segs.begin()) {
						--it2;
						if (it2->ss >= rg) {
							skip = true;
						}
						++it2;
					}

					if (!skip) {
						it2 = have_segs.lower_bound({lg, -1});
						if (it2 != have_segs.begin()) {
							auto it3 = it2;
							--it3;
							if (it2 != have_segs.end()) {
								add(sum_area, MOD - prog(it3->ss - it3->ff, it3->ss - min(it3->ss - 1, it2->ff - 1)));
							} else {
								add(sum_area, MOD - prog(it3->ss - it3->ff, 1));
							}
							add(sum_area, prog(it3->ss - it3->ff, it3->ss - min(it3->ss - 1, lg - 1)));
						}
						while (it2 != have_segs.end()) {
							auto it3 = it2;
							++it3;
							if (it2->ss <= rg) {
								if (it3 == have_segs.end()) {
									add(sum_area, MOD - prog(it2->ss - it2->ff, 1));
								} else {
									add(sum_area, MOD - prog(it2->ss - it2->ff, it2->ss - min(it2->ss - 1, it3->ff - 1)));
								}
								have_segs.erase(it2);
								it2 = it3;
							} else {
								break;
							}
						}

						// cerr << sum_area << endl;

						if (it2 == have_segs.end()) {
							add(sum_area, prog(rg - lg, 1));
						} else {
							add(sum_area, prog(rg - lg, rg - min(rg - 1, it2->ff - 1)));
						}

						// cerr << sum_area << endl;

						have_segs.insert({lg, rg});
					}
				}
			}
		}
		fromx = all[i].ff.ff + 1;
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
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}

#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}