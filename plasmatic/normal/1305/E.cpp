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

/*
sum of all even up to N-1
X=(N-1)/2-1

N=5, M=3

3: 1
4: 1
5: 2
6: 2
7: 3
8: 2
9: 2


a: 3

1, 2, 3, 4, 5, 6
*/

int N, M;

ll f(int to) {
    int tot = 0;
    repi(1, to + 1)
        repj(i + 1, to + 1)
            tot += i + j <= to;
    return tot;
}

const int MV = 50001;
int cnt[MV];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N, M);
    // mt19937 mt;
    // uniform_int_distribution<int> d1(1, 1000), d2(5, 10000);
    // N = d1(mt); M = d2(mt);

    int l = 1, r = N + 1;
    while (l + 1 < r) {
        int mid = (l + r) / 2;
        if (f(mid) > M)
            r = mid;
        else
            l = mid;
    }

    if (f(N) < M) {
        println(-1);
        return 0;
    }

    // db(l); db(f(l)); db(r); dbln;
    vi ans;
    repi(1, l + 1)
        ans.pb(i);
    repi(0, l)
        repj(i + 1, l)
            cnt[ans[i] + ans[j]]++;
        
    // final
    int left = M - f(l);
    
    if (left > 0 && l == N) {
        println(-1);
        return 0;
    }
    
    if (l == N) {
    for (auto x : ans)
        print(x, ' ');
    print('\n');
    return 0;
    }

    repi(1, MV) {
        if (i <= l) continue;
        if (left == cnt[i]) {
            left -= cnt[i];
            ans.pb(i);
            break;
        }
    }
    // repi(1, MV) {
    //     if (cnt[i] > 0) db(i), db(cnt[i]), dbln;
    // }
    assert(left == 0);

    // 0
    int lim = 1e9, jmp = *max_element(all(ans)) + 1;
    while (int(ans.size()) < N) {
        ans.pb(lim);
        lim -= jmp;
    }
    sort(all(ans));
    
    // output
    for (auto x : ans)
        print(x, ' ');
    print('\n');

    // int tot = 0;
    // set<int> cc;
    // for (auto x : ans)
    //     cc.insert(x);
    // int sz = sz(ans);
    // repi(0, sz)
    //     repj(i + 1, sz)
    //         tot += cc.find(ans[i]+ans[j])!=cc.end();
    // db(tot); db(M); dbln;

    return 0;
}