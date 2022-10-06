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
typedef vv<int> Graph;
struct Scc{
  stack<int> S;
  vector<int> inS,low,num;
  int time=0;
public:
  Graph dag;
  vector<int> inv;
  vv<int> scc;
  void visit(const Graph &g, int v){
    low[v] = num[v] = ++time;
    S.push(v); inS[v]=1;
    for(const int  &w:g[v]){
      if(!num[w]){
				visit(g,w);
				low[v]=min(low[v],low[w]);
      }else if(inS[w]) low[v]=min(low[v],num[w]);
    }
    if(low[v]==num[v]){
      scc.eb();
      while(1){
				int w = S.top(); S.pop(); inS[w]=0;
				scc.back().pb(w);
				if(v==w) break;
      }
    }
  }
  Scc(const Graph &g) {
    const int n = g.size();
    num.resize(n); low.resize(n); inS.resize(n);
    rep(u,n)if(!num[u]) visit(g,u);
    reverse(all(scc));
    
    inv.resize(n); dag.resize(scc.size());
    rep(i,scc.size())for(auto v:scc[i]) inv[v]=i;
    rep(i,scc.size())for(auto v:scc[i])for(auto e:g[v])
			if(inv[e]!=i)	dag[i].pb(inv[e]);
  }
};

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
	int n;
	cin>>n;
	vector<string> ss(n);
	rep(i,n) cin>>ss[i];
	vv<int> g(26);
	vector<int> ex(26);
	int ng=0;
	for(string s:ss){
		reps(i,1,s.size()){
			g[s[i-1]-'a'].pb(s[i]-'a');
		}
		sort(all(s));
		reps(i,1,s.size()){
			if(s[i-1]==s[i]) ng=1;
		}
		for(char c:s) ex[c-'a']=1;
	}
	out(g,1);
	Scc h(g);
	if(h.scc.size()<26) ng=1;
	if(ng){
		cout<<"NO"<<endl;
		exit(0);
	}
	string re;
	vector<int> ind(26);
	rep(i,26)for(int x:h.dag[i]) ++ind[x];
	rep(i,26)if(ind[h.inv[i]]==0){
		for(int v=h.inv[i];;){
			re+=string(1,h.scc[v][0]+'a');
			if(h.dag[v].size()==0) break;
			v=h.dag[v][0];
		}
		out(i,re,1);
	}
	if(re.size()!=26) ng=1;
	if(ng){
		cout<<"NO"<<endl;
	}else{
		for(char c:re)if(ex[c-'a']) cout<<c; cout<<Endl;
	}
  return 0;
}