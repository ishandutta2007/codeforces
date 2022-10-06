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
using Cost=ll;
using Cap=int;
struct Edge{int to,rev;Cap cap;Cost cost;};
typedef vector<Edge> Edges;
typedef vector<vector<Edge> > Graph;

void add_edge(Graph &g,int from,int to,ll cap,Cost cost=0){
  g[from].pb((Edge){to,(int)g[to].size(),cap,cost});
  g[to].pb((Edge){from,(int)g[from].size()-1,0,-cost});
}
Cost INF=1e9;

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

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,m;
	cin>>n>>m;
	vector<int> p(n),team(n);
	rep(i,n) cin>>p[i];
	rep(i,n) cin>>team[i], --team[i];
	int d;
	cin>>d;
	vector<int> le(d);
	rep(i,d) cin>>le[i], --le[i];
	Graph g(m+5000+2);
	const int S=m+5000;
	const int T=m+5000+1;
	vector<int> ex(n,1);
	for(int x:le) ex[x]=0;
	rep(i,m) add_edge(g,S,i,1);
	rep(i,n)if(ex[i]) add_edge(g,team[i],m+p[i],1);
	vector<int> re(d);
	int ans=0;
	add_edge(g,m,T,1);
	while(max_flow(g,S,T)){
		++ans;
		add_edge(g,m+ans,T,1);
	}
	rrep(i,d){
		re[i]=ans;
		add_edge(g,team[le[i]],m+p[le[i]],1);
		while(max_flow(g,S,T)){
			++ans;
			add_edge(g,m+ans,T,1);
		}
	}
	out(re,1);
	for(auto x:re) cout<<x<<"\n";
  return 0;
}