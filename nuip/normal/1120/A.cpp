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

void no(){
	cout<<-1<<endl;
	exit(0);
}

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,len,m,t;
	cin>>n>>len>>m>>t;
	vector<int> kinds(n);
	rep(i,n) cin>>kinds[i];
	map<int,int> cnt_;
	rep(i,t){
		int b;
		cin>>b;
		++cnt_[b];
	}
	vector<pii> cnt(all(cnt_));
	vv<int> inds(cnt.size());
	{
		vector<int> inv(512345,-1);
		vector<int> rs(cnt.size());
		rep(i,cnt.size()) inv[cnt[i].X]=i;
		rep(i,n)if(inv[kinds[i]]>=0) inds[inv[kinds[i]]].pb(i);
		int r=0;
		rep(i,cnt.size()){
			rs[i]=cnt[i].Y-1;
			if(inds[i].size()<=rs[i]) no();
			MX(r,inds[i][rs[i]]+1);
		}
		out(inds,1);
		rep(l,n)if(r<MOD){
			out(l,r,1);
			int tmp=l/len;
			tmp+=(n-max(r,l+len))/len;
			if(tmp+1>=m){
				MX(r,l+len);
				if(r>n) no();
				out(l,r,tmp,1);
				vector<int> usd(n);
				int rem=m-1;
				for(int i=0;i+len<=l;i+=len){
					if(rem<=0) break;
					--rem;
					rep(j,len) usd[i+j]=1;
				}
				for(int i=max(r,l+len);i+len<=n;i+=len){
					if(rem<=0) break;
					--rem;
					rep(j,len) usd[i+j]=1;
				}
				if(rem>0) rep(_,MOD) cout<<"!";
				rem=len;
				reps(i,l,r)if(inv[kinds[i]]>=0){
					if(cnt[inv[kinds[i]]].Y){
						--cnt[inv[kinds[i]]].Y;
						usd[i]=1;
						--rem;
					}
				}
				reps(i,l,r)if(!usd[i] && rem){
					usd[i]=1; --rem;
				}
				if(rem) rep(_,MOD) cout<<"!";
				cout<<n-accumulate(all(usd),0) NL;
				rep(i,n)if(!usd[i]) cout<<i+1<<" "; cout NL;
				return 0;
			}
			int j=inv[kinds[l]];
			if(j>=0){
				++rs[j];
				out(j,rs,1);
				if(inds[j].size()<=rs[j]) no();
				MX(r,inds[j][rs[j]]+1);
			}
		}
	}
	cout<<-1 NL;
	// vector<int> lbs{0};
	// for(int i=0;i<n;){
	// 	out(i,1);
	// 	int nxt=i;
	// 	rep(j,cnt.size())if(nxt<MOD){
	// 		auto it=lower_bound(all(inds[j]),i);
	// 		if(it==inds[j].end()){ nxt=MOD; break;}
	// 		int rem=cnt[j].Y-1;
	// 		while(rem--){
	// 			++it;
	// 			if(it==inds[j].end()){ nxt=MOD; break;}
	// 		}
	// 		if(nxt==MOD) break;
	// 		MX(nxt,*it+1);
	// 	}
	// 	out(nxt,1);
	// 	if(nxt<=n){
	// 		lbs.pb(nxt);
	// 	}
	// 	i=nxt;
	// }
	// out(lbs,1);
  return 0;
}