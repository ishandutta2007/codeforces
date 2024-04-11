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
#include "../benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

void yes(){
	cout<<"Yes"<<endl;
	exit(0);
}
void no(){
	cout<<"No"<<endl;
	exit(0);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m,t;
	cin>>n>>m>>t;
	vector<pii> obs(t);
	map<pii,int> inv;
	rep(i,t){
		int y,x;
		cin>>y>>x; --y; --x;
		obs[i]=pii(x,y);
		inv[obs[i]]=i;
	}
	deque<int> xy(t),yx(t);
	iota(all(xy),0); sort(all(xy),[&](const int i,const int j){ return
				pii(obs[i].X,-obs[i].Y)
				<pii(obs[j].X,-obs[j].Y);});
	iota(all(yx),0); sort(all(yx),[&](const int i,const int j){ return
				pii(obs[i].Y,obs[i].X)
				<pii(obs[j].Y,obs[j].X);});
	vector<int> usd(t);
	int y=0,Y=n-1,x=0,X=m-1;
	auto isin=
		[&](int i){
			if(obs[i].X<x || obs[i].X>X) return false;
			if(obs[i].Y<y || obs[i].Y>Y) return false;
			return true;
		};
	auto erase=
		[&](int x,int y,int X,int Y){
			out(x,y,X,Y,1);
			reps(i,y,Y+1)reps(j,x,X+1){
				if(inv.count(pii(j,i))==0) no();
				usd[inv[pii(j,i)]]=1;
			}
		};
	rep(i,MOD){
		if(i%4==0){
			while(yx.size() && !isin(yx.front())) yx.pop_front();
			if(yx.empty()) yes();
			if(obs[yx.front()].Y==y){
				int ind=yx.front();
				usd[ind]=1;
				erase(obs[ind].X,y,X,Y);
				X=obs[ind].X-1;
			}
			++y;
		}else if(i%4==1){
			while(xy.size() && !isin(xy.back())) xy.pop_back();
			if(xy.empty()) yes();
			if(obs[xy.back()].X==X){
				int ind=xy.back();
				usd[ind]=1;
				erase(x,obs[ind].Y,X,Y);
				Y=obs[ind].Y-1;
			}
			--X;
		}else if(i%4==2){
			while(yx.size() && !isin(yx.back())) yx.pop_back();
			if(yx.empty()) yes();
			if(obs[yx.back()].Y==Y){
				int ind=yx.back();
				usd[ind]=1;
				erase(x,y,obs[ind].X,Y);
				x=obs[ind].X+1;
			}
			--Y;
		}else{
			while(xy.size() && !isin(xy.front())) xy.pop_front();
			if(xy.empty()) yes();
			if(obs[xy.front()].X==x){
				int ind=xy.front();
				usd[ind]=1;
				erase(x,y,X,obs[ind].Y);
				y=obs[ind].Y+1;
			}
			++x;
		}
		out(i,x,y,X,Y,usd,1);
	}
	yes();
  return 0;
}