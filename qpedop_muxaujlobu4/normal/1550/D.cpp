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
const ll INF = 1e18 + 100;
const int mod = 1000000007;
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200010, maxT = 25000, A = 179, mid = 150;
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
ll f[maxN], g[maxN];
ll C(int n, int k) {
	return f[n] * g[k] % mod * g[n - k] % mod;
}
void solve() {
	ll n, l, r;
	cin >> n >> l >> r;
	vector<ll>c(4);
	c[0] = n;
	vector<ll>vls = { 0,INF };
	map<ll, vector< pair<int, int>> > mp;
	for (int i = 1; i <= n; ++i) {
		ll d1 = r - i, d2 = i - l;
		vls.push_back(d1);
		vls.push_back(d2);
		if (d1 == d2) {
			mp[d1].push_back({ 0,3 });
		}
		else {
			if (d1 > d2) {
				mp[d1].push_back({ 0,1 });
				mp[d2].push_back({ 1,3 });
			}
			else {
				mp[d2].push_back({ 0,2 });
				mp[d1].push_back({ 2,3 });
			}
		}
	}
	ll ans = 0;
	sort(vls.begin(), vls.end());
	vls.resize(unique(vls.begin(), vls.end()) - vls.begin());
	for (int i = vls.size() - 2; i >= 0; --i) {
		if (c[0] == 0 && c[1] <= (n + 1) / 2 && c[2] <= (n + 1) / 2) {
			int cnt = abs(c[1] - c[2]);
			if (c[3] < cnt) {
				ans = (ans + vls[i + 1] - vls[i]) % mod;
			}
			else {
				ll add;
				int tmp = c[3] - cnt;
				if (tmp % 2 == 1) {
					add = C(c[3], tmp / 2) + C(c[3], tmp / 2 + 1);
				}
				else add = C(c[3], tmp / 2);
				//add = add * 2 * C(tmp, tmp / 2);
				ans = (ans + (vls[i+1]-vls[i]) * add) % mod;
			}
		}
		for (auto x : mp[vls[i]]) {
			--c[x.first];
			++c[x.second];
		}
	}
	cout << ans << '\n';
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
	g[0] = f[0] = 1;
	for (int i = 1; i < maxN; ++i) {
		f[i] = (f[i - 1] * i) % mod;
		g[i] = bp(f[i], mod - 2);
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}