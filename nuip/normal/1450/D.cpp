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
#define T cauto TTT=read();rep(_,TTT)
const ll MOD=1e9+7; //998244353;

string bf(vector<int> vs){
	string re;
	while(1){
		re+="0";
		if(*max_element(all(vs))==vs.size()-1 && set<int>(all(vs)).size()==vs.size()) ++re.back();
		if(vs.size()==1) break;
		cauto cur=vs;
		reps(i,1,cur.size()) vs[i-1]=min(cur[i-1],cur[i]);
		vs.pop_back();
	}
	return re;
}
string solve(const vector<int> vs){
	const int n=vs.size();
	int mx=0;
	int perm=1;
	{
		vector<int> mn(n,n);
		rep(i,n){
			MN(mn[vs[i]],i);
			MX(mx,i-mn[vs[i]]+1);
		}
		rep(i,n)if(mn[i]==n){
			perm=0;
			MX(mx,n+1-i);
			break;
		}
	}
	// out(mx,1);
	set<int> st{-1,n};
	vv<int> inds(n);
	rep(i,n) inds[vs[i]].eb(i);
	rep(ii,n){
		for(cauto i:inds[ii]){
			auto it=st.lower_bound(i);
			cauto r=*it;
			--it;
			cauto l=*it;
			// out(l,i,r,st,1);
			if(l+1==i || i==r-1) continue;
			// out(i,r-l-1,1);
			MX(mx,r-l-1);
		}
		st.insert(all(inds[ii]));
	}
	string re(n,'1');
	reps(i,2,mx) re[i-1]='0';
	if(!perm) re[0]='0';
	// out(perm,mx,1);
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	if(0){
		reps(n,1,100){
			rep(_,1000){
				vector<int> vs(n);
				for(auto &v:vs) v=rand()%n;
				cauto exp=bf(vs);
				cauto act=solve(vs);
				if(exp!=act){
					out(exp,act,vs,1);
					exit(0);
				}
			}
		}
		return 0;
	}
	T{
		cauto n=read();
		auto vs=readV(n,1);
		cout<<solve(vs) NL;
	}
  return 0;
}