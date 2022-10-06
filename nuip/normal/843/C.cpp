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
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
template<class T> inline bool MX(T &l,const T &r){return l<r?l=r,1:0;}
template<class T> inline bool MN(T &l,const T &r){return l>r?l=r,1:0;}
#define out(args...){vector<string> a_r_g_s=s_p_l_i_t(#args, ','); e_r_r(a_r_g_s.begin(), args); }
vector<string> s_p_l_i_t(const string &s, char c){vector<string> v;int d=0,f=0;string t;for(char c:s){if(!d&&c==',')v.pb(t),t="";else t+=c;if(c=='\"'||c=='\'')f^=1;if(!f&&c=='(')++d;if(!f&&c==')')--d;}v.pb(t);return move(v);}
void e_r_r(vector<string>::iterator it) {}
template<typename T, typename... Args> void e_r_r(vector<string>::iterator it, T a, Args... args){ if(*it==" 1"||*it=="1") cerr<<endl; else cerr << it -> substr((*it)[0] == ' ', it -> length()) << " = " << a << ", "; e_r_r(++it, args...);}
const ll MOD=1e9+7;

struct sepDec:public vector<int>{
  struct Rec {
    int root, count, par;
    explicit Rec(int r = 0, int c = 0, int p = 0):root(r), count(c), par(p){}
  };
  struct DFS {
    int u, i, p;
    explicit DFS(int ver = 0, int ind = 0, int pa = 0): u(ver), i(ind), p(pa) {}
  };
  vector<int> dep,par;
  const int n;
  
  void sep_dec(const vv<int> &conn){
    vector<bool> picked(n);
    vector<int> cnt(n); //num_children
    stack<Rec> recs;
    recs.emplace(0, n, -1);
    while(!recs.empty()){
      const Rec rf = recs.top();
      const int lb = rf.count / 2;
      recs.pop();
      int sep = rf.root;
      stack<DFS> dfss;
      dfss.emplace(rf.root, 0, rf.root);
      while(!dfss.empty()){
	DFS df = dfss.top();
	dfss.pop();
	if(df.i >= conn[df.u].size()){
	  cnt[df.u] = 1;
	  for(const int &v:conn[df.u]){
	    if(picked[v] || v == df.p) continue;
  	    cnt[df.u] += cnt[v];
	  }
	  if(cnt[df.u] > lb){
	    sep = df.u;
	    cnt[df.p] = rf.count - cnt[df.u];
	    break;
	  }
	}else{
	  dfss.emplace(df.u, df.i + 1, df.p);
	  const int v = conn[df.u][df.i];
	  if(!picked[v] && v != df.p){
	    dfss.emplace(v, 0, df.u);
	  }
	}
      }
      par[sep] = (rf.par < 0 ? sep : rf.par);
      picked[sep] = true;
      for(const int &v:conn[sep])if(!picked[v])	recs.emplace(v, cnt[v], sep);
    }
  }
  
  int dfs(int v){ return dep[v]>=0?dep[v]:dep[v]=(par[v]==v?v:dfs(par[v])+1);}

  sepDec(const vv<int> &g):n(g.size()){
    dep.resize(n,-1); par.resize(n);
    sep_dec(g);
    resize(n);
    rep(i,n)if(dep[i]<0) dfs(i);
    iota(all(*this),0);
    sort(all(*this),[&](int i,int j){return dep[i]>dep[j];});
  }
};
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


int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vv<int> g(n);
	rep(i,n-1){
		int x,y;
		cin>>x>>y; --x; --y;
		g[x].pb(y);
		g[y].pb(x);
	}
	sepDec sd(g);
	int V=sd.back(),W=-1;
	{
		UF uf(n);
		rep(i,n)if(V!=i)for(int v:g[i])if(v!=V) uf.unite(i,v);
		for(int v:g[V])if(uf.size(v)*2>=n) W=v;
	}
	//out(V,W,1);

	vector<tuple<int,int,int>> re;
	int pt;
	function<void(int,int,int,int)> dfs=[&](int v,int p,int r,int V){
		re.eb(V,pt,v); pt=v;
		re.eb(v,p,r);
		for(int w:g[v])if(w!=p) dfs(w,v,r,V);
	};
	auto fun=[&](int r,int V){
		pt=r;
		for(int v:g[r])if(v!=V) dfs(v,r,r,V);
		re.eb(V,pt,r); pt=r;
	};
	for(int r:g[V])if(r!=W) fun(r,V);
	if(W>=0)for(int r:g[W])if(r!=V) fun(r,W);
	cout<<re.size()<<endl;
	rep(i,re.size()){
		int a,b,c;
		tie(a,b,c)=re[i];
		cout<<a+1<<" "<<b+1<<" "<<c+1<<"\n";
	}
  return 0;
}