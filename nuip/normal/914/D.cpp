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
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;
const int MAX_N=(1<<19);
int nn=MAX_N;

struct Seg{
	int v;
  Seg(int d=0):v(d){}
  static Seg e;
};
vector<Seg> dat(2*MAX_N);
Seg Seg::e=Seg();

Seg operator+(const Seg &l,const Seg &r){
  return Seg(__gcd(l.v,r.v));
}
//ostream& operator<<(ostream &os, const Seg &t) { return os<<"["<<t.mn<<")";}
template<class T=Seg> void upd(int k,int a,vector<T> &dat=dat){
  k+=dat.size()/2-1;
  dat[k].v=a;
  while(k>0){
    k=(k-1)/2;
    dat[k].v=__gcd(dat[k*2+1].v,dat[k*2+2].v);
  }
}

//(l,r,0,0,nn)
template<class T=Seg> bool query(int a,int b,int g,const vector<T> &dat=dat,int k=0,int l=0,int r=-1){
  if(r<0) r=dat.size()/2;
  if(r<=a || b<=l)return 1;
  if(a<=l && r<=b) return dat[k].v%g==0;
  return query(a,b,g,dat,k*2+1,l,(l+r)/2) && query(a,b,g,dat,k*2+2,(l+r)/2,r);
}

int main(){
	int n;
	scanf("%d",&n);
	vector<int> a(n);
	rep(i,n) scanf("%d",&a[i]);
	rep(i,n) dat[nn-1+i]=Seg(a[i]);
	rrep(i,nn-1) dat[i].v=__gcd(dat[i*2+1].v,dat[i*2+2].v);
	int q;
	scanf("%d",&q);
	vector<int> re; re.reserve(q);
	rep(_,q){
		int t;
		scanf("%d",&t);
		if(t==1){
			int l,r,g;
			scanf("%d %d %d",&l,&r,&g); --l;
			if(query(l,r,g)){
				re.pb(1); continue;
			}
			int lb=l,rb=r;
			while(rb-lb>1){
				int m=(lb+rb)/2;
				(query(l,m,g)?lb:rb)=m;
			}
			re.pb(query(rb,r,g));
		}else{
			int i,y;
			scanf("%d %d",&i,&y); --i;
			upd(i,y);
		}
	}
	for(int x:re) printf(x?"YES\n":"NO\n");
  return 0;
}