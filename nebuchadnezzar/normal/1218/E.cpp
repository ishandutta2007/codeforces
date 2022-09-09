// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
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
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
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

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

const int bp = 20;
const int sz = 1 << bp;
int root, roots[sz];
int perm[sz];
int arra[sz], arrb[sz];

void fft(int* arr, int cp) {
	for (int i = 0; i < 1 << cp; ++i) {
		if (perm[i] >> (bp - cp) > i) {
			swap(arr[i], arr[perm[i] >> (bp - cp)]);
		}
	}

	for (int i = 1, root_shift = sz / 2; i < 1 << cp; i *= 2, root_shift /= 2) {
		for (int j = 0; j < 1 << cp; j += i * 2) {
			for (int k = 0, root_ind = 0; k < i; ++k, root_ind += root_shift) {
				int b = mult(arr[j + i + k], roots[root_ind]);
				arr[j + i + k] = sum(arr[j + k], MOD - b);
				add(arr[j + k], b);
			}
		}
	}
}

vector<int> mult(vector<int> const& a, vector<int> const& b) {
	int cp = 0;
	while (1 << cp < szof(a) + szof(b) - 1) {
		++cp;
	}
	for (int i = 0; i < szof(a); ++i) {
		arra[i] = a[i];
	}
	fill(arra + szof(a), arra + (1 << cp), 0);
	for (int i = 0; i < szof(b); ++i) {
		arrb[i] = b[i];
	}
	fill(arrb + szof(b), arrb + (1 << cp), 0);
	fft(arra, cp);
	fft(arrb, cp);
	for (int i = 0; i < 1 << cp; ++i) {
		arra[i] = mult(arra[i], arrb[i]);
	}
	fft(arra, cp);
	reverse(arra + 1, arra + (1 << cp));
	vector<int> c;
	int inv_csz = inv(1 << cp);
	for (int i = 0; i < szof(a) + szof(b) - 1; ++i) {
		c.push_back(mult(arra[i], inv_csz));
	}
	return c;
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> arr;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		arr.push_back(num);
	}
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		int t, num;
		cin >> t >> num;
		vector<int> b = arr;
		if (t == 1) {
			int pos, val;
			cin >> pos >> val;
			--pos;
			b[pos] = val;
		} else {
			int l, r, val;
			cin >> l >> r >> val;
			--l;
			for (int j = l; j < r; ++j) {
				b[j] += val;
			}
		}
		for (int j = 0; j < n; ++j) {
			b[j] = num - b[j];
			b[j] = (b[j] % MOD + MOD) % MOD;
		}

		function<vector<int>(int, int)> rec = [&](int l, int r) {
			if (l + 1 == r) {
				return vector<int>({1, b[l]});
			}
			int m = (l + r) / 2;
			return mult(rec(l, m), rec(m, r));
		};

		cout << rec(0, n)[k] << "\n";
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

	for (int i = 1; ; ++i) {
		if (mpow(i, sz / 2) == MOD - 1) {
			root = i;
			break;
		}
	}

	// cerr << root << endl;

	roots[0] = 1;
	for (int i = 1; i < sz; ++i) {
		roots[i] = mult(roots[i - 1], root);
		perm[i] = (perm[i >> 1] >> 1) | ((i & 1) << (bp - 1));
	}

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