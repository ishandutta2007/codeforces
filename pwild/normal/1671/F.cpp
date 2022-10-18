#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

#define FOR(i,a,b) for (i64 i = (a); i < (b); i++) 
#define FORD(i,a,b) for (i64 i = (b)-1; i >= (a); i--)

const int MOD = 998244353;

i64 solve_naive(i64 n, i64 k, i64 x) {
	vector<int> p(n);
	iota(begin(p), end(p), 0);
	int res = 0;
	do {
		int inv = 0, ind = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < i; j++) {
				if (p[j] < p[i]) continue;
				inv++, ind += (j+1 == i);
			}
		}
		if (inv == k && ind == x) {
			for (int j: p) cout << j << ' ';
			cout << '\n';
			res++;
		}
	} while (next_permutation(begin(p), end(p)));
	return res;
}

void precalc() {
	int dp[13][12][12] = {};
	for (int n = 1; n <= 12; n++) {
		vector<int> p(n);
		iota(begin(p), end(p), 0);
		int pc = 0;


		do {
			bool connected = true;
			for (int k = 1; k < n; k++) {
				if (*max_element(begin(p), begin(p)+k) < k) connected = false;
			}
			if (!connected) continue;
			pc++;

			int inv = 0, ind = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < i; j++) {
					if (p[j] < p[i]) continue;
					inv++, ind += (j+1 == i);
				}
			}
			if (inv <= 11) dp[n][inv][ind]++;
		} while (next_permutation(begin(p), end(p)));
		cout << n << ' ' << pc << endl;
	}

	for (int n = 1; n <= 12; n++) {
		for (int inv = 0; inv <= 11; inv++) {
			for (int ind = 0; ind <= 11; ind++) {
				if (dp[n][inv][ind] == 0) continue;
				cout << '{' << n << ',' << inv << ',' << ind << ',' << dp[n][inv][ind] << "}," << '\n';
			}
		}
	}
}

template<int m>
struct mod {
	i64 x;
	mod(i64 x = 0): x((m + x%m) % m) { }
	
	mod operator+(const mod &a) const { return mod(x+a.x); }
	mod operator-(const mod &a) const { return mod(x-a.x); }
	mod operator*(const mod &a) const { return mod(x*a.x); }
	mod operator/(const mod &a) const { return *this * (a^(m-2)); }
	
	bool operator==(const mod &a) const { return x == a.x; }

	mod operator^(i64 n) const {
		i64 res = 1, a = x;
		for (; n; n /= 2) {
			if (n%2) res = res*a % m;
			a = a*a % m;
		}
		return mod(res);
	}
};

using num = mod<998244353>;

vector<tuple<int,int,int,int>> transitions = {
{1,0,0,1},
{2,1,1,1},
{3,2,1,2},
{3,3,2,1},
{4,3,1,3},
{4,3,2,1},
{4,4,1,1},
{4,4,2,4},
{4,5,2,3},
{4,6,3,1},
{5,4,1,4},
{5,4,2,4},
{5,5,1,2},
{5,5,2,12},
{5,5,3,2},
{5,6,1,2},
{5,6,2,12},
{5,6,3,4},
{5,7,2,9},
{5,7,3,6},
{5,8,2,3},
{5,8,3,6},
{5,9,3,4},
{5,10,4,1},
{6,5,1,5},
{6,5,2,10},
{6,5,3,1},
{6,6,1,3},
{6,6,2,28},
{6,6,3,13},
{6,7,1,4},
{6,7,2,35},
{6,7,3,29},
{6,7,4,1},
{6,8,1,3},
{6,8,2,35},
{6,8,3,41},
{6,8,4,4},
{6,9,1,1},
{6,9,2,30},
{6,9,3,44},
{6,9,4,7},
{6,10,2,17},
{6,10,3,45},
{6,10,4,7},
{6,11,2,8},
{6,11,3,30},
{6,11,4,11},
{7,6,1,6},
{7,6,2,20},
{7,6,3,6},
{7,7,1,4},
{7,7,2,55},
{7,7,3,50},
{7,7,4,3},
{7,8,1,6},
{7,8,2,80},
{7,8,3,118},
{7,8,4,18},
{7,9,1,6},
{7,9,2,95},
{7,9,3,186},
{7,9,4,48},
{7,10,1,6},
{7,10,2,101},
{7,10,3,230},
{7,10,4,85},
{7,10,5,2},
{7,11,1,2},
{7,11,2,94},
{7,11,3,260},
{7,11,4,113},
{7,11,5,4},
{8,7,1,7},
{8,7,2,35},
{8,7,3,21},
{8,7,4,1},
{8,8,1,5},
{8,8,2,96},
{8,8,3,145},
{8,8,4,26},
{8,9,1,8},
{8,9,2,155},
{8,9,3,358},
{8,9,4,124},
{8,9,5,3},
{8,10,1,9},
{8,10,2,207},
{8,10,3,616},
{8,10,4,313},
{8,10,5,16},
{8,11,1,11},
{8,11,2,250},
{8,11,3,859},
{8,11,4,567},
{8,11,5,53},
{9,8,1,8},
{9,8,2,56},
{9,8,3,56},
{9,8,4,8},
{9,9,1,6},
{9,9,2,154},
{9,9,3,350},
{9,9,4,126},
{9,9,5,4},
{9,10,1,10},
{9,10,2,268},
{9,10,3,898},
{9,10,4,552},
{9,10,5,48},
{9,11,1,12},
{9,11,2,389},
{9,11,3,1654},
{9,11,4,1404},
{9,11,5,204},
{9,11,6,1},
{10,9,1,9},
{10,9,2,84},
{10,9,3,126},
{10,9,4,36},
{10,9,5,1},
{10,10,1,7},
{10,10,2,232},
{10,10,3,742},
{10,10,4,448},
{10,10,5,43},
{10,11,1,12},
{10,11,2,427},
{10,11,3,1967},
{10,11,4,1887},
{10,11,5,357},
{10,11,6,6},
{11,10,1,10},
{11,10,2,120},
{11,10,3,252},
{11,10,4,120},
{11,10,5,10},
{11,11,1,8},
{11,11,2,333},
{11,11,3,1428},
{11,11,4,1302},
{11,11,5,252},
{11,11,6,5},
{12,11,1,11},
{12,11,2,165},
{12,11,3,462},
{12,11,4,330},
{12,11,5,55},
{12,11,6,1}};

