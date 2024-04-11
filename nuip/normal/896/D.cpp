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
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef _DEBUG
#ifdef _DEBUG
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;

vector<int> primes,prime;
class PRPRPR{
public:
  PRPRPR(int PRIME_MAX){
    prime.resize(PRIME_MAX);
    for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
	primes.pb(i);
	for(int j=i*2;j<PRIME_MAX;j+=i)
	  prime[j]=1;
      }
  }
} prprprpr(112345);

ll fact[112345];
ll finv[112345];
ll extgcd(ll a,ll b,ll &x,ll &y){
  ll g=a; x=1,y=0;
  if(b){
    g=extgcd(b,a%b,y,x);
    y-=(a/b)*x;
  }
  return g;
}
vector<int> pps;

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}

ll comb(ll n,ll r,ll p){
	if(n<r || r<0) return 0;
	ll re=fact[n]*finv[n-r]%p*finv[r]%p;
	for(int pr:pps){
		int ex=0;
		for(ll i=pr;i<=n;i*=pr) ex+= n/i - (n-r)/i - r/i;
		(re*=modpow(pr,ex,p))%=p;
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	//out(primes.size(),1);
  int n,p,l,r;
	cin>>n>>p>>l>>r;
	fact[0]=finv[0]=1;
	reps(i,1,n+1){
		int x=i,tmp;
		while((tmp=__gcd(x,p))>1) x/=tmp;
		fact[i]=fact[i-1]*x%p;
		ll unko;
		extgcd(fact[i],p,finv[i],unko);
		finv[i]%=p;
		finv[i]+=p;
		finv[i]%=p;
	}
	//rep(i,10) cout<<fact[i]<<",";cout<<Endl;
	//out(fact[22],fact[10],1);
	for(int pr:primes)if(p%pr==0){
			pps.pb(pr);
		}
	out(comb(4,0,p),1);
	ll re=0;
	if(l==r){
		reps(i,l,n+1)if(i%2 == l%2) re+=(comb(i,(i-l)/2,p)+p-
																		 comb(i,(i-l)/2-1,p))%p*comb(n,i,p)%p;
	}else{
		reps(i,l,n+1) re+=(comb(i,(i-l)/2,p)+p-
										comb(i,(i-r+1)/2-1,p))%p*comb(n,i,p)%p;
		// reps(i,l,n+1) out(comb(i,(i-l)/2,p),
		// 							 comb(i,(i-r+1)/2-1,p),comb(n,i,p),1);
		re%=p;
	}
	cout<<re%p<<endl;	
  return 0;
}