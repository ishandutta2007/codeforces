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
	/*struct weight {
	};*/
	
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

void dijkstra(graph &G, int src, vector<long long> &dist) {
	dist.clear();
	dist.resize(G.size(),LLINF);
	
	bool isFinalized[G.size()];	
	memset(isFinalized,0,G.size());
			
	priority_queue<pair<graph::weight,int>, vector<pair<graph::weight,int> >, greater<pair<graph::weight,int> > > pq;
	pq.push({0,src});
	dist[src] = 0;
		
	while (!pq.empty()) {
		long long ndist = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		
		if (isFinalized[node])
			continue;				
		isFinalized[node] = 1;
			
		for (auto i : G.adj(node)) {
			if (ndist + i.first < dist[i.second]) {
				dist[i.second] = ndist + i.first;
				pq.push({dist[i.second],i.second});
			}
		}
	}
}

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n,m;
		cin >> n >> m;
		graph G(n+1);
		for (int i = 0; i < m; i++) {
			int u,v;
			cin >> u >> v;
			G.addedge(u,v,1);
		}
		vector<long long> dist;
		dijkstra(G,1,dist);
		vector<int> v0,v1;
		for (int i = 1; i <= n; i++)
			if (dist[i] % 2)
				v1.pb(i);
			else
				v0.pb(i);
		if (v1.size() < v0.size()) {
			cout << v1.size() EL;
			for (auto i : v1)
				cout << i SP;
			cout EL;
		} else {
			cout << v0.size() EL;
			for (auto i : v0)
				cout << i SP;
			cout EL;
		}
	}
	
	return 0;
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
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();