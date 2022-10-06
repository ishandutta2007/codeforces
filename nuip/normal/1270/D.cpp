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

vector<int> ans{3,4,6,1,7,8,2};
int m=3;

pii ask(vector<int> v){
	cout<<"?";
	for(int x:v) cout<<" "<<x+1; cout<<endl; cout.flush();
#ifdef NUIP
	if(0){
		sort(all(v),[&](int l,int r){return ans[l]<ans[r];});
		return pii(v[m-1],ans[v[m-1]]);
	}
#endif
	int ind,val;
	cin>>ind; if(ind<0) exit(0);
	cin>>val; --ind;
	return pii(ind,val);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,t;
	cin>>n>>t;
	vector<int> v(t); iota(all(v),0);
	vector<int> a(n,-1);
	reps(i,t,n+1){
		pii p=ask(v);
		a[p.X]=p.Y;
		rep(j,t)if(v[j]==p.X) v[j]=i;
	}
	out(a,1);
	int mn=MOD,mx=-1,mni,mxi;
	rep(i,n)if(a[i]>=0){
		if(MX(mx,a[i])) mxi=i;
		if(MN(mn,a[i])) mni=i;
	}
	rep(i,t)if(v[i]==n) v[i]=mni;
	int re=0;
	rep(i,t)if(v[i]!=mni){
		auto w=v;
		w[i]=mxi;
		pii p=ask(w);
		if(p.X==mxi) ++re;
	}
	cout<<"! "<<re+1<<endl; cout.flush();
  return 0;
}