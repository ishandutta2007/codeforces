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

const int MN = 2e5 + 1;
ll n;
ll x, y;
vi g[MN];

// dfs
int lv[MN];
void dfs(int cur, int par, int clv, int lv[MN]) {
    lv[cur] = clv;
    for (int adj : g[cur])
        if (adj ^ par)
            dfs(adj, cur, clv + 1, lv);
}

// int dfs2(int cur, int par) {
//     int chNo = g[cur].size();
//     if (par != -1) chNo--;

//     if (chNo == 0) // leaf
//         return 1;

//     int tot = 0;
//     for (int adj : g[cur])
//         if (adj ^ par)
//             tot += dfs2(adj, cur);
//     return tot;
// }

ll globChainCount = 0;
int dfs2(int cur, int par) {
    int tot = 0;
    for (int adj : g[cur]) {
        if (adj ^ par) {
            tot += dfs2(adj, cur);
        }
    }

    if (par == -1) // root node stuff
        maxa(tot, 2);
    

    if (tot == 0) // must be a leaf node then
        tot++;

    // debug(cur, par, tot);

    if (tot >= 2) {
        globChainCount += tot - 1;
        tot = 0;
    }
    return tot;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(n, x, y);

    Fori(1, n) {
        int a, b;
        scan(a, b);
        g[a].pb(b);
        g[b].pb(a);
    }

    // just use y
    if (y < x) {
        // you can use no `x` edges if you can jump depths 
        // such that it never changes by 1:
        // i.e. 0 1 2 2 3 -> 2 2 0 3 1

        ll ans = y * (ll)(n - 1);
        bool needSub = false;

        Forinci(1, n) {
            if (g[i].size() == (size_t)(n - 1))
                needSub = true;
        }

        if (needSub) {
            ans -= y;
            ans += x;
        }

        println(ans);
        return 0;
    }

    dfs(1, -1, 0, lv);
    int a = max_element(lv + 1, lv + n + 1) - lv; // dia endpoint
    // debug(a);

    // ll chainCount = dfs2(a, -1);
    // ll chainCount = 0;
    // Forinci(1, n) 
    //     chainCount += g[i].size() == (size_t)1;
    // // chainCount = ((chainCount + 1) / 2);
    // // debug(chainCount);
    // chainCount--;

    dfs2(a, -1);
    ll chainCount = globChainCount;
    // debug(chainCount);

    ll ans = x * (ll)(n - 1);
    ans -= (chainCount - 1) * x; // Chains
    ans += (chainCount - 1) * y;

    println(ans);

    return 0;   
}