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

bool check(vector<int> a,vector<pii> ps){
	for(auto [i,j]:ps) swap(a[i],a[j]);
	reps(i,1,a.size())if(a[i-1]>a[i]) return false;
	return true;
}

bool bf(vector<int> a){
	const int n=a.size();
	vector<pii> ps;
	rep(i,n)reps(j,i+1,n)if(a[i]>a[j]) ps.eb(i,j);
	do{
		if(check(a,ps)){
			// out(ps,1);
			return true;
		}
	}while(next_permutation(all(ps)));
	return false;
}

vector<pii> solve(vector<int> a_){
	const int n=a_.size();
	vector<pii> a(n);
	rep(i,n) a[i]=pii(a_[i],i);
	vector<pii> ps;
	rep(i,n)reps(j,i+1,n)if(a[i]>a[j]) ps.eb(i,j);
	vector<pii> re;
	auto swapi=
		[&](int i,int j){
			re.eb(i,j);
			swap(a[i],a[j]);
		};
	while(a.size()>1){
		vector<pair<pii,int>> ps;
		rep(i,a.size())if(a[i]>a.back()) ps.eb(a[i],i);
		sort(all(ps));
		for(auto [x,i]:ps) swapi(i,a.size()-1);
		a.pop_back();
	}
	if(ps.size()!=re.size()){
		out(re,1);
		cout<<-1 NL;
		exit(0);
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	if(0){
		rep(_,100000){
			const int n=rand()%100+1;
			vector<int> a(n);
			for(auto &x:a) x=rand()%n;
			// out(a,1);
			// if(!bf(a)){
			// 	out(a,1);
			// 	exit(0);
			// }
			auto re=solve(a);
			assert(check(a,re));
		}
		return 0;
	}
	int n;
	cin>>n;
	vector<int> a(n);
	for(auto &x:a) cin>>x;
	auto re=solve(a);
	cout<<re.size() NL;
	for(auto [a,b]:re) cout<<a+1<<" "<<b+1 NL;
  return 0;
}