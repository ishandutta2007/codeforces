#include <bits/stdc++.h>
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
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 rng64(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
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


template<class T>
struct indexer{
    private:
    map<T,int> id;
    vector<T> val;

    public:
    inline int getId(T x) {
        auto it = id.find(x);
        if (it == id.end()) {
            id[x] = val.size();
            val.push_back(x);
        }
        return id[x];
    }
    inline int operator[] (T x) {
        return getId(x);
    }

    inline T getVal(int id) {
        return val[id];
    }

    inline int size() {
        return id.size();
    }
};

ll dp[807][807];

inline ll& dist(int a, int b) {
	if (a > b) swap(a,b);
	return dp[a][b];
}

int main() {
	int n,m,k; R(n,m,k);
	vector<pair<int,pii> > v;
	v.reserve(m);
	for (int i = 0; i < m; i++) {
		int x,y,w;
		R(x,y,w);
		v.pb({w,{x,y}});
	}
	sort(v.begin(),v.end());
	v.resize(min(m,k));
	indexer<int> idx;
	for (auto& i : v) {
		i.second.first = idx[i.second.first];
		i.second.second = idx[i.second.second];
	}
	
	n = idx.size();
	
	ll inflength = 1e14;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			dp[i][j] = inflength;
			
	for (auto i : v)
		dist(i.second.first,i.second.second) = i.first;
	
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (dist(i,k) + dist(k,j) < dist(i,j))
					dist(i,j) = dist(i,k) + dist(k,j);
					
	vector<ll> ans;
	ans.reserve(n*n);
	for (int i = 0; i < n; i++)
		for (int j = i+1; j < n; j++)
			if (dist(i,j) != inflength)
				ans.pb(dist(i,j));
				
	sort(ans.begin(),ans.end());
	W(ans[k-1]);
	
	return 0;
}

#ifndef LOCAL
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
#endif