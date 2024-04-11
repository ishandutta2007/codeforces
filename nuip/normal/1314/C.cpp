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

const ll INF=1123456789012345678;
ll dp[1123][1123];
string s;

ll solve(string t,int dvd){
	int n=s.size();
	int m=t.size();
	fill(dp[0],dp[n+1],0);
	dp[0][0]=1; dp[1][0]=-1;
	rep(i,n){
		rep(j,dvd+1) MN(dp[i+1][j]+=dp[i][j],INF);
		int stt=-1;
		rep(j,m){
			if(i+j>=n) break;
			if(s[i+j]<t[j]) break;
			if(s[i+j]>t[j]){ stt=i+j; break;}
			if(j+1==m) stt=i+j;
		}
		if(stt<0) continue;
		rep(j,dvd) MN(dp[stt+1][j+1]+=dp[i][j],INF);
	}
	// rep(i,n+1){rep(j,dvd+1) cout<<dp[i][j]<<","; cout NL;}
	// out(t,dvd,dp[n][dvd],1);
	return dp[n][dvd];
}

string solve(int n,int m,ll t,string s){
	::s=s;
	string pre;
	while(pre.size()<n){
		vector<char> cs;
		rep(i,n-pre.size())if(s.substr(i,pre.size())==pre) cs.eb(s[i+pre.size()]);
		sort(all(cs)); UNIQUE(cs);
		if(cs.empty()) break;
		int l=0,r=(int)cs.size()-1;
		if(solve(pre+cs[l],m)<t) break;
		if(solve(pre+cs[r],m)>=t){
			pre+=cs[r];
			continue;
		}
		while(r-l>1){
			int med=(l+r)/2;
			(solve(pre+cs[med],m)<t?r:l)=med;
		}
		// out(cs,l,r,1);
		pre+=cs[l];
	}
	return pre;
}

vector<string> bf(int n,int m,string s){
	assert(m==4);
	vector<string> ss;
	rep(i2,n)rep(i1,i2)reps(i0,1,i1){
		ss.eb(min({s.substr(0,i0),s.substr(i0,i1-i0),s.substr(i1,i2-i1),s.substr(i2)}));
		if(ss.back().empty()) out(i0,i1,i2,1);
	}
	sort(rall(ss));
	return ss;
}

void test(){
	const int n=rand()%10+5;
	const int m=4;
	string s;
	rep(i,n) s+=string(1,rand()%26+'a');
	auto ans=bf(n,m,s);
	rep(i,ans.size()){
		string exp=ans[i];
		string act=solve(n,m,i+1,s);
		if(exp!=act){
			out(n,m,i,s,exp,act,1);
			exit(0);
		}
	}
}

int main(){
	// out(bf(8,4,"wlrbbmqb"),1);
	// out(solve(8,4,5,"wlrbbmqb"),1); //bmqb
	// // out(solve("bmqb",4),1);
	// // out(solve("bbmqb",4),1);
	// return 0;
	// rep(_,100) test();
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,m;
	ll t;
	cin>>n>>m>>t>>s;
	cout<<solve(n,m,t,s) NL;
	// out(solve("aupontrougevkoff",m),1); return 0;
	// out(solve("aa",m),1);
	// out(solve("au",m),1);
	// out(solve("aup",m),1);
  return 0;
}