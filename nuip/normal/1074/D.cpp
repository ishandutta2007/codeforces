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
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
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
	int q;
	cin>>q;
	int last=0;
	gp_hash_table<int, int> mp;
	vector<UF> ufs;
	rep(i,30) ufs.eb(800000);
	while(q--){
		int t;
		cin>>t;
		int l,r;
		cin>>l>>r; l^=last; r^=last;
		if(l>r) swap(l,r);
		++r;
		{
			int x=mp.size();
			l=mp.insert(pii(l,x)).X->Y;
		}
		{
			int x=mp.size();
			r=mp.insert(pii(r,x)).X->Y;
		}
		l*=2; r*=2;
		if(t==1){
			int x;
			cin>>x; x^=last;
			if(ufs[0](l,r)||ufs[0](l,1+r)) continue;
			// rep(i,30){
			// 	if(x>>i&1){
			// 		if(ufs[i](l,r)) valid=0;
			// 	}else{
			// 		if(ufs[i](l,1+r)) valid=0;
			// 	}
			// }
			rep(i,30){
				if(x>>i&1){
					ufs[i].unite(l,1+r);
					ufs[i].unite(1+l,r);
				}else{
					ufs[i].unite(l,r);
					ufs[i].unite(1+l,1+r);
				}
			}
			out(l,r,x,1);
		}else{
			out(l,r,1);
			int re=0;
			if(ufs[0](l,r)||ufs[0](l,1+r)){
				rep(i,30)if(ufs[i](l,1+r)) re|=1<<i;
			}else{
				re=-1;
			}
			cout<<re NL;
			last=(re<0?1:re);
		}
	}
  return 0;
}