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
#include<unordered_set>
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

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=MOD-1)+=MOD-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
vector<ll> fact,finv,inv;
ll comb(ll n,ll r){
  if(n<r||r<0)return 0;
  return fact[n]*finv[n-r]%MOD*finv[r]%MOD;
}
class Doralion{
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
public:
  Doralion(int n){
    Modinvs(inv,n);
    Facts(fact,n);
    Factinvs(finv,inv,n);
  }
} doralion(212345);

ll dp[22][2222];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int n,m,t,s;
  cin>>n>>m>>t>>s;
  vector<pii> ps(t);
  rep(i,t){
    int x,y;
    cin>>y>>x; --y; --x;
    ps[i]=pii(x,y);
  }
  sort(all(ps),[](pii a,pii b){return pii(a.X+a.Y,a.X)<pii(b.X+b.Y,b.X);});
  if(ps.size() && ps[0]==pii()) s=(s+1)/2;
  if(ps.size() && ps.back()==pii(m-1,n-1)) s=(s+1)/2;
  ps.eb(0,0); ps.eb(m-1,n-1);
  sort(all(ps),[](pii a,pii b){return pii(a.X+a.Y,a.X)<pii(b.X+b.Y,b.X);});
  UNIQUE(ps); t=ps.size();
  //cout<<ps;
  dp[0][0]=1;
  rep(i,20)reps(j,1,t){
    int x,y; tie(x,y)=ps[j];
    dp[i][j]=comb(x+y,x);
    reps(k,1,j)if(ps[k].X<=x && ps[k].Y<=y)
      (dp[i][j]+=MOD-dp[i][k]*comb(x-ps[k].X+y-ps[k].Y,x-ps[k].X)%MOD)%=MOD;
    rep(k,i) (dp[i][j]+=MOD-dp[k][j])%=MOD;
  }
  //rep(i,3){rep(j,t)cout<<dp[i][j]<<",";cout<<endl;}
  ll re=0,rem=comb(n-1+m-1,n-1);
  rep(i,20){
    (rem+=MOD-dp[i][t-1])%=MOD;
    (re+=dp[i][t-1]*s%MOD)%=MOD;
    //cout<<pii(dp[i][t-1],s)<<endl;
    s=(s+1)/2;
  }
  (re+=rem*s%MOD)%=MOD;
  //cout<<pii(rem,s)<<endl;
  ll q=comb(n-1+m-1,n-1);
  cout<<re*modpow(q,-1)%MOD<<endl;
  return 0;
}