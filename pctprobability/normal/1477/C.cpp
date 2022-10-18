#include <bits/stdc++.h>
//#include <atcoder/all>
using namespace std;
//using namespace atcoder;
using ll = long long;
using ld = long double;
#define all(s) (s).begin(),(s).end()
#define vcin(n) for(ll i=0;i<ll(n.size());i++) cin>>n[i]
#define rever(vec) reverse(vec.begin(), vec.end())
#define sor(vec) sort(vec.begin(), vec.end())
#define fi first
#define se second
#define SIZE(n) int(n.size())
//const ll mod = 998244353;
const ll mod = 1000000007;
const ll inf = 2000000000000000000ll;
static const long double pi = 3.141592653589793;
template<class T,class U> void chmax(T& t,const U& u){if(t<u) t=u;}
template<class T,class U> void chmin(T& t,const U& u){if(t>u) t=u;}
ll modPow(ll a, ll n, ll mod) { ll ret = 1; ll p = a % mod; while (n) { if (n & 1) ret = ret * p % mod; p = p * p % mod; n >>= 1; } return ret; }
template <typename T,typename E>
struct SegmentTree{
  typedef function<T(T,T)> F;
  typedef function<T(T,E)> G;
  typedef function<E(E,E)> H;
  typedef function<E(E,int)> P;
  int n;
  F f;
  G g;
  H h;
  P p;
  T d1;
  E d0;
  vector<T> dat;
  vector<E> laz;
  SegmentTree(int n_,F f,G g,H h,T d1,E d0,
	      vector<T> v=vector<T>(),P p=[](E a,int b){return a;}):
    f(f),g(g),h(h),d1(d1),d0(d0),p(p){
    init(n_);
    if(n_==(int)v.size()) build(n_,v);
  }
  void init(int n_){
    n=1;
    while(n<n_) n*=2;
    dat.clear();
    dat.resize(2*n-1,d1);
    laz.clear();
    laz.resize(2*n-1,d0);
  }
  void build(int n_, vector<T> v){
    for(int i=0;i<n_;i++) dat[i+n-1]=v[i];
    for(int i=n-2;i>=0;i--)
      dat[i]=f(dat[i*2+1],dat[i*2+2]);
  }
  inline void eval(int len,int k){
    if(laz[k]==d0) return;
    if(k*2+1<n*2-1){
      laz[k*2+1]=h(laz[k*2+1],laz[k]);
      laz[k*2+2]=h(laz[k*2+2],laz[k]);
    }
    dat[k]=g(dat[k],p(laz[k],len));
    laz[k]=d0;
  }
  T update(int a,int b,E x,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return dat[k];
    if(a<=l&&r<=b){
      laz[k]=h(laz[k],x);
      return g(dat[k],p(laz[k],r-l));
    }
    return dat[k]=f(update(a,b,x,k*2+1,l,(l+r)/2),
		    update(a,b,x,k*2+2,(l+r)/2,r));
  }
  T update(int a,int b,E x){
    return update(a,b,x,0,0,n);
  }
  T query(int a,int b,int k,int l,int r){
    eval(r-l,k);
    if(r<=a||b<=l) return d1;
    if(a<=l&&r<=b) return dat[k];
    T vl=query(a,b,k*2+1,l,(l+r)/2);
    T vr=query(a,b,k*2+2,(l+r)/2,r);
    return f(vl,vr);
  }
  T query(int a,int b){
    return query(a,b,0,0,n);
  }
};
void solve(){
  ll n,q;
  cin>>n>>q;
  string s;
  cin>>s;
  string f;
  cin>>f;
  vector<ll> a(q);
  vector<ll> b(q);
  for(int i=0;i<q;i++){
    cin>>a[i]>>b[i];
    a[i]--;
    b[i]--;
  }
  vector<ll> p(int(s.size()));
  for(int i=0;i<int(f.size());i++){
    p[i]=f[i]-'0';
  }
  using X = ll;
  using M = ll;
  auto fx = [](X x1, X x2) -> X { return x1+x2; };
  auto fa = [](X x, M m) -> X { if(m==8) return x;return m; };
  auto fm = [](M m1, M m2) -> M { return m2; };
  ll ex = 0;
  ll em = 8;
  SegmentTree<X, M> rmq(int(s.size()), fx, fa, fm, ex, em);
  for(int i=0;i<int(f.size());i++){
    rmq.update(i,i+1,p[i]);
  }
  rever(a);
  rever(b);
  cout<<rmq.query(6,9)<<endl;
  for(int i=0;i<q;i++){
    ll s=b[i]-a[i]+1;
    ll r=rmq.query(a[i],b[i]+1);
    cout<<a[i]<<" "<<b[i]<<" "<<r<<endl;
    for(int j=0;j<n;j++){
      cout<<rmq.query(j,j+1);
    }
    cout<<endl;
    if(s==r*2){
      cout<<"NO"<<endl;
      return;
    }
    if(s>r*2){
      rmq.update(a[i],b[i]+1,0);
    }
    if(s<r*2){
      rmq.update(a[i],b[i]+1,1);
    }
  }
  for(int i=0;i<n;i++){
    if(s[i]-'0'!=rmq.query(i,i+1)){
      cout<<"NO"<<endl;
      return;
    }
  }
  cout<<"YES"<<endl;
}
int main() {
  /* mod  1e9+7 */
  ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
  cout<< fixed << setprecision(10);
  ll a;
  cin>>a;
  vector<ll> x(a);
  vector<ll> y(a);
  for(int i=0;i<a;i++){
    cin>>x[i]>>y[i];
  }
  vector<ll> check(a,1);
  cout<<1<<" ";
  ll tmp=0;
  check[0]=0;
  for(int i=0;i<a-1;i++){
    ll r=0;
    ll s=0;
    for(int j=0;j<a;j++){
      if(check[j]){
        if(r<(x[tmp]-x[j])*(x[tmp]-x[j])+(y[tmp]-y[j])*(y[tmp]-y[j])){
          r=(x[tmp]-x[j])*(x[tmp]-x[j])+(y[tmp]-y[j])*(y[tmp]-y[j]);
          s=j;
        }
      }
    }
    check[s]=0;
    cout<<s+1<<" ";
    tmp=s;
  }
}