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
const ll maxN = 1 << 20, maxT = 1010, A = 179, K = 450;
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
	cout << "impossible\n";
	exit(0);
}
ll calc(vector<ll>& dp, vector<ll>& sg, int l, int r) {
	if (r <= l)return 0;
	for (int i = l + 1; i <= r; ++i) {
		if (sg[i] >= l && sg[i] != -1)dp[i] = max(dp[i], dp[sg[i]] + 1);
		dp[i] = max(dp[i], dp[i - 1]);
	}
	return dp[r];
}
void solve() {
	int n, d;
	cin >> n >> d;
	vector<int>vls = { d };
	vector<pair<int, int>>f, s;
	for (int i = 0; i < n; ++i) {
		int a, b;
		cin >> a >> b;
		if (a < d)continue;
		vls.push_back(a);
		vls.push_back(b);
		if (a >= b) {
			f.push_back({ b,a });
		}
		else s.push_back({ a,b });
	}
	sort(vls.begin(), vls.end());
	vls.resize(unique(vls.begin(), vls.end()) - vls.begin());
	for (auto& x : f) {
		x.first = lower_bound(vls.begin(), vls.end(), x.first)
			- vls.begin();
		x.second = lower_bound(vls.begin(), vls.end(), x.second)
			- vls.begin();
	}
	for (auto& x : s) {
		x.first = lower_bound(vls.begin(), vls.end(), x.first)
			- vls.begin();
		x.second = lower_bound(vls.begin(), vls.end(), x.second)
			- vls.begin();
	}
	//swap(f, s);
	vector<ll>sg(vls.size(), vls.size());
	for (auto x : f)sg[x.first] = min(sg[x.first], (ll)x.second);
	for (int i = (int)vls.size() - 2; i >= 0; --i)sg[i] = min(sg[i], sg[i + 1]);
	int ans = f.size();
	for (auto& x : s)swap(x.first, x.second);
	sort(s.begin(), s.end());
	for (auto& x : s)swap(x.first, x.second);
	int mx = 0;
	for (auto x : s) {
		if (x.first < mx)continue;
		if (sg[x.first + 1] < x.second)continue;
		++ans;
		mx = max(mx, x.second);
	}
	cout << ans << endl;
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
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