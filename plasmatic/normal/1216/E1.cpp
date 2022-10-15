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

ll k;

ll ceildiv(ll a, ll b) {
    return (a + b - 1) / b;
}

const int MN = 1e5 + 1;
ll dp[MN], dpc[MN];

int getdig(ll n) {
    int l = 0, r = MN;
    while (l + 1 < r) {
        int mid = (l + r) >> 1;
        if (dpc[mid] >= n)
            r = mid;
        else
            l = mid;
    }

    // debug(l, r, n);

	return to_string(r)[n - dpc[l] - 1] - '0';
}

void solve() {
    int use = -1;
    for (int i = 1; i < MN; i++) {
        if (dp[i - 1] + 1 <= k && k <= dp[i]) {
            use = i;
            break;
        }
    }

    // debug(use, dp[use], k - dp[use - 1]);
    int ans = getdig(k - dp[use - 1]);
    println(ans);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i < MN; i++) {
        dp[i] = (dp[i - 1] << 1) - dp[i - 2] + (int)log10(i) + 1;
    }

    dpc[1] = 1;
    for (int i = 2; i < MN; i++) {
        dpc[i] = dpc[i - 1] + (int)log10(i) + 1;
    }

    int T; scan(T);
    while (T--) {
        scan(k);
        solve();
    }

    return 0;
}