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

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		vector<ll> ps(n);
		rep(i,n) cin>>ps[i];
		sort(rall(ps));
		pll p,q;;
		cin>>p.Y>>p.X;
		cin>>q.Y>>q.X;
		if(p.Y>q.Y) swap(p,q);
		ll t;
		cin>>t;
		pll pq(p.X*q.X/__gcd<ll>(p.X,q.X), p.Y+q.Y);
		auto get=
			[&](int n){
				int a=n/pq.X;
				int b=n/q.X-a;
				int c=n/p.X-a;
				out(a,b,c,1);
				ll re=0;
				reps(i,0,a) re+=ps[i]/100*pq.Y;
				reps(i,a,a+b) re+=ps[i]/100*q.Y;
				reps(i,a+b,a+b+c) re+=ps[i]/100*p.Y;
				return re;
			};
		out(n,get(n),t,1);
		if(get(n)<t){
			cout<<-1 NL;
			continue;
		}
		int l=0,r=n;
		while(r-l>1){
			int m=(l+r)/2;
			(get(m)<t?l:r)=m;
		}
		cout<<r NL;
	}
  return 0;
}