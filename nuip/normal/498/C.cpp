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
#include<cstring>
#include<sstream>
#include<complex>
#include<iomanip>
#include<numeric>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < int(Y);++(X))
#define rrep(X,Y) for (int (X) = int(Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < int(Y);++(X))
#define peat(X,Y) for (;(X) < int(Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
typedef int Cost;
struct Edge{int to,cap,rev;Cost cost;};
typedef vector<Edge> Edges;
typedef vector<vector<Edge> > Graph;

void add_edge(Graph &g,int from,int to,int cap,Cost cost=0){
  //  cout<<from<<"=>"<<to<<":"<<cap<<endl;
  g[from].pb((Edge){to,cap,g[to].size(),cost});
  g[to].pb((Edge){from,0,g[from].size()-1,-cost});
}
Cost INF=1e7;

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

int prime[112345];

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  vector<int> primes;
  for(i=2;i<112345;i++){
    if(prime[i])continue;
    primes.pb(i);
    for(j=i*2;j<112345;j+=i)
      prime[j]=1;
  }
  int n,m;
  cin>>n>>m;
  vector<int> v(n);
  rep(i,n)
    cin>>v[i];
  Graph g(2);
  vector<pii> node[n];
  rep(i,n){
    int num=v[i];
    rep(j,primes.size()){
      if(num%primes[j])
	continue;
      node[i].pb(pii(primes[j],0));
      while(num%primes[j]==0){
	num/=primes[j];
	++node[i].back().Y;
      }
      g.pb(Edges());
      //   cout<<node[i].back()<<endl;
      if(i%2){
	add_edge(g,0,g.size()-1,node[i].back().Y);
      }else{
	add_edge(g,g.size()-1,1,node[i].back().Y);
      }
      node[i].back().Y=g.size()-1;
    }
    if(num>1){
      node[i].pb(pii(num,1));
      g.pb(Edges());
      //   cout<<node[i].back()<<endl;
      if(i%2){
	add_edge(g,0,g.size()-1,node[i].back().Y);
      }else{
	add_edge(g,g.size()-1,1,node[i].back().Y);
      }
      node[i].back().Y=g.size()-1;
    }
  }
  int a,b;
  rep(i,m){
    cin>>a>>b;
    --a,--b;
    if(b%2)swap(a,b);
    rep(i,node[a].size()){
      rep(j,node[b].size()){
	if(node[a][i].X==node[b][j].X)
	  add_edge(g,node[a][i].Y,node[b][j].Y,INF);
      }
    }
  }
  cout<<max_flow(g,0,1)<<endl;
  return 0;
}