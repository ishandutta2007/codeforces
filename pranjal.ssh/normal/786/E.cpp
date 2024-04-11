#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (int i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(int i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; //const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]";cout<<endl;}
// Dinics Max Flow
// To put lower bound on edge capacities form a new graph G' with source s' and t'
// for each edge u->v in G with cap (low, high), replace it with
// s'->v with low
// v->t' with low
// u->v with high - low

const int inf = 0x3f3f3f3f;

struct edge {
    int x, y, cap, flow;
};
const int N = 2e4+10;
int p[N][15], d[N];
map<int, int> mp[N];
vi g[N];

void dfs(int i, int par) {
	p[i][0] = par;
	d[i] = d[par] + 1;
	for (int j: g[i]) {
		if (j == par)continue;
		dfs(j, i);
	}
}

struct DinicFlow {
    vector <edge> e;
    vector <int> cur, d;
    vector < vector <int> > adj;
    int n, source, sink;

    DinicFlow() {}

    DinicFlow(int v) {
        n = v;
        cur = vector <int> (n + 1);
        d = vector <int> (n + 1);
        adj = vector < vector <int> > (n + 1);
    }

    void addEdge(int from, int to, int cap) {
    	// pr(from, to, cap);
        edge e1 = {from, to, cap, 0};
        edge e2 = {to, from, 0, 0};
        adj[from].push_back(e.size()); e.push_back(e1);
        adj[to].push_back(e.size()); e.push_back(e2);
    }

    int bfs() {
        queue <int> q;
        for(int i = 0; i <= n; ++i) d[i] = -1;
        q.push(source); d[source] = 0;
        while(!q.empty() and d[sink] < 0) {
            int x = q.front(); q.pop();
            for(int i = 0; i < (int)adj[x].size(); ++i) {
                int id = adj[x][i], y = e[id].y;
                if(d[y] < 0 and e[id].flow < e[id].cap) {
                    q.push(y); d[y] = d[x] + 1;
                }
            }
        }
        return d[sink] >= 0;
    }

    int dfs(int x, int flow) {
        if(!flow) return 0;
        if(x == sink) return flow;
        for(;cur[x] < (int)adj[x].size(); ++cur[x]) {
            int id = adj[x][cur[x]], y = e[id].y;
            if(d[y] != d[x] + 1) continue;
            int pushed = dfs(y, min(flow, e[id].cap - e[id].flow));
            if(pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }
    set<int> sv, tv;
    void jaa(int x) {
    	if (sv.count(x)) return;
    	sv.insert(x);
    	for (auto it: adj[x]) {
    		if (e[it].flow < e[it].cap) {
    			jaa(e[it].y);
    		}
    	}
    }

    int maxFlow(int src, int snk) {
        this->source = src; this->sink = snk;
        int flow = 0;
        while(bfs()) {
            for(int i = 0; i <= n; ++i) cur[i] = 0;
            while(int pushed = dfs(source, inf)) {
                flow += pushed;
            }
        }
        return flow;
    }
};
DinicFlow G;
int n, m;
int lca(int u, int v, int w) {
	if (d[u] < d[v]) swap(u, v);
	NFOR (i, 14, 0) if (d[p[u][i]] >= d[v]) G.addEdge(w, u+i*n, inf), u = p[u][i];
	if (u == v) return u;
	NFOR (i, 14, 0) if (p[v][i] != p[u][i]) G.addEdge(w, u+i*n, inf), G.addEdge(w, v+i*n, inf), u = p[u][i], v = p[v][i];
	G.addEdge(w, u, inf), G.addEdge(w, v, inf);
	return p[u][0];
}

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m;
	FOR (i, 1, n - 1) {
		int u, v; cin >> u >> v;
		g[u].push_back(v), g[v].push_back(u);
		mp[u][v] = mp[v][u] = i;
	}
	dfs(1, 0);
	G = DinicFlow(n*15+m+5);
	FOR (i, 1, 14) {
		FOR (j, 1, n) {
			p[j][i] = p[p[j][i-1]][i-1];
			if (p[j][i]) {
				G.addEdge(j + i*n, j + (i-1)*n, inf);
				G.addEdge(j + i*n, p[j][i-1] + (i-1)*n, inf);
			}
		}
	}
	FOR (i, 1, m) {
		int u, v; cin >> u >> v;
		lca(u, v, 15*n + i);
		G.addEdge(0, 15*n + i, 1);
	}
	int sink = 15*n + m + 1;
	FOR (j, 1, n) {
		if (p[j][0]) {
			G.addEdge(j, sink, 1);
		}
	}
	int k = G.maxFlow(0, sink);
	cout << k << "\n";
	G.jaa(0);
	
	vi q, e;
	for (auto it : G.e) {
		if (G.sv.count(it.x) and (not G.sv.count(it.y)) and it.cap){
			if (it.x == 0) {
				q.push_back(it.y-15*n);
			}
			else {
				e.push_back(mp[it.x][p[it.x][0]]);
			}
		}
	}
	cout << sz(q) << " ";
	for (int it : q) cout << it << " ";
	cout << "\n";
	cout << sz(e) << " ";
	for (int it : e) cout << it << " ";
	cout << "\n";

	return 0;
}