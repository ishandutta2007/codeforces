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

bool win(){
	cauto n=read();
	cauto m=read();
	vector mp(n,vector(m,0));
	rep(i,n)rep(j,m) cin>>mp[i][j];
	vector<int> cnt(n+m);
	rep(i,n)rep(j,m) cnt[i+j]^=(mp[i][j]);
	return (*max_element(all(cnt)))>0;
	// auto ng=table(n+1,m+1,0);
	// int x=0;
	// rep(i,n)rep(j,m){
	// 	if(mp[i][j] && MX(ng[i][j],1)) x^=mp[i][j];
	// 	if(ng[i][j]) ng[i+1][j]=ng[i][j+1]=1;
	// }
	// return x>0;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);

	if(0){
		cauto n=4;
		cauto m=4;
		using AR=array<array<int,m>,n>;
		map<AR,bool> memo;
		{
			AR ar;
			rep(i,n)rep(j,m) ar[i][j]=0;
			memo[ar]=false;
		}
		cauto dfs=
			[&](auto &&dfs,AR ar)->bool{
				if(memo.count(ar)) return memo[ar];
				rep(i,n)rep(j,m)if(ar[i][j]){
					vector<int> go(n-1-i);
					rep(_,m-1-j) go.eb(1);
					const int t=go.size();
					do{
						AR nxt=ar; nxt[i][j]=0;
						rep(st,1<<t){
							int y=i,x=j;
							rep(i,t){
								if(go[i]) ++x;
								else ++y;
								nxt[y][x]=(st>>i&1);
							}
							if(!dfs(dfs,nxt)) return memo[ar]=true;
						}
					}while(next_permutation(all(go)));
				}
				return memo[ar]=false;
			};
		rep(st,1<<(n*m)){
			AR ar;
			rep(i,n)rep(j,m) ar[i][j]=(st>>(i*m+j)&1);
			if(!dfs(dfs,ar)){
				rep(i,n){rep(j,m) cout<<".#"[ar[i][j]]; cout NL;}
				cout NL;
			}
		}
		return 0;
	}
	cauto T=read();
	rep(_,T){
		cout<<(win()?"Ashish":"Jeel") NL;
	}
  return 0;
}