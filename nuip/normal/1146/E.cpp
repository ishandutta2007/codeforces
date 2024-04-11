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
template<class T> ostream& operator<<(ostream &os, const deque<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
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
const ll MOD=1e9+7;

const int N=(1<<17);

struct Seg{
	int v,f,q,flip;
  Seg(int v=0):v(v),f(0),q(0),flip(0){
  }
  void comp(const Seg &ope){
		if(ope.q){
			q=ope.q;
			flip=ope.flip;
		}else{
			flip^=ope.flip;
		}
  }
  void clear(){
    q=0; flip=0;
  }
  static Seg Ope(int v=0,int f=0){
    Seg re; re.q=v; re.f=0; re.flip=f;
    return re;
  }
  static Seg e;
};
Seg Seg::e=Seg();
// ostream& operator<<(ostream &os, const Seg &t) { return os<<"("<<t.h<<","<<t.q<<","<<t.r<<")";}
Seg seg[2*N+10];
// Seg operator+(const Seg &l,const Seg &r){
//   // Seg re;
//   // re.h=(l.h*r.r%MOD+r.h)%MOD;
//   // re.r=l.r*r.r%MOD;
//   return l;
// }
inline void lazy_eval(int k,int a,int b){
  if(!seg[k].q && !seg[k].flip) return;
  if(seg[k].q) seg[k].v=seg[k].q;
	if(seg[k].flip){
		if(seg[k].v!=3) seg[k].v=3-seg[k].v;
		else seg[k].f^=1;
	}
  if(2*k<=2*N+5){
    seg[2*k+1].comp(seg[k]);
    seg[2*k+2].comp(seg[k]);
  }
  seg[k].clear();
}

// inline void upd_node(int k){seg[k]=seg[2*k+1]+seg[2*k+2];}

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
  // upd_node(k);
}

// Seg query(int l,int r,Seg seg[]=::seg,int k=0,int a=0,int b=N){
//   lazy_eval(k,a,b);
//   if(b<=l || r<=a)return Seg::e; 
//   if(l<=a && b<=r){return seg[k];}
  
//   int m=(a+b)/2;
//   Seg vl=query(l,r,seg,2*k+1,a,m);
//   Seg vr=query(l,r,seg,2*k+2,m,b);
//   upd_node(k);
//   //cout<<a<<","<<b<<":"<<vl<<","<<vr<<endl;
//   return vl+vr;
// }

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,q;
	cin>>n>>q;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	vector<pii> qs(q); // (is<?, num);
	rep(i,q){
		char c;
		int x;
		cin>>c>>x;
		qs[i]=pii(c=='<',x);
	}
	const int X=100000;
	upd(0,X+1,Seg::Ope(3,0));
	auto poyo=
		[&](){
			vector<int> re;
			for(int x:a){
				Seg s=seg[N-1+abs(x)];
				if(s.v==3){
					if(s.f) x=-x;
				}else{
					if(s.v==1) x=abs(x);
					else x=-abs(x);
				}
				re.pb(x);
			}
			out(re,1);
		};
	// rep(i,N+X) lazy_eval(i,0,0);
	// rep(i,5) out(i,seg[N-1+i].v,seg[N-1+i].f,1);
	// return 0;
	// poyo();
	for(pii p:qs){
		if(p.X){
			if(p.Y<0){
				upd(-p.Y+1,X+1,Seg::Ope(1,0));
			}else{
				upd(p.Y,X+1,Seg::Ope(1,0));
				upd(0,p.Y,Seg::Ope(0,1));
			}
		}else{
			if(p.Y>0){
				upd(p.Y+1,X+1,Seg::Ope(2,0));
			}else{
				upd(-p.Y,X+1,Seg::Ope(2,0));
				upd(0,-p.Y,Seg::Ope(0,1));
			}
		}
		// rep(i,N+X) lazy_eval(i,0,0);
		// rep(i,5) out(i,seg[N-1+i].v,seg[N-1+i].f,1);
		// poyo();
	}
	rep(i,N+X) lazy_eval(i,0,0);
	vector<int> re;
	for(int x:a){
		Seg s=seg[N-1+abs(x)];
		if(s.v==3){
			if(s.f) x=-x;
		}else{
			if(s.v==1) x=abs(x);
			else x=-abs(x);
		}
		re.pb(x);
	}
	out(re,1);
	rep(i,n) cout<<re[i]<<" \n"[i+1==n];
  return 0;
}