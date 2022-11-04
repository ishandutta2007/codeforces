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
const ll INF = 1e18 + 100;
const int mod = 1000000007;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200100, maxT = 61, A = 179, mid = 150;
ll bp(ll et, ll b) {
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
mt19937 mt_rand(time(0));
ll f[maxN], g[maxN];
void bld() {
	f[0] = g[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = f[i - 1] * i % mod;
		g[i] = bp(f[i], mod - 2);
	}
	/*g[maxN - 1] = bp(f[maxN - 1], mod - 2);
	for (int i = maxN - 2; i >= 0; --i) {
		g[i] = g[i + 1] * (i + 1) % mod;
	}*/
}
ll c(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
void simle_solve(int n, int k) {
	vector<int>a(n);
	set<vector<int>>s;
	ll ans = 0, sum = 0;
	for (int i = 0; i < n; ++i)
		a[i] = i;
	do {
		vector<int>r;
		for (int j = 0; j < n; ++j) {
			r.push_back(a[j]);
			bool f = 1;
			for (int i = 0; i < j; ++i) {
				if (abs(a[i] - a[j]) < k) {
					f = 0;
				}
			}
			if (f == 0) {
				s.insert(r);
				break;
			}
		}
	} while (next_permutation(a.begin(), a.end()));
	for (auto x : s) {
		ans += x.size();
	}
	sum = s.size();
	cout << ans << " " << sum << "\n";
}
void solve() {
	int n, k;
	cin >> n >> k;
	vector<ll>dp(n + 2, 0);
	for (int i = 1; i <= n; ++i) {
		ll cnt = (ll)(i - 1) * (k - 1) + i;
		if (cnt > n)
			continue;
		ll c1 = n - cnt;
		ll tmp = c(i + c1, i) * f[i] % mod;
		dp[i] = tmp;
	}
	/*for (int i = n - 1; i >= 0; --i) {
		dp[i] = (dp[i] - dp[i + 1] + mod) % mod;
	}*/
	ll ans = 0;
	ll sum = 0;
	for (int i = 2; i <= n; ++i) {
		ll all = (dp[i - 1] * (n - i + 1) % mod - dp[i] + mod) % mod;
		sum = (sum + all) % mod;
		//cout << i << " " << all << "\n";
		ans = (ans + all * i % mod * f[n - i]) % mod;
	}

	cout << ans * g[n] % mod << "\n";
	//cout << ans << " " << sum << "\n";
	//simle_solve(n, k);
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	bld();
	int t = 1;
	cin >> t;
	
	//cout << 166666670LL * 14 % mod << endl;
	while (t--) {
		solve();
	}
	return 0;
}