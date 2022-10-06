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
typedef vv<int> Graph;

vector<int> dep,cld;
vv<int> par;
const int LOGN=20;
int dfsLCA(Graph &g,int v,int p,int dep,vector<int> &d,vv<int> &par=par,vector<int> &cld=cld){
  d[v]=dep; par[v][0]=p;
  int re=0;
  for(int vv:g[v])if(vv!=p)
      re+=dfsLCA(g,vv,v,dep+1,d,par,cld);
  return (cld[v]=re)+1;
}
void preLCA(Graph &g,vector<int> &d,vv<int> &par=par,vector<int> &cld=cld){
  int n=g.size();
  dfsLCA(g,0,-1,0,d,par,cld);
  rep(i,LOGN-1)rep(v,n)
    par[v][i+1]=par[v][i]<0?-1:par[par[v][i]][i];
}

int anc(int v,int n,const vv<int> &par=par){
  rep(i,LOGN)if(n>>i&1)
    if((v=par[v][i])<0)break;
  return v;
}

int LCA(int v,int w,const vector<int> &dep=dep,const vv<int> &par=par){
  if(dep[v]>dep[w])
    swap(v,w);
  w=anc(w,dep[w]-dep[v]);
  rrep(i,LOGN)
    if(par[v][i]!=par[w][i]){
      v=par[v][i];
      w=par[w][i];
    }
  return v==w?v:par[v][0];
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,m;
  int a,b;
  cin>>n;
  Graph g(n);
  rep(i,n-1){
    cin>>a>>b;
    --a,--b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dep.resize(n),cld.resize(n);
  par.resize(n,vector<int>(LOGN));
  preLCA(g,dep,par,cld);
  //   cout<<dep<<cld<<par;
  cin>>m;
  int re;
  rep(i,m){
    cin>>a>>b;
    --a,--b;
    if(dep[a]>dep[b])
      swap(a,b);
    int c=LCA(a,b),mid;
     int dist=dep[a]+dep[b]-2*dep[c];
    if(dep[a]==dep[b]){
      re=(a==b?n:n-cld[anc(a,dep[a]-dep[c]-1)]-cld[anc(b,dep[b]-dep[c]-1)]-2);
    }else{
      if((dist)%2){
	re=0;
      }else{
	mid=anc(b,dist/2);
	//	cout<<dist<<","<<mid<<endl;
	re=cld[mid]-cld[anc(b,dist/2-1)];
      }
    }
    printf("%d\n",re);
  }
  return 0;
}