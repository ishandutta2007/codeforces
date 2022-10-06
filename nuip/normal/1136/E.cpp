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
  ll s,ad;
  Seg(ll v=0):s(v),ad(0){
  }
  void comp(const Seg &ope){
		ad+=ope.ad;
  }
  void clear(){
		ad=0;
  }
  static Seg Ope(int v=0){
    Seg re; re.ad=v;
    return re;
  }
  static Seg e;
};
Seg Seg::e=Seg();
Seg seg[2*N+10];
Seg operator+(const Seg &l,const Seg &r){
  return Seg(l.s+r.s);
}
inline void lazy_eval(int k,int a,int b){
  if(!seg[k].ad) return;
  seg[k].s+=seg[k].ad*(b-a);
  if(2*k<=2*N+5){
    seg[2*k+1].comp(seg[k]);
    seg[2*k+2].comp(seg[k]);
  }
  seg[k].clear();
}

inline void upd_node(int k){seg[k]=seg[2*k+1]+seg[2*k+2];}

void upd(int l,int r,ll ope,Seg seg[]=seg,int k=0,int a=0,int b=N){
  //cout<<"update:"<<l<<","<<r<<","<<x<<","<<d<<","<<a<<","<<b<<endl;
  lazy_eval(k,a,b);
  if(b<=l || r<=a) return; 
  if(l<=a && b<=r){
    seg[k].ad+=ope;
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
  return vl+vr;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<ll> ts(n);
	vector<ll> ds(n);
	rep(i,n) cin>>ds[i];
	reps(i,1,n) cin>>ts[i];
	rreps(i,1,n) ds[i]-=ds[i-1]+ts[i];
	out(ts,ds,1);
	vector<ll> sumt(n+1);
	rep(i,n-1) ts[i+1]+=ts[i];
	rep(i,n) sumt[i+1]=sumt[i]+ts[i];
	rep(i,n) upd(i,n,ds[i]);
	map<int,ll> st;
	rep(i,n)if(ds[i]) st[i]=ds[i];
	st[MOD]=1e18;
	int q;
	cin>>q;
	while(q--){
		string s;
		cin>>s;
		if(s[0]=='s'){
			int l,r;
			cin>>l>>r; --l;
			ll re=sumt[r]-sumt[l];
			out(re,1);
			re+=query(l,r).s;
			cout<<re<<"\n";
		}else{
			int i,x;
			cin>>i>>x; --i;
			if(!x) continue;
			upd(i,n,x);
			ds[i]+=x;
			st[i]=ds[i];
			int rem=x;
			while(rem){
				auto it=st.upper_bound(i);
				if(it->X==MOD) break;
				int t=min<ll>(rem,it->Y);
				ds[it->X]-=t;
				it->Y-=t;
				upd(it->X,n,-t);
				rem-=t;
				if(it->Y==0) it=st.erase(it);
				out(rem,ds,1);
			}
		}
	}
  return 0;
}