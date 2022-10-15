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

const int MN = 2e5 + 1;
int n, lgn,
    lastZeroOf[MN];
string s;
ll tot = 0;

inline int dig(char x) { return x - '0'; }

void solve() {
    for (int i = 1; i <= lgn; i++) {
        int curnum = 0;

        for (int j = 0; j < i - 1; j++) {
            curnum <<= 1;
            curnum += dig(s[j]);
        }

        for (int j = i - 1; j < n; j++) {
            curnum <<= 1;
            curnum &= (1 << i) - 1;
            curnum += dig(s[j]);
            // debug(i, j, curnum, s[j]);

            if (curnum == i) {
                // debug('n', j);
                tot++;
            }
        }
    }

    int lastZero = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '0' && lastZero == -1)
            lastZero = i;
        else if (s[i] == '1')
            lastZero = -1;
        lastZeroOf[i] = lastZero;
        
        int end = min(lgn, i + 1);
        int curnum = 0, lastCurNum = -1;
        for (int j = 1; j <= end; j++) {
            curnum += dig(s[i - j + 1]) << (j - 1);

            if (i - j + 1 == 0)
                continue;

            int lastZeroOld = lastZeroOf[i - j];
            // debug(i, j, curnum, s[i - j + 1], lastZeroOld);

            if (curnum != lastCurNum && lastZeroOld != -1 && curnum <= i - lastZeroOld + 1 && curnum > lgn) {
                // debug("yes", i, j);
                tot++;
            }

            lastCurNum = curnum;
        }
    }

    println(tot);
}   

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; scan(t);
    while (t--) {
        scan(s);
        n = s.length();
        lgn = log2(n) + 1;
        tot = 0;
        // debug(n, lgn);

        solve();
    }

    return 0;
}