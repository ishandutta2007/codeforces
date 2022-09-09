#include "bits/stdc++.h"
#define ff first
#define ss second
#define szof(_x) ((int) (_x).size())
#define TASK_NAME ""

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9 + 7;
const ll INFL = 1e18 + 123;
const double PI = atan2(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

const int MOD = 1e9 + 7;

int mul(int a, int b) {
	return (ll) a * b % MOD;
}

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mul(ret, a);
		}
		a = mul(a, a);
		b >>= 1;
	}
	return ret;
}

int inv(int a) {
	return mpow(a, MOD - 2);
}

void solve() {
	int r;
	int a1, a2, a3, a4;
	cin >> r >> a1 >> a2 >> a3 >> a4;
	int s = inv(a1 + a2 + a3 + a4);

	vector<int> prob = {mul(a1, s), mul(a2, s), mul(a3, s), mul(a4, s)};
	int dx[4] = {-1, 0, 1, 0};
	int dy[4] = {0, -1, 0, 1};
	int cnt = 0;
	map<pii, int> good;
	for (int x = -r - 5; x <= r + 5; ++x) {
		for (int y = -r - 5; y <= r + 5; ++y) {
			if (x * x + y * y <= r * r) {
				good[{x, y}] = cnt++;
			}
		}
	}

	vector<vector<int>> matrix(cnt, vector<int>(cnt + 1));
	for (auto p : good) {
		int x, y;
		tie(x, y) = p.ff;
		int ind = p.ss;
		matrix[ind][ind] = 1;
		for (int d = 0; d < 4; ++d) {
			int nx = x + dx[d];
			int ny = y + dy[d];
			if (good.count({nx, ny})) {
				matrix[ind][good[{nx, ny}]] = MOD - prob[d];
			}
		}
		matrix[ind].back() = 1;
	}

	/*
	for (int i = 0; i < cnt; ++i) {
		for (int j = 0; j <= cnt; ++j) {
			cerr << matrix[i][j] << " ";
		}
		cerr << endl;
	}
	*/


	int num = 0;
	int intr = good[{0, 0}];
	vector<int> order(cnt);
	iota(order.begin(), order.end(), 0);
	for (int i = 0; i < cnt; ++i) {
		//cerr << i << endl;
		int pos = -1;
		for (int j = i; j < cnt; ++j) {
			if (matrix[j][i] != 0) {
				pos = j;
				break;
			}
		}

		assert(pos != -1);

		swap(matrix[i], matrix[pos]);
		swap(order[i], order[pos]);
		vector<int> v;
		for (int j = 0; j < cnt + 1; ++j) {
			if (matrix[i][j]) {
				v.push_back(j);
			}
		}
		for (int j = 0; j < cnt; ++j) {
			if (i == j || (j < i && order[j] != intr)) {
				continue;
			}
			if (matrix[j][i] != 0) {
				int coef = mul(matrix[j][i], inv(matrix[i][i]));
				++num;

				for (int k : v) {
					add(matrix[j][k], MOD - mul(coef, matrix[i][k]));
				}
			}
		}
	}

	cerr << num << endl;

	/*
	for (int i = 0; i < cnt; ++i) {
		cerr << matrix[i].back() / matrix[i][i] << endl;
	}
	*/

	int ind = -1;
	for (int i = 0; i < cnt; ++i) {
		if (order[i] == intr) {
			ind = i;
		}
	}
	cout << mul(matrix[ind].back(), inv(matrix[ind][ind])) << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	int tests = 1;
	// cin >> tests;
	for (int it = 1; it <= tests; ++it) {
		solve();
	}
	
	#ifdef LOCAL
		cerr << "time: " << clock() << " ms\n";
	#endif
	return 0;
}