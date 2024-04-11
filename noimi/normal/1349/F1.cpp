#pragma region Macros
#pragma GCC optimize("O3")

#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;++i)
#define rep3(i,a,b) for(ll i=a;i>=b;--i)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pb push_back
#define eb emplace_back
#define vi vector<int>
#define vec vector<int>
#define vll vector<ll>
#define vpi vector<pii>
#define vpll vector<pll>
#define overload2(_1,_2,name,...) name
#define vv(a,b) vector<vector<int>>(a,vector<int>(b))
#define vv2(a,b,c) vector<vector<int>>(a,vector<int>(b,c))
#define vvl(a,b) vector<vector<ll>>(a,vector<ll>(b))
#define vvl2(a,b,c) vector<vector<ll>>(a,vector<ll>(b,c))
#define vvv(a,b,c) vector<vv(b,c)>(a)
#define vvv2(a,b,c,d) vector<vv(b,c,d)>(a)
#define vvvl(a,b,c) vector<vvl(b,c)>(a)
#define vvvl2(a,b,c,d) vector<vvl(b,c,d)>(a)
#define fi first
#define se second
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance((c).begin(),lower_bound(all(c),(x)))
#define ub(c,x) distance((c).begin(),upper_bound(all(c),(x)))
using namespace std;
template<class T> using pq = priority_queue<T>;
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
#define INT(...) int __VA_ARGS__;IN(__VA_ARGS__)
#define LL(...) ll __VA_ARGS__;IN(__VA_ARGS__)
#define ULL(...) ull __VA_ARGS__;IN(__VA_ARGS__)
#define STR(...) string __VA_ARGS__;IN(__VA_ARGS__)
#define CHR(...) char __VA_ARGS__;IN(__VA_ARGS__)
#define DBL(...) double __VA_ARGS__;IN(__VA_ARGS__)
#define LD(...) ld __VA_ARGS__;IN(__VA_ARGS__)
#define VEC(type,name,size) vector<type> name(size);IN(name)
#define VV(type,name,h,w) vector<vector<type>>name(h,vector<type>(w));IN(name)
int scan(){ return getchar(); }
void scan(int& a){ cin>>a; }
void scan(long long& a){ cin>>a; }
void scan(char &a){cin>>a;}
void scan(double &a){ cin>>a; }
void scan(long double& a){ cin>>a; }
void scan(char a[]){ scanf("%s", a); }
void scan(string& a){ cin >> a; }
template<class T> void scan(vector<T>&);
template<class T, size_t size> void scan(array<T, size>&);
template<class T, class L> void scan(pair<T, L>&);
template<class T, size_t size> void scan(T(&)[size]);
template<class T> void scan(vector<T>& a){ for(auto& i : a) scan(i); }
template<class T> void scan(deque<T>& a){ for(auto& i : a) scan(i); }
template<class T, size_t size> void scan(array<T, size>& a){ for(auto& i : a) scan(i); }
template<class T, class L> void scan(pair<T, L>& p){ scan(p.first); scan(p.second); }
template<class T, size_t size> void scan(T (&a)[size]){ for(auto& i : a) scan(i); }
template<class T> void scan(T& a){ cin >> a; }
void IN(){}
template <class Head, class... Tail> void IN(Head& head, Tail&... tail){ scan(head); IN(tail...); }
string stin() {string s;cin>>s;return s;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
vi iota(int n){vi a(n);iota(all(a),0);return a;}
template<class T> void UNIQUE(vector<T> &x){sort(all(x));x.erase(unique(all(x)),x.end());}
int in() {int x;cin>>x;return x;}
ll lin() {unsigned long long x;cin>>x;return x;}
void print(){putchar(' ');}
void print(bool a){cout<<a;}
void print(int a){cout<<a;}
void print(long long a){cout<<a;}
void print(char a){cout<<a;}
void print(string &a){cout<<a;}
void print(double a){cout<<a;}
template<class T> void print(const vector<T>&);
template<class T, size_t size> void print(const array<T, size>&);
template<class T, class L> void print(const pair<T, L>& p);
template<class T, size_t size> void print(const T (&)[size]);
template<class T> void print(const vector<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } cout<<endl;}
template<class T> void print(const deque<T>& a){ if(a.empty()) return; print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, size_t size> void print(const array<T, size>& a){ print(a[0]); for(auto i = a.begin(); ++i != a.end(); ){ cout<<" "; print(*i); } }
template<class T, class L> void print(const pair<T, L>& p){ cout<<'(';print(p.first); cout<<","; print(p.second);cout<<')'; }
template<class T, size_t size> void print(const T (&a)[size]){ print(a[0]); for(auto i = a; ++i != end(a); ){ cout<<" "; print(*i); } }
template<class T> void print(const T& a){ cout << a; }
int out(){ putchar('\n'); return 0; }
template<class T> int out(const T& t){ print(t); putchar('\n'); return 0; }
template<class Head, class... Tail> int out(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); return 0; }
ll gcd(ll a, ll b){ while(b){ ll c = b; b = a % b; a = c; } return a; }
ll lcm(ll a, ll b){ if(!a || !b) return 0; return a * b / gcd(a, b); }
vector<pll> factor(ll x){ vector<pll> ans; for(ll i = 2; i * i <= x; i++) if(x % i == 0){ ans.push_back({i, 1}); while((x /= i) % i == 0) ans.back().second++; } if(x != 1) ans.push_back({x, 1}); return ans; }
vector<int> divisor(int x){ vector<int> ans; for(int i=1;i*i<=x;i++)if(x%i==0){ans.pb(i);if(i*i!=x)ans.pb(x/i);} return ans;}
int popcount(ll x){return __builtin_popcountll(x);}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){return uniform_int_distribution<int>(0, n)(rng);}
#define endl '\n'

