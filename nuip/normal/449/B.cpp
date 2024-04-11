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
//--
#include<list>
#include<deque>
#include<bitset>
#include<set>
#include<map>
#include<cstring>
#include<sstream>
#include<complex>
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<double,int> pdi;
typedef pair<int,double> pid;

int V;
vector<pid> g[112345];
double d[112345],train[112345],re,INF=5e14,need[112345],fix[112345],EPS=1e-3;

void dij(int s){
  priority_queue<pdi,vector<pdi>,greater<pdi> > que;
  fill(d,d+V,INF);
  d[s]=0;
  que.push(pdi(0,s));
  
  while(!que.empty()){
    pdi p=que.top();que.pop();
    int v=p.Y;
    if(d[v]<p.X)continue;
//    cout<<v<<":"<<d[v]<<endl;
    if(d[v]-int(d[v])){
 //     cout<<"!"<<endl;
      need[v]=1;
      d[v]-=d[v]-int(d[v]);
    }
    for(int i=0;i<g[v].size();i++){
      pid e=g[v][i];
      if(d[e.X]>d[v]+e.Y){
        d[e.X]=d[v]+e.Y;
        que.push(pdi(d[e.X],e.X));
      }
    }
  }
}

int main(){
  int i,j,k;
  int m,s,u,v,c;
  fill(train,train+112345,INF);
  cin>>V>>m>>s;
  rep(i,m){
    cin>>u>>v>>c;
    u--;v--;
    g[u].pb(pid(v,c));
    g[v].pb(pid(u,c));
  }
  rep(i,s){
    cin>>v>>c;
    v--;
    if(train[v]==INF){
      train[v]=c;
    }else{
      train[v]=min(int(train[v]),c);
      re++;
    }
  }
  rep(i,V){
    if(train[i]!=INF){
      g[0].pb(pid(i,train[i]+EPS));
      g[i].pb(pid(0,train[i]+EPS));
    }
  }
  dij(0);
  rep(i,V){//cout<<fix[i];
    if(fix[i])continue;
    if(d[i]-int(d[i])){
      need[i]=1;
      d[i]-=d[i]-int(d[i]);
    }
  }//cout<<endl;
  rep(i,V){
    //cout<<need[i];
    if(need[i]==0&&train[i]!=INF)
      re++;
  }//cout<<endl;
  cout<<re<<endl;
  
  return 0;
}