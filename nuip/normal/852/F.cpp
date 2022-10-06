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
#define rreps(X,S,Y) for (int (X) = (Y)-1;(X) >= (S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl

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
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}

ll MOD;

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
vector<ll> fact,finv,inv;
ll comb(ll n,ll r){
  if(n<r||r<0)return 0;
	if(n<MOD&&r<MOD) return fact[n]*finv[n-r]%MOD*finv[r]%MOD;
  return comb(n/MOD,r/MOD)*comb(n%MOD,r%MOD);
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
};


int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	ll n,m,a,q;
	cin>>n>>m>>a>>q;
	ll mod=1;
	for(ll p=a;p!=1;(p*=a)%=q) ++mod;
	//out(mod,1);
	MOD=mod;

	Doralion doralion(2123456);
	//out(comb(2,1),comb(2,2),1);
	vector<ll> sum(m+1);
	rep(i,m+1) sum[i]=comb(m,i);
	rep(i,m) sum[i+1]+=sum[i];
	vector<ll> re(n);
	rep(i,n) re[i]=sum[min(m,n-1-i)];
	//out(sum,re,1);
	rep(i,n) cout<<modpow(a,re[i],q)<<" \n"[i+1==n];
  return 0;
}