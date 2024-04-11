#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

struct DinicFlow {
    struct edge {
        int x, y, cap, flow;
    };
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
        edge e1 = {from, to, cap, 0};
        edge e2 = {to, from, 0, 0};
        adj[from].push_back(e.size()); e.push_back(e1);
        adj[to].push_back(e.size()); e.push_back(e2);
    }

    int bfs() {
        queue <int> q;
        for (int i = 0; i <= n; ++i) d[i] = -1;
        q.push(source); d[source] = 0;
        while (!q.empty() and d[sink] < 0) {
            int x = q.front(); q.pop();
            for (int i = 0; i < (int)adj[x].size(); ++i) {
                int id = adj[x][i], y = e[id].y;
                if (d[y] < 0 and e[id].flow < e[id].cap) {
                    q.push(y); d[y] = d[x] + 1;
                }
            }
        }
        return d[sink] >= 0;
    }

    int dfs(int x, int flow) {
        if (!flow) return 0;
        if (x == sink) return flow;
        for (; cur[x] < (int)adj[x].size(); ++cur[x]) {
            int id = adj[x][cur[x]], y = e[id].y;
            if (d[y] != d[x] + 1) continue;
            int pushed = dfs(y, min(flow, e[id].cap - e[id].flow));
            if (pushed) {
                e[id].flow += pushed;
                e[id ^ 1].flow -= pushed;
                return pushed;
            }
        }
        return 0;
    }

    int maxFlow(int src, int snk) {
        this->source = src; this->sink = snk;
        int flow = 0;
        while (bfs()) {
            for (int i = 0; i <= n; ++i) cur[i] = 0;
            while (int pushed = dfs(source, inf)) {
                flow += pushed;
            }
        }
        return flow;
    }
    vi DFS(int u) {
    	vi vis(n);
    	stack<int> s;
    	s.push(u);vis[u]=1;
    	while (!s.empty()) {
    		int x= s.top();
    		s.pop();
    		for (int E: adj[x]) {
    			auto ee = e[E];
    			if (ee.flow < ee.cap and !vis[ee.y]) {
    				s.push(ee.y);
    				vis[ee.y] = 1;
    			}
    		}
    	}
    	return vis;
    }
};
struct DSU {
	vi p, r;
	DSU(int n):p(n),r(n){FOR(i, 0, n - 1)p[i] = i;}

	int get(int i) {
		if (p[i] != i)p[i] = get(p[i]);
		return p[i];
	}
	int connect(int i, int j) {
		int x = get(i), y = get(j);
		if (x == y) return 0;
		if (r[x] > r[y]) swap(x, y);
		p[x] = y;
		if (r[x] == r[y]) ++r[y];
		return 1;
	}
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n; cin >> n;
	vector<ii> a(n);
	FOR (i, 0, n - 1) cin >> a[i].F >> a[i].S;

	map<int, vi> hmp, vmp;
	FOR (i, 0, n - 1) hmp[a[i].F].push_back(i), vmp[a[i].S].push_back(i);

	vector<ii> hcan, vcan;
	

	for (auto it: hmp) {
		sort(all(it.S), [&](int x, int y) {return a[x].S < a[y].S;});
		FOR (i, 0, sz(it.S) - 2) {
			hcan.emplace_back(it.S[i], it.S[i + 1]);
		}
	}

	for (auto it: vmp) {
		sort(all(it.S), [&](int x, int y) {return a[x].F < a[y].F;});
		FOR (i, 0, sz(it.S) - 2) {
			vcan.emplace_back(it.S[i], it.S[i + 1]);
		}
	}
	DinicFlow G(sz(hcan) + sz(vcan) + 2);
	int source = G.n - 1, sink = G.n - 2;

	FOR (I, 0, sz(hcan) - 1) {
		auto i = hcan[I];
		FOR (J, 0, sz(vcan) - 1) {
			auto j = vcan[J];
			if (a[j.F].F < a[i.F].F and a[j.S].F > a[i.F].F) {
				if (a[i.F].S < a[j.F].S and a[i.S].S > a[j.F].S) {
					G.addEdge(I, sz(hcan) + J, 1e6);
				}
			}
		}
	}
	FOR (i, 0, sz(hcan) - 1) G.addEdge(source, i, 1);
	FOR (i, 0, sz(vcan) - 1) G.addEdge(i + sz(hcan), sink, 1);
	int f = G.maxFlow(source, sink);
	vi vis = G.DFS(source);
	DSU h(n), v(n);
	for (auto e: G.e) {
		if (e.x == source and vis[e.y]) {
			h.connect(hcan[e.y].F, hcan[e.y].S);
		} else if (e.y == sink and !vis[e.x]) {
			v.connect(vcan[e.x - sz(hcan)].F, vcan[e.x - sz(hcan)].S);
		}
	}

	vi mn(n, inf), mx(n, -inf);
	int x = 0;

	
	FOR (i, 0, n - 1) {
		x += v.get(i) == i;
		mn[v.get(i)] = min(mn[v.get(i)], a[i].F);
		mx[v.get(i)] = max(mx[v.get(i)], a[i].F);
	}
	cout << x << "\n";
	FOR (i, 0, n - 1) if (v.get(i) == i) {
		cout << mn[i] << " " << a[i].S << " " << mx[i] << " " << a[i].S << "\n";
	}

	x = 0;
	mn = vi(n, inf), mx = vi(n, -inf);
	FOR (i, 0, n - 1) {
		x += h.get(i) == i;
		mn[h.get(i)] = min(mn[h.get(i)], a[i].S);
		mx[h.get(i)] = max(mx[h.get(i)], a[i].S);
	}
	cout << x << "\n";
	FOR (i, 0, n - 1) if (h.get(i) == i) {
		cout << a[i].F << " " << mn[i] << " " << a[i].F << " " << mx[i] << "\n";
	}

	
	return 0;
}