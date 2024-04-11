#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ios\
    ios::sync_with_stdio(false);\
    cin.tie(nullptr);
#define VEC(type, name, size)\
    V<type> name(size);\
    IN(name)
#define VVEC(type, name, h, w)\
    VV<type> name(h, V<type>(w));\
    IN(name)
#define INT(...)\
    int __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LL(...)\
    ll __VA_ARGS__;\
    IN(__VA_ARGS__)
#define STR(...)\
    string __VA_ARGS__;\
    IN(__VA_ARGS__)
#define CHAR(...)\
    char __VA_ARGS__;\
    IN(__VA_ARGS__)
#define DOUBLE(...)\
    DOUBLE __VA_ARGS__;\
    IN(__VA_ARGS__)
#define LD(...)\
    LD __VA_ARGS__;\
    IN(__VA_ARGS__)
template <class T> void scan(T &a) { cin >> a; }
template <class T> void scan(vector<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
#define ll long long
#define ld long double
#define FOR(i,l,r) for(ll i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(ll i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((ll)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = ll> using V = vector<T>;
template<class T = ll> using VV = V<V<T>>;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
const ll INF = 1e18;
#pragma endregion

int main(){
    ios;
    INT(h, w);
    VVEC(char, a, h, w);
    fin(h == 1 or w == 1, 0);
    fin(h > 3 and w > 3, -1);
    if(h > w){
        swap(h, w);
        VV<char> b(h, V<char>(w, 0));
        REP(i, h) REP(j, w) b[i][j] = a[j][i];
    }
    VV<> c(h, V<>(w));
    REP(i, h) REP(j, w) c[i][j] = a[i][j] - '0';
    VV<> mat(h - 1, V<>(w - 1));
    REP(i, h - 1) REP(j, w- 1){
        ll sum = c[i][j] + c[i + 1][j] + c[i][j + 1] + c[i + 1][j + 1];
        mat[i][j] = (sum + 1) % 2;
        //0
    }
    if(h == 2){
        VV<> dp(w, V<>(2, INF));
        dp[0][0] = dp[0][1] = 0;
        ll res = 0;
        REP(i, w - 1){
            if(mat[0][i] == 1){
                dp[i + 1][0] = dp[i][1] + 1;
                dp[i + 1][1] = dp[i][0];
            }
            else{
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = dp[i][1] + 1;
            }            
        }
        print(min(dp[w - 1][0], dp[w - 1][1] + 1));
    }
    if(h == 3){
        VV<> dp(w, V<>(4, INF));
        dp[0][0] = dp[0][1] = dp[0][2] = dp[0][3] = 0;
        ll res = 0;
        REP(i, w - 1){
            if(mat[0][i] == 0 and mat[1][i] == 0){
                dp[i + 1][0] = dp[i][0];
                dp[i + 1][1] = dp[i][1] + 1;
                dp[i + 1][2] = dp[i][2] + 1;
                dp[i + 1][3] = dp[i][3] + 1;
            }
            if(mat[0][i] == 0 and mat[1][i] == 1){
                dp[i + 1][0] = dp[i][1] + 1;
                dp[i + 1][1] = dp[i][0];
                dp[i + 1][2] = dp[i][3] + 1;
                dp[i + 1][3] = dp[i][2] + 1;
            }    
            if(mat[0][i] == 1 and mat[1][i] == 0){
                dp[i + 1][0] = dp[i][2] + 1;
                dp[i + 1][1] = dp[i][3] + 1;
                dp[i + 1][2] = dp[i][0];
                dp[i + 1][3] = dp[i][1] + 1;
            }    
            if(mat[0][i] == 1 and mat[1][i] == 1){
                dp[i + 1][0] = dp[i][3] + 1;
                dp[i + 1][1] = dp[i][2] + 1;
                dp[i + 1][2] = dp[i][1] + 1;
                dp[i + 1][3] = dp[i][0];
            }
        }
        print(min({dp[w - 1][0], dp[w - 1][1] + 1, dp[w - 1][2] + 1, dp[w - 1][3] + 1}));
    }
}