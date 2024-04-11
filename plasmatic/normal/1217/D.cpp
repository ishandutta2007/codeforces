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
 
struct edi {
    int i, v;
};
 
const int MN = 5e3 + 1;
int n, m, ba, bb,
    A[MN], B[MN];
vec<edi> g[MN];
 
// Check for cycle edge
bool vis[MN];
 
void dfs(int cur) {
    if (vis[cur]) return;
    vis[cur] = true;
    for (auto adj : g[cur])
        dfs(adj.v);
}
 
// Final DFS
vi found;
bool isCyc[MN];
void dfs2(int cur) {
    if (vis[cur]) return;
    vis[cur] = true;
    // curc++;
    for (auto adj : g[cur]) {
        if (isCyc[adj.i]) {
            dfs2(adj.v);
            found.pb(adj.i);
        }
    }
}
 
// Set clr
int testc,
    clr[MN];
bool vis2[MN];
void dfs3(int cur) {
    if (vis2[cur]) return;
    vis2[cur] = true;
    // debug(cur, testc);
    for (auto adj : g[cur]) {
        // debug(cur, adj.i, adj.v);
        if (clr[adj.i] == testc)
            dfs3(adj.v);
    }
}
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    scan(n, m);
 
    for (int i = 0; i < m; i++) {
        scan(ba, bb);
        g[ba].pb({i, bb});
        A[i] =ba;
        B[i] = bb;
    }
 
 
 
        for (int j = 0; j < m; j++) {
            for (int k = 1; k <= 2; k++) {
                memset(vis2, false, sizeof vis2);
                testc = k;
                dfs3(B[j]);
                // debug(i, j, k, A[j], B[j], vis2[A[j]]);
                if (!vis2[A[j]]) {
                    clr[j] = k;
                    break;
                }
            }
        }
 
    // Non-cycle edges
    for (int i = 0; i < m; i++)
        if (clr[i] == 0) clr[i] = 1;
 
    int mx = *max_element(clr, clr + m);
    println(mx);
    printArray(clr, m);
 
    return 0;
}