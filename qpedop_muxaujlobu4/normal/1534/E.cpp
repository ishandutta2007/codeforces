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
	cout << "-1" << endl;
	exit(0);
}
int n, k;
ll qw(vector<int>id) {
	cout << "? ";
	for (auto x : id)cout << x << " ";
	cout << endl;
	ll v;
	cin >> v;
	return v;
}
void solve() {
	int n, k;
	cin >> n >> k;
	/*if (n < 2 * k && n % 2 == 1 && k % 2 == 0) {
		cout << -1 << endl;
		return;
	}*/
	int vl = 1;
	ll ans = 0;
	if (n % k != 0) {
		int ln = -1;
		for (int add = 2; add <= 2 * k && add + k - add / 2 <= n; add += 2) {
			if ((n - add) % k == 0) {
				ln = add;
			}
		}
		if (ln == -1) {
			if (n % 2 == 1) {
				cout << -1 << endl;
			}
			else {
				for (int add = 2; add <= 2 * k && add + k - add / 2 <= n; add += 2) {
					ln = add;
				}
				while (vl <= n) {
					ln = min(ln, n - vl + 1);
					vector<int>f, s;
					int tmp = vl;
					for (int i = 0; i < ln / 2; ++i) {
						f.push_back(vl++);
						s.push_back(vl++);
					}
					for (int i = 1; i <= n; ++i) {
						if ((i<tmp || i>tmp + ln - 1) && f.size() < k) {
							f.push_back(i);
							s.push_back(i);
						}
					}
					ans ^= qw(f) ^ qw(s);
				}
				cout << "! " << ans << endl;
			}
			return;
		}
		vector<int>f, s;
		for (int i = 0; i < ln / 2; ++i) {
			f.push_back(vl++);
		}
		for (int i = 0; i < ln / 2; ++i) {
			s.push_back(vl++);
		}
		for (int i = 0; i < k - ln / 2; ++i) {
			f.push_back(vl + i);
			s.push_back(vl + i);
		}
		ans ^= qw(f) ^ qw(s);
	}
	while (vl <= n) {
		vector<int>q;
		for (int i = 0; i < k; ++i) {
			q.push_back(vl++);
		}
		ans ^= qw(q);
	}
	cout << "! " << ans << endl;
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