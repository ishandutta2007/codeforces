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
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
using P = pair<ll, ll>;
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
template <class T> void scan(T a) { cin >> a; }
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

    void resize(int x){ graph.resize(x);}

    int size(){return SZ(graph);}
};

template <typename T>
struct ProjectSelectionProblem{
private:
    int n;
    const T INF;
    T res = 0;
    Dinic<T> dinic;

public:
    //n(true), n+1(false)   
    ProjectSelectionProblem(int n_) 
    : n(n_), INF(numeric_limits<T>::max()){
        dinic.resize(n + 2);
    }

    void x_and_noty_loss(int x, int y, T loss){
        assert(loss >= 0);
        dinic.add_edge(x, y, loss);
    }

    void x_xor_y_loss(int x, int y, T loss){
        x_and_noty_loss(x, y, loss);
        x_and_noty_loss(y, x, loss);
    }

    void x_get(int x, T get){
        if(get < 0){
            dinic.add_edge(x, n + 1, -get);
            return;
        }
        res += get;
        notx_loss(x, get);
    }

    void x_loss(int x, T loss){
        if(loss < 0){
            x_get(x, -loss);
            return;
        }
        dinic.add_edge(x, n + 1, loss);
    }

    void notx_get(int x, T get){
        if(get < 0){
            dinic.add_edge(n, x, -get);
            return;
        }
        res += get;
        x_loss(x, get);
    }

    void notx_loss(int x, T loss){
        if(loss < 0){
            notx_get(x, -loss);
            return;
        }
        dinic.add_edge(n, x, loss);
    }

    void x_and_y_get(int x, int y, T get){
        assert(get >= 0);
        res += get;
        dinic.resize(dinic.size() + 1);
        int w = dinic.size() - 1;
        dinic.add_edge(n, w, get);
        dinic.add_edge(w, x, INF);
        dinic.add_edge(w, y, INF);
    }

    void x_nor_y_get(int x, int y, T get){
        assert(get >= 0);
        res += get;
        dinic.resize(dinic.size() + 1);
        int w = dinic.size() - 1;
        dinic.add_edge(w, n + 1, get);
        dinic.add_edge(x, w, INF);
        dinic.add_edge(y, w, INF);
    }

    void x_equal_y_get(int x, int y, T get){
        x_and_y_get(x, y, get);
        x_nor_y_get(x, y, get);
    }

    //
    T solve(){
        return dinic.max_flow(n, n + 1) - res;
    }
};

int dx[2] = {1, 0}, dy[2] = {0, 1};

int main(){
    INT(n, m);
    VVEC(char, a, n, m);
    ProjectSelectionProblem<int> PSP(n * m);
    REP(i, n) REP(j, m){
        if(a[i][j] == '.') continue;
        PSP.x_loss(i * m + j, 1);
        PSP.notx_loss(i * m + j, 1);
        REP(k, 2){
            int nx = i + dx[k], ny = j + dy[k];
            int x = i * m + j, y = nx * m + ny;
            if(nx < n and ny < m and a[nx][ny] == '#'){
                if(k) PSP.x_and_y_get(x, y, 1);
                else PSP.x_nor_y_get(x, y, 1);
            }
        }
    }
    print(PSP.solve());
}