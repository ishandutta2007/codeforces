/**
 *	author: nok0
 *	created: 2020.09.13 00:40:09
**/
#ifdef LOCAL
#define _GLIBCXX_DEBUG
#endif
#include<bits/stdc++.h>
using namespace std;
#pragma region Macros
#define ll long long
#define ld long double
#define FOR(i,l,r) for(int i=(l);i<(r);++i)
#define REP(i,n) FOR(i,0,n)
#define REPS(i,n) FOR(i,1,n+1)
#define RFOR(i,l,r) for(int i=(l);i>=(r);--i)
#define RREP(i,n) RFOR(i,n-1,0)
#define RREPS(i,n) RFOR(i,n,1)
#define pb push_back
#define eb emplace_back
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()
template<class T = int> using V = vector<T>;
template<class T = int> using VV = V<V<T>>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
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
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p){
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p){
    os << p.first << " " << p.second;
    return os;
}
template <class T>
ostream &operator<<(ostream &os, const V<T> &v){
    REP(i, SZ(v)){
        if(i) os << " ";
        os << v[i];
    }
    return os;
}
//debug
template <typename T>
void view(const V<T> &v){
    cerr << "{ ";
    for(const auto &e : v){
        cerr << e << ", ";
    }
    cerr << "\b\b }";
}
template <typename T>
void view(const VV<T> &vv){
    cerr << "{\n";
    for(const auto &v : vv){
        cerr << "\t";
        view(v);
        cerr << "\n";
    }
    cerr << "}";
}
template <typename T, typename U>
void view(const V<pair<T, U>> &v){
    cerr << "{\n";
    for(const auto &c : v) cerr << "\t(" << c.first << ", " << c.second << ")\n";
    cerr << "}";
}
template <typename T, typename U>
void view(const map<T, U> &m){
    cerr << "{\n";
    for(auto &t : m) cerr << "\t[" << t.first << "] : " << t.second << "\n";
    cerr << "}";
}
template <typename T, typename U>
void view(const pair<T, U> &p){ cerr << "(" << p.first << ", " << p.second << ")";}
template <typename T>
void view(const set<T> &s) {
    cerr << "{ ";
    for(auto &t : s) {
        view(t);
        cerr << ", ";
    }
    cerr << "\b\b }";
}
template <typename T>
void view(T e) { cerr << e;}
#ifdef LOCAL
void debug_out() {}
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
    view(H);
    cerr << ", ";
    debug_out(T...);
}
#define debug(...)                                           \
    do{                                                     \
        cerr << __LINE__ << " [" << #__VA_ARGS__ << "] : ["; \
        debug_out(__VA_ARGS__);                              \
        cerr << "\b\b]\n";                                   \
    } while(0)
#else
#define debug(...) (void(0))
#endif
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
struct iofast{iofast(){ios::sync_with_stdio(false); cin.tie(nullptr); cout << fixed << setprecision(15);}}iofast_;
const int inf = 1e9;
const ll INF = 1e18;
#pragma endregion
 
template <class Monoid, class E>
struct LazySegmentTree{
private:
    using F = function<Monoid(Monoid, Monoid)>;
    using G = function<Monoid(Monoid, E)>;
    using H = function<E(E, E)>;
    int n, height;
    V<Monoid> Node;
    V<E> Lazy;
    F f;
    G g;
    H h;
    Monoid Monoid_unit, init_data;
    E e_unit;
 
    void build(V<Monoid> vec){
        Node.assign(2 * n, init_data);
        REP(i, n) Node[i + n] = vec[i];
        RREP(i, n) Node[i] = f(Node[i << 1], Node[i << 1 | 1]);
        Lazy.assign(2 * n, e_unit);
        height = 0;
        for(int i = 1; i <= n; i *= 2) height++;
    }
 
