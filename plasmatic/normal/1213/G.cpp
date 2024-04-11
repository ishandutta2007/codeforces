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

struct ed {
    int a, b, w;
    bool operator<(const ed &o) const {
        return w < o.w;
    }
};

const int MN = 2e5 + 1;
int n, q, ba, bb, bc, 
    dsu[MN], sz[MN];
ll pfx[MN];
map<int, vec<pii>> eds;

void init() {
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        sz[i] = 1;
    }
}

int rt(int x) {
    return dsu[x] == x ? x : dsu[x] = rt(dsu[x]);
}

ll sumBelow(ll x) { return (x * (x - 1)) >> 1; }

ll ctot = 0;
void merge(int x, int y) {
    int rx = rt(x), ry = rt(y);
    // debug(x, y, rx, ry, sz[rx], sz[ry]);

    if (rx != ry) {
        ctot -= sumBelow(sz[rx]);
        ctot -= sumBelow(sz[ry]);
        ctot += sumBelow(sz[rx] + sz[ry]);

        sz[rx] += sz[ry];
        dsu[ry] = rx;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(n, q);

    for (int i = 1; i < n; i++) {
        scan(ba, bb, bc);
        eds[bc].pb(mpr(ba, bb));
    }

    init();

    // Counts and offline
    for (auto x : eds) {
        for (auto edge : x.second) {
            merge(edge.first, edge.second);
        }

        // debug(x.first, ctot);
        pfx[x.first] = ctot;
    }

    for (int i = 1; i < MN; i++) {
        maxa(pfx[i], pfx[i - 1]);
    }

    // Solve queries
    for (int i = 0; i < q; i++) {
        scan(ba);
        print(pfx[ba], ' ');
    }

    print('\n');

    return 0;
}