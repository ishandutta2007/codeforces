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

struct comn {
	double re, im;
	comn() : re(0), im(0) {}
	comn(double num) : re(num), im(0) {}
	comn(double _re, double _im) : re(_re), im(_im) {}

	comn operator*(comn other) {
		return comn(re * other.re - im * other.im, re * other.im + im * other.re);
	}

	comn operator+(comn other) {
		return comn(re + other.re, im + other.im);
	}

	comn operator-(comn other) {
		return comn(re - other.re, im - other.im);
	}
};

const int SZ = 1 << 18;
comn roots[SZ];
comn arr1[SZ], arr2[SZ];
int rev[SZ];

void fft(comn* arr, int sz, int l) {
	for (int i = 0; i < sz; ++i) {
		rev[i] = (rev[i >> 1] >> 1) | ((i & 1) << (l - 1));
		if (rev[i] > i) {
			swap(arr[i], arr[rev[i]]);
		}
	}

	for (int i = 1; i < sz; i *= 2) {
		for (int j = 0; j < sz; j += 2 * i) {
			for (int k = 0; k < i; ++k) {
				comn tmp = arr[j + i + k] * roots[SZ / i / 2 * k];
				arr[j + i + k] = arr[j + k] - tmp;
				arr[j + k] = arr[j + k] + tmp;
			}
		}
	}
}

const int MOD = 1009;

vector<int> mult(vector<int> a, vector<int> b) {
	int sz = 1;
	int l = 0;
	while (sz < szof(a) + szof(b) - 1) {
		sz *= 2;
		++l;
	}

	assert(sz <= SZ);

	for (int i = 0; i < sz; ++i) {
		arr1[i] = i < szof(a) ? a[i] : 0;
		arr2[i] = i < szof(b) ? b[i] : 0;
	}

	fft(arr1, sz, l);
	fft(arr2, sz, l);

	for (int i = 0; i < sz; ++i) {
		arr1[i] = arr1[i] * arr2[i];
	}

	fft(arr1, sz, l);

	reverse(arr1 + 1, arr1 + sz);
	vector<int> ret;
	for (int i = 0; i < sz; ++i) {
		ll tmp = round(arr1[i].re / sz);
		ret.push_back(tmp % MOD);
	}

	while (szof(ret) && ret.back() == 0) {
		ret.pop_back();
	}
	return ret;
}

void solve() {
	int n, m, k;
	cin >> n >> m >> k;


	vector<int> amount(m);
	for (int i = 0; i < n; ++i) {
		int num;
		cin >> num;
		--num;
		amount[num]++;
	}

	vector<vector<int>> vecs;
	for (int i = 0; i < m; ++i) {
		if (amount[i]) {
			vecs.push_back(vector<int>(amount[i] + 1, 1));
		}
	}

	set<pii> have;
	for (int i = 0; i < szof(vecs); ++i) {
		have.insert({szof(vecs[i]), i});
	}

	while (szof(have) > 1) {
		int a = have.begin()->ss;
		have.erase(have.begin());
		int b = have.begin()->ss;
		have.erase(have.begin());
		vecs.push_back(mult(vecs[a], vecs[b]));
		have.insert({szof(vecs.back()), szof(vecs) - 1});
	}

	int pos = have.begin()->ss;
	/*
	for (int num : vecs[pos]) {
		cerr << num << " ";
	}
	cerr << endl;
	*/
	if (szof(vecs[pos]) <= k) {
		cout << "0\n";
	} else {
		cout << vecs[pos][k] << "\n";
	}
}


int main() {
	//freopen(TASK_NAME ".in", "r", stdin);
	//freopen(TASK_NAME ".out", "w", stdout);
	cerr << fixed << setprecision(15);
	cout << fixed << setprecision(15);
	ios::sync_with_stdio(false);

	for (int i = 0; i < SZ; ++i) {
		roots[i] = comn(cos(PI * 2 * i / SZ), sin(PI * 2 * i / SZ));
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