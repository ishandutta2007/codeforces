#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

// edge class (for network-flow)
template<class FLOWTYPE> struct Edge {
    int rev, from, to;
    FLOWTYPE cap, icap;
    Edge(int r, int f, int t, FLOWTYPE c) : rev(r), from(f), to(t), cap(c), icap(c) {}
    friend ostream& operator << (ostream& s, const Edge& E) {
        if (E.cap > 0) return s << E.from << "->" << E.to << '(' << E.cap << ')';
        else return s;
    }
};

// graph class (for network-flow)
template<class FLOWTYPE> struct Graph {
    vector<vector<Edge<FLOWTYPE> > > list;
    
    Graph(int n = 0) : list(n) { }
    void init(int n = 0) { list.clear(); list.resize(n); }
    void reset() { for (int i = 0; i < (int)list.size(); ++i) for (int j = 0; j < list[i].size(); ++j) list[i][j].cap = list[i][j].icap; }
    inline vector<Edge<FLOWTYPE> >& operator [] (int i) { return list[i]; }
    inline const size_t size() const { return list.size(); }
    
    inline Edge<FLOWTYPE> &redge(Edge<FLOWTYPE> e) {
        if (e.from != e.to) return list[e.to][e.rev];
        else return list[e.to][e.rev + 1];
    }
    
    void addedge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, 0));
    }
    
    void add_undirected_edge(int from, int to, FLOWTYPE cap) {
        list[from].push_back(Edge<FLOWTYPE>((int)list[to].size(), from, to, cap));
        list[to].push_back(Edge<FLOWTYPE>((int)list[from].size() - 1, to, from, cap));
    }

    /* 
    // debug
    friend ostream& operator << (ostream& s, const Graph& G) {
        s << endl; for (int i = 0; i < G.V; ++i) { s << i << " : " << G.list[i] << endl; }return s;
    }
    */
};

template<class FLOWTYPE> struct Dinic {
    const FLOWTYPE INF = 1<<30; // to be set
    vector<int> level, iter;

    Dinic() { }
    void dibfs(Graph<FLOWTYPE> &G, int s) {
        level.assign((int)G.size(), -1);
        level[s] = 0;
        queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (int i = 0; i < G[v].size(); ++i) {
                Edge<FLOWTYPE> &e = G[v][i];
                if (level[e.to] < 0 && e.cap > 0) {
                    level[e.to] = level[v] + 1;
                    que.push(e.to);
                }
            }
        }
    }
    
    FLOWTYPE didfs(Graph<FLOWTYPE> &G, int v, int t, FLOWTYPE f) {
        if (v == t) return f;
        for (int &i = iter[v]; i < G[v].size(); ++i) {
            Edge<FLOWTYPE> &e = G[v][i], &re = G.redge(e);
            if (level[v] < level[e.to] && e.cap > 0) {
                FLOWTYPE d = didfs(G, e.to, t, min(f, e.cap));
                if (d > 0) {
                    e.cap -= d;
                    re.cap += d;
                    return d;
                }
            }
        }
        return 0;
    }
    
    FLOWTYPE solve(Graph<FLOWTYPE> &G, int s, int t) {
        level.assign((int)G.size(), -1); iter.assign((int)G.size(), 0);
        FLOWTYPE res = 0;
        while (true) {
            dibfs(G, s);
            if (level[t] < 0) return res;
            for (int i = 0; i < (int)iter.size(); ++i) iter[i] = 0;
            FLOWTYPE flow = 0;
            while ((flow = didfs(G, s, t, INF)) > 0) {
                res += flow;
            }
        }
    }
};

int n, m;
inline int conv(int i, int j) {
    return i*m + j;
}

const int INF = 1<<29;
int main() {
    cin >> n >> m;
    vector<string> fi(n);
    for (int i = 0; i < n; ++i) cin >> fi[i];
    int num_black = 0;
    int num_adj = 0;
    Graph<int> G(n*m*3+2);
    int s = n*m*3, t = n*m*3+1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (fi[i][j] == '.') continue;
            ++num_black;

            if (i+1<n && fi[i+1][j] == '#') {
                ++num_adj;
                int newv = conv(i,j) + n*m;
                G.addedge(newv, t, 1);
                G.addedge(conv(i,j), newv, INF);
                G.addedge(conv(i+1,j), newv, INF);
            }

            if (j+1<m && fi[i][j+1] == '#') {
                ++num_adj;
                int newv = conv(i,j) + n*m*2;
                G.addedge(s, newv, 1);
                G.addedge(newv, conv(i,j), INF);
                G.addedge(newv, conv(i,j+1), INF);
            }
        }
    }
    Dinic<int> dic;
    int flow = dic.solve(G, s, t);

    cout << num_black - (num_adj - flow) << endl;
}