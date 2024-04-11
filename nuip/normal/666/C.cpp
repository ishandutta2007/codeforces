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
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}

template <int mod=MOD> struct modInt{
  int v;
  modInt(int v=0):v(v){}
  modInt operator+(const modInt &n){return v+n.v<mod ? v+n.v : v+n.v-mod;}
  modInt operator-(const modInt &n){return v-n.v<0 ? v+n.v+mod : v+n.v;}
  modInt operator*(const modInt &n){return ll(v)*n.v%mod;}
  modInt operator/(const modInt &n){return ll(v)*modpow(n.v%mod,-1,mod)%mod;}
  template<class T> modInt operator+(const T &n){return v+n<mod ? v+n : v+n-mod;}
  template<class T> modInt operator-(const T &n){return v-n<0 ? v+n+mod : v+n;}
  template<class T> modInt operator*(const T &n){return ll(v)*(n%mod)%mod;}
  template<class T> modInt operator/(const T &n){return ll(v)*modpow(n%mod,-1,mod)%mod;}
  modInt& operator+=(const modInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const modInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const modInt &n){v=ll(v)*n.v%mod; return *this;}
  modInt& operator/=(const modInt &n){v=ll(v)*modpow(n.v,-1,mod)%mod; return *this;}
  template<class T> modInt& operator+=(const T &n){v+=n; if(v>=mod) v-=mod; return *this;}
  template<class T> modInt& operator-=(const T &n){v-=n; if(v<0) v+=mod; return *this;}
  template<class T> modInt& operator*=(const T &n){v=ll(v)*n%mod; return *this;}
  template<class T> modInt& operator/=(const T &n){v=ll(v)*modpow(n,-1,mod)%mod; return *this;}
};
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){return os<<n.v;};
template<class T,int mod> modInt<mod> operator+(const T &n,const modInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<class T,int mod> modInt<mod> operator-(const T &n,const modInt<mod> &m){return m.v-n<0 ? m.v+n+mod : m.v+n;}
template<class T,int mod> modInt<mod> operator*(const T &n,const modInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<class T,int mod> modInt<mod> operator/(const T &n,const modInt<mod> &m){return ll(m.v)*modpow(n%mod,-1,mod)%mod;}
typedef modInt<MOD> mint;

vector<mint> fact,finv,inv;
mint comb(ll n,ll r){
  if(n<r||r<0)return 0;
  return fact[n]*finv[n-r]*finv[r];
}
class Doralion{
  void Modinvs(vector<mint> &re,int n){
    re.resize(n+1); re[1]=1;
    for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);
  }
  void Facts(vector<mint> &re,int n){
    re.resize(n+1); re[0]=1;
    rep(i,n)re[i+1]=re[i]*(i+1);
  }
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){
    re.resize(n+1); re[0]=1;
    rep(i,n)re[i+1]=re[i]*inv[i+1];
  }
public:
  Doralion(int n){
    Modinvs(inv,n);
    Facts(fact,n);
    Factinvs(finv,inv,n);
  }
} doralion(212345);
char str[112345];
mint dp[112345];
typedef pair<pii,int> piii;
bool check(string str){
  int re=0;
  rep(i,26)rep(j,26)rep(k,26)rep(l,26){
    string s;
    s+=i+'a';
    s+=j+'a';
    s+=k+'a';
    s+=l+'a';
    int b=0,f=0;
    rep(a,str.size()){
      if(b>=s.size()){f=1; break;}
      while(str[a]!=s[b]){
	++b;
	if(b>=s.size()){f=1; break;}
      }
      ++b;
    }
    if(!f) ++re;
  }
  cout<<re<<endl;
}
int main(){
  //ios_base::sync_with_stdio(false);
  //string hoge;
  //cin>>hoge;
  //check(hoge);
  int m;
  scanf("%d",&m);
  scanf("%s",str);
  int n=strlen(str);
  int t,x;
  vector<piii> ps;
  rep(i,m){
    scanf("%d",&t);
    if(t==1){
      scanf("%s",str);
      n=strlen(str);
    }else{
      scanf("%d",&x);
      ps.eb(pii(n,x),i); //(n,N)
    }
  }
  vector<mint> re(m,-1);
  vector<mint> pw(112345); pw[0]=1;
  rep(i,112340) pw[i+1]=pw[i]*25;  
  sort(all(ps));
  int prev=-1;
  for(const piii p:ps){
    if(prev!=p.X.X){
      prev=p.X.X;
      fill(dp,dp+112345,0);
      // dp
      dp[0]=1;
      rep(i,102345-p.X.X){
	dp[i+1]=dp[i]*26+pw[i+1]*comb(p.X.X+i,p.X.X-1);
      }
      //cout<<prev<<endl;
      //rep(i,10) cout<<dp[i]<<",";cout<<endl;
    }
    re[p.Y]=(p.X.Y-p.X.X<0?0:dp[p.X.Y-p.X.X]);
  }
  rep(i,m){
    if((int)re[i].v>=0) printf("%d\n",re[i].v);
  }
  return 0;
}