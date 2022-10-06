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
	int n,m;
	cin>>n>>m;
	vector<int> a(m);
	rep(i,m) cin>>a[i], --a[i];
	vector<int> fav(1<<n);
	for(int x:a) fav[x]=1;
	using AR=array<int,4>;
	vector<AR> cur;
	rep(i,1<<n)if(i%2){
		int t=fav[i]+fav[i-1];
		if(t==0) cur.pb({0,-MOD,-MOD,-MOD});
		else if(t==1) cur.pb({-MOD,1,1,-MOD});
		else cur.pb({-MOD,-MOD,-MOD,1});
	}
	while(cur.size()>1){
		vector<AR> nxt(cur.size()/2,AR{-MOD,-MOD,-MOD,-MOD});
		rep(i,cur.size())if(i%2){
			auto A=cur[i-1];
			auto B=cur[i];
			rep(a,4)if(A[a]>=0)rep(b,4)if(B[b]>=0){
					{
						int sum=A[a]+B[b];
						int c=0;
						if(a%2||b%2){
							++sum;
							c|=1;
						}
						if(a/2||b/2){
							++sum;
						}
						if((a/2||b/2) || (a%2&&b%2)){
							++sum;
							c|=2;
						}
						MX(nxt[i/2][c],sum);
					}
					{
						int sum=A[a]+B[b];
						int c=0;
						if(a%2||b%2){
							++sum;
							if(a%2&&b%2) c|=1;
						}
						if(a/2||b/2){
							++sum;
						}
						if((a/2||b/2) || (a%2||b%2)){
							++sum;
							c|=2;
						}
						MX(nxt[i/2][c],sum);
					}
				}
		}
		cur=nxt;
	}
	int re=0;
	rep(i,4) MX(re,cur[0][i]+!!i);
	cout<<re NL;
  return 0;
}