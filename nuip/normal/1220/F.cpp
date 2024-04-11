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
#include "../benri.h"
#else
#define out(args...)
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7; //998244353

template<class T> class RMQ{
  vv<T> vals;
public:
  inline T get(int l,int r){//[l,r]
    if(l==r)return vals[0][l];
    const int d=31-__builtin_clz(l^r); //left-most distinct bit
    return min(vals[d][l],vals[d][r]);
  }
  RMQ(const vector<T> &v,T e=MOD){
    int n=v.size();
    int d=1,N=2;
    while(N<n) N*=2, ++d;
    vals.resize(d,vector<T>(N,e));
    rep(i,n) vals[0][i]=v[i];
    reps(i,1,d)rep(j,N){
      const int b=(j>>i|1)<<i;
      vals[i][j]=j>>i&1?get(b,j):get(j,b-1);
    }
  }
};

const int N=(1<<18);

struct Seg{
	int ad,mx;
  Seg(int v=0):ad(0),mx(v){
  }
  static Seg e;
};
Seg Seg::e=Seg();
// ostream& operator<<(ostream &os, const Seg &t) { return os<<"("<<t.h<<","<<t.q<<","<<t.r<<")";}
Seg seg[2*N+10];
Seg operator+(const Seg &l,const Seg &r){
  return Seg(max(l.mx,r.mx));
}
inline void lazy_eval(int k,int a,int b){
  if(!seg[k].ad)return;
	seg[k].mx+=seg[k].ad;
  if(2*k<=2*N+5){
    seg[2*k+1].ad+=seg[k].ad;
    seg[2*k+2].ad+=seg[k].ad;
  }
  seg[k].ad=0;
}

inline void upd_node(int k){seg[k]=seg[2*k+1]+seg[2*k+2];}

void upd(int l,int r,int ad,Seg seg[]=seg,int k=0,int a=0,int b=N){
  //cout<<"update:"<<l<<","<<r<<","<<x<<","<<d<<","<<a<<","<<b<<endl;
  lazy_eval(k,a,b);
  if(b<=l || r<=a) return; 
  if(l<=a && b<=r){
    seg[k].ad+=ad;
    lazy_eval(k,a,b);
    return;
  }	
  int m=(a+b)/2;
  upd(l,r,ad,seg,2*k+1,a,m);
  upd(l,r,ad,seg,2*k+2,m,b);
  upd_node(k);
}

Seg query(int l,int r,Seg seg[]=::seg,int k=0,int a=0,int b=N){
  lazy_eval(k,a,b);
  if(b<=l || r<=a)return Seg::e; 
  if(l<=a && b<=r){return seg[k];}
  
  int m=(a+b)/2;
  Seg vl=query(l,r,seg,2*k+1,a,m);
  Seg vr=query(l,r,seg,2*k+2,m,b);
  upd_node(k);
  //cout<<a<<","<<b<<":"<<vl<<","<<vr<<endl;
  return vl+vr;
}

void solve(vector<int> &re,const vector<int> &a){
	int n=a.size();
	vector<pii> pa(n); rep(i,n) pa[i]=pii(a[i],i);
	RMQ<pii> rmq(pa,pii(MOD,-1));
	vector<pii> rng(n);
	{
		queue<pii> que; que.emplace(0,n-1);
		while(que.size()){
			int l,r;
			tie(l,r)=que.front(); que.pop();
			if(l>r) continue;
			// out(l,r,1);
			int v=rmq.get(l,r).Y;
			rng[v]=pii(l,r);
			que.emplace(l,v-1);
			que.emplace(v+1,r);
		}
	}
	// out(a,rng,1);
	fill(seg,seg+N-1+n,Seg());
	re.resize(n+1);
	rep(i,n){
		// upd(rng[i].X,i,1);
		// upd(i+1,rng[i].Y+1,1);
		upd(rng[i].X,rng[i].Y+1,1);
		re[i+1]=query(0,N).mx;
	}
}

pii solve(vector<int> a){
	int n=a.size();
	rep(i,n) a.pb(a[i]);
	vector<int> L,R;
	// out(a,1);
	int one;
	rep(i,n)if(a[i]==1){
		one=i;
		reps(j,1,n) R.pb(a[i+j]);
		break;
	}
	rrep(i,2*n)if(a[i]==1){
		reps(j,1,n) L.pb(a[i-j]);
		break;
	}
	vector<int> rel,rer;
	solve(rel,L);
	solve(rer,R);
	int re=MOD;
	int k;
	// out(rel,rer,1);
	rep(i,n)if(MN(re,1+max(rel[i],rer[n-1-i]))){
		// out(re,one,i,1);
		k=(n+one-i)%n;
	}
	return pii(re,k);
}

int get(vector<int> a){
	function<int(int,int)> dfs=
		[&](int l,int r){
			if(r<l) return 0;
			int mn=MOD,mni;
			reps(i,l,r+1)if(MN(mn,a[i])) mni=i;
			return max(dfs(l,mni-1),dfs(mni+1,r))+1;
		};
	return dfs(0,a.size()-1);
}
pii bf(vector<int> a){
	pii re(MOD,0);
	int n=a.size();
	rep(i,n){
		int tmp=get(a);
		MN(re.X,tmp);
		if(re.X==tmp) re.Y=i;
		a.pb(a[0]);
		a.erase(a.begin());
	}
	return re;
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	if(0){
		int n=10;
		vector<int> a(n); iota(all(a),1);
		rep(_,100){
			random_shuffle(all(a));
			pii ans=bf(a);
			pii re=solve(a);
			if(ans.X!=re.X){
				out(a,ans,re,1);
				return 0;
			}
		}
	}
	int n;
	cin>>n;
	vector<int> a(n);
	rep(i,n) cin>>a[i];
	int re,k;
	tie(re,k)=solve(a);
	cout<<re<<" "<<k<<endl;
	out(bf(a),1);
  return 0;
}