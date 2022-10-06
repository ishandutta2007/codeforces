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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

int memo[1123456];

void ans(ll h,int a,int x,int y,int m,int &t,int &d,int &re){
  t=d=re=0;
  memset(memo,-1,sizeof(memo));
  rep(i,2*m){
    if(memo[h]>=0 && !d){
      d=i-memo[h];
      t=memo[h];
    }
    memo[h]=i;
    if(h==a){
      if(!re)
	re=i;
    }
    h=(x*h%m+y)%m;
  }
  //if(!d)d=m;
}


//extGCD
ll extgcd(ll a,ll b,ll &x,ll &y){
  ll g=a; x=1,y=0;
  if(b){
    g=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }
  return g;
}
//]
ll china2(const vector<ll> &a,const vector<ll> &m){
  ll p=1,re=0,pp,x,y;
  rep(i,m.size())
    p*=m[i];
  rep(i,m.size()){
    pp=p/m[i];
    extgcd(m[i],pp,x,y);
    (re+=pp*y%p*a[i]%p)%=p;
  }
  return (re%p+p)%p;
}
int updChina(map<ll,pll> &mp,ll a,ll m,ll p){
  if(mp.count(p)){
    pll tmp=mp[p];
    if((tmp.X-a)%min(tmp.Y,m))
      return 1;
    if(tmp.Y<m)
      mp[p]=pll(a,m);
  }else{
    mp[p]=pll(a,m);
  }
  return 0;
}

const int PRIME_MAX=1123456;
vector<int> primes;
int prime[PRIME_MAX];
void findPrime(){
  for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
      primes.pb(i);
      for(int j=i*2;j<PRIME_MAX;j+=i)
	prime[j]=1;
  }
}
//fB-1
ll china(const vector<ll> &a,const vector<ll> &m){
  //cout<<a<<m;
  map<ll,pll> mp;
  pll tmp;
  ll num,p=1;
  rep(i,a.size()){
    num=m[i];
    rep(j,primes.size())if(m[i]%primes[j]==0){
      p=1;
      while(num%primes[j]==0){
	p*=primes[j];
	num/=primes[j];
      }
      if(updChina(mp,a[i],p,primes[j]))
	return -1;
    }
    if(num>1)
      if(updChina(mp,a[i],num,num))
	return -1;
  }
  vector<ll> aa,mm;
  for(auto temp:mp){
    num=temp.Y.X; p=temp.Y.Y;
    aa.pb((num%p+p)%p);
    mm.pb(p);
  }//cout<<aa<<mm;
  return china2(aa,mm);
}


int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  findPrime();
  int i,j,k;
  int m;
  cin>>m;
  int h,a,x,y,H,A,X,Y;
  cin>>h>>a>>x>>y>>H>>A>>X>>Y;
  ll u=h,v=H;
  rep(i,m){
    if(u==a && v==A){
      cout<<i<<endl;
      return 0;
    }
    u=(u*x%m+y)%m;
    v=(v*X%m+Y)%m;
  }
  int r,d,t,R,D,T;
  ans(h,a,x,y,m,t,d,r);
  ans(H,A,X,Y,m,T,D,R);
  //cout<<t<<","<<d<<","<<r<<endl;
  //cout<<T<<","<<D<<","<<R<<endl;
  vector<ll> ca={r,R},cm={d,D};
  ll re=china(ca,cm);
  //cout<<re<<endl;
  if(re<0 || r==0 || R==0 || r<t || R<T){
    cout<<-1<<endl;
    return 0;
  }
  ll mod=1ll*d/__gcd(d,D)*D,mn=max(t,T);
  if(re<mn)
    re+=(mn-re+mod-1)/mod*mod;
  cout<<re<<endl;
  return 0;
}