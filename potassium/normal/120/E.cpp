#pragma GCC optimize ("Ofast")
//#pragma comment(linker, "/stack:200000000")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << ' '
#define EL << '\n'
#define FL << flush
#define sqr(x) ((x)*(x))
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define distinct(x) sort(all(x)); x.resize(unique(all(x))-x.begin());
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define FOR(i,l,r) for (int i = l; i < r; i++)
#define FORD(i,r,l) for (int i = r; i > l; i--)
#define CASE(x) int x; cin >> x; while (x--)
using namespace std;
//using namespace __gnu_pbds;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
typedef pair<ll,ll> pll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bst;
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
	template<class T1, class T2> inline void _R(pair<T1,T2> &x) {_R(x.first); _R(x.second);}
	template<class T> inline void _R(vector<T> &x) {for (auto& i : x) _R(i);}
	inline void R() {}
	template<class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
} using namespace input;
namespace overload_output {
	template<class T1, class T2> inline ostream& operator << (ostream& out, pair<T1,T2>& p) {return out << p.first << ' ' << p.second;}
	template<class T> inline ostream& operator << (ostream& out, vector<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, deque<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, forward_list<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, list<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, set<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, unordered_set<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T> inline ostream& operator << (ostream& out, unordered_multiset<T>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_map<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
	template<class T1, class T2> inline ostream& operator << (ostream& out, unordered_multimap<T1, T2>& x) {for (auto i : x) out << i << ' '; return out;}
} using namespace overload_output;
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

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace output;
namespace utility{
	inline ll pow(ll b, ll p, ll mod) {
		b %= mod;
		long long ans = 1;
		for (; p > 0; p >>= 1) {
			if (p&1) {ans *= b; ans %= mod;}
			b *= b;
			b %= mod;
		}
		return ans;
	}
} using namespace utility;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	CASE(t) {
	    int n; R(n);
	    if (n & 1) W(0); else W(1);
	}

	return 0;
}

static auto _batch_ios = [](){
	#ifndef LOCAL
	ios::sync_with_stdio(false);
	cin.tie(0);
	#endif
	cout << fixed << setprecision(12);
	return 42;
}();