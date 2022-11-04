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
const double eps = 1e-11, pi = acos(-1);
const ll maxN = 400010, maxT = 600100, A = 179, K = 170;
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
vector<ll>t;
int sz = 1;
void add(int v, int vl) {
	for (v |= sz; v; v >>= 1) {
		t[v] += vl;
	}
}
int get(int l, int r) {
	int res = 0;
	for (l += sz, r += sz; l <= r; l >>= 1, r >>= 1) {
		if (l % 2 == 1)res += t[l++];
		if (r % 2 == 0)res += t[r--];
	}
	return res;
}
set < pair<ll, ll>>compress(set<pair<ll, ll>>seg) {
	set<pair<ll, ll>>ans;
	//if (seg.size() <= 7900) {
	//	for (auto x : seg) {
	//		bool f = 1;
	//		for (auto y : seg) {
	//			if (x == y)
	//				continue;
	//			if (y.first >= x.first && x.second >= y.second) {
	//				f = 0;
	//				break;
	//			}
	//		}
	//		if (f)ans.insert(x);
	//	}
	//	return ans;
	//}
	vector<ll>vls;
	for (auto x : seg) {
		vls.push_back(x.first);
		vls.push_back(x.second);
	}
	sort(vls.begin(), vls.end());
	vls.resize(unique(vls.begin(), vls.end()) - vls.begin());
	vector<ll>v(vls.size(), INF);
	sz = 1;
	while (sz < vls.size())
		sz <<= 1;
	t.assign(2 * sz, 0);
	for (auto x : seg) {
		x.first = lower_bound(vls.begin(), vls.end(), x.first) - vls.begin();
		x.second = lower_bound(vls.begin(), vls.end(), x.second) - vls.begin();
		v[x.first] = min(v[x.first], x.second);
	}
	for (int i = (int)vls.size() - 1; i >= 0; --i) {
		if (v[i] == INF)
			continue;
		if (get(i, v[i]))
			continue;
		add(v[i], 1);
		ans.insert({ vls[i],vls[v[i]] });
	}
	return ans;
}
void solve() {
	int n, m;
	cin >> n >> m;
	vector<ll>a(n);
	set<ll>p;
	set<pair<ll, ll>>seg;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		p.insert(a[i]);
	}
	for (int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		if (seg.count({ l,r }) || p.upper_bound(r) != p.lower_bound(l))
			continue;
		seg.insert({ l,r });
	}
	sort(a.begin(), a.end());
	/*if (seg.size() > 1000) {
		cout << seg.size() << endl;
	}*/
	if (seg.empty()) {
		cout << "0\n";
		return;
	}
	seg = compress(seg);
	vector<vector<ll>>dp(2, vector<ll>(n, INF));
	dp[1][0] = dp[0][0] = 0;
	if ((*seg.begin()).second < a[0]) {
		dp[0][0] = abs(a[0] - (*seg.begin()).second);
		dp[1][0] = dp[0][0] * 2;
	}
	for (int i = 1; i < n; ++i) {
		vector<pair<ll, ll>>s;
		auto it = seg.lower_bound({ a[i - 1],0 });
		while (it != seg.end() && (*it).second < a[i]) {
			s.push_back(*it++);
		}
		if (s.empty()) {
			dp[1][i] = dp[0][i] = min(dp[0][i - 1], dp[1][i - 1]);
		}
		else {
			dp[0][i] = min(dp[0][i], min(dp[0][i - 1], dp[1][i - 1]) + abs(a[i] - s[0].second));
			dp[1][i] = min(dp[1][i], min(dp[0][i - 1], dp[1][i - 1]) + 2 * abs(a[i] - s[0].second));
			dp[0][i] = min(dp[0][i], min(dp[0][i - 1] + 2 * abs(s.back().first - a[i - 1]),
				dp[1][i - 1] + abs(s.back().first - a[i - 1])));
			dp[1][i] = min(dp[1][i], min(dp[0][i - 1] + 2 * abs(s.back().first - a[i - 1]),
				dp[1][i - 1] + abs(s.back().first - a[i - 1])));
			int sz = s.size();
			for (int j = 0; j + 1 < sz; ++j) {
				ll add = min(dp[0][i - 1] + 2 * abs(s[j].first - a[i - 1]),
					dp[1][i - 1] + abs(s[j].first - a[i - 1]));
				dp[0][i] = min(dp[0][i], add + abs(a[i] - s[j + 1].second));
				dp[1][i] = min(dp[1][i], add + 2 * abs(a[i] - s[j + 1].second));
			}
		}
	}
	ll ans = min(dp[0].back(), dp[1].back());
	if ((*seg.rbegin()).first > a.back()) {
		ll d = abs((*seg.rbegin()).first - a.back());
		ans = min(dp[0].back() + 2 * d, dp[1].back() + d);
	}
	cout << ans << '\n';
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