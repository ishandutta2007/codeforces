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

int re[1123][1123];

bool solve(vector<int> a){
	const int n=a.size();
	vector<pii> ps;
	rep(i,n) ps.eb(min(a[i],n+1-a[i]),i);
	sort(all(ps));
	out(ps,1);
	vv<int> seqs(1,vector<int>(n+1)); iota(all(seqs[0]),0);
	vector<int> fr;
	for(auto p:ps){
		rep(i,n+1) re[i][p.Y]=(a[p.Y]!=p.X);
		int m=seqs.size();
		vv<int> ad(m);
		int rem=p.X;
		out(p,seqs,ad,rem,1);
		{
			int t=min(rem,m);
			rep(i,m){
				ad[i].pb(seqs[i].back()); seqs[i].pop_back();
			}
			rem-=t;
		}
		out(p,seqs,ad,rem,1);
		rep(i,m){
			int t=min(rem,((int)seqs[i].size()+2)/2-1);
			rep(_,t){
				ad[i].pb(seqs[i].back()); seqs[i].pop_back();
			}
			rem-=t;
		}
		out(p,seqs,ad,rem,1);
		assert(rem<=fr.size());
		rep(i,rem) re[fr[i]][p.Y]=(a[p.Y]==p.X);
		for(auto &v:ad){
			for(int x:v) re[x][p.Y]=(a[p.Y]==p.X);
			seqs.pb(v);
		}
		sort(rall(seqs),[&](auto &l,auto &r){ return l.size()<r.size();});
		while(seqs.size() && seqs.back().size()<=1){
			if(seqs.back().size()) fr.pb(seqs.back()[0]);
			seqs.pop_back();
		}
	}
	return seqs.empty();
}

int main(){
	if(0){
		int n=rand()%100+1;
		vector<int> a(n); rep(i,n) a[i]=rand()%n+1;
		fill(re[0],re[n],0);
		if(!solve(a)){
			out(a,1);
			exit(0);
		}
		out(2,1);
		return 0;
	}
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	solve(a);
	int cnt=0;
	rep(i,n+1)if(accumulate(re[i],re[i+1],0)) ++cnt;
	cout<<cnt<<endl;
	rep(i,n+1)if(accumulate(re[i],re[i+1],0)){rep(j,n) cout<<re[i][j];cout NL;}
  return 0;
}