#ifdef _LOCAL
    #undef endl
    #define debug(x) cout<<#x<<": ";print(x);cout<<endl;
    void err(){}
    template<class T> void err(const T& t){ print(t);  cout<<" ";}
    template<class Head, class... Tail> void err(const Head& head, const Tail&... tail){ print(head); putchar(' '); out(tail...); }
#else
    #define debug(x)
    template<class... T> void err(const T&...){}
#endif
#pragma endregion
const ll MOD=998244353;
const int N=1100000;
 
template <ll Modulus> class modint {
  using u64 = ll;
 
public:
  u64 a;
 
  constexpr modint(const u64 x = 0) noexcept : a(((x % Modulus) + Modulus)%Modulus) {}
  constexpr u64 &value() noexcept { return a; }
  constexpr const u64 &value() const noexcept { return a; }
  constexpr modint operator+(const modint rhs) const noexcept {
    return modint(*this) += rhs;
  }
  constexpr modint operator-(const modint rhs) const noexcept {
    return modint(*this) -= rhs;
  }
  constexpr modint operator*(const modint rhs) const noexcept {
    return modint(*this) *= rhs;
  }
  constexpr modint operator/(const modint rhs) const noexcept {
    return modint(*this) /= rhs;
  }
  constexpr modint &operator+=(const modint rhs) noexcept {
    a += rhs.a;
    if (a >= Modulus) {
      a -= Modulus;
    }
    return *this;
  }
  constexpr modint &operator-=(const modint rhs) noexcept {
    if (a < rhs.a) {
      a += Modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modint &operator*=(const modint rhs) noexcept {
    a = a * rhs.a % Modulus;
    return *this;
  }
  constexpr modint &operator/=(modint rhs) noexcept {
    u64 exp = Modulus - 2;
    while (exp) {
      if (exp % 2) {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }
};
 
#define mint modint<MOD>
mint inv[N],comb[N],prd[N],invprd[N];
void calc_inv(){
    inv[1]=1;
    rep2(i,2,N-1){
        inv[i]=inv[MOD%i]*(-MOD/i);
    }
    return;
}
void calc_product(){
    prd[0]=prd[1]=1;
    invprd[0]=invprd[1]=1;
    rep2(i,2,N-1){
        prd[i]=prd[i-1]*i;
        invprd[i]=inv[i]*invprd[i-1];
    }
    return ;
}
mint cmb(int a,int b){
    if(a<b)return 0;
    if(a<0||b<0)return 0;
    return {prd[a]*invprd[b]*invprd[a-b]};
}
mint modpow(mint x,ll n){
    if(n==0) return 1;
    mint res=modpow(x*x,n/2);
    if(n&1) res=res*x;
    return res;
}
void calc(){calc_inv();calc_product();}
using vmint = vector<mint> ;
ostream& operator<<(ostream& os, mint a){
    os << a.a ;
    return os;
}

vector<vmint> StirlingTable(int n){
    vector<vmint> res(n+1,vmint(n+1));
    res[0][0] = 1;
    rep2(i,1,n)rep2(j,1,i){
        res[i][j] = res[i-1][j-1] + res[i-1][j] * j;
    }
    return res ;
}

mint sgn(int x){ return (x&1 ? -1:1);}

signed main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);cout<<fixed<<setprecision(15);
    calc();
    int n = in();
    auto S = StirlingTable(n);
    vmint T(n+1);
    // 
    rep2(j,1,n){
        rep2(i,j,n){
            T[j] += prd[i-j+1] * S[i][i-j+1] * invprd[i];
        }
    }
    //  t 
    rep2(t,1,n){
        mint ans = 0;
        rep2(j,t,n){
            ans += sgn(j-t) * prd[j-1] * invprd[j-t] * T[j];
        }
        cout << ans * prd[n] * invprd[t-1] << " ";
    }

                
}