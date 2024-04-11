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
const ll maxN = 300010, maxT = 10010, A = 179, mid = 150;
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
const int byben_size = 23;
vector<int>merge(const vector<int>& a, const vector<int>& b, bool want_mx = true) {
	int s1 = a.size(), s2 = b.size();
	int sz = min(s1 + s2, byben_size);
	vector<int>r(sz);
	if (!want_mx) {
		int y1 = 0, y2 = 0;
		int y = 0;
		while (y < sz && y1 < s1 && y2 < s2) {
			if (a[y1] < b[y2])
				r[y++] = a[y1++];
			else 
				r[y++] = b[y2++];
		}
		while (y < sz && y1 < s1)
			r[y++] = a[y1++];
		while (y < sz && y2 < s2)
			r[y++] = b[y2++];
	}
	else {
		int y1 = s1 - 1, y2 = s2 - 1;
		int y = sz - 1;
		while (y >= 0 && y1 >= 0 && y2 >= 0) {
			if (a[y1] > b[y2])
				r[y--] = a[y1--];
			else
				r[y--] = b[y2--];
		}
		while (y >= 0 && y1 >= 0)
			r[y--] = a[y1--];
		while (y >= 0 && y2 >= 0)
			r[y--] = b[y2--];
	}
	return r;
}
vector<int>t[1 << 18];
int sz = 1 << 17;
int a[maxN];
vector<int>l1[maxN], r1[maxN];
inline void add(int l, int r, int id, bool want_mx) {
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l & 1) {
			int v = l++;
			t[v].push_back(id);
			int szz = t[v].size();
			int rr = szz;
			--szz;
			while (szz > 0 && t[v][szz] < t[v][szz - 1]) {
				swap(t[v][szz], t[v][szz - 1]);
				--szz;
			}
			if (rr > byben_size) {
				if (want_mx)
					t[v].erase(t[v].begin());
				else t[v].pop_back();
			}
		}
		if (~r & 1) {
			int v = r--;
			t[v].push_back(id);
			int szz = t[v].size();
			int rr = szz;
			--szz;
			while (szz > 0 && t[v][szz] < t[v][szz - 1]) {
				swap(t[v][szz], t[v][szz - 1]);
				--szz;
			}
			if (rr > byben_size) {
				if (want_mx)
					t[v].erase(t[v].begin());
				else t[v].pop_back();
			}
		}
	}
}
vector<int> get(int v, bool want_mx) {
	vector<int>r;
	v |= sz;
	for (v = v | sz; v; v >>= 1) {
		r = merge(t[v], r, want_mx);
	}
	return r;
}
ld pw[maxT];
void solve() {
	pw[0] = 1;
	for (int i = 1; i < maxT; ++i)
		pw[i] = pw[i - 1] * 2;
	int n = getint<int>();
	//cin >> n;
	for (int i = 1; i <= n; ++i) {
		//cin >> a[i];
		a[i] = getint<int>();
	}
	add(0, sz - 1, 0, 1);
	for (int i = 1; i <= n; ++i) {
		add(0, a[i], i, 1);
		l1[i] = get(a[i], 1);
	}
	for (int i = 0; i < 2 * sz; ++i)
		t[i].clear();
	add(0, sz - 1, n + 1, 0);
	for (int i = n; i > 0; --i) {
		add(0, a[i], i, 0);
		/*r1[i] = get(a[i] + 1, 0);
		r1[i].push_back(i);
		for (int j = r1[i].size() - 2; j >= 0; --j) {
			swap(r1[i][j], r1[i][j + 1]);
		}*/
		r1[i] = merge({ i }, get(a[i] + 1, 0), 0);
	}
	ld ans = 0;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < l1[i].size(); ++j) {
			for (int k = 0; k + 1 < r1[i].size(); ++k) {
				ll cnt = (ll)(l1[i][j] - l1[i][j - 1]) * (r1[i][k + 1] - r1[i][k]);
				int pww = k + l1[i].size() - j;
				if (pww > byben_size)
					break;
				ans += (ld)cnt / pw[pww] * a[i];
			}
		}
	}



	cout << fixed << ans / n / n << "\n";
}
int32_t main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cout.precision(20);
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