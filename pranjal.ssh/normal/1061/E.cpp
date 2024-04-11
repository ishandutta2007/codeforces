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

typedef int fType;
typedef int cType;

const fType INF = 0x3f3f3f3f;
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


const int N = 555;
vi g[2][N];
bitset<N> b[2][N];
void dfs(int i, int u, int p) {
    b[i][u][u] = 1;
    for (int v: g[i][u]) if (v != p) {
        dfs(i, v, u);
        b[i][u] |= b[i][v];
    }
}
vector<pair<bitset<N>, int>> q[2];




int main()
{
    ios::sync_with_stdio(0); cin.tie(0);

    int sum = 0;

    int n, r[2]; cin >> n >> r[0] >> r[1];
    vi a(n); FOR (i, 0, n - 1) cin >> a[i], sum += a[i];

    FOR (i, 0, 1) {
        FOR (it, 1, n - 1) {
            int x, y; cin >> x >> y;
            g[i][x].push_back(y), g[i][y].push_back(x);
        }
        dfs(i, r[i], 0);
    }
    
    FOR (i, 0, 1) {
        auto temp = q[i];
        int t; cin >> t; FOR (it, 0, t - 1) {
            int k, x; cin >> k >> x;
            temp.emplace_back(b[i][k], x);
        }
        sort(all(temp), [&](const pair<bitset<N>, int> &a, const pair<bitset<N>, int> &b) {
            return ii(a.F.count(), a.S) > ii(b.F.count(), b.S);
        });
        FOR (it1, 0, t - 1) {
            q[i].emplace_back(temp[it1]);
            FOR (it2, it1 + 1, t - 1) {
                if ((q[i][it1].F & temp[it2].F) == temp[it2].F) {
                    q[i][it1].F ^= temp[it2].F;
                    q[i][it1].S -= temp[it2].S;
                    if (q[i][it1].S < 0) {
                        return cout << "-1\n", 0;
                    }
                }
            }
        }
    }


    MinCostMaxFlow G(sz(q[0]) + sz(q[1]) + 2);
    int source = sz(q[0]) + sz(q[1]), sink = source + 1;

    FOR (i, 0, sz(q[0]) - 1) {
        FOR (j, 0, sz(q[1]) - 1) {
            auto X = (q[0][i].F & q[1][j].F);
            if (!X.any()) continue;
            FOR (k, 1, n) if (X[k]) G.addEdge(i, sz(q[0]) + j, 1, -a[k - 1]);
        }
    }

    int s1 = 0, s2 = 0;
    FOR (i, 0, sz(q[0]) - 1) G.addEdge(source, i, q[0][i].S, 0), s1 += q[0][i].S;
    FOR (i, 0, sz(q[1]) - 1) G.addEdge(sz(q[0]) + i, sink, q[1][i].S, 0), s2 += q[1][i].S;

    if (s1 != s2) {
        return cout << "-1\n", 0;
    }

    auto ans = G.getMaxFlow(source, sink);
    if (ans.F != s1) {
        return cout << "-1\n", 0;   
    }

    cout << -ans.S << "\n";

    
    return 0;
}