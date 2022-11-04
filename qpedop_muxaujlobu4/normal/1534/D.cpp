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
const ll maxN = 300100, maxT = 61, A = 179, mid = 150;
mt19937 mt_rand(time(0));
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
int n;
vector<int>qw(int v) {
	cout << "? " << v << endl;
	vector<int>res(n);
	for (auto& x : res)cin >> x;
	return res;
}
void solve() {
	cin >> n;
	vector<int>tmp = qw(1);
	set<int>s1, s2;
	set<pair<int, int>>ans;
	for (int i = 0; i < n; ++i) {
		if (tmp[i] % 2 == 0)s1.insert(i);
		else s2.insert(i);
		if (tmp[i] == 1) {
			ans.insert({ 1,i + 1 });
		}
	}
	s1.erase(0);
	set<int>to_q;
	if (s2.size() < s1.size()) {
		to_q = s2;
	}
	else to_q = s1;
	for (auto x : to_q) {
		tmp = qw(x + 1);
		for (int i = 0; i < n; ++i) {
			if (tmp[i] == 1) {
				ans.insert({ min(i + 1,x + 1),max(i + 1,x + 1) });
			}
		}
	}
	cout << "!" << endl;
	for (auto x : ans) {
		cout << x.first << " " << x.second << endl;
	}
}
int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(10);
	//srand(time(0));
#ifdef _DEBUG
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}