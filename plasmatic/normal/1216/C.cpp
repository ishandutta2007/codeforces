#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common DS shorteners
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using um = unordered_map<K, V>; template <typename K, typename V> using om = map<K, V>;
template <typename K> using us = unordered_set<K>; template <typename K> using os = set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define pb push_back
// Shorthand Function Macros
#define FORI(a, b) for (int i = a; i < b; i++)
#define FORJ(a, b) for (int j = a, j < b; j++)
#define FORK(a, b) for (int k = a; k < b; k++)
#define CMPLT(type) bool operator<(const type &a, const type &b)
#define CMPGT(type) bool operator>(const type &a, const type &b)
#define CMPFN(type) bool operator()(const type &a, const type &b)
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
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
#pragma endregion

struct rect {
    int x1, y1, x2, y2;
};

istream& operator>>(istream& in, rect &o) {
    in >> o.x1 >> o.y1 >> o.x2 >> o.y2;
    return in;
}

// int x1, y1, x2, y2, x3, y4, x4, y4, x5, y5, x6, y6;
rect w, b1, b2;

bool within(rect inner, rect outer) {
    return inner.x1 >= outer.x1 && inner.x2 <= outer.x2 && 
        inner.y1 >= outer.y1 && inner.y2 <= outer.y2;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(w, b1, b2);

    // Check for each
    if (within(w, b1) || within(w, b2)) {
        println("NO");
        return 0;
    }

    // debug(w.x1, w.y1, w.x2, w.y2);

    // Check by X
    for (int i = w.x1; i <= w.x2; i++) {
        // debug('x', i);
        rect lhs = {w.x1, w.y1, i, w.y2}, rhs = {i, w.y1, w.x2, w.y2};
        if ((within(lhs, b1) && within(rhs, b2)) || (within(lhs, b2) && within(rhs, b1))) {
            println("NO");
            return 0;
        }
    }

    // Check by Y
    for (int i = w.y1; i <= w.y2; i++) {
        // debug('y', i);
        rect lhs = {w.x1, w.y1, w.x2, i}, rhs = {w.x1, i, w.x2, w.y2};
        if ((within(lhs, b1) && within(rhs, b2)) || (within(lhs, b2) && within(rhs, b1))) {
            println("NO");
            return 0;
        }
    }

    println("YES");

    return 0;
}