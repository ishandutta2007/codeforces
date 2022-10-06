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

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	using AR=array<int,5>;
	int n;
	cin>>n;
	vector<AR> ar(n);
	for(auto &[a,s,d,f,g]:ar) cin>>a>>s>>d>>f>>g;
	if(n>=500){
		cout<<0 NL;
		return 0;
	}
	vector<int> re;
	auto bad=
		[&](int i){
			rep(j,n)if(i!=j)rep(k,j)if(k!=i){
					if((get<0>(ar[j])-get<0>(ar[i]))*(get<0>(ar[k])-get<0>(ar[i]))
						 +(get<1>(ar[j])-get<1>(ar[i]))*(get<1>(ar[k])-get<1>(ar[i]))
						 +(get<2>(ar[j])-get<2>(ar[i]))*(get<2>(ar[k])-get<2>(ar[i]))
						 +(get<3>(ar[j])-get<3>(ar[i]))*(get<3>(ar[k])-get<3>(ar[i]))
						 +(get<4>(ar[j])-get<4>(ar[i]))*(get<4>(ar[k])-get<4>(ar[i]))>0) return true;
				}
			return false;
		};
	rep(i,n)if(!bad(i)) re.pb(i);
	cout<<re.size() NL;
	rep(i,re.size()) cout<<re[i]+1<<" \n"[i+1==re.size()];
	return 0;
}