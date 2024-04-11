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

const int MN = 1e5 + 1;
int N[3];
ll W[3][MN];
ll ans;

ll calc(ll a, ll b, ll c) {
    ll d1 = b - a, d2 = c - b, d3 = a - c;
    return d1 * d1 + d2 * d2 + d3 * d3;
}

// void check(ll a, ll b) {
//     ll want = (a + b) / 2;
//     int ind = lower_bound(W[2], W[2] + N[2], want) - W[2], l = max(0, ind - 5), r = min(N[2] - 1, ind + 5);
//     // dblb("check"); db(a); db(b); db(want); dbln;
//     repi(l, r + 1) {
//         // dblb("calc"); db(i); db(W[2][i]); dbln;
//         mina(ans, calc(a, b, W[2][i]));
//     }
// }

void solve() {
    ans = LLONG_MAX;
    repi(0, 3) {
        sort(W[i], W[i] + N[i]);
        int nn = unique(W[i], W[i] + N[i]) - W[i];
        N[i] = nn;
        // db(i); dbarr(W[i], N[i]); dbln;
    }

    int mp[3]; iota(mp, mp + 3, 0);
    do {
        int A = mp[0], B = mp[1], C = mp[2];
        repi(0, N[A]) { 
            ll a = W[A][i];
            auto ptr = lower_bound(W[C], W[C] + N[C], a);
            if (ptr != W[C] + N[C]) {
                ll c = *ptr, want = (c + a) / 2;
                auto ptr2 = lower_bound(W[B], W[B] + N[B], want);
                if (ptr2 != W[B] + N[B])
                    mina(ans, calc(a, *ptr2, c));
                if (ptr2 != W[B])
                    mina(ans, calc(a, *(ptr2 - 1), c));
            }
        }
    } while (next_permutation(mp, mp + 3));
    println(ans);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T; cin >> T;
    while (T--) {
        // Input
        repi(0, 3) scan(N[i]);
        repi(0, 3) {
            repj(0, N[i])
                scan(W[i][j]);
        }

        // Reset
        

        solve();
    }
}