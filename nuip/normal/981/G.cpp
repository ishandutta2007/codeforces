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
const ll MOD=998244353;

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

const int N=(1<<18);

struct Seg{
	mint a,b,s;
  Seg(mint A=0):s(A),a(1),b(0){
  }
	void comp(const Seg &x){
		(b*=x.a)+=x.b;
		a*=x.a;
	}
	static Seg Ope(int a,int b){
		Seg re;
		re.a=a; re.b=b;
		return re;
	}
  static Seg e;
};
Seg Seg::e=Seg();
ostream& operator<<(ostream &os, const Seg &t) { return os<<"("<<t.a<<","<<t.b<<","<<t.s<<")";}
Seg seg[2*N+10];
Seg operator+(const Seg &l,const Seg &r){
  return Seg(l.s+r.s);
}
inline void lazy_eval(int k,int a,int b){
  if(seg[k].a.v==1 && seg[k].b.v==0) return;
	out(a,b,seg[k],1);
	(seg[k].s*=seg[k].a)+=(b-a)*seg[k].b;
	out(a,b,seg[k],1);
  if(2*k<=2*N+5){
    seg[2*k+1].comp(seg[k]);
    seg[2*k+2].comp(seg[k]);
  }
  seg[k].a=1; seg[k].b=0;
}

inline void upd_node(int k){seg[k]=seg[2*k+1]+seg[2*k+2];}

void upd(int l,int r,Seg ope,Seg seg[]=seg,int k=0,int a=0,int b=N){
  //cout<<"update:"<<l<<","<<r<<","<<x<<","<<d<<","<<a<<","<<b<<endl;
  lazy_eval(k,a,b);
  if(b<=l || r<=a) return; 
  if(l<=a && b<=r){
    seg[k].comp(ope);
    lazy_eval(k,a,b);
    return;
  }	
  int m=(a+b)/2;
  upd(l,r,ope,seg,2*k+1,a,m);
  upd(l,r,ope,seg,2*k+2,m,b);
  upd_node(k);
}

Seg query(int l,int r,Seg seg[]=::seg,int k=0,int a=0,int b=N){
  lazy_eval(k,a,b);
  if(b<=l || r<=a)return Seg::e; 
  if(l<=a && b<=r){return seg[k];}
  
  int m=(a+b)/2;
  Seg vl=query(l,r,seg,2*k+1,a,m);
  Seg vr=query(l,r,seg,2*k+2,m,b);
  upd_node(k);
  //cout<<a<<","<<b<<":"<<vl<<","<<vr<<endl;
	//out(l,r,vl,vr,vl+vr,1);
  return vl+vr;
}

map<int,int> ints[212345];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,q;
	cin>>n>>q;
	// out(Seg(3,4)+Seg(1,2),1);
	// out(query(0,3),1);
	// return 0;
	rep(i,n) ints[i][-10]=-9, ints[i][MOD]=MOD+3;
	vector<int> re;
	rep(i,q){
		int t;
		cin>>t;
		if(t==1){
			int l,r,x;
			cin>>l>>r>>x; --l; --x;
			int L=l,R=r;
			auto &st=ints[x];
			auto it=st.upper_bound(l); --it;
			int prv=l;
			for(;it->X<r; it=st.erase(it)){
				out(*it,1);
				if(it->Y <= l) ++it;
				if(it->X >= r) break;
				MN(l, it->X);
				MX(r, it->Y);
				if(prv < it->X){
					upd(prv, it->X, Seg::Ope(1,1));
					out("u",prv, it->X, Seg::Ope(1,1),1);
				}
				upd(max(L, it->X), min(R,it->Y), Seg::Ope(2,0));
				out("u", max(L, it->X), min(R,it->Y), Seg::Ope(2,0),1);
				prv=it->Y;
			}
			if(prv<R){
				upd(prv, R, Seg::Ope(1,1));
				out("u",prv, R, Seg::Ope(1,1),1);
			}
			out(l,r,x,1);
			it=st.upper_bound(l);
			if(it->X==r){
				r=it->Y;
				it=st.erase(it);
			}
			--it;
			if(it->Y==l){
				l=it->X;
				it=st.erase(it);
			}
			st[l]=r;//todo merge
			//for(auto x:st) cout<<x<<",";cout<<endl;
		}else{
			int l,r;
			cin>>l>>r; --l;
			Seg s=query(l,r);
			out(l,r,s,1);
			re.pb(s.s.v);
		}
	}
	// out(query(0,2),query(0,3),query(2,3),1);
	// rep(i,n) cout<<query(i,i+1);cout<<endl;
	for(int x:re) cout<<x<<"\n";
	out(re,1);
  return 0;
}