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
	int n;
	cin>>n;
	vector<ll> a(n);
	rep(i,n) cin>>a[i];
	mt19937 rand(time(0));
	shuffle(all(a),rand);
	vector<ll> cand{2,3,5,7};
	out(primes.size(),1);
	int N=min(n,60);
	if(n<=1000) N=n;
	rep(i,N)reps(j,-1,2){
		ll x=a[i]+j;
		if(!x) continue;
		for(int p:primes){
			if(x<1ll*p*p) break;
			if(x%p) continue;
			cand.pb(p);
			while(x%p==0){
				x/=p;
			}
		}
		if(x>1) cand.pb(x);
	}
	sort(all(cand)); UNIQUE(cand);
	
	int m=cand.size();
	vector<ll> val(m);
	for(auto x:a){
		rep(i,m){
			const auto &p=cand[i];
			if(x<p){
				val[i]+=p-x;
			}else{
				auto rem=x%p;
				val[i]+=min(rem,p-rem);
			}
		}
	}
	out(m,val[0],cand[0],1);
	cout<<*min_element(all(val)) NL;
  return 0;
}