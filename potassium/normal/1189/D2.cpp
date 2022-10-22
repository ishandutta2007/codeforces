#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
//mt19937 x(chrono::steady_clock::now().time_since_epoch().count());
//mt19937_64 x(chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
template <class T1, class T2> ostream& operator << (ostream& out, pair<T1,T2> p);
template <template <class...> class _TContainer, class... _T> ostream& operator << (ostream& out, _TContainer<_T...>& _Container);

struct graph{
	public:
	typedef long long weight;
	
	private:
	int Vcnt;
	vector<vector<pair<weight,int> > > _graph;
	
	public:	
	inline int size() {
		return Vcnt;
	}	
	
	inline vector<pair<weight,int> >& adj(int node) {
		return _graph[node];
	}
	
	inline void addedge(int a, int b, weight w){
		addedge_onedir(a,b,w);
		addedge_onedir(b,a,w);
	}
	
	inline void addedge_onedir(int a, int b, weight w){
		_graph[a].push_back({w,b});
	}
	
	inline graph(int V) {
		_graph.resize(V);
		Vcnt = V;
	}
};

vector<bool> traversed(1010,0);
vector<vector<int> > leaf;
vector<vector<int> > ans;
int root = 1;
graph g(1010);

inline void add(int toNode, int val) {
	if (toNode == root) return;
	if (leaf[toNode].size() == 1)
		ans.pb({root,toNode,val});
	else {
		ans.pb({root,leaf[toNode][0],val/2});
		ans.pb({root,leaf[toNode][1],val/2});
		ans.pb({leaf[toNode][0],leaf[toNode][1],-val/2});
	}
}

inline void dfs(int node) {
	traversed[node] = 1;
	for (auto i : g.adj(node)) {
		if (!traversed[i.second]) {
			dfs(i.second);
			leaf[node].pb(leaf[i.second][0]);
			traversed[i.second] = 0;
		}
	}
	if (leaf[node].size() == 0) {
		leaf[node].pb(node);
		return;
	}
	for (auto i : g.adj(node))
		if (!traversed[i.second]) {
			add(i.second,i.first);
			add(node,-i.first);
		}
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		int u,v,w;
		cin >> u >> v >> w;
		g.addedge(u,v,w);
	}
	
	for (int i = 1; i <= n; i++)
		if (g.adj(i).size() == 2) {
			cout << "NO";
			return 0;
		}
		
	cout << "YES" EL;
	
	while (g.adj(root).size() != 1)
		root++;
		
	leaf.resize(n+10);
		
	dfs(root);
	
	cout << ans.size() EL;
	for (auto i : ans)
		cout << i[0] SP << i[1] SP << i[2] EL;
}
 
/*
  _____                                               _               _       _                   _ _ 
 |  __ \                                             (_)             (_)     | |                 | | |
 | |__) | __ ___   __ _ _ __ __ _ _ __ ___  _ __ ___  _ _ __   __ _   _ ___  | |__   __ _ _ __ __| | |
 |  ___/ '__/ _ \ / _` | '__/ _` | '_ ` _ \| '_ ` _ \| | '_ \ / _` | | / __| | '_ \ / _` | '__/ _` | |
 | |   | | | (_) | (_| | | | (_| | | | | | | | | | | | | | | | (_| | | \__ \ | | | | (_| | | | (_| |_|
 |_|   |_|  \___/ \__, |_|  \__,_|_| |_| |_|_| |_| |_|_|_| |_|\__, | |_|___/ |_| |_|\__,_|_|  \__,_(_)
                   __/ |                                       __/ |                                  
                  |___/                                       |___/                                                                                 
*/
 
template <class T1, class T2>
ostream& operator << (ostream& out, pair<T1,T2> p) {
	return out << '(' << p.first << ',' << p.second << ')';
}
template <template <class...> class _TContainer, class... _T>
ostream& operator << (ostream& out, _TContainer<_T...>& _Container) {	
    out << '[';
    bool first = 1;
    for(auto x : _Container) {
    	if (!first) out << ',';
    	out << x;
    	first = 0;
    }
    out << ']';
    return out;
}
/*
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
*/