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

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#include<ext/pb_ds/tag_and_trait.hpp>
using namespace __gnu_pbds;
// fast unordered_map
// gp_hash_table<int,int>
template<class T> using SET=tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;

const int nn=212345;
ll bit[nn+1];

ll sum(int i){ ++i;
  ll s=0;
  while(i>0){
    s+=bit[i];
    i-=i&-i;
  }
  return s;
}

void add(int i,ll x){ ++i;
  while(i<=nn){
    bit[i]+=x;
    i+=i&-i;
  }
}

ll solve(vector<int> p,int t){
	int n=p.size();
	queue<int> que;
	int cur=-n-10;
	rep(_,(n-t)/2) que.emplace(cur++);
	cur=n+10;
	rep(_,(n-t+1)/2) que.emplace(cur++);
	for(auto &x:p)if(x>=t){
			x=que.front(); que.pop();
		}
	
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<int> p(n);
	rep(i,n) cin>>p[i], --p[i];
	vector<int> inv(n);
	rep(i,n) inv[p[i]]=i;
	vector<ll> re(n);

	{
		rep(i,n){
			if(i) re[i]+=re[i-1];
			re[i]+=i-sum(inv[i]);
			add(inv[i],1);
		}
		out(re,1);
	}

	fill(bit,bit+nn+1,0);
	int c=inv[0];
	SET<int> inds; inds.insert(c);
	rep(i,n)if(i!=c) add(i,1);
	ll cur=0;
	int lc=0,rc=0;
	reps(i,1,n){
		add(inv[i],-1);
		inds.insert(inv[i]);
		int tmp=inds.order_of_key(inv[i]);
		cur-=min(tmp,i-tmp);
		if(inv[i]<c){
			cur+=sum(c)-sum(inv[i]);
			++lc;
		}else{
			cur+=sum(inv[i])-sum(c);
			++rc;
		}
		while(lc+1<=rc-1){
			++lc; --rc;
			int tmp=*inds.upper_bound(c);
			cur-=sum(tmp)-sum(c);
			c=tmp;
		}
		while(lc-1>=rc+1){
			--lc; ++rc;
			auto it=inds.lower_bound(c);
			--it;
			int tmp=*it;
			cur-=sum(c)-sum(tmp);
			c=tmp;
		}
		re[i]+=cur;
	}
	out(re,1);
	for(auto x:re) cout<<x<<" ";
  return 0;
}