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

int ask(int i,int j){
	if(0){
		vector<int> p{3,1,2,0};//{0,1,2};
		vector<int> b{3,1,2,0};//{0,1,2};
		return p[i]^b[j];
	}
	cout<<"? "<<i<<" "<<j<<endl; cout.flush();
	int re;
	cin>>re;
	if(re==-1) exit(0);
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	a[0]=b[0]=ask(0,0);
	reps(i,1,n) a[i]=ask(0,i);
	reps(i,1,n) b[i]=ask(i,0);
	int re=0;
	vector<int> re2;
	rep(i,n){
		vector<int> per(n),inv(n);
		rep(j,n) inv[j]=i^a[j];
		rep(j,n) per[j]=inv[0]^b[j];
		if(*max_element(all(per))>=n) continue;
		if(*max_element(all(inv))>=n) continue;
		int ok=1;
		rep(i,n)if(inv[per[i]]!=i) ok=0;
		if(ok){
			++re;
			re2=per;
		}
	}
	out(re,re2,1);
	cout<<"!" NL;
	cout<<re NL;
	rep(i,n) cout<<re2[i]<<" \n"[i+1==n];
	cout.flush();
  return 0;
}