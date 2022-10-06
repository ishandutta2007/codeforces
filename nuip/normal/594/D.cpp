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
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define int long long 
#include<cassert>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;

const int SQ=447;

const int MAX_P=1123456;
int prime[MAX_P];

void Fact(int n,vector<int> &st){
  while(prime[n]){
    st.pb(prime[n]);
    n/=prime[n];
  }
  st.pb(n);
  sort(all(st)); UNIQUE(st);
}
void pre(){
  int i,j,k;
  for(i=2;i<MAX_P;i++){
    if(prime[i]==0)
      for(ll j=1ll*i*i;j<MAX_P;j+=i)
        prime[j]=i;
  }
}
vector<pii> qs[212345];

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=MOD-1)+=MOD-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
const int nn=212345;
ll bit[nn+1];

ll sum(int i){ ++i;
  ll s=1;
  while(i>0){
    (s*=bit[i])%=MOD;//ok?
    assert(bit[i]);
    i-=i&-i;
  }
  return s;
}
void add(int i,ll x){ ++i;
  //cout<<pii(i,x)<<endl;
  if(!x) return;
  while(i<=nn){
    (bit[i]*=x)%=MOD;
    i+=i&-i;
  }
}
vector<int> nxt[1123456];
signed main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  fill(bit,bit+nn+1,1);
  pre();
  int n;
  cin>>n;
  vector<int> a(n);
  vector<ll> prod(n+1,1);
  vv<int> fact(n);
  rep(i,n){
    cin>>a[i];
    prod[i+1]=prod[i]*a[i]%MOD;
    Fact(a[i],fact[i]);
  }

  rrep(i,n)
    for(int x:fact[i])
      nxt[x].pb(i);

  int q,l,r;
  cin>>q;
  vector<ll> ls(q),rs(q);
  rep(i,q){
    cin>>l>>r; --l;
    ls[i]=l; rs[i]=r;
    qs[l].eb(r,i);
  }

  vector<int> st(1123456),re(q,1);
  vector<ll> pp(1123456,1);
  rep(i,1123456)if(i>1)
    assert(pp[i]=modpow(i,-1)*(i-1ll)%MOD);
  rep(i,n){
    for(int x:fact[i])
      if(!st[x] && x>1){
	st[x]=1;
	add(i+1,pp[x]);
      }
  }
  rep(i,n){
    //cout<<fact[i];
    for(pii p:qs[i]){
      re[p.Y]=sum(p.X);
      //cout<<p<<sum(p.X)<<endl;
    }
    for(int x:fact[i])if(x>1){
      add(i+1,modpow(pp[x],-1));
      //cout<<x<<":"<<nxt[x];
      nxt[x].pop_back();
      if(nxt[x].size()){
	add(nxt[x].back()+1,pp[x]);
      }
    }
  }
  //cout<<re<<ls<<rs<<prod;

  rep(i,q){
    cout<<re[i]*prod[rs[i]]%MOD*modpow(prod[ls[i]],-1)%MOD<<endl;
    //cout<<re[i]<<","<<prod[rs[i]]*modpow(prod[ls[i]],-1)%MOD<<endl;
  }
  return 0;
}