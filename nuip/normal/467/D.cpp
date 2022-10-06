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
#define X first
#define Y second
#define pb push_back
#define rep(X,Y) for (int (X) = 0;(X) < (Y);++(X))
#define rrep(X,Y) for (int (X) = Y-1;(X) >=0;--(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

map<string,int> str2num;
Graph g;
int n,m;

void visit(const Graph &g, int v, vector< vector<int> >& scc,
    stack<int> &S, vector<bool> &inS,
    vector<int> &low, vector<int> &num, int& time) {
  low[v] = num[v] = ++time;
  S.push(v); inS[v] = true;
  FOR(e, g[v]) {
    int w = e->dst;
    if (num[w] == 0) {
      visit(g, w, scc, S, inS, low, num, time);
      low[v] = min(low[v], low[w]);
    } else if (inS[w])
      low[v] = min(low[v], num[w]);
  }
  if (low[v] == num[v]) {
    scc.push_back(vector<int>());
    while (1) {
      int w = S.top(); S.pop(); inS[w] = false;
      scc.back().push_back(w);
      if (v == w) break;
    }
  }
}
void stronglyConnectedComponents(const Graph& g,
    vector< vector<int> >& scc) {
  const int n = g.size();
  vector<int> num(n), low(n);
  stack<int> S;
  vector<bool> inS(n);
  int time = 0;
  REP(u, n) if (num[u] == 0)
    visit(g, u, scc, S, inS, low, num, time);
}

pii cost[312345],cost2[312345],minCost[312345];
vector<int> edges[312345];
int toScc[312345];

pii calcCost(string str){
  pii re;
  rep(i,str.size())
    re.X+=(str[i]=='r');
  re.Y=str.size();
  return re;
}

vector<vector<int> > scc;

pii solve(int p){
  if(minCost[p].X>=0)
    return minCost[p];
  int i,j,k;
  minCost[p]=cost2[p];
  rep(i,edges[p].size())
    minCost[p]=min(minCost[p],solve(edges[p][i]));
  return minCost[p];
}

int main(){
  int i,j,k;
  cin>>n;
  vector<int> in(n);
  string tmp,temp;
  rep(i,n){
    cin>>tmp;
    rep(j,tmp.size())
      tmp[j]=tolower(tmp[j]);
    if(!str2num.count(tmp)){
      str2num[tmp]=str2num.size()-1;
      cost[str2num[tmp]]=calcCost(tmp);
    }
    in[i]=str2num[tmp];
  }
  g.resize(str2num.size());
  cin>>m;
  rep(i,m){
    cin>>tmp>>temp;
    rep(j,tmp.size())
      tmp[j]=tolower(tmp[j]);
    rep(j,temp.size())
      temp[j]=tolower(temp[j]);
    if(!str2num.count(tmp)){
      str2num[tmp]=str2num.size()-1;
      cost[str2num[tmp]]=calcCost(tmp);
      g.pb(Edges());
    }
    if(!str2num.count(temp)){
      str2num[temp]=str2num.size()-1;
      cost[str2num[temp]]=calcCost(temp);
      g.pb(Edges());
    }
    if(tmp!=temp)g[str2num[tmp]].pb(
      Edge(str2num[tmp],str2num[temp],0));
  }

  stronglyConnectedComponents(g,scc);
 /* 
  for(auto vv:scc){
    for(auto v:vv)cout<<v<<" ";cout<<endl;}
  for(auto p:str2num)cout<<p.X<<","<<p.Y<<endl;*/

  rep(i,scc.size()){
    cost2[i]=cost[scc[i][0]];
    rep(j,scc[i].size()){
      cost2[i]=min(cost2[i],cost[scc[i][j]]);
      toScc[scc[i][j]]=i;
    }
    //cout<<cost[i].X<<","<<cost[i].Y<<" ";
  }//cout<<endl;
  rep(i,scc.size()){
    rep(j,scc[i].size()){
      Edges tmp=g[scc[i][j]];
      for(auto e:tmp){
        if(toScc[e.dst]!=i)
          edges[i].pb(toScc[e.dst]);
      }
    }
  }
  fill(minCost,minCost+scc.size(),pii(-1,0));
  rep(i,scc.size()){
    if(minCost[i].X<0)
      minCost[i]=solve(i);
  }

  ll re1=0,re2=0;
  rep(i,n){
    re1+=minCost[toScc[in[i]]].X;
    re2+=minCost[toScc[in[i]]].Y;
   // cout<<re1<<" "<<re2<<endl;
  }
  cout<<re1<<" "<<re2<<endl;
  return 0;
}