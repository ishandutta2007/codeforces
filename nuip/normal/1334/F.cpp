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

const int nn=512345;
ll bit[nn+1];

ll sum(int i){ ++i;
	if(i<=0) return 0;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,ll x){ ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> as(n),ps(n);
	for(auto &x:as) cin>>x, --x;
	for(auto &x:ps) cin>>x;
	int m;
	cin>>m;
	vector<int> bs(m);
	for(auto &x:bs) cin>>x, --x;
	vector<int> prv(n,-1);
	reps(i,1,m) prv[bs[i]]=bs[i-1];
	ll re=0;
	vector<ll> costs(n);
	rep(i,n){
		int a=as[i];
		costs[i]+=sum(a)-sum(prv[a]);
		if(ps[i]<0){
			re+=ps[i];
			costs[i]+=-ps[i];
		}else{
			add(a,ps[i]);
		}
	}
	re+=sum(n)-sum(bs.back());

	out(costs,1);
	const ll INF=1e17;
	vector<ll> dp(m+1,INF+INF); dp[0]=0;
	vector<int> inv(n,-1);
	rep(i,m) inv[bs[i]]=i;
	rep(i,n){
		int a=as[i];
		int b=inv[a];
		if(b<0) continue;
		ll c=costs[i];
		MN(dp[b+1],dp[b]+c);
	}
	re+=dp.back();
	if(re>=INF){
		cout<<"NO" NL;
	}else{
		cout<<"YES\n"<<re NL;
	}
  return 0;
}