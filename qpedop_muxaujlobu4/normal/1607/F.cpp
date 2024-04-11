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
const ll maxN = 2000, maxT = 1010, A = 179, K = 450;
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
char a[maxN][maxN];
int n, m;
char is_c[maxN][maxN];
int mx_len[maxN][maxN];
char used[maxN][maxN];
int deep[maxN][maxN];
vector<pair<int, int>>st;
void dfs(int i, int j) {
	used[i][j] = 1;
	st.push_back({ i,j });
	int add_i = 0, add_j = 0;
	if (a[i][j] == 'U')--add_i;
	if (a[i][j] == 'D')++add_i;
	if (a[i][j] == 'L')--add_j;
	if (a[i][j] == 'R')++add_j;
	if (i + add_i < n && i + add_i >= 0 && j + add_j < m && j + add_j >= 0) {
		if (used[i + add_i][j + add_j] == 1) {
			int idd = deep[i + add_i][j + add_j];
			int ans = deep[i][j] - deep[i + add_i][j + add_j] + 1;
			for (int t = idd; t < st.size(); ++t) {
				int x, y;
				tie(x, y) = st[t];
				is_c[x][y] = 1;
				mx_len[x][y] = ans;
			}
		}
		else {
			if (used[i + add_i][j + add_j] == 0) {
				deep[i + add_i][j + add_j] = deep[i][j] + 1;
				dfs(i + add_i, j + add_j);
			}
			if (!is_c[i][j]) {
				mx_len[i][j] = mx_len[i + add_i][j + add_j] + 1;
			}
		}
	}
	else {
		mx_len[i][j] = 1;
	}
	st.pop_back();
	used[i][j] = 2;
}
void solve() {
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cin >> a[i][j];
			is_c[i][j] = 0;
			mx_len[i][j] = 0;
			used[i][j] = 0;
			deep[i][j] = 0;
		}
	}
	int ans = -1;
	int i1 = 0, j1 = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (used[i][j])
				continue;
			dfs(i, j);
			if (mx_len[i][j] > ans) {
				ans = mx_len[i][j];
				i1 = i;
				j1 = j;
			}
		}
	}

	cout << i1 + 1 << " " << j1 + 1 << " " << ans << '\n';
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