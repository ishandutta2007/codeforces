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
#define NL <<"\n"

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
const ll MOD=1e9+7; //998244353

bool in(int n,pii pp,const vector<pii> ps){
	for(auto p:ps)if(pp!=p && p.X==n) return true;
	for(auto p:ps)if(pp!=p && p.Y==n) return true;
	return false;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	vector<pii> ps(n),qs(m);
	for(auto &p:ps) cin>>p.X>>p.Y;
	for(auto &p:qs) cin>>p.X>>p.Y;
	for(auto &p:ps)if(p.X>p.Y) swap(p.X,p.Y);
	for(auto &p:qs)if(p.X>p.Y) swap(p.X,p.Y);
	while(true){
		int upd=0;
		vector<pii> nps;
		for(auto p:ps)if(in(p.X,p,qs)||in(p.Y,p,qs)) nps.pb(p); else upd=1;
		ps=nps;
		vector<pii> nqs;
		for(auto p:qs)if(in(p.X,p,ps)||in(p.Y,p,ps)) nqs.pb(p); else upd=1;
		qs=nqs;
		if(!upd) break;
	}
	for(auto p:ps)if(in(p.X,p,qs)&&in(p.Y,p,qs)){ cout<<-1<<endl; return 0;}
	for(auto p:qs)if(in(p.X,p,ps)&&in(p.Y,p,ps)){ cout<<-1<<endl; return 0;}
	{
		set<int> st;
		for(auto p:ps){
			if(in(p.X,p,qs)) st.emplace(p.X);
			if(in(p.Y,p,qs)) st.emplace(p.Y);
		}
		if(st.size()==1) { cout<<*st.begin()<<endl; return 0;}
	}
	{
		set<int> st;
		for(auto p:qs){
			if(in(p.X,p,ps)) st.emplace(p.X);
			if(in(p.Y,p,ps)) st.emplace(p.Y);
		}
		if(st.size()==1) { cout<<*st.begin()<<endl; return 0;}
	}
	cout<<0<<endl;
  return 0;
}