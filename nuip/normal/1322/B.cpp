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

const int nn=1<<25;
ll bit[nn+1];

ll sum(int i){ ++i;
	MN(i,nn);
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,ll x){ ++i; ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

int bf(vector<int> a){
	int n=a.size();
	int re=0;
	rep(i,n)rep(j,i) re^=a[i]+a[j];
	return re;
}
int solve(vector<int> a){
	int n=a.size();
	int re=0;
	rep(d,25){
	// rep(d,2){
		fill(bit,bit+nn+1,0);
		rep(i,n){
			int x=a[i]&((2<<d)-1);
			int cnt=i;
			cnt-=sum((1<<d)-x);
			cnt+=sum((2<<d)-x);
			cnt-=sum((3<<d)-x);
			// out(i,x,cnt,1);
			if(cnt%2) re^=1<<d;
			add(x,1);
		}
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	if(0)rep(_,100){
		int n=300;
		vector<int> a(n);
		rep(i,n) a[i]=rand()%10000000;
		int exp=bf(a);
		int act=solve(a);
		if(exp!=act){
			out(act,exp,a,1);
			return 0;
		}
	}
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	cout<<solve(a) NL;
  return 0;
}