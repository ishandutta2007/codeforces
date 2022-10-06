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

vector<int> inv[2222][2222];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n,m,e;
	cin>>n>>m>>e;
	//n=m=1; e=2000;
	Graph g(n+m+2);
	rep(i,n) add_edge(g,n+m,i,1);
	rep(i,m) add_edge(g,n+i,n+m+1,1);
	vector<int> deg(n+m);
	vector<pii> es;
	vector<set<int>> led(n),red(m);
	rep(i,e){
		int a=0,b=0;
		cin>>a>>b; --a; --b;
		++deg[a]; ++deg[n+b];
		inv[a][b].pb(i);
		es.eb(a,b);
		led[a].insert(i);
		red[b].insert(i);
		add_edge(g,a,n+b,1);
	}
	int D=*min_element(all(deg));
	cout<<"0\n";
	rep(i,D){
		max_flow(g,n+m,n+m+1);
		//out(max_flow(g,n+m,n+m+1),1);
		vector<int> re;
		vector<int> L(n),R(m);
		auto add=[&](int e){
			re.pb(e);
			++L[es[e].X];
			++R[es[e].Y];
			led[es[e].X].erase(e);
			red[es[e].Y].erase(e);
			//out(e,L,es[e],1);
		};
		rep(x,n)for(auto e:g[x])if(e.cap==0){
				int y=e.to-n;
				// out(x,y,1);
				if(y>=0 && y<m){
					add(inv[x][y].back());
					inv[x][y].pop_back();
				}
			}
		out(2,1);
		rep(x,n)while(L[x]<i+1)	add(*led[x].begin());
		out(3,1);
		rep(y,m)while(R[y]<i+1)	add(*red[y].begin());
		cout<<re.size();
		for(int x:re) cout<<" "<<x+1;
		cout<<endl;
		for(int e:re){
			int x,y;
			tie(x,y)=es[e];
			inv[x][y].pb(e);
			led[x].insert(e);
			red[y].insert(e);
		}
		for(auto &e:g[n+m]) ++e.cap;
		rep(i,n) --g[i][0].cap;
		for(auto &e:g[n+m+1]) --e.cap;
		rep(i,m) ++g[n+i][0].cap;
	}
  return 0;

}