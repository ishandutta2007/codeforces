#include <bits/stdc++.h>
 
using namespace std;
 
// Common DS shorteners
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using mp = unordered_map<K, V>;
template <typename K> using us = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define pb push_back
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void printDebug(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
inline void println(){cout<<"\n";}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
int di_; string dnms_, co_ = ",";
void debug_(){cout<<endl;}
template<typename F, typename... R>
void debug_(F f,R... r){int bc=0;while (bc != 0 || dnms_[di_] != ','){if (dnms_[di_] == '(') {bc++;}else if (dnms_[di_] == ')') {bc--;}cout << dnms_[di_++];}di_++;cout << ": " << f << ",";debug_(r...);}
#define debug(...) do{dnms_=#__VA_ARGS__+co_,di_=0,debug_(__VA_ARGS__);}while(0)
 
template <int MAX>
struct Graph {
    int n, m, __ba, __bb; vector<int> matrix[MAX];
    void init(int n0, int m0) { n = n0; m = m0; }
    inline void addEdge(int a, int b) { matrix[a].push_back(b); }
    inline auto& adjs(int x) { return matrix[x]; }
    Graph& operator=(const Graph o) { n = o.n; m = o.m; copy(o.matrix, o.matrix + n + 1, matrix); return *this; }
    void input(bool undirected) { // Reads a graph's edges from stdin
        for (int i = 0; i < m; i++) {
            cin >> __ba >> __bb;
            addEdge(__ba, __bb);
            if (undirected) addEdge(__bb, __ba);
        }
    }
};
template <int MAX, typename T>
struct SCC {
    int curOrd = -1, ord[MAX], low[MAX], to[MAX]; stack<int> stk; bool inStk[MAX], vis[MAX]; T &graph;
    vector<vector<int>> comps;
    SCC(T &graph0) : graph(graph0) {}
    void tarjan() {
        comps.clear();
        curOrd = -1;
        memset(inStk, false, sizeof inStk);
        memset(vis, false, sizeof vis);
 
        for (int i = 1; i <= graph.n; i++)
            if (!vis[i])
                dfs(i);
    }
    void dfs(int cur) {
        stk.push(cur);
        vis[cur] = inStk[cur] = true;
        ord[cur] = low[cur] = ++curOrd;

        for (int adj : graph.adjs(cur)) {
            if (!vis[adj]) {
                dfs(adj);
                low[cur] = min(low[cur], low[adj]);
            }
            else if (inStk[adj]) {
                mina(low[cur], ord[adj]);
            }
        }
 
        // If root of SCC
        if (low[cur] == ord[cur]) {
            int v = -1;
            vector<int> comp;
            do {
                v = stk.top(); stk.pop(); inStk[v] = false;
                comp.push_back(v);
                to[v] = comps.size();
            }
            while (v != cur);
            comps.push_back(comp);
        }
    }
};
template <int MAX, typename T>
struct TopologicalSortNT {
    int &n, inDeg[MAX]; vector<int> order; queue<int> nxt; T &graph;
    TopologicalSortNT(T &graph0) : n(graph0.n), graph(graph0) {}
    void sort() {
        for (int i = 0; i < n; i++)
            for (int adj : graph.adjs(i))
                inDeg[adj]++;
        for (int i = 0; i < n; i++)
            if (inDeg[i] == 0)
                nxt.push(i);
        while (!nxt.empty()) {
            int cur = nxt.front(); nxt.pop();
            order.push_back(cur);
            for (int adj : graph.adjs(cur)) {
                inDeg[adj]--;
                if (!inDeg[adj])
                    nxt.push(adj);
            }
        }
    }
};
 
inline char ulet(int x) { return x + 'a'; }
 
const int MN = 2e5 + 1;
int n, k, ba, 
    vals[MN];
Graph<MN> g, g2;
SCC<MN, Graph<MN>> scc(g);
TopologicalSortNT<MN, Graph<MN>> topo(g2);
 
// Topo fuck you
int idOf[MN];
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    scan(n, k);
    g.init(n, -1);
 
    // // Twice for both permutations
    // for (int i = 1; i <= n; i++) {
    //     scan(ba);
    //     idxOf1[ba] = i;
    // }
    // for (int i = 1; i < n; i++)
    //     g.addEdge(idxOf1[i], idxOf1[i + 1]);
    // for (int i = 1; i <= n; i++) {
    //     scan(ba);
    //     idxOf1[ba] = i;
    // }
    // for (int i = 1; i < n; i++)
    //     g.addEdge(idxOf1[i], idxOf1[i + 1]);

    // input graph
    for (int i = 1; i <= n; i++)
        scan(vals[i]);
    for (int i = 1; i < n; i++)
        g.addEdge(vals[i], vals[i + 1]);
    for (int i = 1; i <= n; i++)
        scan(vals[i]);
    for (int i = 1; i < n; i++)
        g.addEdge(vals[i], vals[i + 1]);

    // :Poggies: run scc
    scc.tarjan();
 
    int sz = scc.comps.size();
    if (sz < k) {
        println("NO");
        return 0;
    }
 
    // Compress graph
    g2.init(sz, -1);
    for (int i = 1; i <= n; i++) {
        for (int adj : g.adjs(i)) {
            int a = scc.to[i], b = scc.to[adj];
            if (a != b)
                g2.addEdge(a, b);
        }
    }
 
    // topological sort
    topo.sort();
    // debug(topo.order);
    // printDebug(scc.to + 1, n);
    for (int i = 0; i < sz; i++) {
        idOf[topo.order[i]] = i;
        // debug(i, topo.order[i]);
    }
 
    // output answer
    println("YES");
    for (int i = 1; i <= n; i++) {
        int valOfIdx = idOf[scc.to[i]];
        mina(valOfIdx, 25);
        print(ulet(valOfIdx));
        // debug(i, valOfIdx);
    }
    print('\n');
 
    return 0;
}