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

const int N=65;
pii dp[N][31][30*N+100];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> as(n);
	for(auto &x:as) cin>>x;
	sort(all(as));
	dp[1][0][as[0]]=pii(1,0);
	int sz=-1;
	reps(i,1,N-1){
		if(dp[i][n-1][i*(i-1)/2].X){
			sz=i;
			break;
		}
		rep(j,n)reps(k,i*(i-1)/2,30*N)if(dp[i][j][k].X){
			dp[i+1][j][k+as[j]]=pii(1,j);
			if(j+1<n) dp[i+1][j+1][k+as[j+1]]=pii(1,j);
		}
	}
	// rep(i,5){rep(j,4){rep(k,30) cout<<dp[i][j][k].X;cout NL;} cout NL;}
	out(sz,1);
	auto no=
		[&](){
			cout<<"=" NL;
			exit(0);
		};
	if(sz==-1) no();
	vector<int> degs;
	for(int i=sz,j=n-1,k=i*(i-1)/2;i>0;--i){
		out(i,j,k,1);
		int nj=dp[i][j][k].Y;
		degs.pb(as[j]);
		k-=as[j];
		j=nj;
	}
#define n unkounko
	reverse(all(degs));
	out(degs,1);
	{
		int s=0;
		rep(i,sz){
			s+=degs[i];
			if(s<(i+1)*i/2) no();
		}
		if(s!=sz*(sz-1)/2) no();
	}
	auto s=degs;
	vector re(sz,vector(sz,0));
	rep(i,sz)rep(j,i) re[i][j]=1;
	vector<int> u(sz); iota(all(u),0);
	rep(_,1000000){
		int alpha=-1;
		rep(i,sz)if(s[i]!=u[i]){ alpha=i; break;}
		if(alpha<0) break;
		int beta;
		rrep(i,sz)if(u[alpha]==u[i]){ beta=i; break;}
		int gamma;
		reps(i,beta,sz)if(u[i]>s[i]){ gamma=i; break;}
		out(alpha,beta,gamma,u,1);
		rep(lambda,sz)if(re[gamma][lambda] && re[lambda][beta]){
			out(lambda,1);
			re[gamma][lambda]=re[lambda][beta]=0;
			re[lambda][gamma]=re[beta][lambda]=1;
			break;
		}
		--u[gamma];
		++u[beta];
		// rep(i,sz){rep(j,sz) cout<<re[i][j];cout NL;} cout NL;
	}
	if(u!=s) no();
	cout<<sz NL;
	rep(i,sz){rep(j,sz) cout<<re[i][j];cout NL;}
  return 0;
}