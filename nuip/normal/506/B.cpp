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
#define rrep(X,Y) for (int (X) = (Y-1);(X) >=0;--(X))
#define repe(X,Y) for ((X) = 0;(X) < (Y);++(X))
#define peat(X,Y) for (;(X) < (Y);++(X))
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
template<class T> using vv=vector<vector<T>>;
template<class T> ostream& operator<<(ostream &os, const vector<T> &t) {
os<<"{"; rep(i,t.size()) {os<<t[i]<<",";} os<<"}"<<endl; return os;}
template<class S, class T> ostream& operator<<(ostream &os, const pair<S,T> &t) { return os<<"("<<t.first<<","<<t.second<<")";}

typedef int Weight;
struct Edge {
  int src, dst;
  Weight weight;
  Edge(int src, int dst, Weight weight) :
    src(src), dst(dst), weight(weight) { }
};
ostream& operator<< (ostream &os,const Edge &e){
  return cout<<"("<<e.src<<","<<e.dst<<")";}
bool operator < (const Edge &e, const Edge &f) {
  return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
    e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
bool operator==(const Edge &e,const Edge &f){
  return e.src==f.src && e.dst==f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

void visit(const Graph &g, int v, vector< vector<int> >& scc,
    stack<int> &S, vector<bool> &inS,
    vector<int> &low, vector<int> &num, int& time) {
  low[v] = num[v] = ++time;
  S.push(v); inS[v] = true;
  for(auto e : g[v]) {
    int w = e.dst;
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

void toDag(const Graph& g,const vector<vector<int> >&scc,
           vector<int> &dagV,Graph &dag){
  dagV.resize(g.size());
  dag.resize(scc.size());
  rep(i,scc.size()){
    rep(j,scc[i].size()){
      dagV[scc[i][j]]=i;
    }
  }
  rep(i,scc.size()){
    rep(j,scc[i].size()){
      for(auto e:g[scc[i][j]]){
        if(dagV[e.dst] != i)
          dag[i].pb(Edge(i,dagV[e.dst],e.weight));
      }
    }
  }
}

vector<int> Scc(const Graph& g,
    vector< vector<int> >& scc,Graph &dag) {
  const int n = g.size();
  vector<int> num(n), low(n),dagV(n);
  stack<int> S;
  vector<bool> inS(n);
  int time = 0;
  rep(u, n) if (num[u] == 0)
    visit(g, u, scc, S, inS, low, num, time);
  reverse(all(scc));
  toDag(g,scc,dagV,dag);
  rep(i,dag.size()){
    dag[i].erase(unique(all(dag[i])),dag[i].end());
  }
  return dagV;
}
pii count(Graph &g,vv<int> &scc,vector<int> &usd,int v){
  //   cout<<v<<endl;
  if(usd[v])return pii(0,0);
  pii re=pii(scc[v].size(),scc[v].size()>1),tmp;
  usd[v]=1;
  for(Edge e:g[v])
    if(!usd[e.dst]){
      tmp=count(g,scc,usd,e.dst);
      re.X+=tmp.X;
      re.Y|=tmp.Y;
    }
  return re;
}
void ccdfs(Graph &g,vector<int> &cc,vector<int> &usd,int v){
  if(usd[v])return;
  usd[v]=1;
  cc.pb(v);
  for(const Edge &e:g[v])if(!usd[e.dst])
    ccdfs(g,cc,usd,e.dst);
}
void CC(Graph &h,vv<int> &cc){
  int n=h.size();
  vector<int> usd(n);
  Graph g=h;
  rep(i,n)for(const Edge &e:h[i])
    g[e.dst].pb(Edge(e.dst,e.src,e.weight));
  rep(i,n)if(!usd[i]){
    cc.pb(vector<int>());
    ccdfs(g,cc.back(),usd,i);
  }
}
bool topodfs(const Graph &g,int v,vector<int> &order,vector<int> &usd,vector<int> &ex){
  usd[v]=1;
  for(const Edge &e:g[v])if(*lower_bound(all(ex),e.dst)==e.dst){
    if(usd[e.dst]==2) continue;
    if(usd[e.dst]==1) return 0;
    if(!topodfs(g,e.dst,order,usd,ex)) return 0;
  }
  order.pb(v); usd[v]=2;
  return 1;
}
bool topoSort(const Graph &g,vector<int> &ex,vector<int> &order){
  int n=g.size();
  vector<int> usd(n);
  rep(i,n)if(!usd[i]&& *lower_bound(all(ex),i)==i)
    if(!topodfs(g,i,order,usd,ex))return 0;
  reverse(all(order));
  return 1;
}
int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,m;
  scanf("%d %d",&n,&m);
  Graph g(n);
  int a,b;
  rep(i,m){
    scanf("%d %d",&a,&b);
    --a; --b;
    g[a].pb(Edge(a,b,1));
  }/*
  vv<int> cc;
  CC(g,cc);
  int re=0;
  for(vector<int> &vs:cc){
    if(vs.size()<2){
      continue;
    }else if(vs.size()==2){
      re+=g[vs[0]].size()>0 && g[vs[1]].size()>0;
      continue;
    }
    sort(all(vs));
    vector<int> order;
    re+=vs.size()-(topoSort(g,vs,order));
  }*/
  
  vv<int> scc;
  Graph dag;
  Scc(g,scc,dag);
  int dn=scc.size(),re=0;
  vector<int> usd(dn);
  // cout<<scc<<dag<<endl;
  vv<int> cc;
  CC(dag,cc);
  rep(i,cc.size()){
    int f=0;
    rep(j,cc[i].size()){
      f|=(scc[cc[i][j]].size()>1);
      re+=scc[cc[i][j]].size();
    }
    if(!f)--re;
  }
  /*
  rep(i,dn)
    if(!usd[i]){
      pii tmp=count(dag,scc,usd,i);//cout<<i<<tmp;
      re+=tmp.X-1+tmp.Y;
    }*/
  printf("%d\n",re);
  return 0;
}