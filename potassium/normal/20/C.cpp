#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << ' '
#define EL << '\n'
#define WSP cout << ' '
#define WEL cout << '\n'
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
#define mp make_pair
#define F first
#define S second
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
typedef long long ll;
using namespace std;
template <class T1, class T2> inline ostream& operator << (ostream& out, pair<T1,T2>& p) {return out << p.first << ',' << p.second;}
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
template <class T1, class T2> inline void _W(const pair<T1,T2>& p) {cout << p.first << ',' << p.second;}
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
template<class T> inline void _R(T& x) {cin >> x;}
inline void R() {}
template <class T1, class... T2> inline void R(T1 &x, T2 &...y) { _R(x); R(y...);}
template<class T> inline void _W(T& x) {cout << x << ' ';}
inline void W() {}
template <class T1, class... T2> inline void W(const T1 &x, const T2 &...y) { _W(x); W(y...);}

template<class T>
struct graph{	
	private:
	int Vcnt;
	vector<vector<pair<T,int> > > _graph;
	public:	
	inline int size() {return Vcnt;}	
	inline vector<pair<T,int> >& adj(int node) {return _graph[node];}
	inline void addedge_onedir(int a, int b, T w){_graph[a].push_back({w,b});}
	inline void addedge(int a, int b, T w){addedge_onedir(a,b,w); addedge_onedir(b,a,w);}
	inline graph(int V) {_graph.resize(V); Vcnt = V;}
};
 
template<class T>
void dijkstra(graph<T> &G, int src, vector<T> &dist) {
	dist.clear(); dist.resize(G.size(),LLINF);
	bool isFinalized[G.size()];	memset(isFinalized,0,G.size());
			
	set<pair<T,int> > s;
	dist[src] = 0;
	s.insert({0,src});
		
	while (!s.empty()) {
		auto it = s.begin();
		T ndist = it->first;
		int node = it->second;
		s.erase(it);
		
		for (auto i : G.adj(node))
			if (ndist + i.first < dist[i.second]) {
				s.erase({dist[i.second],i.second});
				dist[i.second] = ndist + i.first;
				s.insert({dist[i.second],i.second});
			}
	}
}

int main() {
	int n,m; R(n,m);
	graph<ll> g(n+1);
	for (int i = 0; i < m; i++) {
		int a,b; ll w; R(a,b,w);
		g.addedge(a,b,w);
	}
	vector<ll> dist;
	dijkstra(g, 1, dist);
	
	int h = n;
	vector<int> path;
	if (dist[n] == LLINF) {
		W(-1);
		return 0;
	}
	
	while (h != 1) {
		path.pb(h);
		for (auto i : g.adj(h))
			if (dist[i.second] + i.first == dist[h]) {
				h = i.second;
				break;
			}
	}
	
	path.push_back(1);
	reverse(path.begin(),path.end());
	
	for (auto i : path)
		W(i);
				
	return 0;
}

static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();