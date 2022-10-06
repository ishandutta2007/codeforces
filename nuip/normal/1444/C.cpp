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
const ll MOD=1e9+7; //998244353

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(-data[y]>-data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
	bool operator()(int x,int y){ return findSet(x,y);}
	int operator[](int x){ return root(x);}
	bool unti(int x,int y){ return unite(x,y);}
};

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	cauto m=read();
	cauto t=read();
	cauto cs=readV(n,1);
	cauto es=readV<pii>(m,{1,1});
	vv<int> g(n);
	UF uf(n);
	for(cauto [v,w]:es){
		g[v].eb(w);
		g[w].eb(v);
		if(cs[v]==cs[w]) uf.unite(v,w);
	}
	vector<int> bi(n,-1);
	vector<int> okc(t,1);
	rep(v,n)if(bi[v]<0){
		cauto c=cs[v];
		bi[v]=0;
		queue<int> que; que.emplace(v);
		while(que.size()){
			cauto v=que.front(); que.pop();
			for(cauto w:g[v])if(cs[w]==c){
					if(bi[w]<0){
						bi[w]=1-bi[v];
						que.emplace(w);
					}else if(bi[w]!=1-bi[v]){
						out(w,v,1);
						okc[c]=0;
						break;
					}
				}
		}
	}
	out(bi,okc,1);
	ll re=0;
	{
		cauto tmp=accumulate(all(okc),0ll);
		re+=tmp*(tmp-1)/2;
	}
	map<pii,vector<pii>> ces;
	for(cauto [a,b]:es){
		if(cs[a]==cs[b]) continue;
		if(!okc[cs[a]] || !okc[cs[b]]) continue;
		cauto x=uf.root(a);
		cauto y=uf.root(b);
		ces[{min(cs[a],cs[b]),max(cs[a],cs[b])}].eb(x*2+bi[a],y*2+bi[b]);
	}
	{
		vector<int> bi(n+n);
		vv<int> g(n+n);
		vector<int> vs;
		for(cauto &p:ces){
			cauto &es=p.Y;
			vs.clear();
			for(cauto [a,b]:es){
				vs.eb(a); vs.eb(a^1);
				vs.eb(b); vs.eb(b^1);
			}
			sort(all(vs)); UNIQUE(vs);
			for(cauto v:vs){
				bi[v]=-1;
				g[v].clear();
				g[v].eb(v^1);
			}
			for(cauto [a,b]:es){
				g[a].eb(b);
				g[b].eb(a);
			}
			int ng=0;
			for(cauto v:vs)if(bi[v]<0){
				bi[v]=0;
				queue<int> que; que.emplace(v);
				while(que.size()){
					cauto v=que.front(); que.pop();
					for(cauto w:g[v]){
						if(bi[w]<0){
							bi[w]=1-bi[v];
							que.emplace(w);
						}else if(bi[w]!=1-bi[v]){
							ng=1;
							break;
						}
					}
					if(ng) break;
				}
				if(ng) break;
			}
			if(ng) out(p,1);
			if(ng) --re;
		}
		
	}
	cout<<re NL;
  return 0;
}