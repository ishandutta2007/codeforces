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

const int nn=112345;
ll bit[nn+1];

ll sum(int i){ ++i;
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
void add(int l,int r,ll x){
	if(l>=r) return;
	add(l,x); add(r,-x);
}
int lb(ll v){
	int l=0,r=nn;
	if(sum(l)>=v) return 0;
	while(r-l>1){
		int m=(l+r)/2;
		(sum(m)<v?l:r)=m;
	}
	return r;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	rep(i,m) cin>>a[i], --a[i];

	if(n==1){
		cout<<0<<endl;
		return 0;
	}
	
	reps(i,1,n) add(i,1);
	for(int x:a){
		add(0,n,1);
		int l=lb(x);
		int r=lb(x+1);
		out(l,r,x,1);
		add(l,r,-1);
		//rep(i,n) out(i,sum(i),1);
	}
	ll re=0;
	rep(i,n) re+=min(n-1ll,sum(i)+1)+1;
	rep(i,n) out(i,sum(i),1);
	fill(bit,bit+nn+1,0);

	reps(i,1,n) add(i,1);
	for(int x:a){
		add(0,n,-1);
		int l=lb(x);
		int r=lb(x+1);
		add(l,r,1);
	}
	rep(i,n) re-=max(0ll,sum(i)-1);
	rep(i,n) out(i,sum(i),1);
	cout<<re<<endl;
	return 0;
}