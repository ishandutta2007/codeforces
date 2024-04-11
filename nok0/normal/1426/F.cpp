/**
 *	author: nok0
 *	created: 2020.09.28 16:57:12
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

//ModInt
template <const int &mod>
struct ModInt {
private:
    long long x;

    long long ext_gcd(long long a, long long b, long long &x, long long &y){
        if(b == 0){
            x = 1, y = 0;
            return a;
        }
        long long q = a / b;
        long long g = ext_gcd(b, a - q * b, x, y);
        long long z = x - q * y;
        x = y, y = z;
        return g;
    }

public:    
    ModInt() : x(0) {}

    ModInt(long long x_) {
        if ((x = x_ % mod + mod) >= mod) x -= mod;
    }

    constexpr ModInt& operator+=(ModInt rhs){
        if ((x += rhs.x) >= mod) x -= mod;
        return *this;
    }

    constexpr ModInt& operator-=(ModInt rhs){
        if ((x -= rhs.x) < 0) x += mod;
        return *this;
    }

    constexpr ModInt& operator*=(ModInt rhs){
        x = (unsigned long long)x * rhs.x % mod;
        return *this;
    }

    constexpr ModInt& operator/=(ModInt rhs){
        x = (unsigned long long)x * rhs.inv().x % mod;
        return *this;
    }
  
    constexpr ModInt operator-() const noexcept{ return -x < 0 ? mod - x : -x; }

    constexpr ModInt operator+(ModInt rhs) const noexcept{ return ModInt(*this) += rhs; }

    constexpr ModInt operator-(ModInt rhs) const noexcept{ return ModInt(*this) -= rhs; }

    constexpr ModInt operator*(ModInt rhs) const noexcept{ return ModInt(*this) *= rhs; }

    constexpr ModInt operator/(ModInt rhs) const noexcept{ return ModInt(*this) /= rhs; }

    constexpr ModInt &operator++ () { *this += 1; return *this;}

    constexpr ModInt operator++ (int) { *this += 1; return *this - 1;}

    constexpr ModInt &operator-- () { *this -= 1; return *this;}

    constexpr ModInt operator-- (int) { *this -= 1; return *this + 1;}

    bool operator==(ModInt rhs) const { return x == rhs.x; }    

    bool operator!=(ModInt rhs) const { return x != rhs.x; }

    bool operator<=(ModInt rhs) const { return x <= rhs.x; }

    bool operator>=(ModInt rhs) const { return x >= rhs.x; }

    bool operator<(ModInt rhs) const { return x < rhs.x; }

    bool operator>(ModInt rhs) const { return x > rhs.x; }

    ModInt inv() {
        long long x, y;
        ext_gcd(this->x, mod, x, y);
        return (ModInt) x;
    }
  
    friend std::ostream& operator<<(std::ostream& s, ModInt<mod> a) {
        s << a.x;
        return s;
    }
    
    friend std::istream& operator>>(std::istream& s, ModInt<mod>& a) {
        s >> a.x;
        return s;
    }
};

//Modulo Calculation
static int MOD = 1e9 + 7;
// static int MOD = 998244353;
using mint = ModInt<MOD>;

int main(){
    INT(n);
    STR(s);
    //dp[i]aababc
    using T = tuple<mint, mint, mint>;
    V<T> dp(n + 1, T(0, 0, 0));
    ll cnt = 0;
    REP(i, n){
        auto [x, y, z] = dp[i];
        if(s[i] == 'a')
            dp[i + 1] = T(x + pow(mint(3), cnt), y, z);
        
        if(s[i] == 'b')
            dp[i + 1] = T(x, x + y, z);
        
        if(s[i] == 'c')
            dp[i + 1] = T(x, y, y + z);
        
        if(s[i] == '?')
            dp[i + 1] = T(x * 3 + pow(mint(3), cnt), x + y * 3, y + z * 3), cnt++;
    }
    auto[neg, neg2, res] = dp[n];
    print(res);
}