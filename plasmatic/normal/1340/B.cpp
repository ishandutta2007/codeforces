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
#define mtup make_tuple
#define pb push_back
#define popcount __builtin_popcount
#define clz __builtin_clz
#define ctz __builtin_ctz
#define finline __attribute__((always_inline))
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
#define db(x) cout << (#x) << ": " << (x) << ", "
#define dblb(s) cout << "[" << (s) << "] "
#define dba(alias, x) cout << (alias) << ": " << (x) << ", "
template<typename F> inline string __generic_tostring(F f) { stringstream ss; ss << f; return ss.str(); }
template<typename F> inline string __join_comma(F f) {return __generic_tostring(f);}
template<typename F, typename... R> string __join_comma(F f, R... r) { return __generic_tostring(f) + ", " + __join_comma(r...); }
#define dbp(alias, ...) cout << (alias) << ": (" << __join_comma(__VA_ARGS__) << "), "
#define dbbin(x, n) cout << (#x) << ": " << bitset<n>(x) << ", "
#define dbarr(x, n) cout << (#x) << ": " << arrayStr((x), (n)) << ", "
#define dbln cout << endl;
#pragma endregion

const int MN = 2001;
const string DIG[10] = {"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
int N, K;
string dig[MN];
struct par {
    int prek, dig;
} dp[MN][MN];

int gain(const string &a, const string &b) { // a into b
    int add = 0;
    repi(0, 7) {
        if (a[i] == '1' && b[i] != '1') {
            add = -1;
            break;
        }
        else if (a[i] == '0' && b[i] == '1')
            add++;
    }
    return add;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // repi(0, 10) {
    //     dmap[DIG[i]] = i;
    //     // repj(0, 10) { // i to j
    //     //     gain[i][j] = add;
    //     // }
    // }

    scan(N, K);
    repi(0, N) scan(dig[i]);
    reverse(dig, dig + N);
    // init dp
    repi(1, K + 1)
        dp[0][i].dig = -1;
    dp[0][0].dig = -2;
    repi(1, N + 1)
        repj(0, K + 1)
            dp[i][j].dig = -1;
    // dp
    repi(0, N) {
        repj(0, K + 1) {
            if (dp[i][j].dig == -1) continue;
            repk(0, 10) {
                int add = gain(dig[i], DIG[k]), nj = j + add;
                if (add != -1 && nj <= K) {
                    if (dp[i + 1][nj].dig == -1 || k > dp[i + 1][nj].dig) {
                        dp[i + 1][nj] = {j, k};
                    }
                }
            }
        }
    }
    // output
    string ans;
    int ck = K;
    reprev(i, N, 0) {
        if (dp[i][ck].dig == -1) {
            println(-1);
            return 0;
        }
        // db(i); db(ck); db(dp[i][ck].dig); db(dp[i][ck].prek); dbln;
        ans += char(dp[i][ck].dig + '0');
        ck = dp[i][ck].prek;
    }
    // reverse(all(ans));
    println(ans);

    return 0;
}