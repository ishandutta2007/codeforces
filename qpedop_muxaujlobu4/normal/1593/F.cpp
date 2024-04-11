#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,abm,mmx,tune=native")
#include<vector>
#include<iostream>
#include<stack>
#include<cmath>
#include<algorithm>
#include<set>
#include<map>
#include<string>
#include<tuple>
#include<bitset>
#include<queue>
#include<unordered_map>
#include<random>
#include<ctime>
//#include<complex>
#include<numeric>
typedef long long ll;
typedef long double ld;
typedef unsigned short us;
typedef unsigned long long ull;
//typedef complex<double> base;
using namespace std;
ll gcd(ll i, ll j) {
	if (j == 0)return i;
	else return gcd(j, i % j);
}
#ifdef _DEBUG
int __builtin_popcount(int x) { return x ? (__builtin_popcount(x >> 1) + (x & 1)) : 0; }
#endif
template<typename T> inline T getint() {
	T val = 0;
	char c;

	bool neg = false;
	while ((c = getchar()) && !(c >= '0' && c <= '9')) {
		neg |= c == '-';
	}

	do {
		val = (val * 10) + c - '0';
	} while ((c = getchar()) && (c >= '0' && c <= '9'));

	return val * (neg ? -1 : 1);
}
//#define int long long
const ll INF = 1e9 + 100;
const int mod = 1000000007;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 1000010, maxT = 41, A = 179, K = 420;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	et %= mod;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "No solution\n";
	exit(0);
}
vector<ll>mx_b[21];
int r1[maxT][maxT][maxT];
int r2[maxT][maxT][maxT];
int sm[1 << 20];
int ln[1 << 20];
int vl[1 << 20];
void buildr1(int a, int b, vector<int>arr, int n) {
	for (int i = 0; i < maxT; ++i)
		for (int j = 0; j < maxT; ++j)
			for (int k = 0; k < maxT; ++k)r1[i][j][k] = -1;
	for (int i = 0; i < n; ++i)vl[1 << i] = arr[i];
	if (mx_b[n].empty()) {
		mx_b[n].assign(1 << n, 0);
		for (int i = 1; i < (1 << n); ++i) {
			int mx = n - 1;
			while ((i & (1 << mx)) == 0)--mx;
			mx_b[n][i] = 1 << mx;
		}
	}
	for (int i = 1; i < (1 << n); ++i) {
		int bit = mx_b[n][i];
		sm[i] = (sm[i ^ bit] * 10 + vl[bit]) % (a * b);
		//sm_b[i] = (sm_b[i ^ bit] * 10 + vl[bit]) % b;
		ln[i] = ln[i ^ bit] + 1;
	}
	for (int i = 0; i < (1 << n); ++i) {
		int j = ((1 << n) - 1) ^ i;
		r1[ln[i]][sm[i] % a][sm[j] % b] = i;
	}
}
void buildr2(int a, int b, vector<int>arr, int n) {
	for (int i = 0; i < maxT; ++i)
		for (int j = 0; j < maxT; ++j)
			for (int k = 0; k < maxT; ++k)r2[i][j][k] = -1;
	for (int i = 0; i < n; ++i)vl[1 << i] = arr[i];
	if (mx_b[n].empty()) {
		mx_b[n].assign(1 << n, 0);
		for (int i = 1; i < (1 << n); ++i) {
			int mx = n - 1;
			while ((i & (1 << mx)) == 0)--mx;
			mx_b[n][i] = 1 << mx;
		}
	}
	for (int i = 1; i < (1 << n); ++i) {
		int bit = mx_b[n][i];
		sm[i] = (sm[i ^ bit] * 10 + vl[bit]) % (a * b);
		//sm_b[i] = (sm_b[i ^ bit] * 10 + vl[bit]) % b;
		ln[i] = ln[i ^ bit] + 1;
	}
	for (int i = 0; i < (1 << n); ++i) {
		int j = ((1 << n) - 1) ^ i;
		r2[ln[i]][sm[i] % a][sm[j] % b] = i;
	}
}
void solve() {
	int n, a, b;
	cin >> n >> a >> b;
	vector<int>arr(n);
	for (auto& x : arr) {
		char t;
		cin >> t;
		x = t - '0';
	}
	int l1 = n / 2, l2 = (n + 1) / 2;
	vector<int>f, s;
	for (int i = 0; i < n; ++i) {
		if (i < l1)f.push_back(arr[i]);
		else s.push_back(arr[i]);
	}
	ll msk = 0;
	ll res = INF;
	vector<ll>pw_a(n + 1, 1), pw_b(n + 1, 1);
	for (int i = 1; i <= n; ++i) {
		pw_a[i] = pw_a[i - 1] * 10 % a;
		pw_b[i] = pw_b[i - 1] * 10 % b;
	}
	buildr1(a, b, f, l1);
	buildr2(a, b, s, l2);
	for (int l = 0; l <= l1; ++l) {
		for (int oa = 0; oa < a; ++oa) {
			for (int ob = 0; ob < b; ++ob) {
				if (r1[l][oa][ob] == -1)
					continue;
				//if (abs(n - l - r - l - r) >= res)
				for (int r = 0; r <= l2; ++r) {
					if (abs(n - l - r - l - r) >= res)
						continue;
					int add_a = r, add_b = l2 - r;
					ll ta = oa * pw_a[add_a] % a;
					ll tb = ob * pw_b[add_b] % b;
					ta = (a - ta) % a;
					tb = (b - tb) % b;
					if (r2[r][ta][tb] == -1)
						continue;
					res = abs(n - l - r - l - r);
					msk = (((ll)r2[r][ta][tb]) << l1) | r1[l][oa][ob];
				}
			}
		}
	}
	if (res >= n) {
		cout << "-1\n";
		return;
	}
	for (int i = 0; i < n; ++i) {
		if ((msk & (1LL << i)) != 0)cout << 'R';
		else cout << 'B';
	}
	cout << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.in", "r", stdin); freopen("input.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
7 7
1 2
2 3
3 4
4 5
2 5
5 6
6 7
5
4 3 2 5 6 7
1
*/