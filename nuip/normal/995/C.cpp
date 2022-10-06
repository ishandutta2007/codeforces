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

const int SMALL=20;
using P=complex<double>;

void solve(vector<P> ps){
	auto PS=ps;
	int n=ps.size();
		vector<int> par(n,-1);
	vector<int> ind(n); iota(all(ind),0);
	while(ind.size()>SMALL){
		int n=ind.size();
		while(1){
			int x=(1ll*rand()*RAND_MAX+rand())%n;
			swap(ind[x],ind[n-1]);
			int y=(1ll*rand()*RAND_MAX+rand())%(n-1);
			swap(ind[y],ind[n-2]);
			if(abs(ps[ind[n-2]]-ps[ind[n-1]])<1e6) break;
		}
		ps[ind[n-2]]-=ps[ind[n-1]];
		par[ind[n-1]]=ind[n-2];
		ind.pop_back();
	}
	out(ps,ind,par,1);
	vector<int> re(n);
	int m=ind.size();
	rep(i,m) par[ind[i]]=-i-1;
	rep(i,1<<m){
		P p(0,0);
		rep(j,m){
			if(i>>j&1){
				p+=ps[ind[j]];
			}else{
				p-=ps[ind[j]];
			}
		}
		if(abs(p)<1.5e6){
			function<int(int)> dfs=[&](int v){
															 if(re[v]) return re[v];
															 if(par[v]<0) re[v]=(i>>(-par[v]-1)&1)?1:-1;
															 else re[v]=-dfs(par[v]);
															 return re[v];
														 };
			rep(i,n) dfs(i);
			out(re,1);
			rep(v,n)if(par[v]>=0) assert(re[v]*re[par[v]]<0);
			P pp(0,0);
			rep(i,n){
				if(re[i]>0) pp+=PS[i];
				else pp-=PS[i];
			}
			if(abs(pp)<1.5e6){
				rep(i,n) cout<<re[i]<<" ";cout<<endl;
			}else{
				cout<<pp<<endl;
				cout<<abs(pp)<<endl;
				cout<<p<<endl;
				cout<<abs(p)<<endl;
				cout<<pp-p<<endl;
				//rep(i,n) cout<<re[i]<<" ";cout<<endl;
				exit(1);
			}
			return;
		}
	}

}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	// rep(_,100){
	// 	int n=100000;
	// 	vector<P> ps;
	// 	while(ps.size()<n){
	// 		P p((1ll*rand()*RAND_MAX+rand())%2000000-1000000,(1ll*rand()*RAND_MAX+rand())%2000000-1000000);
	// 		if(abs(p)<1e6) ps.pb(p);
	// 	}
	// 	solve(ps);
	// }
	// return 0;
	srand(time(0));
	int n;
	cin>>n;
	vector<P> ps;
	rep(i,n){
		int a,b;
		cin>>a>>b;
		ps.eb(a,b);
	}
	solve(ps);
  return 0;
}