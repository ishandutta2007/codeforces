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
const ll maxN = 200010, maxT = 61, A = 179, mid = 150;
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
void solve() {
	int n, m;
	cin >> n >> m;
	map<int, int>mp;
	vector<int>a(n);
	vector<char>b(n);
	vector<pair<int, char>>f, s;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		mp[a[i]] = i;
	}
	for (int i = 0; i < n; ++i) {
		cin >> b[i];
		if (a[i] % 2 == 0) {
			f.push_back({ a[i],b[i] });
		}
		else
			s.push_back({ a[i],b[i] });
	}
	vector<int>ans(n, -1);
	sort(f.begin(), f.end());
	stack<pair<int, char>>st;
	for (auto x : f) {
		if (x.second == 'L' && !st.empty() && st.top().second == 'R') {
			int res = (x.first - st.top().first) / 2;
			ans[mp[st.top().first]] = res;
			ans[mp[x.first]] = res;
			st.pop();
			continue;
		}
		st.push(x);
	}
	pair<int, int>rr = { -1,-1 }, ll = { -1,-1 };
	while (!st.empty() && st.top().second == 'R') {
		pair<int, int>tmp = st.top();
		st.pop();
		if (st.empty() || st.top().second == 'L') {
			rr = tmp;
			break;
		}
		pair<int, int>tmp1 = st.top();
		st.pop();
		int res = (m - tmp.first + (tmp.first - tmp1.first) / 2);
		ans[mp[tmp.first]] = res;
		ans[mp[tmp1.first]] = res;
	}
	if (st.size() % 2 == 1) {
		ll = st.top();
		st.pop();
	}
	while (st.size()) {
		pair<int, int>tmp = st.top();
		st.pop();
		pair<int, int>tmp1 = st.top();
		st.pop();
		int res = (tmp1.first + (tmp.first - tmp1.first) / 2);
		ans[mp[tmp.first]] = res;
		ans[mp[tmp1.first]] = res;
	}
	if (ll.first != -1 && rr.first != -1) {
		int res = (ll.first + m - rr.first + m) / 2;
		ans[mp[ll.first]] = res;
		ans[mp[rr.first]] = res;
	}




	sort(s.begin(), s.end());
	for (auto x : s) {
		if (x.second == 'L' && !st.empty() && st.top().second == 'R') {
			int res = (x.first - st.top().first) / 2;
			ans[mp[st.top().first]] = res;
			ans[mp[x.first]] = res;
			st.pop();
			continue;
		}
		st.push(x);
	}
	rr = { -1,-1 }, ll = { -1,-1 };
	while (!st.empty() && st.top().second == 'R') {
		pair<int, int>tmp = st.top();
		st.pop();
		if (st.empty() || st.top().second == 'L') {
			rr = tmp;
			break;
		}
		pair<int, int>tmp1 = st.top();
		st.pop();
		int res = (m - tmp.first + (tmp.first - tmp1.first) / 2);
		ans[mp[tmp.first]] = res;
		ans[mp[tmp1.first]] = res;
	}
	if (st.size() % 2 == 1) {
		ll = st.top();
		st.pop();
	}
	while (st.size()) {
		pair<int, int>tmp = st.top();
		st.pop();
		pair<int, int>tmp1 = st.top();
		st.pop();
		int res = (tmp1.first + (tmp.first - tmp1.first) / 2);
		ans[mp[tmp.first]] = res;
		ans[mp[tmp1.first]] = res;
	}
	if (ll.first != -1 && rr.first != -1) {
		int res = (ll.first + m - rr.first + m) / 2;
		ans[mp[ll.first]] = res;
		ans[mp[rr.first]] = res;
	}





	for (auto x : ans) {
		cout << x << " ";
	}
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