#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

//constexpr long long int MOD = 1000000007;
constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-8;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int val[] = {5,7,11,13,17,19,23,29 };

long long gcd(long long a, long long b) {
	while (b) {
		a %= b;
		swap(a, b);
	}
	return a;
}

long long int extended_gcd(long long int a, long long int b, long long int c, long long int d, long long int m) {
	long long int ret = 0;
	if (c == 1)return d;
	ret = extended_gcd(c, d, a % c, (b + (MOD * MOD / m) * m - ((a / c) % m) * (d % m)) % m, m);
	return ret;
}

long long int extended_gcd(long long int a, long long int b) {
	int g = gcd(a, b);
	a /= g;
	b /= g;
	long long int box = a % b;
	long long int bag = b - (a % b);
	long long int bbox = 1;
	long long int bbag = b - 1;
	return extended_gcd(box, bbox, bag, bbag, b) * g;
}

long long int mul(long long int a, long long int b, long long int m) {
	long long int ret = 0;
	long long int add = a;
	for (int i = 0; i < 63; i++) {
		if (b >> i & 1)ret += add;
		ret %= m;
		add *= 2;
		add %= m;
	}
	return ret;
}

pair<long long int, long long int>crt(long long int m1, long long int a1, long long int m2, long long int a2) {
	if (m1 <= 0 || m2 <= 0)return { -1,-1 };
	long long int g = gcd(m1, m2);
	if (a1 % g != a2 % g)return { -1,-1 };
	long long int by = (a2 - a1) / g;
	if (by < 0) {
		by *= -1;
		by %= m1 / g * m2;
		by *= -1;
		by += m1 / g * m2;
	}
	by %= m1 / g * m2;
	long long int a = extended_gcd(m1 / g, m2 / g);
	a %= m1 / g * m2;
	a = mul(a, by, m1 / g * m2);
	a = mul(a, m1, m1 / g * m2);
	a += a1;
	a %= m1 / g * m2;
	return { m1 / g * m2,a };
}

long long int crt(vector<long long int>m, vector<long long int>a) {
	long long int reta = 0;
	long long int retm = 1;
	for (int i = 0; i < m.size(); i++) {
		tie(retm, reta) = crt(retm, reta, m[i], a[i]);
	}
	return reta;
}

int by = 5 * 7 * 11 * 13 * 17 * 19 * 23 * 29;

void Solve() {
//	cin >> M;
	vector<vector<int>>ok(8, vector<int>(30, 0));
	vector<long long>m;
	for (int i = 0; i < 8; i++) {
		m.push_back(val[i]);
	}
	for (int loop = 1; loop <= 30; loop++) {
		cout << "? " << loop << " " << loop + by << endl;
		//K = gcd(loop + M, loop + M + by);
		//cout << K << endl;
		cin >> K;
		for (int i = 0; i < 8; i++) {
			if (gcd(K, val[i]) == val[i]) {
				ok[i][(by - loop) % val[i]] = 1;
			}
		}
	}
	cout << "! ";
	vector<long long>a;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < val[i]; j++) {
			if (ok[i][j]) {
				a.push_back(j);
				break;
			}
		}
	}
	auto val = crt(m, a);
	cout << val << endl;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> T;
	while (T--) {
		Solve();
	}
}