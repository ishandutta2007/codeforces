#include <bits/stdc++.h>
using namespace std;

#define cerr cout
#define F first
#define S second
#define FOR(i,a,b) for (auto i = (a); i <= (b); ++i)
#define NFOR(i,a,b) for(auto i = (a); i >= (b); --i)
#define all(x) (x).begin(), (x).end()
#define sz(x) int(x.size())
typedef long long ll; typedef pair <int, int> ii; typedef vector <int> vi; const int inf = 1e9 + 7;
string to_string(string s) { return '"' + s + '"';}
string to_string(char s) { return string(1, s);}
string to_string(const char* s) { return to_string((string) s);}
string to_string(bool b) { return (b ? "true" : "false");}
template <typename A> string to_string(A);
template <typename A, typename B>string to_string(pair<A, B> p) {return "(" + to_string(p.first) + ", " + to_string(p.second) + ")";}
template <typename A> string to_string(A v) {bool f = 1; string r = "{"; for (const auto &x : v) {if (!f)r += ", "; f = 0; r += to_string(x);} return r + "}";}
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << to_string(H); debug_out(T...);}
#define pr(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)

typedef ll fType;
typedef ll cType;

const fType INF = 1e15;
// check for flow in i ^ 1
struct edge {
    int u, v;
    fType flow;
    cType cost;
    edge() {}
    edge(int u, int v, fType f, cType c) : u(u), v(v), flow(f), cost(c) {}
};

struct MinCostMaxFlow {
    int N;
    vector < vector <int> > G;
    vector <edge> E;
    int numEdges;
    vector <int> found, dad;
    vector <cType> dist;

    MinCostMaxFlow(int N): 
     N(N), G(N), numEdges(0), found(N), dad(N), dist(N)  {}
  
    void addEdge(int from, int to, fType capacity, cType cost) {
        // dbg(from), dbg(to), dbg(capacity), dbg(cost), dbn;
        G[from].push_back(numEdges++);
        E.push_back(edge(from, to, capacity, cost));
        G[to].push_back(numEdges++);
        E.push_back(edge(to, from, 0, cType(-1) * cost));
    }
  
    bool spfa(int s, int t) {
        fill(dad.begin(), dad.end(), -1);
        fill(dist.begin(), dist.end(), INF);
        fill(found.begin(), found.end(), 0);
        queue <int> Q;
        dist[s] = 0;
        Q.push(s);
        found[s] = true;
        
        while(!Q.empty()) {
            int u = Q.front(); Q.pop();
            if(u == t) continue;
            for (int i = 0; i < (int)G[u].size(); ++i) {
                edge &pres = E[G[u][i]];
                int v = pres.v;
                if(pres.flow <= 0) continue;
                if(dist[u] + pres.cost < dist[v]) {
                    dad[v] = G[u][i];
                    dist[v] = dist[u] + pres.cost;
                    if(!found[v]) Q.push(v), found[v] = true;
                }
            }
            found[u] = false;
        }
        return (dad[t] != -1);
    }
 
    fType dfs(int t) {
        fType flow = INF;
        for(int i = dad[t]; i != -1; i = dad[E[i].u]) {
            if(E[i].flow < flow) flow = E[i].flow;
        }
        for(int i = dad[t]; i != -1; i = dad[E[i].u]) {
            E[i].flow -= flow;
            E[i ^ 1].flow += flow;
        }
        return flow;
    }

    pair <fType, cType> getMaxFlow(int s, int t) {
        fType totflow = 0;
        cType totcost = 0;
        while(spfa(s,t)) {
            fType amt = dfs(t);
            totflow += amt;
            totcost += dist[t] * (cType)amt;
        }
        return make_pair(totflow, totcost);
    }
};

int main()
{
	ios::sync_with_stdio(0); cin.tie(0);

	int n, k; cin >> n >> k;
	vi a(n), b(n);
	FOR (i, 0, n - 1) cin >> a[i];
	FOR (i, 0, n - 1) cin >> b[i];
	int s1 = n+n, s2 = s1+1, s3 = s2+1;
	MinCostMaxFlow G(n + n + 3);
	G.addEdge(s1, s2, k, 0);
	FOR (i, 0, n - 1) G.addEdge(s2, i, 1, a[i]), G.addEdge(i, n+i, 1, 0);
	FOR (i, 0, n - 1) G.addEdge(i+n, s3, 1, b[i]);
	FOR (i, 1, n - 1) G.addEdge(n+i-1, n+i, k, 0);
	cout << G.getMaxFlow(s1, s3).S << "\n";
	
	return 0;
}