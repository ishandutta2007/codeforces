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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;

vector<ll> fact,finv,inv;
void Modinvs(vector<ll> &re,int n){
  re.resize(n+1); re[1]=1;
  for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i)%MOD;
}
void Facts(vector<ll> &re,int n){
  re.resize(n+1); re[0]=1;
  rep(i,n)re[i+1]=re[i]*(i+1)%MOD;
}
void Factinvs(vector<ll> &re,const vector<ll> &inv,int n){
  re.resize(n+1); re[0]=1;
  rep(i,n)re[i+1]=re[i]*inv[i+1]%MOD;
}
ll comb(ll n,ll r){
  if(n<r)return 0;
  return fact[n]*finv[n-r]%MOD*finv[r]%MOD;
}

ll mult[1123456];
ll sign[1123456];
vector<ll> ps,ns;
int T;

inline void upd(int x){
  for(int i=1;i*i<=x;++i){
    if(x%i) continue;
    mult[i]++;
    if(i*i<x) mult[x/i]++;
  }
}

int one(int n,int q){
  int x;
  ll re=0;
  rep(i,n+q){
    cin>>x;
    (re+=x)%=MOD;
    if(i>=n) cout<<re<<endl;
  }
  return 0;
}

ll dp[2123456];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);

  Modinvs(inv,212345);
  Facts(fact,212345);
  Factinvs(finv,inv,212345);
  rep(i,1000123)if(i){
    int x=i,sgn=1;
    for(int j=2;j*j<=x;++j){
      if(x%j) continue;
      sgn*=-1;
      x/=j;
      if(x%j==0){
	sgn=0;
	break;
      }
    }
    if(x>1) sgn*=-1;
    sign[i]=sgn;
    if(sgn){
      if(sgn>0) ps.pb(i);
      else ns.pb(i);
    }
  }
  //rep(i,10)cout<<sign[i]<<",";cout<<endl;
  rep(i,1000123)if(i)rep(j,1000123/i+1) (dp[i*j]+=sign[j]*i)%=MOD;
  
  int n,t,q,x;
  cin>>n>>t>>q;
  T=t;
  if(t==1) return one(n,q);
  ll re=0;
  rep(i,n+q){
    cin>>x;
    //cout<<"["<<x<<"]"<<endl;
    for(int i=1;i*i<=x;++i){
      if(x%i) continue;
      (re+=comb(mult[i],T-1)*dp[i]%MOD)%=MOD;
      //cout<<i<<":"<<comb(mult[i],T-1)<<","<<dp[i]<<endl;
      if(i*i<x){
	(re+=comb(mult[x/i],T-1)*dp[x/i]%MOD)%=MOD;
	//cout<<x/i<<":"<<comb(mult[x/i],T-1)<<","<<dp[x/i]<<endl;
      }
    }
    upd(x);
    (re+=MOD)%=MOD;
    if(i>=n)cout<<re<<endl;
  }
  return 0;
}