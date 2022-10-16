#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
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
using P = pair<ll, ll>;
using Graph = VV<int>;
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
template<class T> T Roundup_div(T x, T y) {return (x+(y-1))/y;}
template <typename T> T pow(T a, long long n, T e = 1) {T ret = e; while (n) {if (n & 1) ret *= a; a *= a; n >>= 1; } return ret; }
const ll INF = 1e18;
#pragma endregion

void solve(){
    INT(x);
    STR(u);
    ll res = INF;
    REP(_, 7){
        ll n, c = 0;
        string s;
        if(_ == 0){
            n = x - 2;
            if(u[0] == 'R') c++;
            if(u[x - 1] == 'L') c++;
            s = u.substr(1, n);
        }
        if(_ == 1){
            n = x - 3;
            if(u[0] == 'R') c++;
            if(u[x - 2] == 'L') c++;
            s = u.substr(1, n);
        }
        if(_ == 2){
            n = x - 3;
            if(u[1] == 'R') c++;
            if(u[x - 1] == 'L') c++;
            s = u.substr(2, n);
        }
    
        if(_ == 3){
            n = x;
            s = u;
        }
        if(_ == 4){
            if(n == 3) break;
            n = x - 4;
            if(u[0] == 'R') c++;
            if(u[x - 3] == 'L') c++;
            if(u[x - 2] == 'L') c++;
            if(u[x - 1] == 'R') c++;
            s = u.substr(1, n);
        }
        if(_ == 5){
            n = x - 4;
            if(u[0] == 'R') c++;
            if(u[1] == 'R') c++;
            if(u[x - 2] == 'L') c++;
            if(u[x - 1] == 'L') c++;
            s = u.substr(2, n);
        }
        if(_ == 6){
            n = x - 4;
            if(u[0] == 'L') c++;
            if(u[1] == 'R') c++;
            if(u[2] == 'R') c++;
            if(u[x - 1] == 'L') c++;
            s = u.substr(3, n);
        }
        V<> dp(n + 1, INF);
        dp[0] = 0;
        REP(i, n){
            if(i + 1 < n){
                ll cnt = 0;
                if(s[i] == 'L') cnt++;
                if(s[i + 1] == 'R') cnt++;
                chmin(dp[i + 2], dp[i] + cnt);
            }
            if(i + 2 < n){
                ll cnt = 0;
                if(s[i] == 'L') cnt++;
                if(s[i + 2] == 'R') cnt++;
                chmin(dp[i + 3], dp[i] + cnt);
            }
            if(i + 3 < n){
                ll cnt = 0;
                if(s[i] == 'L') cnt++;
                if(s[i + 1] == 'L') cnt++;
                if(s[i + 2] == 'R') cnt++;
                if(s[i + 3] == 'R') cnt++;
                chmin(dp[i + 4], dp[i] + cnt);
            }
        }
        chmin(res, dp[n] + c);
    }
    print(res);
}

int main(){
    ios;
    INT(t);
    while(t--) solve();
}