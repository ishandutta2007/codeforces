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
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
namespace std {
    template <class T1, class T2> struct hash<pair<T1,T2>> {
    	std::size_t operator()(pair<T1,T2> _) const {
        	return hash<T1>{}(_.first) ^ hash<T2>{}(_.second);
    	}
    };
}



int main() {
	#define int long long
	CASE(m) {
		int n,t,a,b; R(n,t,a,b);
		vector<int> isHard(n); R(isHard);
		vector<int> mand(n); R(mand);
		
		map<int, pii> cnt;
		cnt[0] = {0,0};
		for (int i = 0; i < n; i++)
			if (isHard[i])
				cnt[mand[i]].S++;
			else
				cnt[mand[i]].F++;
			
		int re[2];
		re[0] = re[1] = 0;
		for (int i = 0; i < n; i++)
			re[isHard[i]]++;
			
		ll need[2];
		need[0] = need[1] = 0;
			
		int ans = 0;
		for (auto it = cnt.begin(); it != cnt.end(); ++it) {
			need[0] += it->S.F;
			need[1] += it->S.S;
			
			auto nxt = it;
			++nxt;
			ll realtime = t;
			if (nxt != cnt.end()) realtime = min(realtime, nxt->F - 1);
			ll needtime = need[0] * a + need[1] * b;
			
			//W(need[0], need[1], realtime, needtime);
			
			if (realtime < needtime) continue;
			
			int num = need[1];
			realtime -= need[1] * b;
			
			ll easy = min(re[0], realtime / a);
			realtime -= easy * a;
			num += easy;
			
			num += min(re[1] - need[1], realtime / b);
			
			ans = max(ans, num);
		}
		
		W(ans);
	}

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