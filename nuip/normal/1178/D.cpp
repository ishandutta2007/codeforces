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
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

vector<int> primes,prime;
class PRPRPR{
public:
  PRPRPR(int PRIME_MAX){
    prime.resize(PRIME_MAX);
    for(int i=2;i<PRIME_MAX;i++)if(!prime[i]){
	primes.pb(i);
	for(int j=i*2;j<PRIME_MAX;j+=i)
	  prime[j]=1;
      }
  }
} prprprpr(1123456);

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	reps(n,3,1001){
		int ok=0;
		rep(j,n/2+1)if(!prime[n+j]) ok=1;
		if(!ok) out(n,1);
	}
	int n;
	cin>>n;
	vector<pii> re;
	vv<int> g(n);
	rep(i,n){
		int a=i,b=(i+1)%n;
		g[a].pb(b);
		g[b].pb(a);
		re.eb(a,b);
	}
	int e=n;
	vector<pii> es;
	rep(i,n){
		int a=i,b=(i+n/2)%n;
		if(a<b) es.eb(a,b);
	}
	while(prime[e]){
		int a,b;
		tie(a,b)=es.back(); es.pop_back();
		g[a].pb(b);
		g[b].pb(a);
		re.eb(a,b);
		++e;
	}
	rep(i,n) assert(prime[g[i].size()]==0);
	cout<<re.size()<<endl;
	for(pii p:re){
		cout<<p.X+1<<" "<<p.Y+1 NL;
	}
  return 0;
}