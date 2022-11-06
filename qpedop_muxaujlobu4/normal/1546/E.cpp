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
const ld eps = 1e-10, pi = acosl(-1);
const ll maxN = 200010, maxT = 10000, A = 179, mid = 150;
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
	cout << "NO\n";
	exit(0);
}

void solve() {
	int n;
	cin >> n;
	vector<vector<int>>a(2 * n, vector<int>(n));
	vector<int>ans;
	int res = 1;
	for (auto& vec : a)
	{
		for (auto& x : vec) {
			cin >> x;
			--x;
		}
	}
	vector<vector<int>>ps(n, vector<int>(n));
	set<pair<int, int>>st;
	for (auto vec : a) {
		for (int i = 0; i < n; ++i) {
			++ps[i][vec[i]];
			if (ps[i][vec[i]] == 1) {
				st.insert({ i,vec[i] });
			}
			else {
				if (ps[i][vec[i]] == 2) {
					st.erase({ i,vec[i] });
				}
			}
		}
	}
	vector<int>used(2 * n);
	while (true) {
		int sum = 0;
		for (auto x : used) {
			sum += x;
		}
		if (sum == 2 * n)
			break;
		if (st.empty()) {
			res = (res * 2) % mod;
			int y = 0;
			while (used[y])
				++y;
			used[y] = 1;
			for (int i = 0; i < n; ++i) {
				--ps[i][a[y][i]];
				if (ps[i][a[y][i]] == 0) {
					st.erase({ i,a[y][i] });
				}
				if (ps[i][a[y][i]] == 1) {
					st.insert({ i,a[y][i] });
				}
			}
		}
		int ii, vl;
		tie(ii, vl) = *st.begin();
		st.erase(st.begin());
		int y = 0;
		while (used[y] || a[y][ii] != vl) {
			++y;
		}
		ans.push_back(y + 1);
		used[y] = 1;
		for (int i = 0; i < n; ++i) {
			--ps[i][a[y][i]];
			if (ps[i][a[y][i]] == 0) {
				st.erase({ i,a[y][i] });
			}
			if (ps[i][a[y][i]] == 1) {
				st.insert({ i,a[y][i] });
			}
		}
		for (int j = 0; j < 2 * n; ++j) {
			if (used[j])
				continue;
			for (int i = 0; i < n; ++i) {
				if (a[j][i] == a[y][i]) {
					used[j] = 1;
					for (int k = 0; k < n; ++k) {
						--ps[k][a[j][k]];
						if (ps[k][a[j][k]] == 0) {
							st.erase({ k,a[j][k] });
						}
						if (ps[k][a[j][k]] == 1) {
							st.insert({ k,a[j][k] });
						}
					}
					break;
				}
			}
		}
	}
	cout << res << "\n";
	for (auto x : ans)
		cout << x << " ";
	cout << "\n";
}
int main()
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
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}