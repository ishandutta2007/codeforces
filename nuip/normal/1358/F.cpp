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

void no(){
	cout<<"IMPOSSIBLE" NL;
	exit(0);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);

	// int n=3;
	// vector<ll> as{1,1,1};
	// vector<ll> bs{1,1,1};
	// while(bs.back()<=1e12) rep(i,2) bs[i+1]+=bs[i];

	int n;
	cin>>n;
	vector<ll> as(n),bs(n);
	for(auto &x:as) cin>>x;
	for(auto &x:bs) cin>>x;
	if(n==1){
		if(as==bs){
			cout<<"SMALL" NL;
			cout<<0 NL;
			cout NL;
		}else{
			no();
		}
		return 0;
	}
	vector<ll> re;
	ll A=accumulate(all(as),0ll);
	while(A<accumulate(all(bs),0ll)){
		if(*min_element(all(bs))<=0) no();
		if(bs[0]>=bs[1]){
			re.eb(-1);
			reverse(all(bs));
			reps(i,1,n)if(bs[i-1]>=bs[i]) no();
		}
		ll t=bs[1]/bs[0];
		re.eb();
		if(n==2){
			if(bs[0]==min(as[0],as[1])){
				ll d=bs[1]-max(as[0],as[1]);
				if(d%bs[0]) no();
				t=d/bs[0];
			}
			re.back()+=t;
			bs[1]-=bs[0]*t;
		}else{
			for(ll i=0;i<t;++i){
				rrep(i,n-1){
					bs[i+1]-=bs[i];
					if(bs[i+1]<=0) no();
				}
				++re.back();
				if(A>=accumulate(all(bs),0ll)) break;
			}
		}
		out(bs,re,1);
	}
	if(as!=bs){
		reverse(all(bs));
		re.eb(-1);
	}
	if(as!=bs) no();
	out(re,1);
	ll sum=0;
	for(auto x:re) sum+=(x<0?0:x);
	if(sum>200000){
		cout<<"BIG" NL;
		cout<<sum NL;
	}else{
		for(auto x:re) sum+=(x<0?1:0);
		cout<<"SMALL" NL;
		cout<<sum NL;
		reverse(all(re));
		for(auto x:re) cout<<(x<0?"R"s:string(x,'P'));
		cout NL;
	}
  return 0;
}