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

int dp[88][88][88][2];

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	string s;
	cin>>n>>s;
	vector<int> vs(n);
	rep(i,n) vs[i]=(s[i]=='V')+2*(s[i]=='K');
	vv<int> cnts(n,vector<int>(3));
	vv<int> inv(3);
	{
		vector<int> cnt(3);
		rep(i,n){
			inv[vs[i]].pb(i);
			cnts[i]=cnt;
			++cnt[vs[i]];
		}
	}
	int x=inv[0].size();
	int y=inv[1].size();
	int z=inv[2].size();
	fill(dp[0][0][0],dp[88][0][0],MOD);
	dp[0][0][0][0]=0;
	rep(i,x+1)rep(j,y+1)rep(k,z+1)rep(f,2){
		if(i<x){
			auto &cnt=cnts[inv[0][i]];
			MN(dp[i+1][j][k][0],dp[i][j][k][f]+max(0,cnt[1]-j)+max(0,cnt[2]-k));
		}
		if(j<y){
			auto &cnt=cnts[inv[1][j]];
			out(dp[i][j][k][f],cnt[0]-i+cnt[2]-k,i,j,k,cnt,1);
			MN(dp[i][j+1][k][1],dp[i][j][k][f]+max(0,cnt[0]-i)+max(0,cnt[2]-k));
		}
		if(k<z && !f){
			auto &cnt=cnts[inv[2][k]];
			MN(dp[i][j][k+1][0],dp[i][j][k][f]+max(0,cnt[0]-i)+max(0,cnt[1]-j));
		}
	}
	// rep(i,x+1){
	// 	rep(j,y+1){rep(k,z+1) cout<<pii(dp[i][j][k][0],dp[i][j][k][1])<<","; cout NL;}
	// 	cout NL;
	// }
	out(cnts,inv,x,y,z,1);
	cout<<min(dp[x][y][z][0],dp[x][y][z][1]) NL;
  return 0;
}