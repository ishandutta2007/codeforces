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
template<class S, class T,class U,class V,class W> ostream& operator<<(ostream &os, const tuple<S,T,U,V,W> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<","<<get<4>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD0=999999929;
const ll MOD1=1e9+9;
const ll MOD2=999999893;
const ll MOD3=999999937;

ll modpow(ll r,ll n,ll m){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}
template <int mod> struct modInt{
  int v;
  modInt(int v=0):v(v){}
  bool operator==(const modInt &n)const{return v==n.v;}
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
typedef modInt<MOD0> mint0;
typedef modInt<MOD1> mint1;
typedef modInt<MOD2> mint2;
typedef modInt<MOD3> mint3;
template <int mod> modInt<mod> modpow(modInt<mod> r,ll n){ modInt<mod> re(1); if(n<0)(n%=mod-1)+=mod-1; for(;n;n/=2){if(n&1) re*=r; r*=r;} return re;}

mint0 dp0[112][11234];
mint1 dp1[112][11234];
mint2 dp2[112][11234];
mint3 dp3[112][11234];

mint0 comb0[112][112];
mint1 comb1[112][112];
mint2 comb2[112][112];
mint3 comb3[112][112];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	comb0[0][0]=1;
	comb1[0][0]=1;
	comb2[0][0]=1;
	comb3[0][0]=1;
	rep(i,101)rep(j,101){
		comb0[i+1][j]+=comb0[i][j];
		comb1[i+1][j]+=comb1[i][j];
		comb2[i+1][j]+=comb2[i][j];
		comb3[i+1][j]+=comb3[i][j];
		comb0[i+1][j+1]+=comb0[i][j];
		comb1[i+1][j+1]+=comb1[i][j];
		comb2[i+1][j+1]+=comb2[i][j];
		comb3[i+1][j+1]+=comb3[i][j];
	}
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	dp0[0][0]=1;
	dp1[0][0]=1;
	dp2[0][0]=1;
	dp3[0][0]=1;
	rep(jj,n){
		int x=a[jj];
		rrep(j,jj+1)rep(i,10234){
			dp0[j+1][i+x]+=dp0[j][i];
			dp1[j+1][i+x]+=dp1[j][i];
			dp2[j+1][i+x]+=dp2[j][i];
			dp3[j+1][i+x]+=dp3[j][i];
		}
	}
	int re=1;
	vector<int> cnt(101);
	out(cnt,1);
	// rep(j,5){rep(i,10) cout<<dp0[j][i]<<",";cout<<endl;}
	out(comb0[3][3],dp0[3][3],1);
	out(comb1[3][3],dp1[3][3],1);
	out(comb2[3][3],dp2[3][3],1);
	out(comb3[3][3],dp3[3][3],1);
	for(int x:a) ++cnt[x];
	int mxf=0;
	rep(i,101)reps(j,1,cnt[i]+1){
		out(i,j,1);
		if(comb0[cnt[i]][j]==dp0[j][i*j]
			 && comb1[cnt[i]][j]==dp1[j][i*j]
			 && comb3[cnt[i]][j]==dp3[j][i*j]
			 && comb2[cnt[i]][j]==dp2[j][i*j]){
			MX(re,j);
			if(j==cnt[i]) mxf=1;
		}
	}
	if(count_if(all(cnt),[&](int x){return x;})==2 && mxf) re=n;
	cout<<re<<endl;
  return 0;
}