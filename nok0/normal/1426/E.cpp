/**
 *	author: nok0
 *	created: 2020.09.28 16:57:01
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(int i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V<V<T>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define VEC(type, name, size)\
    V<type> name(size);\
    IN(name)
#define VVEC(type, name, h, w)\
    VV<type> name(h, V<type>(w));\
    IN(name)
#define INT(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LL(...)\
    ll __VA_ARGS__;\
    IN(__VA_ARGS__)
#define STR(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define CHAR(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define DOUBLE(...)\
    DOUBLE __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LD(...)\
    LD __VA_ARGS__;\
    IN(__VA_ARGS__)
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(V<T> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T> void scan(V<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p){
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p){
    os << p.first << " " << p.second;
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const V<T> &v){
    REP(i, SZ(v)){
        if(i) os << " ";
        os << v[i];
    }
    return os;
}
//debug
template <typename T>
void view(const V<T> &v){
    cerr << "{ ";
    for(const auto &e : v){
        cerr << e << ", ";
    }
    cerr << "\b\b }";
}
template <typename T>
void view(const VV<T> &vv){
    cerr << "{\n";
    for(const auto &v : vv){
        cerr << "\t";
        view(v);
        cerr << "\n";
    }
    cerr << "}";
}
template <typename T, typename U>
void view(const V<pair<T, U>> &v){
    cerr << "{\n";
    for(const auto &c : v) cerr << "\t(" << c.first << ", " << c.second << ")\n";
    cerr << "}";
}
template <typename T, typename U>
void view(const map<T, U> &m){
    cerr << "{\n";
    for(auto &t : m) cerr << "\t[" << t.first << "] : " << t.second << "\n";
    cerr << "}";
}
template <typename T, typename U>
void view(const pair<T, U> &p){ cerr << "(" << p.first << ", " << p.second << ")";}
template <typename T>
void view(const set<T> &s) {
    cerr << "{ ";
    for(auto &t : s) {
        view(t);
        cerr << ", ";
    }
    cerr << "\b\b }";
}
template <typename T>
void view(T e) { cerr << e;}
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    view(H);
    cerr << ", ";
    debug_out(T...);
}
#define debug(...)                                           \
    do{                                                     \
        cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
        debug_out(__VA_ARGS__);                              \
        cerr << "\b\b]\n";                                   \
    } while(0)
#else
#define debug(...) (void(0))
#endif
template <class T> V<T> press(V<T> &x){ 
    V<T> res = x;
    sort(all(res));
    res.erase(unique(all(res)), res.end());
    REP(i, SZ(x)){
        x[i] = lower_bound(all(res), x[i]) - res.begin();
    }
    return res;
}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T divup(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
struct iofast{iofast(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(15);}}iofast_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion

template <typename flow_t>
struct Dinic{
private:
    const flow_t INF;
    struct edge{
        int to;
        flow_t cap;
        int rev;
        bool isrev;
        int idx;
    };
    VV<edge> graph;
    V<int> min_cost, iter;

    bool bfs(int s, int t){
        min_cost.assign(SZ(graph), -1);
        queue<int> que;
        min_cost[s] = 0;
        que.push(s);
        while(!que.empty() and min_cost[t] == -1){
            int p = que.front(); que.pop();
            for(auto &e : graph[p]){
                if(e.cap > 0 and min_cost[e.to] == -1){
                    min_cost[e.to] = min_cost[p] + 1;
                    que.push(e.to);
                }
            }
        }
        return min_cost[t] != -1;
    }

    flow_t dfs(int idx, const int t, flow_t flow){
        if(idx == t) return flow;
        for(int &i = iter[idx]; i < SZ(graph[idx]); i++){
            edge &e = graph[idx][i];
            if(e.cap > 0 and min_cost[idx] < min_cost[e.to]){
                flow_t d = dfs(e.to, t, min(flow, e.cap));
                if(d > 0){
                    e.cap -= d;
                    graph[e.to][e.rev].cap += d;
                    return d;
                }
            }
        }
        return 0;
    }

public:
    Dinic(int v = 0) : INF(numeric_limits<flow_t>::max()), graph(v) {}

    void add_edge(int from, int to, flow_t cap, int idx = -1){
        graph[from].eb(edge{to, cap, SZ(graph[to]), false, idx});
        graph[to].eb(edge{from, 0, SZ(graph[from]) - 1, true, idx});
    }

    flow_t max_flow(int s, int t){
        flow_t flow = 0;
        while(bfs(s, t)){
            iter.assign(SZ(graph), 0);
            flow_t f = 0;
            while((f = dfs(s, t, INF)) > 0) flow += f;
        }
        return flow;
    }

    void output(){
        for (int i = 0; i < SZ(graph); i++){
            for(auto &e : graph[i]){
                if(e.isrev) continue;
                auto &rev_e = graph[e.to][e.rev];
                cout << i << "->" << e.to << " (flow:" << rev_e.cap << "/" << e.cap + rev_e.cap << ")\n";
                }
        }
    }

    void resize(int x){ graph.resize(x);}

    int size(){return SZ(graph);}
};

int n;
V<> a, b;

//A
int minsolve(){
    Dinic<ll> dinic(8);
    int s = 6, t = 7;
    REP(i, 3) dinic.add_edge(s, i, a[i]);
    REP(i, 3) dinic.add_edge(i + 3, t, b[i]);
    REP(i, 3){
        dinic.add_edge(i, i + 3, min(a[i], b[i]));
        dinic.add_edge(i, 3 + (i + 2) % 3, min(a[i], b[(i + 2) % 3]));
    }
    return n - dinic.max_flow(s, t);
}

//A
int MAXsolve(){
    int res = 0;
    REP(i, 3){
        int d = min(a[i], b[(i + 1) % 3]);
        res += d;
    }
    return res;
}

int main(){
    cin >> n;
    REP(i, 3){
        INT(x);
        a.pb(x);
    }
    REP(i, 3){
        INT(x);
        b.pb(x);
    }
    cout << minsolve() << " " << MAXsolve() << endl;
}