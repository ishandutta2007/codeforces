 #pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define ll long long
#define rep2(i,a,b) for(ll i=a;i<=b;++i)
#define rep(i,n) for(ll i=0;i<n;i++)
#define rep3(i,a,b) for(ll i=a;i>=b;i--)
#define pii pair<int,int>
#define pll pair<ll,ll>
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define vec vector<int>
#define vecll vector<ll>
#define vecpii vector<pii>
#define vec2(a,b) vector<vec>(a,vec(b))
#define vec2ll(a,b) vector<vecll>(a,vecll(b))
#define vec3(a,b,c) vector<vector<vec>>(a,vec2(b,c))
#define vec3ll(a,b,c) vector<vector<vecll>>(a,vec2ll(b,c))
#define fi first
#define se second
#define endl "\n"
#define all(c) begin(c),end(c)
#define ios ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define lb(c,x) distance(c.begin(),lower_bound(all(c),x))
#define ub(c,x) distance(c.begin(),upper_bound(all(c),x))
#define MM " "
#define INF 100000000
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}


    
void go();

main(){
    ios
    int tc=1;
    // tc=in();
    while(tc--){
        go();
    }
    return 0;
}

const ll MOD=1e9+9;
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



vector<vec> g;
const ll mod=1e9+9;
void go(){
    
    int n=in(),a=in(),b=in(),k=in();
    mint A = modpow(a,MOD-2);
    mint P = modpow(a,n);
    string s;cin>>s;
    vec t;
    for(auto e:s){
        if(e=='+')t.pb(1);
        else t.pb(-1);
        // t.pb(e=='+');
    }
    vmint p={1};
    mint c=A*b;
    rep(i,k+1)p.pb(p.back()*c);
    mint T = (modpow(c,n+1)-1)*(modpow(modpow(c,k)-1,MOD-2));
    if(modpow(c,k).a==1)T=(n+1)/k;
    
    mint ans=0;
    rep(i,k)ans+=(mint)t[i]*P*p[i]*T;
    cout<<ans.a<<endl;
        

}