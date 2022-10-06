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
template<class T> ostream& operator<<(ostream &os, const deque<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class T,size_t n> ostream& operator<<(ostream &os, const array<T,n> &t) {
	os<<"{"; rep(i,n) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class S, class T,class U> ostream& operator<<(ostream &os, const tuple<S,T,U> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<")";}
template<class S, class T,class U,class V> ostream& operator<<(ostream &os, const tuple<S,T,U,V> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<")";}
template<class S, class T,class U,class V,class W> ostream& operator<<(ostream &os, const tuple<S,T,U,V,W> &t) { return os<<"("<<get<0>(t)<<","<<get<1>(t)<<","<<get<2>(t)<<","<<get<3>(t)<<","<<get<4>(t)<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
//#undef NUIP
#ifdef NUIP
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
#else
#define out
#endif
#ifdef __cpp_init_captures
template<typename T>vector<T> table(int n, T v){ return vector<T>(n, v);}
template <class... Args> auto table(int n, Args... args){auto val = table(args...); return vector<decltype(val)>(n, move(val));}
#endif
const ll MOD=1e9+7;

void no(){
	cout<<"No"<<endl;
	exit(0);
}

ll fun(ll n){
	return n*(n+1)/2;
}

pll low(ll n,ll d){
		ll ub=1;
		ll rem=n;
		ll sum=0;
		reps(i,1,MOD){
			ll t=min(rem,ub);
			rem-=t;
			sum+=i*t;
			if(!rem) return pll(sum,i);
			ub*=d;
		}
}

ll calc(vector<int> par){
	int n=par.size();
	vv<int> g(n);
	reps(i,1,n) g[par[i]].pb(i);
	ll re=0;
	function<void(int,int)> dfs=
		[&](int v,int h){
			re+=h;
			for(int w:g[v]) dfs(w,h+1);
		};
	dfs(0,1);
	return re;
}

int solve(ll n,ll s){
	out(fun(n),1);
		if(fun(n)==s){
		cout<<"Yes"<<endl;
		rep(i,n-1) cout<<i+1<<" \n"[i+1==n-1];
		return 0;
	}
	out(low(n,2),1);
	int l=1,r=n;
	while(r-l>1){
		int d=(l+r)/2;
		(s>=low(n,d).X?r:l)=d;
	}
	out(l,r,1);
	if(r==n) no();
	const int d=r;
	out(2*(d-1)+fun(n-(d-1)),1);
	// if(2*(d-1)+fun(n-(d-1))<s) return 0;//no();
	reps(i,2,n+1){
		ll sum,h;
		tie(sum,h)=low(i,d);
		out(sum,h,1);
		ll rem=n-i;
		sum+=h*rem;
		sum+=fun(rem);
		if(sum<=s){
			vector<int> par(n);
			reps(j,1,i) par[j]=(j-1)/d;
			vector<int> ad(n);
			ad[0]=par[i-1];
			int prv=i-2;
			int cnt=0;
			reps(j,i,n){
				++cnt;
				ad[cnt]=prv;
				par[j]=prv;
				prv=j;
			}
			out(par,calc(par),1);
			if(s-sum>=n) no();
			par[i-1]=ad[s-sum];
			if(s!=calc(par)) no(); //return 1;
			cout<<"Yes"<<endl;
			// cout<<r<<endl;
			reps(i,1,n) cout<<par[i]+1<<" ";cout<<endl;
			out(i,s,sum,calc(par),1);
			return 0;
		}
	}
	no();
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	ll n,s;
	cin>>n>>s;
	solve(n,s);
	// cout<<solve(99, 4949)<<endl;	// 
	return 0;
	assert(!solve(99, 4949));
	rep(_,100000) assert(!solve(rand(),rand()));
  return 0;
}