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
const long double PI = atan2l(0, -1);
mt19937 tw(960172);
ll rnd(ll x, ll y) { static uniform_int_distribution<ll> d; return d(tw) % (y - x + 1) + x; }

#define complex qweqwerqwer

struct complex {
	long double x, y;
	complex() : x(0), y(0) {}

	complex(int num) : x(num), y(0) {}

	complex(long double _x, long double _y) : x(_x), y(_y) {}

	complex operator*(complex const& other) {
		return complex(x * other.x - y * other.y, x * other.y + y * other.x);
	}

	complex operator/(long double num) {
		return complex(x / num, y / num);
	}

	complex operator+(complex const& other) {
		return complex(x + other.x, y + other.y);
	}

	complex operator-(complex const& other) {
		return complex(x - other.x, y - other.y);
	}	
};

const int P = 19, SZ = 1 << P;

complex roots[SZ];
int perm[SZ];

complex arr1[SZ], arr2[SZ];

void fft(complex arr[]) {
	for (int i = 0; i < SZ; ++i) {
		if (perm[i] > i) {
			swap(arr[i], arr[perm[i]]);
		}
	}

	for (int i = 1; i < SZ; i *= 2) {
		for (int j = 0; j < SZ; j += i * 2) {
			for (int k = 0; k < i; ++k) {
				auto val1 = arr[j + k], val2 = arr[j + i + k] * roots[SZ / i / 2 * k];
				arr[j + k] = val1 + val2;
				arr[j + i + k] = val1 - val2;
			}
		}
	}
}

vector<ll> mul(vector<int> a, vector<int> b) {
	for (int i = 0; i < szof(a); ++i) {
		arr1[i] = a[i];
	}
	for (int i = 0; i < szof(b); ++i) {
		arr2[i] = b[i];
	}
	fft(arr1);
	fft(arr2);
	for (int i = 0; i < SZ; ++i) {
		arr1[i] = arr1[i] * arr2[i];
	}
	fft(arr1);
	reverse(arr1 + 1, arr1 + SZ);
	vector<ll> ret;
	for (int i = 0; i < SZ; ++i) {
		arr1[i] = arr1[i] / SZ;
		ret.push_back(roundl(arr1[i].x));
	}
	return ret;
}

void solve() {
	int n, x;
	cin >> n >> x;
	vector<int> arr;
	int cur = 1;
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		if (num >= x) {
			++cur;
		} else {
			arr.push_back(cur);
			cur = 1;
		}
	}

	arr.push_back(cur);
	
	auto tmp = arr;
	reverse(tmp.begin(), tmp.end());

	auto res = mul(arr, tmp);

	ll val = 0;
	for (int num : arr) {
		val += (ll) num * (num - 1) / 2;
	}

	int cnt = 1;
	cout << val << " ";
	for (int i = szof(arr) - 2; i >= 0; --i) {
		cout << res[i] << " ";
		++cnt;
	}

	while (cnt < n + 1) {
		cout << "0 ";
		++cnt;
	}

	cout << "\n";
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	for (int i = 0; i < SZ; ++i) {
		roots[i] = complex(cosl(PI * 2 / SZ * i), sinl(PI * 2 / SZ * i));

		perm[i] = (perm[i >> 1] >> 1) | ((i & 1) << (P - 1));
	}

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