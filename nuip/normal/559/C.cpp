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
ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  for(n=(n%(m-1)+m-1)%(m-1);n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}

vector<ll> fact,finv,inv;
void Modinvs(vector<ll> &re,int n){
  re.resize(n+1); re[1]=1;
  for(int i=2;i<=n;++i)re[i]=inv[MOD%i]*(MOD-MOD/i)%MOD;
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
ll dp[2][2123];
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int h,w,n;
  Modinvs(inv,212345);
  Facts(fact,212345);
  Factinvs(finv,inv,212345);
  cin>>h>>w>>n;
  vector<pii> p(n);
  rep(i,n){
    cin>>p[i].X>>p[i].Y;
    --p[i].X; --p[i].Y;
  }
  p.eb(0,0); p.eb(h-1,w-1);
  sort(all(p));
  //cout<<p;
  dp[0][0]=1;
  rep(i,n+2)rep(j,i){
    int dx=-p[j].X+p[i].X ,dy=-p[j].Y+p[i].Y;
      if(dx>=0 && dy>=0)
	rep(k,2){
	  //cout<<k<<","<<p[i]<<"<-"<<p[j]<<","<<dp[1-k][j]<<","<<comb(dx+dy,dx)%MOD<<endl;
	  (dp[k][i]+=dp[1-k][j]*comb(dx+dy,dx)%MOD)%=MOD;
	}
  }
  ll re=-dp[0][n+1]+dp[1][n+1];
  (re%=MOD)+=MOD;
  //rep(i,2){rep(j,n+2)cout<<dp[i][j]<<",";cout<<endl;}
  cout<<re%MOD<<endl;
  return 0;
}