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

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef _DEBUG
#ifdef _DEBUG
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
const ll MOD=1e9+7;

struct UF{
  vector<int> data;
  UF(int size):data(size,-1){}
  bool unite(int x,int y){
    x=root(x); y=root(y);
    if(x!=y){
      if(data[y]<data[x]) swap(x,y);
      data[x]+=data[y]; data[y]=x;
    }
    return x!=y;
  }
  bool findSet(int x,int y){return root(x)==root(y);}
  int root(int x){return data[x]<0?x:data[x]=root(data[x]);}
  int size(int x) {return -data[root(x)];}
};


#include<chrono>
#define TIME (duration_cast<milliseconds>(system_clock::now()-starttime).count())
using namespace chrono;
system_clock::time_point starttime = system_clock::now();

ll modpow(ll r,ll n,ll m=MOD){
  ll re=1,d=r%m;
  if(n<0)(n%=m-1)+=m-1;
  for(;n;n/=2){
    if(n&1)(re*=d)%=m;
    (d*=d)%=m;
  }
  return re;
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<string> mp(n);
	rep(i,n) cin>>mp[i];
	{
		int f=1;
		rep(i,n)rep(j,n)if(mp[i][j]=='A') f=0;
		if(f){
			cout<<n-1<<endl;
			return 0;
		}
	}
	UF uf(n);
	rep(i,n)rep(j,n)if(mp[i][j]=='A') uf.unite(i,j);
	int ng=0;
	rep(i,n)rep(j,n)if(mp[i][j]=='X' && uf.findSet(i,j)) ng=1;
	if(ng){
		cout<<-1<<endl;
		return 0;
	}
	vector<int> ids;
	rep(i,n)if(uf.root(i)==i && uf.size(i)>1) ids.pb(i);
	vector<int> inv(n,-1);
	int m=ids.size();
	rep(i,m) inv[ids[i]]=i;
	vv<int> g(m);
	rep(i,n)rep(j,n)if(mp[i][j]=='X'){
		int x=inv[uf.root(i)];
		int y=inv[uf.root(j)];
		if(x>=0 && y>=0){
			g[x].pb(y);
			g[y].pb(x);
		}
	}
	rep(i,m){
		sort(all(g[i]));
		UNIQUE(g[i]);
	}
	vector<ll> cv(1<<m);
	cv[0]=1;
	reps(i,1,1<<m){
		int k;
		rep(j,m)if(i>>j&1){ k=j; break;}
		if(!cv[i^(1<<k)]) continue;
		int ng=0;
		for(int j:g[k])if(i>>j&1){ ng=1; break;}
		if(!ng) cv[i]=1;
	}
	out(g,cv,1);
	rep(j,m)rep(i,1<<m)if(i>>j&1) cv[i]+=cv[i^(1<<j)];
	vector<ll> prod(1<<m,1);
	vector<int> ad(1<<m);
	rep(i,1<<m) ad[i]=__builtin_popcount(i)%2==m%2;
	rep(re,m+1){
		ll tmp=0;
		rep(i,1<<m)if(ad[i]){
			tmp+=prod[i];
		}else{
			tmp-=prod[i];
		}
		if(tmp%MOD){
			cout<<n+re-1<<endl;
			return 0;
		}
		rep(i,1<<m) (prod[i]*=cv[i])%=MOD;
	}
  return 0;
}