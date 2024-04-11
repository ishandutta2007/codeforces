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
	int n;
	cin>>n;
	string opes(n,'.');
	vector<pii> clds(n);
	rep(i,n){
		string s;
		cin>>s>>clds[i].X;
		if(s=="IN"){
			opes[i]='>';
			continue;
		}
		--clds[i].X;
		if(s=="NOT"){
			opes[i]='~';
			continue;
		}
		cin>>clds[i].Y; --clds[i].Y;
		if(s=="AND"){
			opes[i]='&';
		}else if(s=="OR"){
			opes[i]='|';
		}else if(s=="XOR"){
			opes[i]='^';
		}else return 1;
	}
	out(opes,clds,1);
	vector<int> vals(n);
	{
		function<int(int)> dfs=
			[&](int v){
				if(opes[v]=='&'){
					vals[v]=dfs(clds[v].X)&dfs(clds[v].Y);
				}else if(opes[v]=='|'){
					vals[v]=dfs(clds[v].X)|dfs(clds[v].Y);
				}else if(opes[v]=='^'){
					vals[v]=dfs(clds[v].X)^dfs(clds[v].Y);
				}else if(opes[v]=='~'){
					vals[v]=1-dfs(clds[v].X);
				}else vals[v]=clds[v].X;
				return vals[v];
			};
		dfs(0);
	}
	out(vals,1);

	string re(n,vals[0]+'0');
	out(re,1);
	{
		function<void(int)> dfs=
			[&](int v){
				if(opes[v]=='&'){
					if(vals[clds[v].X]) dfs(clds[v].Y);
					if(vals[clds[v].Y]) dfs(clds[v].X);
				}else if(opes[v]=='|'){
					if(!vals[clds[v].X]) dfs(clds[v].Y);
					if(!vals[clds[v].Y]) dfs(clds[v].X);
				}else if(opes[v]=='^'){
					dfs(clds[v].X);
					dfs(clds[v].Y);
				}else if(opes[v]=='~'){
					dfs(clds[v].X);
				}else re[v]^=1;
			};
		dfs(0);
	}
	rep(i,n)if(opes[i]=='>') cout<<re[i];
	cout NL;
  return 0;
}