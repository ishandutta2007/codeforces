#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
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

int n, m;
//grid
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int ddx[8] = {1,1,0,-1,-1,-1,0,1,};
int ddy[8] = {0,1,1,1,0,-1,-1,-1};
inline bool inside(int x, int y) {return x >= 0 and x < n and y >= 0 and y < m;}

int gridtoint(int x, int y){
    return x * m + y;
}

struct UnionFind {
    public:
    vector<int> par;
    UnionFind(int n){
        par=vector<int>(n,-1);
    }
    int root(int x){
        if(par[x]<0)return x;
    return par[x]=root(par[x]);
    }
    bool issame(int x,int y){
        return root(x)==root(y);
    }
    bool merge(int x,int y){
        x=root(x);
        y=root(y);
        if(x==y)return false;
        if(par[x]>par[y])swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        return true;
    }
    int size(int x){
        return -par[root(x)];
    }
};

int main(){
    cin >> n >> m;
    VVEC(char, a, n, m);
    V<> hused(n), wused(m), nh(n), nw(m);
    REP(i, n) REP(j, m) if(a[i][j] == '#') hused[i] = 1, wused[j] = 1;
    REP(i, n) REP(j, m) if(hused[i] == 0 and wused[j] == 0) nh[i] = 1, nw[j] = 1;
    REP(i, n) fin(hused[i] == 0 and nh[i] == 0, -1);
    REP(i, m) fin(wused[i] == 0 and nw[i] == 0, -1);
    UnionFind uf(n * m);
    REP(i, n) REP(j, m){
        if(a[i][j] == '.') continue;
        REP(k, 4){
            int nx = i + dx[k], ny = j + dy[k];
            if(!inside(nx, ny)) continue;
            if(a[nx][ny] == '#') uf.merge(gridtoint(i, j), gridtoint(nx, ny));
        }
    }
    VV<int> vec(n, V<int>(m));
    REP(i, n) REP(j, m) vec[i][j] = uf.root(gridtoint(i, j));
    /*REP(i, n){
        REP(j, m)cout <<vec[i][j] <<" ";
        cout << endl;
    }*/
    set<int> st;
    REP(i, n) REP(j, m) if(a[i][j] == '#') st.insert(uf.root(gridtoint(i, j)));
    map<int, int> mp;
    REP(i, n){
        mp.clear();
        REP(j, m){
            fin(mp[vec[i][j]] != 0 and mp[vec[i][j]] != j, -1);
            mp[vec[i][j]] = j + 1;
        } 
    }
    REP(j, m){
        mp.clear();
        REP(i, n){
            fin(mp[vec[i][j]] != 0 and mp[vec[i][j]] != i, -1);
            mp[vec[i][j]] = i + 1;
        } 
    }
    set<int> st2;
    REP(i, n){
        st2.clear();
        REP(j, m){
            if(uf.size(vec[i][j]) < 2 and a[i][j] != '#') continue;
            st2.insert(uf.root(vec[i][j]));
        } 
        fin(SZ(st2) > 1, -1);
    }
    REP(j, m){
        st2.clear();
        REP(i, n){
            if(uf.size(vec[i][j]) < 2 and a[i][j] != '#') continue;
            st2.insert(uf.root(vec[i][j]));
        } 
        fin(SZ(st2) > 1, -1);
    }
    print(SZ(st));
}