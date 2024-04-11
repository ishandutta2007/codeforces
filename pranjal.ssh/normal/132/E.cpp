#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
// #include <sys/resource.h>

using namespace std;
using namespace __gnu_pbds;

template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

#define TRACE

#ifdef TRACE

#define cerr cout

#define pra(a,n) cerr<<#a<<" : ";for(int i=0;i<n;++i)cerr<<a[i]<<" ";cerr<<endl;
#define praa(a,n,m) cerr<<#a<<" : "<<endl;for(int i=0;i<n;++i){for(int j=0;j<m;++j)cerr<<a[i][j]<<" ";cerr<<endl;}
#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
	cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
	const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}
#undef cerr
#else
#define pr(...)
#define pra(a,n)
#define praa(a,n,m)
#endif

#define inc_stack_limit const rlim_t kStackSize = 64 * 1024 * 1024;struct rlimit rl;rl.rlim_cur = kStackSize;setrlimit(RLIMIT_STACK, &rl);
#define all(x) (x).begin(), (x).end()
#define nall(x) (x).rbegin(), (x).rend()
#define sz(a) int((a).size())
#define pb push_back
#define MP make_pair
#define F first
#define S second
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define NFOR(i,a,b) for(int i=(a);i>=(b);--i)
#define TCASE int __T;cin>>__T;FOR(Tc,1,__T)


typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<vector<int> > vvi;
typedef pair<int, int> ii;
typedef vector<pair<int, int> > vii;
typedef vector<vector<pair<int, int> > > vvii;

const ll inf2 = 1e18;
const int inf = 1e9 + 7;

inline int add(int a, int b, int m = inf) {a += b; if (a >= m)a -= m; return a;}
inline int sub(int a, int b, int m = inf) {a -= b; if (a < 0)a += m; return a;}
inline int mul(int a, int b, int m = inf) {return (int)(((ll)a * (ll)b) % m);}

typedef int fType;
typedef int cType;

const fType INF = 0x3f3f3f3f;
// check for flow == 0
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
    vvi ans;

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

    void mydfs(int n, int s, int t) {
    	if (s == t) return;
    	ans.back().pb(s);
    	for (auto &it : G[s + n]) {
    		if (E[it].flow == 0 and E[it].v > s) {
    			mydfs(n, E[it].v, t);
    			break;
    		}
    	}
    	return;
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
	ios_base::sync_with_stdio(false);	cin.tie(NULL);

	int n, m; cin >> n >> m;	
	vi a(n + 1); FOR (i, 1, n)	cin >> a[i];
	
	int source = 0;
	int sink = 2*n + 1;
	int source2 = 2*n + 2;
	MinCostMaxFlow G(2*n + 3);

	FOR (i, 1, n) G.addEdge(i, i + n, 1, -20000);

	FOR (i, 1, n) {
		FOR (j, i + 1, n) {
			G.addEdge(i + n, j, 1, a[i] == a[j] ? 0 : __builtin_popcount(a[j]));
		}
	}

	FOR (i, 1, n) G.addEdge(source, i, 1, __builtin_popcount(a[i]));
	FOR (i, 1, n) G.addEdge(i + n, sink, 1, 0);
	G.addEdge(source2, source, m, 0);
	G.addEdge(source, sink, m, 0);

	ii ans = G.getMaxFlow(source2, sink);

	ans.S += 20000 * n;

	
	for (auto& it : G.E) {
		if (it.u == source and it.v >= 1 and it.v <= n and it.flow == 0) {
			G.ans.pb(vi());
			G.mydfs(n, it.v, sink);
		}
	}
	int lines = n;
	vii yo(n + 1);
	int ctr = 0;
	for (auto & it : G.ans) {
		++lines;
		yo[it[0]] = {ctr, a[it[0]]};
		FOR (i, 1, sz(it) - 1) {
			lines+= a[it[i]] != a[it[i - 1]];
			yo[it[i]].F = ctr;
			if (a[it[i]] != a[it[i-1]]) yo[it[i]].S = a[it[i]];
		}
		++ctr;
	}
	cout << lines << " " << ans.S << "\n";

	FOR (i, 1, n) {
		if (yo[i].S) cout << char('a'+yo[i].F) << "=" << yo[i].S << "\n";
		cout << "print(" <<  char('a'+yo[i].F) << ")\n";
	}

	


	return 0;	
}