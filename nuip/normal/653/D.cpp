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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y)-1;(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define eb emplace_back
#define UNIQUE(X) (X).erase(unique(all(X)),(X).end())

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
const ll MOD=1e9+7;
typedef int Cost;
struct Edge{int to,cap,rev;Cost cost;};
typedef vector<Edge> Edges;
typedef vector<vector<Edge> > Graph;

void add_edge(Graph &g,int from,int to,int cap,Cost cost=0){
  //cout<<from<<"->"<<to<<":"<<cap<<endl;
  g[from].pb((Edge){to,cap,(int)g[to].size(),cost});
  g[to].pb((Edge){from,0,(int)g[from].size()-1,-cost});
}
Cost INF=1e7;
const double EPS=1e-10;
//max_flow

vector<int> used;

int dfs(Graph &g,int v,int t,int f){
  if(v==t) return f;
  used[v]=1;
  int re,i,j,k;
  for(i=0;i<g[v].size();i++){
    Edge &e=g[v][i];
    if(e.cap<=0||used[e.to])continue;
    int d=dfs(g,e.to,t,min(f,e.cap));
    if(d>0){
      e.cap-=d;
      g[e.to][e.rev].cap+=d;
      return d;
    }
  }
  return 0;
}

int max_flow(Graph &g,int s,int t){
  int sum=0,f,V=g.size();
  while(1){
    used.resize(V);
    fill(all(used),0);
    sum+=f=dfs(g,s,t,INF);
    if(!f)return sum;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(10);
  int n,m,x;
  cin>>n>>m>>x;
  vv<pii> g(n);
  int f,y,c;
  rep(i,m){
    cin>>f>>y>>c; --f; --y;
    g[f].eb(y,c);
  }
  double l=0,r=1000123,med;
  rep(hoge,60){
    med=(l+r)/2;
    Graph h(n);
    rep(i,n) for(pii p:g[i]){
      add_edge(h,i,p.X,int(min<double>(x,p.Y/med+EPS)));
    }
    int flow=max_flow(h,0,n-1);
    //cout<<flow<<":"<<med<<endl;
    if(flow>=x)
      l=med;
    else
      r=med;
  }
  cout<<l*x<<endl;
  return 0;
}