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
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
mt19937 tw(9450189);
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

void setbit(vector<ull>& arr, int pos) {
	arr[pos / 64] |= 1ull << (pos % 64);
}

int getbit(vector<ull> const& arr, int pos) {
	return (arr[pos / 64] >> (pos % 64)) & 1;
}

void doxor(vector<ull>& arr1, vector<ull> const& arr2) {
	for (int i = 0; i < szof(arr1); ++i) {
		arr1[i] ^= arr2[i];
	}
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>> graph(n);
	for (int i = 0; i < m; ++i) {
		int a, b;
		cin >> a >> b;
		--a; --b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}

	bool fl = true;
	for (int i = 0; i < n; ++i) {
		if (szof(graph[i]) % 2) {
			fl = false;
			break;
		}
	}

	if (fl) {
		cout << "1\n";
		for (int i = 0; i < n; ++i) {
			cout << "1 ";
		}
		cout << "\n";
		return;
	}

	int h = n, w = n;
	vector<vector<ull>> matr(h, vector<ull>((w + 63) / 64));
	vector<bool> res(h);

	for (int i = 0; i < n; ++i) {
		if (szof(graph[i]) % 2 == 1) {
			setbit(matr[i], i);
			for (int to : graph[i]) {
				setbit(matr[i], to);
			}
			res[i] = 1;
		} else {
			for (int to : graph[i]) {
				setbit(matr[i], to);
			}
			res[i] = 0;
		}
	}

	// for (int i = 0; i < h; ++i) {
	// 	for (int j = 0; j < w; ++j) {
	// 		cerr << getbit(matr[i], j) << " ";
	// 	}
	// 	cerr << res[i] << "\n";
	// }

	int cur = 0;
	for (int i = 0; i < w; ++i) {
		for (int j = cur; j < h; ++j) {
			if (getbit(matr[j], i)) {
				swap(matr[j], matr[cur]);
				swap(res[j], res[cur]);
				break;
			}
		}
		if (!getbit(matr[cur], i)) {
			continue;
		}
		for (int j = 0; j < h; ++j) {
			if (j != cur && getbit(matr[j], i)) {
				doxor(matr[j], matr[cur]);
				res[j] = res[j] ^ res[cur];
			}
		}
		++cur;
	}

	vector<int> type(n, -1);
	for (int i = 0; i < h; ++i) {
		for (int j = 0; j < w; ++j) {
			if (getbit(matr[i], j)) {
				type[j] = res[i];
				break;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (type[i] == -1) {
			//assert(szof(graph[i]) % 2 == 0);
			type[i] = 0;
		}
	}

	cout << "2\n";
	for (int num : type) {
		cout << num + 1 << " ";
	}
	cout << "\n";
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