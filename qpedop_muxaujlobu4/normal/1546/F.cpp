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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 70010, maxT = 25000, A = 179, mid = 150;
mt19937 mt_rand(time(0));
ll bp(ll et, ll b) {
	b %= mod - 1;
	ll res = 1;
	for (int i = 30; i >= 0; --i) {
		res = (res * res) % mod;
		if ((b & (1 << i)) != 0)res = (res * et) % mod;
	}
	return res;
}
void panic() {
	cout << "-1\n";
	exit(0);
}
void solve() {
	int m, n;
	cin >> m >> n;
	vector<ll>sum(n);
	vector<vector<ll>>a(n, vector<ll>(m));
	map<ll, ll>vls;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			sum[i] += a[i][j];
		}
		if (i)
			++vls[sum[i] - sum[i - 1]];
	}
	ll v;
	for (auto x : vls) {
		if (x.second >= n - 3) {
			v = x.first;
		}
	}
	int ans = -1;
	for (int i = 1; i < n && ans == -1; ++i) {
		if (sum[i] - sum[i - 1] != v) {
			if (i == 1 && sum[i + 1] - sum[i] == v) {
				ans = 0;
			}
			else {
				ans = i;
			}
		}
	}
	vector<vector<ld>>gauss;
	for (int i = 0; i < n; ++i) {
		if (i == ans || gauss.size() == 3) {
			continue;
		}
		gauss.push_back({});
		gauss.back().push_back(1);
		gauss.back().push_back(2 * i);
		gauss.back().push_back(i * i);
		ld vll = 0;
		for (int j = 0; j < m; ++j) {
			vll += a[i][j] * a[i][j];
		}
		gauss.back().push_back(vll);
	}
	for (int i = 0; i < 3; ++i) {
		for (int j = i + 1; j < 3; ++j) {
			if (abs(gauss[i][i]) < abs(gauss[j][i]))
				swap(gauss[i], gauss[j]);
		}
		for (int j = 0; j < 3; ++j) {
			if (i == j)
				continue;
			ld d = gauss[j][i] / gauss[i][i];
			for (int k = 0; k < 4; ++k) {
				gauss[j][k] -= d * gauss[i][k];
			}
		}
	}
	ll tt = ll(gauss[0].back() / gauss[0][0] + 0.5) + 2 * ans * ll(gauss[1].back() / gauss[1][1] + 0.5)
		+ ans * ans * ll((gauss[2].back() / gauss[2][2]) + 0.5);
	int bb = -1;
	vector<ll>vec = a[ans];
	ll dlt;
	//??
	if (ans == 0) {
		dlt = -(v - (sum[ans + 1] - sum[ans]));
	}
	else {
		dlt = v - (sum[ans] - sum[ans - 1]);
	}
	for (int i = 0; i < m; ++i) {
		vec[i] += dlt;
		ll tmp = 0;
		for (int j = 0; j < m; ++j)
			tmp += vec[j] * vec[j];
		if (tmp == tt) {
			bb = vec[i];
			break;
		}
		vec[i] -= dlt;
	}
	cout << ans << " " << bb << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("gymnasts.in", "r", stdin); freopen("gymnasts.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}