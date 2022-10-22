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



struct triangle {
	int n[3];
};

int main() {
	CASE(t) {
		int n; R(n);
		
		vector<vector<int>> g(n+1);
		unordered_set<pii> seen;
		
		vector<set<int>> tri(n+1);
		vector<bool> isRemoved(n+1, 0);
		
		vector<triangle> inp(n+1);
		
		for (int i = 1; i <= n-2; i++) {
			int a,b,c; R(a,b,c);
			inp[i] = {a,b,c};
			tri[a].insert(i);
			tri[b].insert(i);
			tri[c].insert(i);
		}
		
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		for (int i = 1; i <= n; i++)
			pq.push({tri[i].size(), i});
			
		vector<int> order;
			
		while (!pq.empty()) {
			pii tmp = pq.top();
			int x = tmp.S;
			pq.pop();
			
			if (isRemoved[x]) continue;
			assert(tri[x].size() == 1);
			
			int num = *tri[x].begin();
			order.pb(num);
			
			vector<int> nodes;
			for (auto& i : inp[num].n)
				 if (i != x) nodes.pb(i);
			
			assert(nodes.size() == 2);
			
			for (int i = 0; i < 2; i++) {
				int a = x, b = nodes[i];
				if (a > b) swap(a,b);
				if (seen.count({a,b}) == 0) {
					g[a].pb(b);
					g[b].pb(a);
					seen.insert({a,b});
				}
			}
			
			if (nodes[0] > nodes[1]) swap(nodes[0], nodes[1]);
			if (order.size() == n-2 && seen.count({nodes[0], nodes[1]}) == 0) {
				g[nodes[0]].pb(nodes[1]);
				g[nodes[1]].pb(nodes[0]);
			}
			seen.insert({nodes[0], nodes[1]});
			
			for (auto& i : inp[num].n) {
				tri[i].erase(num);
				if (tri[i].size() > 0) pq.push({tri[i].size(), i});
			}
			
			isRemoved[x] = 1;
			if (order.size() == n-2) break;
		}
		
		vector<int> cyc;
		int h = 1;
		vector<bool> isSeen(n+1, 0);
		while (cyc.size() < n) {
			cyc.pb(h);
			isSeen[h] = 1;
			if (isSeen[g[h][0]]) h = g[h][1]; else h = g[h][0];
		}
		
		W(cyc);
		W(order);
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