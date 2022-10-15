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

const int MN = 51;
int N,
    dp[MN][MN][MN][MN], invDp[MN][MN][MN][MN];
bool ans[MN][MN], invAns[MN][MN];

bool ask(int a, int b, int c, int d) {
    a++; b++; c++; d++;
    cout << "? " << a << ' ' << b << ' ' << c << ' ' << d << '\n';
    cout.flush();
    int res; cin >> res; assert(res != -1);
    return res;
}

void answer(bool ans[MN][MN]) {
    cout << "!\n";
    repi(0, N) {
        repj(0, N) print(ans[i][j]);
        print('\n');
    }
    cout.flush();
}

int rec(int dp[MN][MN][MN][MN], bool grid[MN][MN], int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 + 1 == y2) return grid[x1][y1] == grid[x2][y2];
    if (y1 == y2 && x1 + 1 == x2) return grid[x1][y1] == grid[x2][y2];
    if (x1 == y1 && x2 == y2) return 1;
    int &ret = dp[x1][y1][x2][y2];
    if (ret != -1) return ret;

    ret = 0;
    if (grid[x1][y1] != grid[x2][y2]) return ret;
    if (y1 + 1 <= y2) {
        if (x2 - 1 >= x1)
            ret |= rec(dp, grid, x1, y1 + 1, x2 - 1, y2);
        if (y1 + 1 <= y2 - 1)
            ret |= rec(dp, grid, x1, y1 + 1, x2, y2 - 1);
    }
    else if (x1 + 1 <= x2) {
        if (x2 - 1 >= x1 + 1)
            ret |= rec(dp, grid, x1 + 1, y1, x2 - 1, y2);
        if (y1 <= y2 - 1)
            ret |= rec(dp, grid, x1 + 1, y1, x2, y2 - 1);
    }
    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    scan(N);

    ans[0][0] = 1;
    ans[0][1] = 1; // assuming makes an ass out of you and me
    repi(0, N) {
        if (i > 0) {
            if (i % 2) {
                ans[i][1] = ans[i - 1][0] ^ !ask(i - 1, 0, i, 1);
                ans[i][2] = ans[i - 1][1] ^ !ask(i - 1, 1, i, 2);
            }
            else {
                ans[i][0] = ans[i - 2][0] ^ !ask(i - 2, 0, i, 0);
                ans[i][1] = ans[i - 2][1] ^ !ask(i - 2, 1, i, 1);
            }
        }
        if (i % 2)
            ans[i][0] = ans[i][2] ^ !ask(i, 0, i, 2);
        repj(2, N) {
            if ((i % 2) && j == 2) continue;
            if (i != N - 1 || j != N - 1)
                ans[i][j] = ans[i][j - 2] ^ !ask(i, j - 2, i, j);
        }

        // dblb("done"); db(i); dbarr(ans[i], N); dbln;
    }
    repi(0, N)
        repj(0, N)
            invAns[i][j] = ans[i][j] ^ ((i + j) % 2);
    
    // check check check check check
    memset(dp, -1, sizeof dp);
    memset(invDp, -1, sizeof invDp);
    repi(0, N) {
        repj(0, N) {
            repk(i, N) {
                rep(l, j, N) {
                    if (k - i + l - j >= 2) { // pog
                        bool res1 = rec(dp, ans, i, j, k, l), res2 = rec(invDp, invAns, i, j, k, l);
                        // if (i==0&&j==0&&k==2&&l==1){
                        //     db(i);db(j);db(k);db(l);db(res1);db(res2);dbln;
                        // }
                        if (res1 != res2) {
                            bool q = ask(i, j, k, l);
                            if (q == res2) answer(invAns);
                            else answer(ans);

                            return 0;
                        }
                    }
                }
            }
        }
    }

    assert(0);
    answer(ans);
    answer(invAns);

    return 0;
}