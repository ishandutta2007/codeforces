#pragma region
#include <bits/stdc++.h>
using namespace std;
// Common Type shorteners and int128
using ll = long long; using ull = unsigned long long; using ld = long double;
using pii = pair<int, int>; using pll = pair<ll, ll>;
template <typename T> using vec = vector<T>;
template <typename K, typename V> using umap = unordered_map<K, V>; template <typename K> using uset = unordered_set<K>;
using vi = vec<int>; using vl = vec<ll>; using vpi = vec<pii>; using vpl = vec<pll>;
#ifdef __SIZEOF_INT128__
using int128 = __int128_t; using uint128 = __uint128_t;
#endif
template<typename I> string intStr(I x) { string ret; while (x > 0) { ret += (x % 10) + '0'; x /= 10; } reverse(ret.begin(), ret.end()); return ret; } // Int to string
// Shorthand Macros
#define INF 0x3f3f3f3f
#define LLINF 0x3f3f3f3f3f3f3f3f
#define mpr make_pair
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
// Shorthand Function Macros
#define sz(x) ((int)((x).size()))
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (__typeof(a) i = a; i < b; i++)
#define reprev(i, a, b) for (__typeof(a) i = a; i > b; i--)
#define repi(a, b) rep(i, a, b)
#define repj(a, b) rep(j, a, b)
#define repk(a, b) rep(k, a, b)
#define Cmplt(type) bool operator<(const type &o) const
#define Cmpgt(type) bool operator>(const type &o) const
#define Cmpfn(name, type) bool name(const type &a, const type &b)
#define Inop(type) istream& operator>>(istream& in, type &o)
#define Outop(type) ostream& operator<<(ostream& out, type o)
#define Pow2(x) (1LL << (x))
#define scn(type, ...) type __VA_ARGS__; scan(__VA_ARGS__) // scn -> Short for SCan New
// Shorthand Functions
template<typename T> inline void maxa(T& st, T v) { st = max(st, v); }
template<typename T> inline void mina(T& st, T v) { st = min(st, v); }
inline void setprec(ostream& out, int prec) { out << setprecision(prec) << fixed; }
// Out operators and printing for arrays and vectors
template <typename T> ostream& operator<<(ostream& out,vector<T> iter){out<<"[";for(auto t:iter){out<<t<<", ";}out<<"]";return out;}
template <typename T> string arrayStr(T *arr,int sz){string ret = "[";for(int i=0;i<sz;i++){ret+=to_string(arr[i])+", "; } return ret + "]";}
template <typename T> void printArray(T *arr,int sz){for(int i=0;i<sz;i++){cout<<arr[i]<<" "; } cout<<"\n";}
// I/O Operations
inline void scan(){}
template<typename F, typename... R> inline void scan(F &f,R&... r){cin>>f;scan(r...);}
template <typename F> inline void println(F t){cout<<t<<'\n';}
template<typename F, typename... R> inline void println(F f,R... r){cout<<f<<" ";println(r...);}
inline void print(){}
template<typename F, typename... R> inline void print(F f,R... r){cout<<f;print(r...);}
// Debugging
#define db(x) cout << (#x) << ": " << x << ", "
#define dblb(s) cout << "[" << s << "] "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

struct p {
    int i, j, k;
};

Outop(p) {
    out << '(' << o.i << ", " << o.j << ", " << o.k << ")";
    return out;
}

const int MN = 201, MD = 501;
int n, m;
string a, b;
int dp[MN][MN][MD];
p par[MN][MN][MD];
queue<p> nxt;

// int rec(int aind, int bind, int bal) {
//     if (aind > n || bind > m) return INF;
//     if (aind == n && bind == m) return bal == 0 ? 0 : INF;
//     auto &ret = dp[aind][bind][bal];
//     auto &rpar = par[aind][bind][bal];
//     if (ret != -1) return ret;

//     ret = INF;

//     return ret;
// }

inline void tryPush(p &cur, p adj) {
    if (adj.k >= MD) return;

    int lv = dp[cur.i][cur.j][cur.k], &adjlv = dp[adj.i][adj.j][adj.k];
    if (adjlv == -1) {
        adjlv = lv + 1;
        par[adj.i][adj.j][adj.k] = cur;
        nxt.push(adj);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(a, b);
    n = a.length();
    m = b.length();

    memset(dp, -1, sizeof dp);
    // rec(0, 0, 0);
    par[0][0][0] = {-1, -1, -1};

    // graph theory time :)
    // int its=100000;
    nxt.push({0, 0, 0});
    dp[0][0][0] = 0;
    while (!nxt.empty()) {
        p cur = nxt.front(); nxt.pop();
        // int cdis = dp[cur.i][cur.j][cur.k];

        // db(cur); db(dp[cur.i][cur.j][cur.k]); dbln;
        // assert(its--);

        // insert '('
        bool eq1 = cur.i < n && a[cur.i] == '(', eq2 = cur.j < m && b[cur.j] == '(';
        if (eq1) tryPush(cur, {cur.i + 1, cur.j, cur.k + 1});
        if (eq2) tryPush(cur, {cur.i, cur.j + 1, cur.k + 1});
        if (eq1 && eq2) tryPush(cur, {cur.i + 1, cur.j + 1, cur.k + 1});
        tryPush(cur, {cur.i, cur.j, cur.k + 1});

        // insert ')'
        if (cur.k > 0) {
            eq1 = cur.i < n && a[cur.i] == ')', eq2 = cur.j < m && b[cur.j] == ')';
            if (eq1) tryPush(cur, {cur.i + 1, cur.j, cur.k - 1});
            if (eq2) tryPush(cur, {cur.i, cur.j + 1, cur.k - 1});
            if (eq1 && eq2) tryPush(cur, {cur.i + 1, cur.j + 1, cur.k - 1});
            tryPush(cur, {cur.i, cur.j, cur.k - 1});
        }
    }

    // backtrack
    int i = n, j = m, k = 0;
    string ans;
    // int its=1000;
    while (i != -1 && j != -1 && k != -1) {
        auto cpar = par[i][j][k];
        // assert(its--);
        if (cpar.k != -1) { // park cant be negative anyway
            if (cpar.k < k)
                ans += '(';
            else if (cpar.k > k)
                ans += ')';
        }
        
        // db(i); db(j); db(k); db(cpar); db(ans); dbln;
        
        i = cpar.i;
        j = cpar.j;
        k = cpar.k;
    }
    reverse(all(ans));

    println(ans);

    return 0;
}