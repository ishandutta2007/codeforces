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
Graph g;
vector<int> leaf;

int dfsl(int v,int p){
  int f=0;
  for(int &w:g[v])
    if(w!=p){
      f=1;
      leaf[v]+=dfsl(w,v);
    }
  if(!f)leaf[v]=1;
  return leaf[v];
}

int dfsL(int v,int p,int dep){
  if(dep){
    int re=0;
    for(int &w:g[v])
      if(w!=p)
	re+=dfsL(w,v,1-dep);
    return re;
  }else{
    int re=leaf[v]-1;
    for(int &w:g[v])
      if(w!=p)
	re=min(re,leaf[w]-1-dfsL(w,v,1-dep));
    return leaf[v]-1-re;
  }
}

int dfsS(int v,int p,int dep){
  if(!dep){
    int re=0;
    for(int &w:g[v])
      if(w!=p)
	re+=leaf[w]-1-dfsS(w,v,1-dep);
    return leaf[v]-1-re;
  }else{
    int re=leaf[v]-1;
    for(int &w:g[v])
      if(w!=p)
	re=min(re,dfsS(w,v,1-dep));
    return re;
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cout<<fixed<<setprecision(0);
  int i,j,k;
  int n,a,b;
  cin>>n;
  g.resize(n);
  leaf.resize(n);
  rep(i,n-1){
    cin>>a>>b;
    --a; --b;
    g[a].pb(b);
    g[b].pb(a);
  }
  dfsl(0,-1);
  cout<<dfsL(0,-1,0)+1<<" "<<dfsS(0,-1,0)+1<<endl;
  return 0;
}