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
	int T;
	cin>>T;
	while(T--){
		int n,t,a,b;
		cin>>n>>t>>a>>b;
		vector<int> ish(n);
		rep(i,n) cin>>ish[i];
		vector<pii> ps(n);
		rep(i,n){
			ps[i].Y=i;
			cin>>ps[i].X;
		}
		sort(rall(ps));
		int H=accumulate(all(ish),0),E=n-H;
		ll easy=0,hard=0;
		auto get=
			[&](ll t){
				ll rem=t-easy*a-hard*b;
				// out(t,rem,1);
				if(rem<0) return 0;
				int re=easy+hard;
				{
					int t=min(E-easy,rem/a);
					re+=t;
					rem-=a*t;
					t=min(H-hard,rem/b);
					re+=t;
				}
				return re;
			};
		int re=0;
		while(ps.size()){
			int t=ps.back().X;
			MX(re,get(t-1));
			while(ps.size() && ps.back().X==t){
				auto p=ps.back(); ps.pop_back();
				(ish[p.Y]?hard:easy)++;
			}
		}
		MX(re,get(t));
		cout<<re NL;
	}
  return 0;
}