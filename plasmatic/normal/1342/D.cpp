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

const int MN = 2e5 + 1;
int N, K,
    size[MN], allow[MN], jmp[MN];
vec<vi> ans;
multiset<int, greater<int>> its;
int fst[MN];
bool lst[MN];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, K);
    repi(0, N) {
        scan(size[i]);
        its.insert(size[i]);
    }
    repi(1, K + 1) scan(allow[i]);

    // jmp
    memset(fst, -1, sizeof fst);
    repi(1, K + 1) {
        if (fst[allow[i]] == -1)
            fst[allow[i]] = i;
    }
    set<int> has;
    reprev(i, K, 0) {
        if (!has.count(allow[i])) {
            lst[i] = true;
            has.insert(allow[i]);
        }
    }
    int preind = 0;
    repi(1, K + 1) {
        jmp[i] = preind;
        if (lst[i])
            preind = fst[allow[i]];
    }
    // repi(1, K + 1) {
    //     db(i); db(jmp[i]); dbln;
    // }

    // gre
    while (sz(its)) {
        vi cans;
        int cur = *its.begin(), chas = 0;
        auto it = its.begin();
        // dblb("start"); dbln;
        // int aaaaa=10;
        while (cur >= 1) {
            // assert(aaaaa--);
            // db(cur); db(chas); dbln;
            while (it != its.end() && *it >= fst[allow[cur]] && chas < allow[cur]) {
                // db(cur); db(chas); db(allow[cur]); db(*it); dbln;
                cans.pb(*it);
                chas++;
                it++;
                // if (it!=its.end()) {
                //     dblb("aft"); db(chas); db(allow[cur]); db(*it); dbln;
                // }
            }

            it = its.upper_bound(fst[allow[cur]]);
            if (it != its.end()) {
                // dblb("nxt"); db(*it); dbln;
                cur = fst[allow[*it]];
            }
            else break;
            // while (it != its.end() && *it >= fst[allow[cur]])
            //     it++;
            // cur = jmp[cur];
        }
        for (auto &x : cans)
            its.erase(its.find(x));
        ans.pb(cans);
    }

    // output
    println(sz(ans));
    for (auto &v : ans) {
        print(sz(v), ' ');
        for (auto x : v) print(x, ' ');
        print('\n');
    }

    return 0;
}