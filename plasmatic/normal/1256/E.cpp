// k
#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common DS shorteners
using ll = long long; using ull = unsigned long long;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using um = unordered_map<K, V>; template<typename K, typename V> using om = map<K, V>;
template <typename K> using us = unordered_set<K>; template <typename K> using os = set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define pb push_back
// Shorthand Function Macros
#define Fori(a, b) for (int i = a; i < b; i++)
#define Forj(a, b) for (int j = a; j < b; j++)
#define Fork(a, b) for (int k = a; k < b; k++)
#define Forinci(a, b) for (int i = a; i <= b; i++)
#define Forincj(a, b) for (int j = a; j <= b; j++)
#define Forinck(a, b) for (int k = a; k <= b; k++)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(type) bool operator()(const type &a, const type &b)
#define Memset(ptr, val) memset((ptr), (val), sizeof (ptr))
#define Memset(ptr, val, size) memset((ptr), (val))
// Shorthand Function Macros Part 2
#define Pow2(x) (1LL << (x))
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> void debugArray(T *arr,int sz){cout<<"[";for(int i=0;i<sz;i++){cout<<arr[i]<<", "; } cout<<"]\n";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
#define OUT_OPERATOR(type, propa, propb) ostream& operator<<(ostream& out,type obj){out<<"("<<#propa<<"="<<obj. propa<<", "<<#propb<<"="<<obj. propb<<")";return out;}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
int di_; string dnms_, casttostr_ = ",";
void debug_(){cout<<endl;}
template<typename T> string debug_tostring_(T val) { ostringstream os; os << val; return os.str(); }
string debug_name_(string s, string str_val) {
    string ret = ""; if (s[0] == ' ') { ret += ' '; s = s.substr(1); } if (s[0] == '"' && s[s.length() - 1] == '"') { ret += string("[") + str_val + "]"; }
    else if (s.length() == (size_t)3 && s[0] == '\'' && s[2] == '\'') { ret += '(' + str_val + ')'; } else { ret += s + ": " + str_val; } return ret;
} template<typename F, typename... R> void debug_(F f, R... r) {
    int bc = 0; string pr = "";
    while (bc != 0 || dnms_[di_] != ',') { if (dnms_[di_] == '(') { bc++; } else if (dnms_[di_] == ')') { bc--; } pr += dnms_[di_++]; }
    di_++; cout << debug_name_(pr, debug_tostring_(f)) << ","; debug_(r...);
}
#define debug(...) do{dnms_=#__VA_ARGS__+casttostr_,di_=0,debug_(__VA_ARGS__);}while(0)
#pragma endregion

struct p {
    int i, v;
    Cmplt(p) { return v < o.v; }
};

const int MN = 2e5 + 1;
int n,
    ans[MN];
p vals[MN];
struct {
    int pari, parj, k;
    ll val;
} dp[MN][4];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(n);

    Forinci(1, n) {
        int v;
        scan(v);
        vals[i] = {i, v};
    }
    sort(vals + 1, vals + 1 + n);

    // dp
    Forinci(0, n)
        Forincj(1, 3)
            dp[i][j] = {-1, -1, 0, LLINF};
    dp[1][1] = {-1, -1, 1, 0LL};

    Forinci(1, n - 1) {
        Forincj(1, 3) {
            if (j == 3) { // Make new or not make new
                ll alt = dp[i][j].val + vals[i + 1].v - vals[i].v;
                if (dp[i + 1][j].val > alt) {
                    dp[i + 1][j] = {i, j, dp[i][j].k, alt};
                }

                alt = dp[i][j].val;
                if (dp[i + 1][1].val > alt) {
                    dp[i + 1][1] = {i, j, dp[i][j].k + 1, alt};
                }
            }
            else { // keep going
                ll alt = dp[i][j].val + vals[i + 1].v - vals[i].v;
                if (dp[i + 1][j + 1].val > alt) {
                    dp[i + 1][j + 1] = {i, j, dp[i][j].k, alt};
                }
            }
        }
    }

    // backtrack
    int ck = dp[n][3].k, ci = n, cj = 3;
    while (ci != -1 && cj != -1) {
        auto dpv = dp[ci][cj];
        ans[vals[ci].i] = ck;

        // debug(ci, cj, dpv.parj, cj);
        if (dpv.pari != -1 && dpv.parj != -1 && dpv.parj > cj) // next group
            ck--;
        
        ci = dpv.pari;
        cj = dpv.parj;
    }

    // output
    println(dp[n][3].val, dp[n][3].k);
    Forinci(1, n)
        print(ans[i], ' ');
    print('\n');

    return 0;
}