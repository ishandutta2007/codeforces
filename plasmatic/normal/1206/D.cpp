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
const int MN = 1e5 + 1, BITS = 61;
int n, best = INF;
ll vals[MN];
vi hasBit[MN];
 
// BFS stuff
const int SMALL = 2001;
vi g[MN];
vpi edges;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    scan(n);
 
    for (int i = 1; i <= n; i++) {
        scan(vals[i]);
 
        for (int j = 0; j < BITS; j++) {
            if ((vals[i] >> j) & 1)
                hasBit[j].pb(i);
        }
    }
 
    for (int i = 0; i < BITS; i++) {
        if (hasBit[i].size() >= (size_t)3) {
            println(3);
            return 0;
        }
    }
 
    for (int i = 0; i < BITS; i++) {
        if (hasBit[i].size() == (size_t)2) {
            int a = hasBit[i][0], b = hasBit[i][1];
            g[a].pb(b);
            g[b].pb(a);
            edges.pb(mpr(a, b));
        }
    }

    for (auto edge : edges) {
        int lv[n + 1];
        memset(lv, 0x3f, sizeof lv);

        queue<int> nxt;
        nxt.push(edge.first);
        lv[edge.first] = 0;
 
        while (!nxt.empty()) {
            int cur = nxt.front(), clv = lv[cur];
            nxt.pop();
 
            for (int adj : g[cur]) {
                if (cur == edge.first && adj == edge.second)
                    continue;

                if (clv + 1 < lv[adj]) {
                    lv[adj] = clv + 1;
                    nxt.push(adj);
                }
            }
        }

        mina(best, lv[edge.second] + 1);
    }
 
    if (best == INF)
        println(-1);
    else
        println(best);
 
    return 0;
}