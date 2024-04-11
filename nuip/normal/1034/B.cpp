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

using Cost=ll;
using Cap=ll;
struct Edge{int to,rev;Cap cap;Cost cost;};
typedef vector<Edge> Edges;
typedef vector<vector<Edge> > Graph;

void add_edge(Graph &g,int from,int to,ll cap,Cost cost=0){
  g[from].pb((Edge){to,(int)g[to].size(),cap,cost});
  g[to].pb((Edge){from,(int)g[from].size()-1,0,-cost});
}
Cost INF=2e11;

//max_flow

vector<int> used;

Cap dfs(Graph &g,int v,int t,Cap f){
  if(v==t) return f;
  used[v]=1;
  Cap re=0;
	rep(i,g[v].size()){
    Edge &e=g[v][i];
    if(e.cap<=0||used[e.to])continue;
    Cap d=dfs(g,e.to,t,min(f,e.cap));
    if(d>0){
      e.cap-=d;
      g[e.to][e.rev].cap+=d;
      return d;
    }
  }
  return 0;
}

Cap max_flow(Graph &g,int s,int t){
  Cap sum=0,f;
	int V=g.size();
  while(1){
    used.resize(V);
    fill(all(used),0);
    sum+=f=dfs(g,s,t,INF);
    if(!f) return sum;
  }
}

int solve(int n,int m){
	auto fun=[&](int x,int y){ return y*m+x;};
	Graph g(n*m+2);
	rep(y,n)rep(x,m){
		if(x%2==y%2){
			add_edge(g,n*m,fun(x,y),1);
		}else{
			add_edge(g,fun(x,y),n*m+1,1);
		}
	}
	rep(y,n)rep(x,m)if(x%2==y%2){
		rep(Y,n)rep(X,m)if(abs(x-X)+abs(y-Y)==3){
			add_edge(g,fun(x,y),fun(X,Y),1);
		}
	}
	return max_flow(g,n*m,n*m+1);
}

ll unko(ll n,ll m){
	if(n>m) swap(n,m);
	if(m<10) return solve(n,m);
	if(n==1){
		ll d=max(0ll,m-10+5)/6;
		return solve(n,m-d*6)+3*d;
	}
	if(n==2) return m;
	if(n==3){
		ll d=max(0ll,m-10+1)/2;
		return solve(n,m-d*2)+3*d;
	}
	if(n>=4){
		ll re=8;
		re+=(n-4)/2*4;
		re+=(m-4)/2*(n/2*2);
		if(n%2) re+=m/2;
		if(m%2) re+=n/2;
		return re;
	}
}

int re[300][300];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	ll n,m;
	cin>>n>>m;
	cout<<unko(n,m)*2<<endl;
	return 0;
	rep(i,30)rep(j,30) re[i+1][j+1]=solve(i+1,j+1);
  // rep(i,30){ rep(j,30) printf("%d%d, ",
	// 														(re[i+1][j+1]+j+1==re[i+2][j+1]),
	// 														(re[i+1][j+1]+i+1==re[i+1][j+2])); puts("");}
  // rep(i,30){ rep(j,30) printf("%3d, ",re[i+1][j+1]-re[i+1][j]); puts("");}
	// reps(i,1,30){reps(j,1,31) printf("%3d, ",re[i][j]==(i+(i%2!=j%2))/2+re[i][j-1]); puts("");}
  // rep(i,10){ rep(j,10) printf("%3d, ",re[4+i*2][4+j*2]-re[4][4]); puts("");}
	reps(i,1,30){reps(j,1,31) printf("%3d, ",(re[i][j]==unko(i,j))); puts("");}

	reps(i,1,50)reps(j,1,50) assert(solve(i,j)==unko(i,j));
  return 0;
}