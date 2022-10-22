#pragma GCC optimize ("O3", "unroll-loops")
//#pragma GCC target ("avx2")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define CASE(x) int x; cin >> x; while (x--)
#define CASEt(x) int x; cin >> x; for (int tc = 1; tc <= x; ++tc)
using namespace std;
using namespace __gnu_pbds;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template <class T> using ordered_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
} using namespace input;
namespace output {
	template<class T> inline void _W(const T& x) {cout << x;}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
	template<class T> inline void _W(const vector<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const deque<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const forward_list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2, class T3> inline void _W(const set<T1,T2,T3>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const unordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T> inline void _W(const unordered_multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2, class T3> inline void _W(const map<T1, T2, T3>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}
	
	template<class T> inline void _W(const ordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; _W(i);}}

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace output;
namespace output_format{
	inline string Case(int tc) {return "Case #" + to_string(tc) + ':';}
} using namespace output_format;
namespace utility{
	inline ll pow(ll b, ll p, ll mod) {
		b %= mod;
		ll ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
	template<class T> inline void sort(vector<T>& v) {sort(all(v));}
	inline bool chkmin(ll& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(ll& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, ll y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmin(int& x, int y) {return x > y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(ll& x, int y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, ll y) {return x < y ? x = y, 1 : 0;}
	inline bool chkmax(int& x, int y) {return x < y ? x = y, 1 : 0;}
} using namespace utility;


ll a[70], up[70], r1[70];
ll n,k;
int lbitn = -1;

inline int lbit(ll x) {
	bool isN = 0;
	if (x == n) isN = 1;
	if (isN && lbitn != -1) return lbitn;
	
	int cnt = 0;
	while (x > 0) {
		++cnt;
		x >>= 1;
	}
	
	if (isN) lbitn = cnt;
	
	return cnt;
}

inline ll solve(ll x) {
	if (x > n) return 0;
	ll ans = 0;
	if ((x & 1) == 0) ans += solve(x+1);

	int diff = lbit(n) - lbit(x);
	ans += (1LL << diff) - 1;
	
	ll sh = n >> diff;
	
	if (sh > x) ans += (1LL << diff);
	else if (sh == x) ans += r1[diff-1] + 1;
	
	//W(x, diff, sh, x, 1LL << diff, r1[diff-1] + 1, ans);
	
	return ans;
}

int main() {
	R(n,k);
	
	ll cop = n;
	for (int i = 0; i < 70; i++) {
		up[i] = cop & 1;
		if (i == 0) r1[i] = up[i]; else r1[i] = r1[i-1] + (up[i] << i);
		cop >>= 1;
	}
	
	ll ans = -1;
	
	ll oddcnt = (n+1)/2;
	ll evencnt = n/2;
	
	ll l = 1, r = oddcnt;
	while (r >= l) {
		ll mid = (l+r)/2;
		ll num = mid*2-1;
		
		ll cnt = solve(num);
		if (cnt >= k) l = mid+1; else r = mid-1;
	}
	
	chkmax(ans,r*2-1);
	
	l = 1, r = evencnt;
	while (r >= l) {
		ll mid = (l+r)/2;
		ll num = mid*2;

		ll cnt = solve(num);
		if (cnt >= k) l = mid+1; else r = mid-1;
	}
	
	chkmax(ans,r*2);
	
	W(ans);
	
    return 0;
}

static auto _batch_ios = [](){
	#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	#endif
	cout << fixed << setprecision(10);
	return 42;
}();