    void eval(int left, int right){
        left += n, right += n - 1;
        RREPS(i, height){
            int l = left >> i, r = right >> i;
            Lazy[l << 1] = h(Lazy[l << 1], Lazy[l]);
            Lazy[l << 1 | 1] = h(Lazy[l << 1 | 1], Lazy[l]);
            Node[l] = g(Node[l], Lazy[l]);
            Lazy[l] = e_unit;
            Lazy[r << 1] = h(Lazy[r << 1], Lazy[r]);
            Lazy[r << 1 | 1] = h(Lazy[r << 1 | 1] , Lazy[r]);
            Node[r] = g(Node[r], Lazy[r]);
            Lazy[r] = e_unit;
        }
    }
 
public:
    LazySegmentTree(V<Monoid> vec, F f_, G g_, H h_, Monoid Monoid_unit_, E e_unit_)
    :n(SZ(vec)), f(f_), g(g_), h(h_), Monoid_unit(Monoid_unit_), e_unit(e_unit_){
        build(vec);
    }
 
    LazySegmentTree(int n_, F f_, G g_, H h_, Monoid Monoid_unit_, E e_unit_)
    :n(n_), f(f_), g(g_), h(h_), Monoid_unit(Monoid_unit_), e_unit(e_unit_), init_data(Monoid_unit_){
        build(V<Monoid>(n, init_data));
    }
 
    LazySegmentTree(int n_, F f_, G g_, H h_, Monoid Monoid_unit_, E e_unit_, Monoid init_data_)
    :n(n_), f(f_), g(g_), h(h_), Monoid_unit(Monoid_unit_), e_unit(e_unit_), init_data(init_data_){
        build(V<Monoid>(n, init_data));
    }
 
    void update(int left, int right, E operator_){
        eval(left, right);
        left += n, right += n;
        int L0 = left / (left & -left);
        int R0 = right / (right & -right);
        while(left < right) {
            if(left & 1) Lazy[left] = h(Lazy[left], operator_);
            if(right & 1) Lazy[right - 1] = h(Lazy[right - 1], operator_);
            (left += 1) >>= 1;
            right >>= 1;
        }
        left = L0;
        right = R0;
        while(left > 1) {
            left >>= 1;
            Node[left] = f(g(Node[left << 1], Lazy[left << 1]), g(Node[left << 1 | 1], Lazy[left << 1 | 1]));
            Lazy[left] = e_unit;
        }
        while(right > 1) {
            right >>= 1;
            Node[right] = f(g(Node[right << 1], Lazy[right << 1]), g(Node[right << 1 | 1], Lazy[right << 1 | 1]));
            Lazy[right] = e_unit;
        }
    }
 
    //[a, b)
    Monoid query(int left, int right) {  
        eval(left, right);
        Monoid a = Monoid_unit, b = Monoid_unit;
        left += n, right += n;
        while(left < right){
            if(left & 1) a = f(a, g(Node[left], Lazy[left]));
            if(right & 1) b = f(g(Node[right - 1], Lazy[right - 1]), b);
            (left += 1) >>= 1;
            right >>= 1;
            }
        return f(a, b);
    }
 
    Monoid operator[](int i) {
        return query(i, i + 1);
    }
};
 
int main(){
    INT(n);
    VEC(int, a, n);
    INT(q);
    int res;
    auto f = [](ll a, ll b){return a + b;};
    LazySegmentTree<ll, ll> LST(n, f, f, f, 0, 0);
    REP(i, n) LST.update(i, i + 1, a[i]);
    ll b = 0, c = a[0];
    REP(i, n - 1){
        if(a[i + 1] - a[i] > 0) b += a[i + 1] - a[i];
    }
    print((c - b) / 2 + b);
    debug(b, c);
    while(q--){
        LL(l, r, x);
        l--;
        ll sa, sa2;
        if(l) sa = LST[l] - LST[l - 1];
        if(r != n) sa2 = LST[r] - LST[r - 1];
        LST.update(l, r, x);
        if(l == 0) c += x;
        if(l){
            ll nsa = sa + x;
            if(sa > 0 and nsa > 0) b += x;
            if(sa > 0 and nsa <= 0) b-= sa;
            if(sa <= 0 and nsa > 0) b += nsa;
        }
        if(r != n){
            ll nsa2 = sa2 - x;
            if(sa2 > 0 and nsa2 > 0) b -= x;
            if(sa2 > 0 and nsa2 <= 0) b -= sa2;
            if(sa2 <= 0 and nsa2 > 0) b += nsa2;
        }
        debug(sa, sa2, b, c);
        print((c - b) / 2 + b);
    }
}