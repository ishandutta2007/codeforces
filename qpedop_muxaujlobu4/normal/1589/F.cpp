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
const int mod = 998244353;
const ld eps = 1e-11, pi = acos(-1);
const ll maxN = 300100, maxT = 510, A = 179, K = 450;
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
char char_by_code(int cd) {
	if (cd < 26)return 'a' + cd;
	cd -= 26;
	return 'A' + cd;
}
int code_by_char(char lett) {
	if ('a' <= lett && lett <= 'z')return lett - 'a';
	return lett - 'A' + 26;
}
vector<int>tp[52][1 << 10];
int used[52][1 << 10];
int n;
vector<int> idx[10][52];
void upd(vector<int>& lhs, const vector<int>&rhs) {
	if (rhs.size() > lhs.size())lhs = rhs;
}
vector<int> get(int cd, int msk) {
	if (used[cd][msk])return tp[cd][msk];
	used[cd][msk] = 1;
	for (int j = 0; j < n; ++j) {
		int nmb = (msk & (1 << j)) != 0;
		if (nmb >= idx[j][cd].size())return tp[cd][msk];
	}
	//if (msk == ((1 << n) - 1))upd(tp[cd][msk], get(cd, 0));
	for (int let = 0; let < 52; ++let) {
		bool go = true;
		//if (cd == 2 && msk == 3 && let == 14) {
		//	int b = 0;
		//}
		int msk1 = 0;
		for (int j = 0; j < n; ++j) {
			int my = idx[j][cd][(msk & (1 << j)) != 0];
			if (idx[j][let].empty() || idx[j][let][0] >= my)
			{
				go = false;
				break;
			}
			if (idx[j][let].size() == 2
				&& idx[j][let][1] < my)msk1 |= 1 << j;
		}
		if (go) {
			upd(tp[cd][msk], get(let, msk1));
		}
	}
	tp[cd][msk].push_back(cd);
	for (int i = 0; i < n; ++i) {
		int nmsk = msk ^ (1 << i);
		if (nmsk < msk) {
			upd(tp[cd][msk], get(cd, nmsk));
		}
	}
	return tp[cd][msk];
}
void solve() {
	cin >> n;
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < n; ++j)idx[j][i].clear();
		for (int j = 0; j < (1 << n); ++j) {
			used[i][j] = 0;
			tp[i][j].clear();
		}
	}
	for (int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); ++j) {
			int cd = code_by_char(s[j]);
			idx[i][cd].push_back(j);
		}
	}
	vector<int>ans;
	for (int i = 0; i < 52; ++i) {
		for (int j = 0; j < (1 << n); ++j) {
			upd(ans, get(i, j));
		}
	}
	cout << ans.size() << "\n";
	for (auto x : ans)cout << char_by_code(x);
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
	//freopen("hear.in", "r", stdin); freopen("hear.out", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	//cout << code_by_char('o') << "\n";
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