#include <string>
#include <vector>
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<stack>
#include<queue>
#include<cmath>
#include<algorithm>
#include<functional>
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<unordered_map>
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#include<cassert>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define reps(X,S,Y) for (int (X) = S;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
const ll MOD=1e9+7;

inline double Mod(double v,double mod=MOD){
  return v;
}
inline ll Mod(ll v,ll mod=MOD){
  return v%mod;
}
typedef vector<vector<ll> > matl;
typedef vector<vector<double> > matd;
template<class T> vector<T> operator*(const T &a,vector<T> v){
  rep(i,v.size())
    v[i]=Mod(v[i]*a);
  return v;
}
template<class T> vector<T> operator+(vector<T> v,const vector<T> &w){
  rep(i,v.size())
    v[i]=Mod(v[i]+w[i]);
  return v;
}
template<class T> vector<vector<T> > matE(T n){
  vector<vector<T> > re(n,vector<T>(n));
  rep(i,n)
    re[i][i]=1;
  return re;
}
template<class T>vector<vector<T> >matE(vector<vector<T> >mat){
  return matE((T)(mat.size()));
}

template<class T>
vector<vector<T> > transpose(const vector<vector<T> > &a,
vector<vector<T>> &re){
  re.resize(a[0].size(),vector<T>(a.size()));
  rep(i,a[0].size())
    rep(j,a.size())
      re[i][j]=a[j][i];
  return re;
}

template<class T> T operator*(const vector<T> &a,
		     const vector<T> &b){
  T re=0;
  rep(i,a.size())
    re=Mod(re+Mod(a[i]*b[i]));
  return re;
}
template<class T> vector<vector<T> >
operator*(const vector<vector<T> > &a
,const vector<vector<T> > &b_){
  vector<vector<T> > b;
  transpose(b_,b);
  vector<vector<T> > re(a.size(),vector<T>(b.size()));
  rep(i,a.size())
    rep(j,b.size())
      re[i][j]=a[i]*b[j];
  return re;
}
template<class T>
vector<vector<T> > pow(vector<vector<T> > a,ll n){
  vector<vector<T> > re;
  if(n==0)
    return matE(a);
  re=pow(a,n/2);
  return re*re*(n%2?a:matE(a));
}
ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}

inline ll mult(ll &a,ll &b,ll &c,ll &d,ll s,ll t, ll u,ll v,ll w,ll x,ll y,ll z){
  a=s*w%MOD+t*y%MOD;
  b=s*x%MOD+t*z%MOD;
  c=u*w%MOD+v*y%MOD;
  d=u*x%MOD+v*z%MOD;
  a%=MOD;
  b%=MOD;
  c%=MOD;
  d%=MOD;
}

void pow(ll &a,ll &b,ll &c,ll &d,ll n){
  ll w=1,x=0,y=0,z=1;
  for(;n;n/=2){
    if(n%2) mult(w,x,y,z,w,x,y,z,a,b,c,d);
    mult(a,b,c,d,a,b,c,d,a,b,c,d);
  }
  a=w;
  b=x;
  c=y;
  d=z;
}


int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n;
  cin>>n;
  ll t;
  ll a=0,b=1,c=2,d=1,p=1;
  rep(i,n){//cout<<i<<endl;
    cin>>t;
    (p*=t%(MOD-1))%=MOD-1;

    ll w=1,x=0,y=0,z=1;
  for(;t;t/=2){
    if(t%2) mult(w,x,y,z,w,x,y,z,a,b,c,d);
    mult(a,b,c,d,a,b,c,d,a,b,c,d);
  }
  a=w;
  b=x;
  c=y;
  d=z;
  }
  mult(a,b,c,d,a,b,c,d,MOD-1,1,2,0);
  //cout<<a<<","<<b<<","<<c<<","<<d<<endl;
  ll inv=modpow(2,-1);
  (p+=MOD-2)%=MOD-1;
  cout<<b*inv%MOD<<"/"<<modpow(2,p)<<endl;
  return 0;
}