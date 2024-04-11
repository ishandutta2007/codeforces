#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
#define pr(...) dbs(#__VA_ARGS__, __VA_ARGS__)
template <class T> void dbs(string str, T t) {cout << str << " : " << t << endl;}
template <class T, class... S> void dbs(string str, T t, S... s) {int idx = str.find(','); cout << str.substr(0, idx) << " : " << t << ","; dbs(str.substr(idx + 1), s...);}
template <class S, class T>ostream& operator <<(ostream& os, const pair<S, T>& p) {return os << "(" << p.first << ", " << p.second << ")";}
template <class T>ostream& operator <<(ostream& os, const vector<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T>ostream& operator <<(ostream& os, const set<T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class S, class T>ostream& operator <<(ostream& os, const map<S, T>& p) {os << "[ "; for (auto& it : p) os << it << " "; return os << "]";}
template <class T> void prc(T a, T b) {cout << "["; for (T i = a; i != b; ++i) {if (i != a) cout << ", "; cout << *i;} cout << "]"; cout << endl;}
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
};
map<int, int> leaf;
map<int, int> rleaf;
void build(DinicFlow& G, int no, int l, int r) {
	if (l == r) {
		leaf[l] = no;
		rleaf[no] = l;
		return;
	}
	int mid = (l + r) / 2;
	G.addEdge(no, 2*no, 10000);
	G.addEdge(no, 2*no+1, 10000);
	build(G, 2*no, l, mid);
	build(G, 2*no+1, mid+1, r);
}
void qry(DinicFlow& G, int w, int no, int l, int r, int u, int v) {
	if (r < u or l > v) return;
	if (l >= u and r <= v) {
		G.addEdge(w, no, 1);
		return;
	}
	int mid = (l + r)/2;
	qry(G, w, 2*no, l, mid, u, v);
	qry(G, w, 2*no+1, mid+1, r, u, v);
}
int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, m; cin >> n >> m;
	DinicFlow G(n + 4*m+10 + n + 2);
	build(G, 1, 1, m);

	int w = 0; // + i
	FOR (i, 1, m) w = max(w, leaf[i]);
	map<int, vi> t3;
	set<int> sp;

	FOR (i, 1, n) {
		int t; cin >> t;
		if (t == 0) {
			int k; cin >> k; while (k--) {
				int x; cin >> x;
				G.addEdge(w + i, leaf[x], 1);
			}
		} else if (t == 1) {
			int l, r; cin >> l >> r;
			qry(G, w+i, 1, 1, m, l, r);
		} else {
			int a, b, c; cin >> a >> b >> c;
			t3[i] = {a,b,c};
			sp.insert(a), sp.insert(b), sp.insert(c);
		}
	}


	int ctr = w + n;
	int source = ctr + n + 1, sink = source + 1;
	assert(sink < G.n);
	FOR (i, 1, n) {
		G.addEdge(source, w + i, 1);
	}
	FOR (i, 1, m) {
		if (!sp.count(i)) {
			G.addEdge(leaf[i], sink, 1);
		}
	}
	for (auto it : t3) {
		FOR (i, 0, 2) G.addEdge(leaf[it.S[i]], ctr + it.F, 1);
		G.addEdge(ctr + it.F, sink, 1);
	}

	int ans = G.maxFlow(source, sink) + 2 * sz(t3);
	cout << ans << "\n";
	map<int, int> bc;
	set<int> done;
	FOR (i, 1, n) {
		int r = w + i;
		while (!rleaf.count(r)) {
			int yo = 0;
			for (auto &it : G.adj[r]) {
				if (G.e[it].flow > 0) {
					G.e[it].flow--;
					r = G.e[it].y;
					yo = 1;
					break;
				}
			}
			if (yo == 0) break;
		}
		if (rleaf.count(r)) {
			bc[i] = rleaf[r];
			done.insert(rleaf[r]);
		}
	}
	assert(sz(bc) + 2*sz(t3) == ans);
	for (auto it : bc) cout << it.F <<  " " << it.S << "\n";
	for (auto it : t3) {
		int fuck = 0;
		FOR (i, 0, 2) {
			if (fuck < 2 and !done.count(it.S[i])) {cout << it.F << " " << it.S[i] << "\n"; ++fuck;}

		}
	}


	return 0;
}