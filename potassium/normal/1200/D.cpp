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
	template<class T> inline void _W(const T& x) {cout << x;}
	template<class T1, class T2> inline void _W(const pair<T1,T2>& p) {_W(p.first); _W(' '); _W(p.second);}
	template<class T> inline void _W(const vector<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const deque<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const forward_list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const list<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const unordered_set<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T> inline void _W(const unordered_multiset<T>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const map<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const unordered_map<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}
	template<class T1, class T2> inline void _W(const unordered_multimap<T1, T2>& x) {bool isFirst = 1; for (auto i : x) {if (!isFirst) cout << ' '; isFirst = 0; cout << i;}}

 	inline void W() {cout << '\n';}
	template<class T> inline void W(const T &x) {_W(x); W();}
	template<class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); _W(' '); W(y...);}
} using namespace output;



bool checkr[2007], checkc[2007];
string s[2007];
int anss[2007][2007];
int main() {
	int n,k; R(n,k);
	for (int i = 0; i < n; i++) R(s[i]);

	vector<vector<int> > r(n),c(n);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			if (s[i][j] == 'B') {
				r[i].pb(j);
				c[j].pb(i);
			}

	int ans = 0;
	int initial = 0;

	for (int i = 0; i < n; i++) {
		if (r[i].empty()) {initial++; checkr[i] = 1;} else if (r[i].back() - r[i].front() > k) checkr[i] = 1;
		if (c[i].empty()) {initial++; checkc[i] = 1;} else if (c[i].back() - c[i].front() > k) checkc[i] = 1;
	}
	
	for (int i = 0; i <= n-k; i++) {
		int rl = i, rr = i+k-1;
		int cur = 0;
		
		for (int j = 0; j < k; j++)
			if (checkc[j] == 0 && rl <= c[j].front() && c[j].back() <= rr)
				cur++;
				
		anss[i][0] = cur;
		for (int j = k; j < n; j++) {
			if (checkc[j] == 0 && rl <= c[j].front() && c[j].back() <= rr)
				cur++;
			if (checkc[j-k] == 0 && rl <= c[j-k].front() && c[j-k].back() <= rr)
				cur--;
			anss[i][j-k+1] = cur;
		}
	}

	for (int i = 0; i <= n-k; i++) {
		for (int j = 0; j <= n-k; j++) {
			ans = max(ans,anss[i][j]+initial);
		}
	}
	
	for (int i = 0; i <= n-k; i++) {
		int cl = i, cr = i+k-1;
		int cur = 0;

		for (int j = 0; j < k; j++)
			if (checkr[j] == 0 && cl <= r[j].front() && r[j].back() <= cr)
				cur++;

		anss[0][i] += cur;
		for (int j = k; j < n; j++) {
			if (checkr[j] == 0 && cl <= r[j].front() && r[j].back() <= cr)
				cur++;
			if (checkr[j-k] == 0 && cl <= r[j-k].front() && r[j-k].back() <= cr)
				cur--;
			anss[j-k+1][i] += cur;
		}
	}

	for (int i = 0; i <= n-k; i++) {
		for (int j = 0; j <= n-k; j++) {
			ans = max(ans,anss[i][j]+initial);
		}
	}

	W(ans);

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