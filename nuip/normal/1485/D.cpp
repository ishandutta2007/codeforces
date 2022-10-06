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
#include<random>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (int)(Y);++(X))
#define reps(X,S,Y) for (int (X) = (int)(S);(X) < (int)(Y);++(X))
#define rrep(X,Y) for (int (X) = (int)(Y)-1;(X) >=0;--(X))
#define rreps(X,S,Y) for (int (X) = (int)(Y)-1;(X) >= (int)(S);--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())
#define Endl endl
#define NL <<"\n"
#define cauto const auto

using namespace std;
using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
template<class T> using vv=vector<vector<T>>;
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#include "benri.h"
#else
#define out(args...)
#endif
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return move(re);}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
#define TT cauto TTT=read();rep(_,TTT)
const ll MOD=1e9+7; //998244353;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	// ll x=1;
	// reps(i,1,17) x=lcm(x,i);
	// out(x,1);
	// reps(i,1,40)reps(j,i,40)reps(k,1,40)reps(l,k,40){
	// 	cauto i4=i*i*i*i;
	// 	cauto j4=j*j*j*j;
	// 	cauto k4=k*k*k*k;
	// 	cauto l4=l*l*l*l;
	// 	if(i4+j4==k4+l4 && i4!=k4) out(i,j,k,l,1);
	// }
	vector<int> facts;
	reps(i,1,720721)if(720720%i==0) facts.eb(i);
	out(facts,1);
	map<int,int> quad;
	reps(i,1,40) quad.emplace(i*i*i*i,i);
	// for(cauto x:facts)for(cauto y:facts)if(quad.count(x-y)) out(x,y,quad[x-y],1);
	// const int UB=100000;
	// for(int a=15;a<=UB;a+=15){
	// 	for(int b=15;b<=UB;b+=15){
	// 		if(quad.count(abs(a-b))==0) continue;
	// 		for(int c=11;c<=UB;c+=11){
	// 			if(quad.count(abs(a-c))==0) continue;
	// 			for(int d=11;d<=UB;d+=11){
	// 				if(quad.count(abs(b-d))==0) continue;
	// 				if(quad.count(abs(c-d))==0) continue;
	// 				out(a,b,c,d,a/15,b/15,c/11,d/11,1);
	// 			}
	// 		}
	// 	}
	// }
	cauto n=read();
	cauto m=read();
	auto mp=table(n,m,0);
	rep(i,n)rep(j,m) cin>>mp[i][j];
	cauto x=720720;
	rep(i,n)rep(j,m){
		if(i%2!=j%2){
			cauto y=mp[i][j];
			mp[i][j]*=x/y+y*y*y;
		}else{
			mp[i][j]=x;
		}
	}
	rep(i,n)rep(j,m){
		if(i) assert(quad.count(abs(mp[i-1][j]-mp[i][j])));
		if(j) assert(quad.count(abs(mp[i][j-1]-mp[i][j])));
	}
	rep(i,n)rep(j,m) cout<<mp[i][j]<<" \n"[j+1==m];
	return 0;
}