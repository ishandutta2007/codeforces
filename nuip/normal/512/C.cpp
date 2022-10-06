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
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}
//--------------------
typedef int Cost;
struct Edge{int to,cap,rev;Cost cost;};
typedef vector<Edge> Edges;
typedef vector<vector<Edge> > Graph;
Graph g2;
void add_edge(Graph &g,int from,int to,int cap,Cost cost=0){
  g[from].pb((Edge){to,cap,(int)g[to].size(),cost});
  g[to].pb((Edge){from,0,(int)g[from].size()-1,-cost});
}
Cost INF=1e7;

//max_flow

vector<int> used,a;

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
int flag;
int max_flow(Graph &g,int s,int t){
  int sum=0,f,V=g.size(),n=g.size()-4;
  while(1){
    used.resize(V);
    fill(all(used),0);
    sum+=f=dfs(g,s,t,INF);
    if(!f){
      rep(i,n)for(auto &gg:g[i+2]){
	if(gg.cap==0 && a[i]%2 && gg.to>1 && gg.to<n+2){
	  gg.cap=0;
	  g[gg.to][gg.rev].cap=0;
	  //	  cout<<"["<<i<<","<<gg.to-2<<"]"<<endl;
	  g2[i].pb((Edge){gg.to-2,0,0,0});
	  g2[gg.to-2].pb((Edge){i,0,0,0});
	}
      }
      flag=1;
      return sum;
    }
  }
}

int dfs2(vector<vector<int>> &re,vector<int> &usd,int p){
  if(usd[p])
    return 0;
  usd[p]=1;
  re.back().pb(p);
  for(auto pp:g2[p])
    dfs2(re,usd,pp.to);
  return 0;
}

const int NP=112345;
int prime[NP];
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  for(i=2;i<NP;i++)if(!prime[i]){
      for(j=i+i;j<NP;j+=i)
	prime[j]=1;
    }
  int n;
  cin>>n;
  a.resize(n);
  g2.resize(n);
  rep(i,n)
    cin>>a[i];
  if(n%2){
    cout<<"Impossible"<<endl;
    return 0;
  }
  Graph g(n+4);
  rep(i,n)for(j=i+1;j<n;j++){
    if(!prime[a[i]+a[j]]){
      if(a[i]%2)
	add_edge(g,i+2,j+2,1);
      else
	add_edge(g,j+2,i+2,1);
    }
  }
  int sum=0;
  rep(i,n){
    if(a[i]%2){
      sum++;
      add_edge(g,0,i+2,1);
      add_edge(g,n+2,i+2,1);
    }else{
      sum--;
      add_edge(g,i+2,1,1);
      add_edge(g,i+2,n+3,1);
    }
  }
  if(sum){
    cout<<"Impossible"<<endl;
    return 0;
  }
  /*  rep(i,n+4){
    cout<<i<<":";
    for(auto tmp:g[i])
      cout<<"("<<tmp.to<<","<<tmp.cap<<"),";cout<<endl;
      }*/
  if(max_flow(g,0,1)<n/2){
    cout<<"Impossible"<<endl;
    return 0;
  }
  /*  cout<<endl;
  rep(i,n+4){
    cout<<i<<":";
    for(auto tmp:g[i])
      cout<<"("<<tmp.to<<","<<tmp.cap<<"),";cout<<endl;
      }*/
  if(max_flow(g,n+2,n+3)<n/2){
    cout<<"Impossible"<<endl;
    return 0;
  }
  vector<vector<int>> re;
  vector<int> usd(n);
  // rep(i,n)rep(j,g2[i].size())cout<<"("<<i<<","<<g2[i][j].to<<")";
  rep(i,n){
    if(!usd[i]){
      re.pb(vector<int>());
      dfs2(re,usd,i);
    }
  }
  cout<<re.size()<<endl;
  for(auto v:re){
    cout<<v.size();
    rep(i,v.size())
      cout<<" "<<v[i]+1;
    cout<<endl;
  }
  return 0;
}