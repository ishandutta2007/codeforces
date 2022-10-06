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

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,t;
	cin>>n>>t;
	vector pws(n,vector<int>(t));
	rep(i,n)rep(j,t) cin>>pws[i][j];
	map<int,pair<vector<pii>,int>> mp;
	mp[0]=make_pair(vector<pii>(t,pii(0,0)),0);
	mp[MOD]=make_pair(vector<pii>(t,pii(MOD,MOD)),0);
	out(mp,1);
	for(auto v:pws){
		auto it=mp.emplace(v[0],make_pair(vector<pii>(),1)).X;
		rep(i,t) it->Y.X.eb(v[i],v[i]);
		// out(v,mp,1);
		while(1){
			auto tmp=it->Y.X;
			--it;
			int ng=0;
			rep(i,t){
				if(!(it->Y.X[i].Y < tmp[i].X)){
					ng=1;
					break;
				}
			}
			if(!ng){ ++it; break;}
			auto p=*it;
			it=mp.erase(it);
			rep(j,t){
				MX(it->Y.X[j].Y, p.Y.X[j].Y);
				MN(it->Y.X[j].X, p.Y.X[j].X);
			}
			it->Y.Y += p.Y.Y;
		}
		while(1){
			auto tmp=it->Y.X;
			++it;
			int ng=0;
			rep(i,t){
				if(!(it->Y.X[i].X > tmp[i].Y)){
					ng=1;
					break;
				}
			}
			--it;
			if(!ng) break;
			auto p=*it;
			it=mp.erase(it);
			rep(j,t){
				MX(it->Y.X[j].Y, p.Y.X[j].Y);
				MN(it->Y.X[j].X, p.Y.X[j].X);
			}
			it->Y.Y += p.Y.Y;
		}
		// out(mp,1);
		if(0){
			for(auto it=mp.begin();;++it){
				auto ite=it; ++ite;
				if(ite==mp.end()) break;
				rep(i,t) assert(ite->Y.X[i] > it->Y.X[i]);
			}
		}
		{
			out(mp,1);
			auto it=mp.end(); --it; --it;
			cout<<it->Y.Y NL;
		}
	}
	return 0;
}