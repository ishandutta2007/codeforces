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


void solve() {
	int n, m, l;
	cin >> n >> m >> l;
	vector<ll> inp;
	set<pii> have;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		inp.push_back(num);
		if (num > l) {
			if (szof(have) && (--have.end())->ss == i) {
				pii p = *--have.end();
				have.erase(--have.end());
				p.ss++;
				have.insert(p);
			} else {
				have.insert({i, i + 1});
			}
		}
	}

	for (int i = 0; i < m; ++i) {
		int t;
		cin >> t;
		if (t == 0) {
			cout << szof(have) << "\n";
		} else {
			int p, d;
			cin >> p >> d;
			--p;
			if (inp[p] <= l && inp[p] + d > l) {
				int lg = p, rg = p + 1;
				auto it = have.lower_bound({p, p});
				if (it != have.end() && it->ff == rg) {
					rg = it->ss;
					have.erase(it);
				}
				it = have.lower_bound({p, p});
				if (it != have.begin()) {
					--it;
					if (it->ss == lg) {
						lg = it->ff;
						have.erase(it);
					}
				}
				have.insert({lg, rg});
			}
			inp[p] += d;
		}
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