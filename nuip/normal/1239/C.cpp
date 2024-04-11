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

const ll INF=2e18;

int main(){
  ios_base::sync_with_stdio(false); cin.tie(0);
  cout<<fixed<<setprecision(0);
	int n,p;
	cin>>n>>p;
	vector<ll> ts(n);
	rep(i,n) cin>>ts[i];
	vector<pll> ps{{INF,-1}}; ps.reserve(n+1);
	rep(i,n) ps.eb(ts[i],i);
	sort(rall(ps));
	ll cur=0;
	priority_queue<int,vector<int>,greater<int>> wait;
	set<ll> event(all(ts));
	queue<int> que;
	vector<ll> re(n,INF);
	while(event.size()){
		ll t=*event.begin(); event.erase(event.begin());
		out(t,1);
		while(ps.back().X<=t){
			wait.emplace(ps.back().Y); ps.pop_back();
		}
		out(2,1);
		while(que.size() && re[que.front()]<=t) que.pop();
		out(3,1);
		while(wait.size()){
			out(wait.size(),que,1);
			if(que.empty() || que.back()>wait.top()){
				int id=wait.top(); wait.pop();
				re[id]=(que.size()?re[que.back()]:t)+p;
				event.emplace(re[id]);
				que.push(id);
			}else{
				break;
			}
		}
	}
	for(ll t:re) cout<<t<<" "; cout NL;
  return 0;
}