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
#define pb push_back
#define mp make_pair
#define F first
#define S second
using namespace std;
//using namespace __gnu_pbds;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
//typedef tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update> bst;
namespace input {
	template<class T> inline void _R(T &x) {cin >> x;}
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
	template<class T> inline void _W(const T& x) {cout << x << ' ';}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(p.second);}
	template<class T> inline void _W(const vector<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const deque<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const forward_list<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const list<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const set<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const multiset<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const unordered_set<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T> inline void _W(const unordered_multiset<T>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {for (auto i : x) cout << i << ' ';}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {for (auto i : x) cout << i << ' ';}

 	inline void W() {cout << '\n';}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); W(y...);}
} using namespace output;



int main() {
	int n,m,k,q; R(n,m,k,q);
	vector<vector<int> > vv(n+1);
	
	int maxn = 0;
	
	for (int i = 0; i < k; i++) {
		int r,c; R(r,c);
		vv[r].pb(c);
		maxn = max(maxn,r);
	}
	n = maxn;
	
	vector<int> safe(q);
	for (int i = 0; i < q; i++)
		R(safe[i]);
	sort(safe.begin(),safe.end());
		
	int left[n+1], right[n+1];
	ll dp1[n+1],dp2[n+1];

	if (!vv[1].empty()) {
		sort(vv[1].begin(),vv[1].end());
		//W(vv[1],"WOW");
		left[1] = right[1] = vv[1].back();
		dp1[1] = dp2[1] = vv[1].back()-1;
	} else {
		left[1] = right[1] = 1;
		dp1[1] = dp2[1] = 0;
	}
	
	int last = 1;
	for (int i = 2; i <= n; i++) {
		if (vv[i].empty())
			continue;
			
		sort(vv[i].begin(),vv[i].end());
		//W(vv[i],"WOW");
		left[i] = vv[i].front();
		right[i] = vv[i].back();

		//W(last,dp1[last],dp2[last]);

		dp1[i] = dp2[i] = LLINF;
		auto itleft = lower_bound(safe.begin(),safe.end(),left[last]);
		if (itleft != safe.end()) {
			//W(1);
			ll lastcost = dp1[last];
			ll cost = abs(left[last]-*itleft);
			ll path = right[i]-left[i];
			ll leftfirst = abs(*itleft-left[i]);
			ll rightfirst = abs(*itleft-right[i]);
			//W(lastcost,cost,path,leftfirst,rightfirst);
			dp1[i] = min(dp1[i],lastcost+cost+path+rightfirst);
			dp2[i] = min(dp2[i],lastcost+cost+path+leftfirst);
			//W(dp1[i],dp2[i]);
		}
		
		auto itright = upper_bound(safe.begin(),safe.end(),left[last]);
		if (itright != safe.begin()) {
			//W(2);
			itright--;
			ll lastcost = dp1[last];
			ll cost = abs(left[last]-*itright);
			ll path = right[i]-left[i];
			ll leftfirst = abs(*itright-left[i]);
			ll rightfirst = abs(*itright-right[i]);
			//W(lastcost,cost,path,leftfirst,rightfirst);
			dp1[i] = min(dp1[i],lastcost+cost+path+rightfirst);
			dp2[i] = min(dp2[i],lastcost+cost+path+leftfirst);
			//W(dp1[i],dp2[i]);
		}
		
		itleft = lower_bound(safe.begin(),safe.end(),right[last]);
		if (itleft != safe.end()) {
			//W(3);
			ll lastcost = dp2[last];
			ll cost = abs(right[last]-*itleft);
			ll path = right[i]-left[i];
			ll leftfirst = abs(*itleft-left[i]);
			ll rightfirst = abs(*itleft-right[i]);
			//W(lastcost,cost,path,leftfirst,rightfirst);
			dp1[i] = min(dp1[i],lastcost+cost+path+rightfirst);
			dp2[i] = min(dp2[i],lastcost+cost+path+leftfirst);
			//W(dp1[i],dp2[i]);
		}

		itright = upper_bound(safe.begin(),safe.end(),right[last]);
		if (itright != safe.begin()) {
			//W(4);
			itright--;
			ll lastcost = dp2[last];
			ll cost = abs(right[last]-*itright);
			ll path = right[i]-left[i];
			ll leftfirst = abs(*itright-left[i]);
			ll rightfirst = abs(*itright-right[i]);
			//W(lastcost,cost,path,leftfirst,rightfirst);
			dp1[i] = min(dp1[i],lastcost+cost+path+rightfirst);
			dp2[i] = min(dp2[i],lastcost+cost+path+leftfirst);
			//W(dp1[i],dp2[i]);
		}
		//W(dp1[i],dp2[i]);
		last = i;
	}
	
	W(min(dp1[n],dp2[n])+n-1);
		
	return 0;
}

#ifndef LOCAL
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
#endif