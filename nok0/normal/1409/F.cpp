#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
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
using P = pair<int, int>;
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
template <class T> void scan(T a) { cin >> a; }
void scan(int &a) { cin >> a; }
void scan(long long &a) { cin >> a; }
void scan(char &a) { cin >> a; }
void scan(double &a) { cin >> a; }
void scan(long double &a) { cin >> a; }
void scan(char a[]) { scanf("%s", a); }
void scan(string &a) { cin >> a; }
template <class T> void scan(V<T> &);
template <class T, class L> void scan(pair<T, L> &);
template <class T> void scan(V<T> &a) { for(auto &i : a) scan(i); }
template <class T, class L> void scan(pair<T, L> &p){ scan(p.first); scan(p.second); }
template <class T> void scan(T &a) { cin >> a; }
void IN() {}
template <class Head, class... Tail> void IN(Head &head, Tail &... tail) { scan(head); IN(tail...); }
template <class T> inline void print(T x){ cout << x << '\n';}
struct inputoutputfaster{
    inputoutputfaster(){
        ios::sync_with_stdio(false);\
        cin.tie(nullptr);
        cout << fixed << setprecision(15);
    }
}inputoutputfaster_;
template <class T> V<T> press(V<T> &x){ 
    V<T> res = x;
    sort(all(res));
    res.erase(unique(all(res)), res.end());
    REP(i, SZ(x)){
        x[i] = lower_bound(all(res), x[i]) - res.begin();
    }
    return res;
}
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b; return true; }return false; }
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b; return true; }return false; }
inline void Yes(bool b = true) {cout << (b ? "Yes" : "No") << '\n';}
inline void YES(bool b = true) {cout << (b ? "YES" : "NO") << '\n';}
inline void err(bool b = true) {if(b) {cout << -1 << '\n'; exit(0);}}
template<class T> inline void fin(bool b = true, T e = 0) {if(b) {cout << e << '\n'; exit(0);}}
template<class T> T divup(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
const ll INF = 1e18;
#pragma endregion

int res;
int main(){
    INT(n, K);
    STR(s, t);
    if(t[0] == t[1]){
        int cnt = 0;
        REP(i, n) if(s[i] == t[0]) cnt++;
        cnt = min(cnt + K, n);
        print(cnt * (cnt - 1) / 2);
        return 0;
    }
    V<VV<int>> dp(n + 1, VV<int>(n + 1, V<int>(n + 1, -1)));//3t[0]
    dp[0][0][0] = 0;
    REP(i, n){
        if(s[i] != t[0] and s[i] != t[1]){
            REP(j, i + 1) REP(k, i + 1){
                if(dp[i][j][k] == -1) continue;
                chmax(dp[i + 1][j][k], dp[i][j][k]);
                chmax(dp[i + 1][j + 1][k], dp[i][j][k] + k);
                chmax(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
            }
        }
        if(s[i] == t[0]){
            REP(j, i + 1) REP(k, i + 1) if(dp[i][j][k] != -1) chmax(dp[i + 1][j][k + 1], dp[i][j][k]);
            REP(j, i + 1) REP(k, i + 1) if(dp[i][j][k] != -1) chmax(dp[i + 1][j + 1][k], dp[i][j][k] + k);
        }
        if(s[i] == t[1]){
            REP(j, i + 1) REP(k, i + 1) if(dp[i][j][k] != -1) chmax(dp[i + 1][j][k], dp[i][j][k] + k);
            REP(j, i + 1) REP(k, i + 1) if(dp[i][j][k] != -1) chmax(dp[i + 1][j + 1][k + 1], dp[i][j][k]);
        }
    }   
    REP(j, K + 1) REP(k, n + 1) chmax(res, dp[n][j][k]);
    print(res);
}