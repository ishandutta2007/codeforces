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
#define repre(i, a, b) for (__typeof(a) i = a; i > b; i--)
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

struct Qu {
    int i, l, r, k;
};

Cmpfn(byl, Qu) {
    return a.l > b.l;
}

Cmpfn(byr, Qu) {
    return a.r < b.r;
}

const int MN = 3e5 + 1, TRIALS = 200;
int n, q,
    val[MN], freq[MN], ans[MN], pre[MN];
vi randresres[MN], randres[MN];
mt19937 mt;
Qu qus[MN];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    mt = mt19937(time(NULL));
    scan(n, q);
    repi(1, n + 1) {
        int v; scan(v);
        val[i] = v;
    }

    repi(0, q) {
        scn(int, l, r, k);
        uniform_int_distribution<int> dis(l, r);
        randres[i].resize(TRIALS);
        for (int j = 0; j < TRIALS; j++)
            randres[i][j] = val[dis(mt)];
        qus[i] = {i, l, r, k};
    }

    memset(pre, -1, sizeof pre);
    repi(1, n + 1) {
        // db(i); dbarr(pre, n + 1); dbln;
        freq[i] = pre[val[i]] == -1 ? 1 : freq[pre[val[i]]] + 1;        
        pre[val[i]] = i;
    }
    // dbarr(freq, n + 1); dbln;

    // back
    memset(pre, -1, sizeof pre);
    sort(qus, qus + q, byr);
    int ptr = 1;
    repi(0, q) {
        while (ptr <= qus[i].r) {
            pre[val[ptr]] = ptr;
            ptr++;
        }
        vi &res = randresres[qus[i].i], &resVals = randres[qus[i].i]; res.resize(TRIALS);
        repj(0, TRIALS) 
            res[j] = freq[pre[resVals[j]]];
    }

    // forward
    memset(pre, -1, sizeof pre);
    sort(qus, qus + q, byl);
    ptr = n;
    repi(0, q) {
        while (ptr >= qus[i].l) {
            pre[val[ptr]] = ptr;
            ptr--;
        }
        vi &res = randresres[qus[i].i], &resVals = randres[qus[i].i];
        int best = INF, threshold = (qus[i].r - qus[i].l + 1) / qus[i].k;
        repj(0, TRIALS) {
            int left = res[j] - freq[pre[resVals[j]]] + 1;
            // db(i); dbp("qu", qus[i].l, qus[i].r, qus[i].k); db(j); db(left); db(resVals[j]); db(threshold); dbln;
            if (left > threshold)
                mina(best, resVals[j]);
        }
        ans[qus[i].i] = best == INF ? -1 : best;
    }

    repi(0, q)
        println(ans[i]);

    return 0;
}