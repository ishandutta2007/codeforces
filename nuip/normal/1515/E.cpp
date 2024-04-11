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
#define cauto const auto

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
void ouT(ll x,int d=3){auto re=to_string(x);if((int)re.size()>d) re=x>0?"oo":"-oo";cout<<string(d-re.size(),' ')<<re<<",";}
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
template<class A,class B> pair<A,B> operator+(const pair<A,B> &p,const pair<A,B> &q){ return {p.X+q.X,p.Y+q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator+=(pair<A,B> &p,const pair<C,D> &q){ p.X+=q.X; p.Y+=q.Y; return p;}
template<class A,class B> pair<A,B> operator-(const pair<A,B> &p,const pair<A,B> &q){ return {p.X-q.X,p.Y-q.Y};}
template<class A,class B,class C,class D> pair<A,B>& operator-=(pair<A,B> &p,const pair<C,D> &q){ p.X-=q.X; p.Y-=q.Y; return p;}
template<class A,class B> istream& operator>>(istream &is, pair<A,B> &p){ is>>p.X>>p.Y; return is;}
template<class T=ll> T read(){ T re; cin>>re; return move(re);}
template<class T=ll> T read(const T &dec){ T re; cin>>re; return re-dec;}
template<class T=ll> vector<T> readV(const int sz){ vector<T> re(sz); for(auto &x:re) x=read<T>(); return move(re);}
template<class T=ll> vector<T> readV(const int sz, const T &dec){ vector<T> re(sz); for(auto &x:re) x=read<T>(dec); return move(re);}
vv<int> readG(const int &n,const int &m){ vv<int> g(n); rep(_,m){ cauto a=read<int>(1),b=read<int>(1); g[a].pb(b); g[b].pb(a);} return move(g);}
vv<int> readG(const int &n){ return readG(n,n-1);}
#define TT cauto TTT=read();rep(_,TTT)

ll binom[1123][1123];

ll get(int n){
	vector<int> perm(n); iota(all(perm),0);
	set<vector<int>> st;
	do{
		vector<int> seq;
		vector<int> usd(n);
		for(cauto i:perm){
			if(!MX(usd[i],1)) continue;
			seq.eb(i);
			if(i>=2 && usd[i-2]) MX(usd[i-1],1);
			if(i+2<n && usd[i+2]) MX(usd[i+1],1);
		}
		st.emplace(seq);
	}while(next_permutation(all(perm)));
	// out(st,1);
	vector<int> cnt(n+1);
	for(cauto &v:st) ++cnt[v.size()];
	out(cnt,1);
	{
		vector<int> vs{0,3,4,5};
		do{
			auto X=vs;
			X.eb(1);
			// if(st.count(X)==0) out(X,1);
		}while(next_permutation(all(vs)));
	}
	return st.size();
}

int dp[412][412];
ll mod;

void fun(const int &m, const int &L,const int &R,const int &t){
	int l0=0,r0=0;
	while(l0<L && dp[L][l0]==0) ++l0;
	while(r0<R && dp[R][r0]==0) ++r0;
	reps(l,l0,L+1)if(dp[L][l])reps(r,r0,R+1){
			(dp[m][l+r+1]+=dp[L][l]*dp[R][r]%mod*binom[l+r][l]*t)%=mod;
		}
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	cauto n=read();
	mod=read();
	binom[0][0]=1;
	rep(i,1023)rep(j,1023){
		if((binom[i+1][j]+=binom[i][j])>=mod) binom[i+1][j]-=mod;
		if((binom[i+1][j+1]+=binom[i][j])>=mod) binom[i+1][j+1]-=mod;
	}
	// rep(i,10){rep(j,10) ouT(binom[i][j]); cout NL;}
	dp[0][0]=1;
	dp[1][1]=1;
	reps(m,1,n){
		rep(k,m+1){
			if((dp[m+1][k+1]+=dp[m][k])>=mod) dp[m+1][k+1]-=mod;
			if((dp[m+1][k+1]+=dp[m][k])>=mod) dp[m+1][k+1]-=mod;
			if((dp[m+2][k+1]+=dp[m][k])>=mod) dp[m+2][k+1]-=mod;
			if((dp[m+2][k+1]+=dp[m][k])>=mod) dp[m+2][k+1]-=mod;
		}
		if(m+m+2<=n)reps(i,m/2,m+1)reps(j,m/2,m+1){
			cauto tmp=binom[i+j][i]*dp[m][i]%mod*dp[m][j]%mod;
			if((dp[m+m+2][i+j+1]+=tmp)>=mod) dp[m+m+2][i+j+1]-=mod;
			if((dp[m+m+2][i+j+1]+=tmp)>=mod) dp[m+m+2][i+j+1]-=mod;
			if((dp[m+m+3][i+j+1]+=tmp)>=mod) dp[m+m+3][i+j+1]-=mod;
		}
		reps(i,m/2,m+1)if(dp[m][i])reps(k,1,m){
			if(m+k+2>n) break;
			reps(j,k/2,k+1){
				cauto tmp=binom[i+j][i]*dp[m][i]%mod*dp[k][j]*2%mod;
				if((dp[m+k+2][i+j+1]+=tmp)>=mod) dp[m+k+2][i+j+1]-=mod;
				if((dp[m+k+2][i+j+1]+=tmp)>=mod) dp[m+k+2][i+j+1]-=mod;
				if((dp[m+k+3][i+j+1]+=tmp)>=mod) dp[m+k+3][i+j+1]-=mod;
			}
		}
	}
	// rep(i,n+1){rep(j,n+1) ouT(dp[i][j]); cout NL;}
	ll re=accumulate(dp[n],dp[n+1],0ll);
	cout<<re%mod NL;
	// out(get(n),1);
  return 0;
}