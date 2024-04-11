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

int dirx[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int diry[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void solve() {
	int kx, ky;
	cin >> kx >> ky;
	--kx; --ky;
	vector<pii> coords;
	for (int i = 0; i < 666; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		coords.push_back({x, y});
	}

	while (kx != 999 / 2 || ky != 999 / 2) {
		for (int d = 0; d < 8; ++d) {
			int nx = kx + dirx[d];
			int ny = ky + diry[d];
			if (0 <= nx && nx < 999 && 0 <= ny && ny < 999) {
				bool good = false;
				bool bad = false;
				for (auto p : coords) {
					if (p.ff == nx && p.ss == ny) {
						bad = true;
						break;
					}
					if (p.ff == nx || p.ss == ny) {
						good = true;
					}
				}
				if (good && !bad) {
					cout << nx + 1 << " " << ny + 1 << endl;
					return;
				}
			}
		}

		int nx = kx, ny = ky;
		if (nx < 999 / 2) {
			++nx;
		} else if (nx > 999 / 2) {
			--nx;
		}

		if (ny < 999 / 2) {
			++ny;
		} else if (ny > 999 / 2) {
			--ny;
		}

		cout << nx + 1 << " " << ny + 1 << endl;
		kx = nx; ky = ny;
		int ind, x, y;
		cin >> ind >> x >> y;
		if (ind == 0) {
			return;
		}
		--ind; --x; --y;
		coords[ind] = {x, y};
	}

	int cnt[2][2] = {{0, 0}, {0, 0}};
	for (auto p : coords) {
		if (p.ff < kx) {
			if (p.ss < ky) {
				cnt[0][0]++;
			} else {
				cnt[0][1]++;
			}
		} else {
			if (p.ss < ky) {
				cnt[1][0]++;
			} else {
				cnt[1][1]++;
			}
		}
	}

	int dx = 0, dy = 0;
	if (max(kx, ky) <= 666 - cnt[1][1]) {
		dx = -1; dy = -1;
	} else if (max(kx, 999 - ky - 1) <= 666 - cnt[1][0]) {
		dx = -1; dy = 1;
	} else if (max(999 - kx - 1, ky) <= 666 - cnt[0][1]) {
		dx = 1; dy = -1;
	} else if (max(999 - kx - 1, 999 - ky - 1) <= 666 - cnt[0][0]) {
		dx = 1; dy = 1;
	} else {
		assert(false);
	}

	while (true) {
		for (int d = 0; d < 8; ++d) {
			int nx = kx + dirx[d];
			int ny = ky + diry[d];
			if (0 <= nx && nx < 999 && 0 <= ny && ny < 999) {
				bool good = false;
				bool bad = false;
				for (auto p : coords) {
					if (p.ff == nx && p.ss == ny) {
						bad = true;
						break;
					}
					if (p.ff == nx || p.ss == ny) {
						good = true;
					}
				}
				if (good && !bad) {
					cout << nx + 1 << " " << ny + 1 << endl;
					return;
				}
			}
		}

		int nx = min(max(kx + dx, 0), 998);
		int ny = min(max(ky + dy, 0), 998);

		cout << nx + 1 << " " << ny + 1 << endl;
		kx = nx; ky = ny;
		int ind, x, y;
		cin >> ind >> x >> y;
		if (ind == 0) {
			return;
		}
		--ind; --x; --y;
		coords[ind] = {x, y};
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