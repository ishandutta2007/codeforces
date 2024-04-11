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
  modInt operator+(const modInt &n)const{return v+n.v<mod ? v+n.v : v+n.v-mod;}
  modInt operator-(const modInt &n)const{return v-n.v<0 ? v-n.v+mod : v-n.v;}
  modInt operator*(const modInt &n)const{return ll(v)*n.v%mod;}
  modInt operator/(const modInt &n)const{return ll(v)*modpow(n.v%mod,-1,mod)%mod;}
  modInt operator+(const ll &n)const{return v+n<mod ? v+n : v+n-mod;}
  modInt operator-(const ll &n)const{return v-n<0 ? v-n+mod : v-n;}
  modInt operator*(const ll &n)const{return ll(v)*(n%mod)%mod;}
  modInt operator/(const ll &n)const{return ll(v)*modpow(n%mod,-1,mod)%mod;}
  modInt& operator+=(const modInt &n){v+=n.v; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const modInt &n){v-=n.v; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const modInt &n){v=ll(v)*n.v%mod; return *this;}
  modInt& operator/=(const modInt &n){v=ll(v)*modpow(n.v,-1,mod)%mod; return *this;}
  modInt& operator+=(const ll &n){v+=n; if(v>=mod) v-=mod; return *this;}
  modInt& operator-=(const ll &n){v-=n; if(v<0) v+=mod; return *this;}
  modInt& operator*=(const ll &n){v=ll(v)*n%mod; return *this;}
  modInt& operator/=(const ll &n){v=ll(v)*modpow(n,-1,mod)%mod; return *this;}
};
template<int mod> ostream& operator<<(ostream &os,const modInt<mod> &n){return os<<n.v;};
template<int mod> modInt<mod> operator+(const ll &n,const modInt<mod> &m){return m.v+n<mod ? m.v+n : m.v+n-mod;}
template<int mod> modInt<mod> operator-(const ll &n,const modInt<mod> &m){return n-m.v<0 ? n-m.v+mod : n-m.v;}
template<int mod> modInt<mod> operator*(const ll &n,const modInt<mod> &m){return ll(m.v)*(n%mod)%mod;}
template<int mod> modInt<mod> operator/(const ll &n,const modInt<mod> &m){return ll(m.v)*modpow(n%mod,-1,mod)%mod;}
typedef modInt<MOD> mint;
template <int mod> modInt<mod> modpow(modInt<mod> r,ll n){ modInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}
vector<mint> fact,finv,inv;
mint comb(ll n,ll r){ if(n<r||r<0)return 0; return fact[n]*finv[n-r]*finv[r];}
class Doralion{
  void Modinvs(vector<mint> &re,int n){ re.resize(n+1); re[1]=1; for(int i=2;i<=n;++i)re[i]=re[MOD%i]*(MOD-MOD/i);}
  void Facts(vector<mint> &re,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*(i+1);}
  void Factinvs(vector<mint> &re,const vector<mint> &inv,int n){ re.resize(n+1); re[0]=1; rep(i,n)re[i+1]=re[i]*inv[i+1];}
public:
  Doralion(int n){ Modinvs(inv,n); Facts(fact,n); Factinvs(finv,inv,n);}
} doralion(212345);

template<int N>
class Mat:public array<array<mint,N>,N>{
public:
	static Mat ZERO(){
		Mat re;
		rep(i,N)rep(j,N) re[i][j]=0;
		return re;
	};
	static Mat E(){
		Mat re;
		rep(i,N)rep(j,N) re[i][j]=(i==j);
		return re;
	};
	Mat operator*(const Mat &A)const{
		Mat re=ZERO();
		rep(i,N)rep(j,N)rep(k,N) re[i][k]+=(*this)[i][j]*A[j][k];
		return re;
	}
	Mat operator+(const Mat &A)const{
		Mat re=ZERO();
		rep(i,N)rep(j,N) re[i][j]=(*this)[i][j]+A[i][j];
		return re;
	}
	Mat operator-(const Mat &A)const{
		Mat re=ZERO();
		rep(i,N)rep(j,N) re[i][j]=(*this)[i][j]-A[i][j];
		return re;
	}
	Mat(const vector<int> &v){
		rep(i,N)rep(j,N) (*this)[i][j]=v[i*N+j];
	}
	Mat(){}
	Mat pow(ll n)const{
		Mat re=E(),r=*this;
		for(;n;n/=2){
			if(n%2) re=re*r;
			r=r*r;
		}
		return re;
	}
	Mat inv()const{
		Mat A=*this;
		Mat re=E();
		rep(j,N){
			reps(i,j,N)if(A[i][j].v){
				if(i!=j) swap(A[i],A[j]), swap(re[i],re[j]);
				break;
			}
			{
				mint inv=modpow(A[j][j],-1);
				rep(i,N) A[j][i]*=inv, re[j][i]*=inv;
			}
			rep(i,N)if(i!=j && A[i][j].v){
				mint t=A[i][j];
				rep(k,N) A[i][k]-=A[j][k]*t, re[i][k]-=re[j][k]*t;
			}
		}
		auto tmp=re**this;
		rep(i,N)rep(j,N)if((i==j)!=tmp[i][j].v){
			out(*this,re,tmp,1);
			exit(0);
		}
		return re;
	}
};

Mat<16> Ms[16];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  rep(i,16){
    if(i){
      Ms[i]=Ms[i-1];
      Ms[i][i-1][i]=Ms[i][i][i-1]=1;
    }
    Ms[i][i][i]=1;
  }
  Mat<16> A; rep(i,16) A[i][i]=1;
  ll n,t;
  cin>>n>>t;
  rep(i,n){
    ll l,r,h;
    cin>>l>>r>>h; MN(r,t);
    A=Ms[h].pow(r-l)*A;
  }
  cout<<A[0][0]<<endl;
  return 0;
}