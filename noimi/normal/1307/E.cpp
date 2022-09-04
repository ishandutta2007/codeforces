// #pragma GCC optimize("O3")
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
#define vec2ll(a,b) vector<vec>(a,vecll(b))
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
using namespace std;
int in() {int x;cin>>x;return x;}
ll lin() {ll x;cin>>x;return x;}
template<class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline void print(pair<T,T> p){cout<<"("<<p.first<<","<<p.second<<") ";}
template<class T> inline void print(vector<pair<T,T>> v){for(auto e:v)print(e); cout<<endl;}
template<class T> inline void print(T v){for(auto e:v)cout<<e<<" ";cout<<endl;}

long double eps=1e-8;
unsigned xorshift()
{
    static unsigned x=123456789, y=362436069, z=521288629, w=8867512;
    unsigned t=(x^(x<<11));
    x=y; y=z; z=w;
    return w=(w^(w>>19))^(t^(t>>8));
}
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int n){
    return xorshift()%(n);
}
double drnd(){
    return (double)(rnd(INT_MAX))/INT_MAX;
}
void shuffle(vec &x){
    int n=x.size();
    rep3(i,n-1,1){
        swap(x[i],x[rnd(i-1)]);
    }
}
clock_t start;
double time(){
    return (double)(clock()-start)/CLOCKS_PER_SEC;
}
template< typename T >
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}

  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};

template< typename T >
using Edges = vector< edge< T > >;
template< typename T >
using WeightedGraph = vector< Edges< T > >;
using UnWeightedGraph = vector< vector< int > >;
template< typename T >
using Matrix = vector< vector< T > >;
template< typename T >
vector< T > dijkstra(WeightedGraph< T > &g, int s) {
  const auto INF = numeric_limits< T >::max();
  vector< T > dist(g.size(), INF);

  using Pi = pair< T, int >;
  priority_queue< Pi, vector< Pi >, greater< Pi > > que;
  dist[s] = 0;
  que.emplace(dist[s], s);
  while(!que.empty()) {
    T cost;
    int idx;
    tie(cost, idx) = que.top();
    que.pop();
    if(dist[idx] < cost) continue;
    for(auto &e : g[idx]) {
      auto next_cost = cost + e.cost;
      if(dist[e.to] <= next_cost) continue;
      dist[e.to] = next_cost;
      que.emplace(dist[e.to], e.to);
    }
  }
  return dist;
}
const ll MOD=1e9+7;
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

main(){
    ios
    int t=1;
    while(t--){
        int n=in(),m=in();
        vec s;
        rep(i,n)s.pb(in());
        vec f,h;
        rep(i,m)f.pb(in()),h.pb(in());
        vec l,r;
        rep(i,m){
            int cnt=0;
            bool flag=false;
            rep(j,n){
                if(s[j]==f[i])cnt++;
                if(cnt==h[i]){
                    l.pb(j);break;
                }
                if(j==n-1)l.pb(1e6);
            }
            cnt=0;
            rep3(j,n-1,0){
                if(s[j]==f[i])cnt++;
                if(cnt==h[i]){r.pb(j);break;}
                if(j==0)r.pb(-1e6);
            }
        }
        int maxnum=0;
        mint ans=0;
        rep(i,n+1){
            int L[5100]={},R[5100]={};
            rep(j,m){
                if(l[j]<i)L[f[j]]++;
                if(r[j]>=i)R[f[j]]++;
            }
            bool flag=false;
            int special,nr;
            rep(j,m){
                if(l[j]==(i-1)){
                    special=f[j];
                    nr=r[j];
                    flag=true;
                }
            }
            if(i==0)flag=true;
            if(!flag)continue;
            int cnt=0;
            mint tmp=1;
            rep(j,n+1){
                int a=L[j],b=R[j];
                if(!(a or b))continue;
                // cout<<i<<" "<<a<<" "<<b<<endl;
                if(j==special){
                    cnt++;
                    if(nr>=i)b--;
                    if(b){
                        cnt++;
                        tmp*=b;
                    }
                    continue;
                }
                        
                if(a==1 and b==1){
                    cnt++;tmp*=2;
                }
                else if(a==0){
                    cnt++;tmp*=b;
                }
                else if(b==0){
                    cnt++;tmp*=a;
                }
                else{
                    if(a<b)swap(a,b);
                    cnt+=2;
                    tmp*=b;
                    tmp*=(a-1);
                }
            }
            if(cnt==maxnum)ans+=tmp;
            else if(cnt>maxnum){
                ans=tmp;
                maxnum=cnt;
            }
            // cout<<maxnum<<" "<<ans.a<<endl;
        }
        cout<<maxnum<<" "<<ans.a<<endl;
    }
}