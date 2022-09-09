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

const int MOD = 1000000007;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
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

void solve() {
	int n, m;
	cin >> n >> m;
	vector<pii> left;
	vector<int> right;
	vector<pii> edges;
	int cnt = 0;

	for (int i = 0; i < n; ++i) {
		left.push_back({cnt, cnt + 1});
		cnt += 2;
		edges.push_back({left[i].ff, left[i].ss});
	}
	for (int i = 0; i < m; ++i) {
		right.push_back(cnt++);
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < m; ++j) {
			if (s[j] == '1') {
				edges.push_back({left[i].ff, right[j]});
				edges.push_back({left[i].ss, right[j]});
			}
		}
	}

	vector<vector<int>> matr(cnt, vector<int>(cnt));
	for (pii e : edges) {
		int tmp = rnd(1, INF);
		matr[e.ff][e.ss] = tmp;
		matr[e.ss][e.ff] = -tmp;
	}

	int cur = 0;
	for (int i = 0; i < cnt; ++i) {
		for (int j = cur; j < cnt; ++j) {
			if (matr[j][i]) {
				swap(matr[j], matr[cur]);
				break;
			}
		}
		if (!matr[cur][i]) {
			continue;
		}
		for (int j = 0; j < cnt; ++j) {
			if (j == cur) {
				continue;
			}
			int c = mult(matr[j][i], inv(matr[cur][i]));
			for (int k = 0; k < cnt; ++k) {
				add(matr[j][k], MOD - mult(matr[cur][k], c));
			}
		}
		++cur;
	}

	cout << cur / 2 - n << "\n";
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