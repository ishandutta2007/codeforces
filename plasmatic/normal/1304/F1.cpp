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

const int MN = 51, MM = 2e4 + 10, MK = 21;
int N, M, K;
ll cnt[MN][MM], cntp[MN][MM], 
    dp[MN][MM];

ll rsq(ll p[MM], int L, int R) {
    return p[R] - p[L - 1];
}

ll pmax[MM], smax[MM];
void makeMax(int idx) {
    copy(dp[idx], dp[idx] + M + 1, pmax);
    copy(dp[idx], dp[idx] + M + 1, smax);
    repi(1, M + 1)
        pmax[i] += rsq(cntp[idx + 1], i, min(M, i + K - 1));
    repi(1, M + 1)
        smax[i] += rsq(cntp[idx + 1], i, min(M, i + K - 1));
    repi(1, M + 1)
        maxa(pmax[i], pmax[i - 1]);
    reprev(i, M - 1, 0)
        maxa(smax[i], smax[i + 1]);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, M, K);
    repi(1, N + 1)
        repj(1, M + 1)
            scan(cnt[i][j]);
    repi(1, N + 1) {
        copy(cnt[i], cnt[i] + M + 1, cntp[i]);
        repj(1, M + 1)
            cntp[i][j] += cntp[i][j - 1];
        // partial_sum(cntp[i], cntp[i] + M + 1, cntp[i]);
    }

    // dp
    repi(1, M + 1) {
        dp[1][i] = rsq(cntp[1], i, min(M, i + K - 1));
        // db(i); db(dp[1][i]); dbln;
    }
    repi(2, N + 1) {
        makeMax(i - 1);
        repj(1, M + 1) {
            int st = max(1, j - K + 1), en = min(M, j + K - 1);
            repk(st, j + 1) {
                // dblb("trans"); db(i); db(j); db(k); db(dp[i - 1][k]); db(rsq(cntp[i], k, en)); dbln;
                maxa(dp[i][j], dp[i - 1][k] + rsq(cntp[i], k, en));
            }
            repk(j, en + 1) {
                // dblb("trans"); db(i); db(j); db(k); db(dp[i - 1][k]); db(rsq(cntp[i], j, min(M, k + K - 1))); dbln;
                maxa(dp[i][j], dp[i - 1][k] + rsq(cntp[i], j, min(M, k + K - 1)));
            }

            ll baseRsq = rsq(cntp[i], j, en);
            maxa(dp[i][j], pmax[st - 1] + baseRsq);
            maxa(dp[i][j], smax[en + 1] + baseRsq);

            // db(i); db(j); db(dp[i][j]); dbln;
        }
    }

    // get ans
    ll ans = -LLINF;
    repi(1, M + 1)
        maxa(ans, dp[N][i]);
    println(ans);

    return 0;
}