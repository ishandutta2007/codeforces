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
using P = pair<ll, ll>;
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

//Segment Tree
//reference materials: <https://www.creativ.xyz/segment-tree-abstraction-979/>, <https://algo-logic.info/segment-tree/>
template <class Monoid>
class SegTree {
    using F = function<Monoid(Monoid,Monoid)>;
    int n;// 
    vector<Monoid> data; // 
    Monoid def;          // 
    F operation; // 
    F update;    // 
    // [a,b)k=[l,r)
    Monoid _query(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return def; // 
        if (a <= l && r <= b)
            return data[k]; // a,l,r,b
        else {
            Monoid c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); // 
            Monoid c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); // 
            return operation(c1, c2);
        }
    }
 
  public:
    // _n:SegTree, _def:, _operation:,
    // _update:
    SegTree(size_t _n, Monoid _def, F _operation, F _update)
        : def(_def), operation(_operation), update(_update) {
        n = 1;
        while (n < _n) {
            n *= 2;
        }
        data = vector<Monoid>(2 * n - 1, def);
    }
 
    // i(0-indexed)x
    void set(int i, Monoid x) {
        i += n - 1;
        data[i] = update(data[i], x);
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = operation(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
 
    // [a, b)
    Monoid query(int a, int b) {
        return _query(a, b, 0, 0, n);
    }
 
    // 
    Monoid operator[](int i) {
        return data[i + n - 1];
    }
    // [a,b)x()
    // a:, b:, x:x
    int find_rightest(int a, int b, Monoid x) { return find_rightest_sub(a, b, x, 0, 0, n); }
    // [a,b)x()
    // a:, b:, x:x
    int find_leftest(int a, int b, Monoid x) { return find_leftest_sub(a, b, x, 0, 0, n); }
    int find_rightest_sub(int a, int b, Monoid x, int k, int l, int r) {
        if (data[k] > x || r <= a || b <= l) {  // x or [a,b)[l,r)return a-1
            return a - 1;
        } else if (k >= n - 1) {  // return
            return (k - (n - 1));
        } else {
            int vr = find_rightest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            if (vr != a - 1) {  //  a-1 return
                return vr;
            } else {  // return
                return find_rightest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            }
        }
    }
    int find_leftest_sub(int a, int b, Monoid x, int k, int l, int r) {
        if (data[k] > x || r <= a || b <= l) {  // x or [a,b)[l,r)return b
            return b;
        } else if (k >= n - 1) {  // return
            return (k - (n - 1));
        } else {
            int vl = find_leftest_sub(a, b, x, 2 * k + 1, l, (l + r) / 2);
            if (vl != b) {  //  b return
                return vl;
            } else {  // return
                return find_leftest_sub(a, b, x, 2 * k + 2, (l + r) / 2, r);
            }
        }
    }
};

int main(){
    LL(n, k);
    STR(s);
    V<> dp(n + 1, INF);
    SegTree<ll> ST(n + 1, INF, [](ll x, ll y){return min(x, y);}, [](ll x, ll y){return y;});
    ST.set(0, 0);
    dp[0] = 0;
    REP(i, n){
        chmin(dp[i + 1], dp[i] + i + 1);
        if(s[i] == '1'){
            chmin(dp[min(i + k + 1, n)], ST.query(max(i - k, 0ll), n + 1) + i + 1);
            ST.set(min(i + k + 1, n), dp[min(i + k + 1, n)]);
        }
        ST.set(i + 1, dp[i + 1]);
    }
    print(dp[n]);
}