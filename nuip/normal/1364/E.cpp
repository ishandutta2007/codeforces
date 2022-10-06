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
#undef NUIP
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

void exp2(){
	int mx=0;
	rep(_,1-000){
		vector<int> p(2048); iota(all(p),0); random_shuffle(all(p));
		int a=0,b=1,cur=p[a]|p[b];
		int cnt=1;
		auto sub=[](int a,int b){ return (a|b)==b;};
		reps(i,2,2048){
			++cnt;
			if(sub(p[a]|p[i],cur)){ b=i; cur=p[a]|p[i]; continue;}
			++cnt;
			if(sub(p[b]|p[i],cur)){ a=i; cur=p[b]|p[i]; continue;}
		}
		out(cur,__builtin_popcount(cur),1);
	}
	out(mx,1);
}
void exp4(){
	int mx=0;
	rep(_,100000){
		vector<int> p(2048); iota(all(p),0); random_shuffle(all(p));
		rep(i,2048)rep(j,i)if((p[i]&p[j])==0){
			MX(mx,i+1);
			i=j=2048;
			break;
		}
	}
	out(mx,1);
}

pii get(int n,int a=-1){
	if(a<0) a=rand()%n;
	int b=rand()%(n-1);
	if(b>=a) ++b;
	return pii(a,b);
}
void exp(){
	int mx=0;
	rep(_,10000){
		int cnt=1;
		auto [a,b]=get(2048);
		while(__builtin_popcount(a|b)>1){
			++cnt;
			auto c=get(2048,a).Y;
			while(c==b) c=get(2048,a).Y;
			if(__builtin_popcount(a|c)<__builtin_popcount(a|b)){ b=c; continue;}
			++cnt;
			if(__builtin_popcount(b|c)<__builtin_popcount(a|b)){ a=c; continue;}
		}
		MX(mx,cnt);
	}
	out(mx,1);
}
void exp3(){
	int mx=0;
	rep(_,10000){
		int mn=MOD;
		rep(_,100){
			auto [a,b]=get(2048);
			MN(mn,__builtin_popcount(a|b));
		}
		MX(mx,mn);
	}
	out(mx,1);
}

vector<int> secret;
int count_=0;
map<pii,int> memo;
vector<int> ind;
int ask(int i,int j){
	i=ind[i];
	j=ind[j];
	if(i>j) swap(i,j);
	if(memo.count(pii(i,j))) return memo[pii(i,j)];
	++count_;
#ifdef NUIP
	return secret[i]|secret[j];
#endif
	cout<<"? "<<i+1<<" "<<j+1 NL; cout.flush();
	int x;
	cin>>x;
	if(x<0) exit(0);
	return memo[pii(i,j)]=x;
}

vector<int> solve(int n){
	memo.clear();
	count_=0;
	mt19937 rand(time(0));
	ind.resize(n); iota(all(ind),0);
	shuffle(all(ind),rand);
	vector<int> vals(n);
	int a=-1,b;
	rep(i,n){
		vals[i]=2047;
		rep(_,4){
			int t=rand()%n;
			while(t==i) t=rand()%n;
			vals[i]&=ask(i,t);
		}
		rep(j,i)if((vals[i]&vals[j])==0){
			a=i; b=j;
			break;
		}
		if(a>=0) break;
	}
	vector<int> re(n);
	vector<int> usd(n);
	rep(i,n)if(i!=a && i!=b){
		re[i]|=ask(i,a)&~vals[a];
		re[i]|=ask(i,b)&~vals[b];
		usd[re[i]]=1;
	}
	rep(i,n)if(!usd[i]){
		if((i|vals[a])==vals[a]) re[a]=i;
		else re[b]=i;
	}
	if(count_>4269){
		out(count_,1);
		exit(0);
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	// exp4(); return 0;
	int n;
	cin>>n;
	mt19937 rand(time(0));
#ifdef NUIP
	secret.resize(n);
	iota(all(secret),0); shuffle(all(secret),rand);
	// secret={1,0,2};
#endif
	auto re=solve(n);
	vector<int> res(n);
	rep(i,n) res[ind[i]]=re[i];
	cout<<"!";
	for(int x:res) cout<<" "<<x;
	cout NL;
	 cout.flush();
#ifdef NUIP
	assert(re==secret);
#endif
  return 0;
}