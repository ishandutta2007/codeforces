#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define mtup make_tuple
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define finline __attribute__((always_inline))
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

struct Ed {
    int a, b; ll w;
    Cmplt(Ed) { return w < o.w; }
};

const int MN = 2e5 + 1, MK = 401;
int N, M, K;
vec<Ed> edges;

using DisArray = vec<vec<ll>>;

// floyd warshall algorithm.  Node map is a vector that rank compresses nodes
void floydWarshall(int n, vec<Ed> &edges, vi &nodeMap, DisArray &dis) {
    dis = DisArray(n, vec<ll>(n, LLINF));
    for (auto x : edges)
        dis[nodeMap[x.a]][nodeMap[x.b]] = x.w;
    repi(0, n)
        dis[i][i] = 0LL;
    repk(0, n)
        repi(0, n)
            repj(0, n)
                mina(dis[i][j], dis[i][k] + dis[k][j]);
    // repi(0, n)
    //     db(dis[i]), dbln;
}

// get kth smallest element in vector
ll kth(DisArray &dis, int k) {
    priority_queue<ll> pq;
    int sz = dis.size();
    repi(0, sz) {
        repj(i + 1, sz) {
            pq.push(dis[i][j]);
            if (int(pq.size()) > k) pq.pop();
        }
    }
    return pq.top();
}

// dsu stuff
vi comps[MN];
int dsu[MN];
int rt(int x) { return dsu[x] == x ? x : dsu[x] = rt(dsu[x]); }
void unite(int x, int y) { dsu[rt(x)] = rt(y); }

// multiple connected components stuff
vec<pair<int, ll>> g[MN];
vi nodeMap;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, M, K);
    repi(0, M) {
        int a, b, w;
        scan(a, b, w);
        edges.pb({a, b, w});
    }

    if (M < K) { // floyd warshall
        // initialize stuff for floyd warshall function
        vi nodeMap(N + 1);
        iota(all(nodeMap), -1);
        repi(0, M)
            edges.pb({edges[i].b, edges[i].a, edges[i].w});

        // output
        DisArray dis;
        floydWarshall(N, edges, nodeMap, dis);
        println(kth(dis, K));

        return 0;
    }
    else { // floyd warshall with extra steps
        nodeMap.resize(N + 1);
        sort(all(edges));

        // get connected components
        iota(dsu, dsu + N + 1, 0);
        repi(0, K) {
            unite(edges[i].a, edges[i].b);
            g[edges[i].a].emplace_back(edges[i].b, edges[i].w);
            g[edges[i].b].emplace_back(edges[i].a, edges[i].w);
            // db(i); db(edges[i].a); db(edges[i].b); dbln;
        }
        repi(1, N + 1)
            comps[rt(i)].pb(i);
        
        priority_queue<ll> pq;
        repi(1, N + 1) {
            int sz = comps[i].size();
            if (sz <= 1) continue;

            // init stuff
            repj(0, sz)
                nodeMap[comps[i][j]] = j;
            vec<Ed> curEdges;
            for (auto x : comps[i]) {
                for (auto to : g[x])
                    curEdges.pb({x, to.first, to.second});
            }

            // db(i); db(comps[i]); dbln;
            // for (auto x : curEdges)
            //     dbp("ed", x.a, x.b, x.w), dbln;

            // floyd warshall !!!
            DisArray dis;
            floydWarshall(sz, curEdges, nodeMap, dis);
            repi(0, sz) {
                repj(i + 1, sz) {
                    pq.push(dis[i][j]);
                    if (int(pq.size()) > K) pq.pop();
                }
            }
        }
            
        // output
        println(pq.top());
    }

    return 0;
}