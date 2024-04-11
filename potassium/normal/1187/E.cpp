#include <bits/stdc++.h>
#define INF 2147483647
#define LLINF LLONG_MAX
#define PI 3.1415926535
#define MOD 1000000007
#define MOD2 998244353
#define SP << " "
#define EL << "\n"
#define FL << flush
#define sqr(x) ((x)*(x))
#define pb push_back
#define ll long long
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
} g(200007);

ll dp[200007];
ll subtree[200007];
bool isVisited[200007];
ll ans = 0;

void dfs(int node) {
	isVisited[node] = 1;
	for (auto i : g.adj(node))
		if (!isVisited[i.second]) {
			dfs(i.second);
			subtree[node] += subtree[i.second];
			dp[node] += dp[i.second];
		}
	subtree[node]++;
	dp[node] += subtree[node];
}

void dfs2(int node) {
	isVisited[node] = 1;
	for (auto i : g.adj(node)) {
		if (!isVisited[i.second]) {
			subtree[node] -= subtree[i.second];
			dp[node] -= dp[i.second] + subtree[i.second];
			subtree[i.second] += subtree[node];
			dp[i.second] += dp[node] + subtree[node];
			
			ans = max(ans,dp[i.second]);
			dfs2(i.second);
			
			subtree[i.second] -= subtree[node];
			dp[i.second] -= dp[node] + subtree[node];
			subtree[node] += subtree[i.second];
			dp[node] += dp[i.second] + subtree[i.second];
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n-1; i++) {
		int u,v;
		cin >> u >> v;
		g.addedge(u,v,1);
	}
	dfs(1);
	ans = dp[1];
	for (int i = 1; i <= n; i++)
		isVisited[i] = 0;
	dfs2(1);
	
	cout << ans;
	
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
/*
static auto _batch_ios = [](){
	ios::sync_with_stdio(false);
	cin.tie(0);
	return 42;
}();
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