template<typename T>
vector<T> berlekamp_massey(vector<T> a) {
	i64 n = size(a), L = 0, k = 0;
	T b(1), r;
	vector<T> C(n), B(n), D;
	C[0] = B[0] = 1;
	
	for (i64 i = 0; i < n; i++) { k++;
		T d = a[i];
		for (i64 j = 1; j <= L; j++) d = d + C[j]*a[i-j];
	
		if (d == 0) continue;
		D = C, r = d / b;
		for (i64 j = k; j < n; j++) {
			C[j] = C[j] - r*B[j-k];
		}
		if (2*L > i) continue;
		L = i+1-L, B = D, b = d, k = 0;
	}

	C.resize(L+1), C.erase(begin(C));
	for (auto &x: C) x = T(0) - x;
	return C;
}

const int K = 30;

template<typename T>
struct linear_recurrence {
	vector<T> a, c;
	int n;

	linear_recurrence(vector<T> a): a(a), c(berlekamp_massey(a)), n(size(c)) {}
	linear_recurrence() {}

	vector<T> multiply(const vector<T> &p, const vector<T> &q) {
		vector<T> r(2*n+1);
		FOR(i,0,n+1) FOR(j,0,n+1)
			r[i+j] = r[i+j] + p[i]*q[j];
		FORD(i,n+1,2*n+1) FOR(j,1,n+1)
			r[i-j] = r[i-j] + r[i]*c[j-1];
		r.resize(n+1);
		return r;
	}
	
	vector<vector<T>> y;

	void precalc_powers() {
		y.resize(K, vector<T>(n+1));
		y[0][1] = T(1);
		for (int k = 1; k < K; k++) {
			y[k] = multiply(y[k-1], y[k-1]);
		}
	}
	
	T get(i64 k) {
		i64 n = size(c);
		
		vector<T> q(n+1);
		q[0] = T(1);
		
		int j = 0;
		for (k++; k; k /= 2, j++) {
			if (k&1) q = multiply(q, y[j]);
		}
		
		T res(0);
		FOR(i,0,n) res = res + q[i+1]*a[i];
		return res;
	}
};

linear_recurrence<num> L[12][12];

void find_linear_recs() {
	int N = 400, K = 12, X = 12;
	vector<vector<vector<num>>> dp(N, vector<vector<num>>(K, vector<num>(X)));
	dp[0][0][0] = 1;
	for (int n = 1; n < N; n++) {
		for (int k = 0; k < K; k++) {
			for (int x = 0; x < X; x++) {
				for (auto [dn,dk,dx,c]: transitions) {
					if (n >= dn && k >= dk && x >= dx) {
						dp[n][k][x] = dp[n][k][x] + dp[n-dn][k-dk][x-dx]*num(c);
					}
				}
			}
		}
	}

	for (int k = 1; k < K; k++) {
		for (int x = 1; x < X; x++) {
			if (k < x) continue;
			vector<num> v;
			for (int n = 1; n < N; n++) {
				v.push_back(dp[n][k][x]);
			}
			L[k][x] = linear_recurrence(v);
			L[k][x].precalc_powers();
//			cerr << L[k][x].c.size() << endl;
		}
	}
}

i64 solve(i64 n, i64 k, i64 x) {
	if (n == 1 || k < x) return 0;
	return L[k][x].get(n-1).x;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	find_linear_recs();

	int tc; cin >> tc;
	while (tc--) {
		int n, k, x;
		cin >> n >> k >> x;
		cout << solve(n,k,x) << '\n';
	}
}