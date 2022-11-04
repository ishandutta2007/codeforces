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
const int mod = 998244353;
const double eps = 4.5e-9, pi = acos(-1);
const ll maxN = 100010, maxT = 600100, A = 179, K = 170;
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
	cout << "No\n";
	exit(0);
}
string to_s(ull n) {
	string s;
	while (n) {
		s.push_back('0' + n % 10);
		n /= 10;
	}
	reverse(s.begin(), s.end());
	return s;
}
//int lcs(string a, string b) {
//	int n = a.length(), m = b.length();
//	vector<vector<int>>dp(n + 1, vector<int>(m + 1));
//	for (int i = 1; i <= n; ++i) {
//		for (int j = 1; j <= m; ++j) {
//			if (a[i - 1] == b[j - 1]) {
//				dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
//			}
//			dp[i][j] = max(dp[i][j], dp[i - 1][j]);
//			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
//		}
//	}
//	return dp.back().back();
//}
void solve() {
	int ans = 100;
	string s;
	cin >> s;
	vector<string>a;
	for (int i = 0; i < 64; ++i) {
		a.push_back(to_s(1ULL << i));
	}
	for (auto x : a) {
		int y = 0, j;
		for (j = 0; j < x.size(); ++j) {
			while (y < s.size() && s[y] != x[j])++y;
			if (y == s.size()) {
				ans = min(ans, (int)x.size() + (int)s.size() - 2 * j);
				break;
			}
			++y;
		}
		if (j == x.size()) {
			ans = min(ans, (int)s.size() - j);
		}
	/*	for (int i = 0; i < 1; ++i) {
			for (int j = 0; i + j <= x.size(); ++j) {
				if (lcs(s, x.substr(i, j)) == j) {
					ans = min(ans, (int)s.length() + (int)x.length() - 2 * j);
				}
			}
		}*/
		//ans = min(ans, (int)s.length() + (int)x.length() - 2 * lcs(s, x));
	}
	cout << ans << "\n";
}

int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
	srand(time(0));
#ifdef _DEBUG
	freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("flow.in", "r", stdin); freopen("flow.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
/*
2 2
1 1
1 1 2 1
2 1 2
*/