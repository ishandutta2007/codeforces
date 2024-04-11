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

const int MOD = 998244353;
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

vector<int> factorial;

int get_perm_ind(vector<int> const& perm) {
	int ret = 0;
	vector<bool> used(szof(perm));
	for (int i = 0; i < szof(perm); ++i) {
		for (int j = 0; j < perm[i]; ++j) {
			if (!used[j]) {
				add(ret, factorial[szof(perm) - i - 1]);
			}
		}
		used[perm[i]] = true;
	}
	return ret;
}

int get_ind_stupid(vector<int> const& prev, vector<int> const& cur) {
	int ret = 0;
	vector<int> order(szof(cur));
	iota(order.begin(), order.end(), 0);
	do {
		if (order == cur) {
			break;
		}
		bool ok = true;
		for (int i = 0; i < szof(order); ++i) {
			if (order[i] == prev[i]) {
				ok = false;
				break;
			}
		}
		ret += ok;
	} while (next_permutation(order.begin(), order.end()));
	return ret;
}

vector<vector<int>> f;

int get_ind(vector<int> const& prev, vector<int> const& cur) {
	// for (int num : prev) {
	// 	cerr << num << " ";
	// }
	// cerr << endl;
	// for (int num : cur) {
	// 	cerr << num << " ";
	// }
	// cerr << endl;
	int ret = 0;
	vector<bool> used(szof(prev));
	vector<bool> met(szof(prev));
	int bpv = 1;
	while (bpv < szof(cur)) {
		bpv *= 2;
	}
	vector<int> rsq_used(bpv * 2);
	vector<int> rsq_met(bpv * 2);
	function<int(int, int, int, int, int)> rsq_get_used = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			return rsq_used[v];
		}
		int vm = (vl + vr) / 2;
		return rsq_get_used(v * 2, vl, vm, l, r) + rsq_get_used(v * 2 + 1, vm, vr, l, r);
	};

	function<void(int, int)> rsq_set_used = [&](int pos, int val) {
		used[pos] = val;
		pos += bpv;
		rsq_used[pos] = val;
		pos /= 2;
		while (pos) {
			rsq_used[pos] = rsq_used[pos * 2] + rsq_used[pos * 2 + 1];
			pos /= 2;
		}
	};

	function<int(int, int, int, int, int)> rsq_get_met = [&](int v, int vl, int vr, int l, int r) {
		if (r <= vl || vr <= l) {
			return 0;
		}
		if (l <= vl && vr <= r) {
			return rsq_met[v];
		}
		int vm = (vl + vr) / 2;
		return rsq_get_met(v * 2, vl, vm, l, r) + rsq_get_met(v * 2 + 1, vm, vr, l, r);
	};

	function<void(int, int)> rsq_set_met = [&](int pos, int val) {
		met[pos] = val;
		pos += bpv;
		rsq_met[pos] = val;
		pos /= 2;
		while (pos) {
			rsq_met[pos] = rsq_met[pos * 2] + rsq_met[pos * 2 + 1];
			pos /= 2;
		}
	};

	function<int(int, int)> get_unused = [&](int l, int r) {
		// int ret = 0;
		// for (int i = l; i < r; ++i) {
		// 	if (!used[i]) {
		// 		ret++;
		// 	}
		// }
		return r - l - rsq_get_used(1, 0, bpv, l, r);
	};

	function<int(int, int)> get_not_met = [&](int l, int r) {
		// int ret = 0;
		// for (int i = l; i < r; ++i) {
		// 	if (!met[i]) {
		// 		++ret;
		// 	}
		// }
		return r - l - rsq_get_met(1, 0, bpv, l, r);
	};

	for (int i = 0; i < szof(prev); ++i) {
		// /met[prev[i]] = true;
		rsq_set_met(prev[i], 1);
		// met[cur[i]] = true;
		// used[cur[i]] = true;
		rsq_set_used(cur[i], 1);
		bool mem = false;
		if (!used[prev[i]]) {
			// used[prev[i]] = true;
			rsq_set_used(prev[i], 1);
			mem = true;
		}

		int tot = get_unused(0, cur[i]);
		int intr = get_not_met(0, cur[i]);

		int not_met = get_not_met(0, szof(prev));
		// cerr << tot << " " << intr << " " << not_met << endl;

		//add(ret, f[intr][tot - intr]);
		add(ret, mult(tot - intr, f[not_met][szof(prev) - i - 1 - not_met]));
		if (intr) {
			add(ret, mult(intr, f[not_met - 1][szof(prev) - i - not_met]));
		}

		if (mem) {
			// used[prev[i]] = false;
			rsq_set_used(prev[i], 0);
		}

		// met[cur[i]] = true;
		rsq_set_met(cur[i], 1);
		// cerr << ret << endl;
	}
	// int val = get_ind_stupid(prev, cur);
	// cerr << ret << " " << val << endl;
	// assert(ret == val);
	return ret;
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> matr(n, vector<int>(n));
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			cin >> matr[i][j];
			--matr[i][j];
		}
	}

	factorial = {1};
	for (int i = 1; i <= n; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}

	f = vector<vector<int>>(n + 1, vector<int>(n + 1));

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= n; ++j) {
			if (j == 0) {
				if (i == 0) {
					f[i][j] = 1;
				} else {
					f[i][j] = mult(f[i - 1][j], i);
					if (i & 1) {
						add(f[i][j], MOD - 1);
					} else {
						add(f[i][j], 1);
					}
				}
			} else {
				f[i][j] = mult(f[i][j - 1], i + j);
				if (i) {
					add(f[i][j], mult(f[i - 1][j - 1], i));
				}
			}
		}
	}

	// for (int i = 0; i <= 8; ++i) {
	// 	for (int j = 0; j <= 8; ++j) {
	// 		cerr << f[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }

	vector<int> suffs = {1};
	for (int i = 1; i <= n; ++i) {
		suffs.push_back(mult(suffs.back(), f[n][0]));
	}

	int ans = mult(get_perm_ind(matr[0]), suffs[n - 1]);

	for (int i = 1; i < n; ++i) {
		add(ans, mult(get_ind(matr[i - 1], matr[i]), suffs[n - i - 1]));
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